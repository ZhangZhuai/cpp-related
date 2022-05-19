#include "auto_pointer.h"

template <typename T>
auto_ptr<T>::auto_ptr(T* ptr) {
    this->ptr_ = ptr;
}

template <typename T>
auto_ptr<T>::~auto_ptr() {
    std::cout << "~auto_ptr()" << std::endl;
    delete ptr_;
}

template <typename T>
T* auto_ptr<T>::get() const {
    return ptr_;
}


// Operator overload to enable pointer-relationed op
template <typename T>
T& auto_ptr<T>::operator*() const { return *ptr_; }

template <typename T>
T* auto_ptr<T>::operator->() const { return ptr_; }

template <typename T>
auto_ptr<T>::operator bool() const { return ptr_; }

template <typename T>
auto_ptr<T>::auto_ptr(auto_ptr& other) noexcept {
    ptr_ = other.release();
}

//copy alignment : copy and swap
template <typename T>
auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<T>& rhs) {
    auto_ptr(rhs).swap(*this);
    return *this;
}

//release ownership
template <typename T>
T* auto_ptr<T>::release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
}

template <typename T>
void auto_ptr<T>::swap(auto_ptr& rhs) {
    using std::swap;
    swap(ptr_, rhs.ptr_);
}
