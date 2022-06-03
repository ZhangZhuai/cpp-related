#ifndef SCOPED_SCOPE_H
#define SCOPED_SCOPE_H

#include <algorithm>
#include <iostream>

template <typename T>
class scoped_ptr {
public:
    explicit scoped_ptr(T* ptr = nullptr)
        : ptr_{ptr} {}

    ~scoped_ptr() {
        std::cout << "~scoped_ptr()" << std::endl;
        delete ptr_;
    }

    //reset scoped_ptr
    void reset(T* ptr = nullptr) {
        scoped_ptr(ptr).swap(*this);
    }

    T* get() const {
        return ptr_;
    }
    

    // Operator overload to enable pointer-relationed op
    T& operator*() const { return *ptr_; }

    T* operator->() const { return ptr_; }

    operator bool() const { return ptr_; }

    void swap(scoped_ptr& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T* ptr_;

    //forbid copy
    scoped_ptr(const scoped_ptr&);
    scoped_ptr& operator=(const scoped_ptr&);
};

#endif