#ifndef AUTO_SCOPE_H
#define AUTO_SCOPE_H

#include <algorithm>
#include <iostream>

template <typename T>
class auto_ptr {
public:
    explicit auto_ptr(T* ptr);

    ~auto_ptr();

    T* get() const;
    
    // Operator overload to enable pointer-relationed op
    T& operator*() const;

    T* operator->() const;

    operator bool() const;

    auto_ptr(auto_ptr& other) noexcept;

    //copy alignment : copy and swap
    auto_ptr& operator=(auto_ptr& rhs);

    //release ownership
    T* release();

    void swap(auto_ptr& rhs);

private:
    T* ptr_;
};

#endif