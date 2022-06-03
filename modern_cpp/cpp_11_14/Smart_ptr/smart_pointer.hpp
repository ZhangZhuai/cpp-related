#ifndef __SMART_POINTER_HPP__
#define __SMART_POINTER_HPP__
template <typename T>
class Smart_pointer
{
public:
    explicit Smart_pointer(T *memory);

    Smart_pointer(const Smart_pointer &other);
    Smart_pointer &operator=(const Smart_pointer &other);

    ~Smart_pointer();

    T &operator*() const;
    T *operator->() const;

    T *get() const;

    unsigned int getSharedCount() const;

    void reset(T* newRes);

private:
    struct Intermediary
    {
        T *resource;
        unsigned int refCount;
    };

    Intermediary *data;

    // Helper function to implement the copy behaviour for Smart_pointer
    void detach();
    void attach(Intermediary *other);
};

template <typename T>
Smart_pointer<T>::Smart_pointer(T *res)
{
    data = new Intermediary;
    data->resource = res;
    data->refCount = 1;
}

template <typename T>
Smart_pointer<T>::~Smart_pointer()
{
    detach();
}

template <typename T>
T &Smart_pointer<T>::operator*() const
{
    return *data->resource;
}

template <typename T>
T *Smart_pointer<T>::operator->() const
{
    // return &**this;
    return data->resource;
}

template <typename T>
void Smart_pointer<T>::detach()
{
    --data->refCount;
    if (data->refCount == 0)
    {
        delete data->resource;
        delete data;
    }
}

template <typename T>
void Smart_pointer<T>::attach(Intermediary *to)
{
    data = to;
    ++data->refCount;
}

template <typename T>
Smart_pointer<T>::Smart_pointer(const Smart_pointer &other)
{
    attach(other.data);
}

template <typename T>
Smart_pointer<T> &Smart_pointer<T>::operator=(const Smart_pointer &other)
{
    if (this != &other)
    {
        detach();
        attach(other.data);
    }
    return *this;
}

template <typename T>
T *Smart_pointer<T>::get() const
{
    return data->resource;
}

template <typename T>
unsigned int Smart_pointer<T>::getSharedCount() const
{
    return data->refCount;
}

template <typename T>
void Smart_pointer<T>::reset(T* newRes)
{
    detach();
    data = new Intermediary;
    data->resource = newRes;
    data->refCount = 1;
}

#endif // Smart_pointer
