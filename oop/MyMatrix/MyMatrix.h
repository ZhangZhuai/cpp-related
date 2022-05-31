#ifndef __MYMATRIX_H__
#define __MYMATRIX_H__
#include <vector>
#include <algorithm>

template <typename T>
class MyMatrix
{
public:
    MyMatrix();
    MyMatrix(size_t rows, size_t clos);

    void clear();
    void resize(size_t rows, size_t clos);

    size_t getRows() const;
    size_t getCols() const;
    bool empty();
    size_t size() const;

    T &getAt(size_t row, size_t col);
    const T &getAt(size_t row, size_t col) const;

    // Use typedef to make MyMatrix<T>::iterator possible
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    iterator row_begin(size_t row);
    const_iterator row_begin(size_t row) const;
    iterator row_end(size_t row);
    const_iterator row_end(size_t row) const;

    // Proxy object to make mymatrix[1][1] possible
    class MutableReference
    {
    public:
        friend class MyMatrix;
        T &operator[](size_t col);

    private:
        MutableReference(MyMatrix *owner, size_t row);
        MyMatrix *const owner;
        const size_t row;
    };

    MutableReference operator[](size_t row);

    // Proxy object to make mymatrix[1][1] possible, and const
    class ImmutableReference
    {
    public:
        friend class MyMatrix;
        const T &operator[](size_t col) const;

    private:
        ImmutableReference(MyMatrix *owner, size_t row);
        MyMatrix *const owner;
        const size_t row;
    };

    ImmutableReference operator[](size_t row) const;

    bool operator<(const MyMatrix &other) const;
    bool operator<=(const MyMatrix &other) const;
    bool operator==(const MyMatrix &other) const;
    bool operator!=(const MyMatrix &other) const;
    bool operator>(const MyMatrix &other) const;
    bool operator>=(const MyMatrix &other) const;

private:
    std::vector<T> elems;
    size_t rows, cols;
};

#endif // MyMatrix