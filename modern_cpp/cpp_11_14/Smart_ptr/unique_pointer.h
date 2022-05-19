#ifndef __UNIQUE_SCOPE_H
#define __UNIQUE_SCOPE_H

#include <algorithm>
#include <iostream>

template <typename T>
class unique_ptr {
public:
    explicit unique_ptr(T* ptr = nullptr)
        : ptr_{ptr} {}

    ~unique_ptr() {
        std::cout << "~unique_ptr()" << std::endl;
        delete ptr_;
    }


    T* get() const {
        return ptr_;
    }
    

    // Operator overload to enable pointer-relationed op
    T& operator*() const { return *ptr_; }

    T* operator->() const { return ptr_; }

    operator bool() const { return ptr_; }

    //move ctor!!!
    unique_ptr(unique_ptr&& other) noexcept {
        ptr_ = other.release();
    }

    //move alignment : copy and swap!!!
    //operator= parameter (unique_ptr) to avoid the a=a; judge
    unique_ptr& operator=(unique_ptr rhs) {
        (rhs).swap(*this);
        return *this;
    }

    //release ownership
    T* release() {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(unique_ptr& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T* ptr_;
};

#endif