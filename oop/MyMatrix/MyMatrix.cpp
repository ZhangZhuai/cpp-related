#include "MyMatrix.h"

template <typename T>
MyMatrix<T>::MyMatrix() : rows(0), cols(0)
{
}

template <typename T>
MyMatrix<T>::MyMatrix(size_t rows, size_t cols)
    : elems(rows * cols), rows(rows), cols(cols)
{
}

template <typename T>
void MyMatrix<T>::clear()
{
    // reuse the resize method
    resize(0, 0);
}

template <typename T>
void MyMatrix<T>::resize(size_t rows, size_t cols)
{
    elems.assign(rows * cols, T());
    this->rows = rows;
    this->cols = cols;
}

template <typename T>
size_t MyMatrix<T>::getRows() const
{
    return rows;
}

template <typename T>
size_t MyMatrix<T>::getCols() const
{
    return cols;
}

template <typename T>
bool MyMatrix<T>::empty()
{
    return size() == 0;
}

template <typename T>
size_t MyMatrix<T>::size() const
{
    return getCols() * getRows();
}

template <typename T>
const T &MyMatrix<T>::getAt(size_t row, size_t col) const
{
    return elems[row * col + col];
}

template <typename T>
T &MyMatrix<T>::getAt(size_t row, size_t col)
{
    return elems[row * col + col];
}

template <typename T>
typename MyMatrix<T>::iterator MyMatrix<T>::begin()
{
    return elems.begin();
}

template <typename T>
typename MyMatrix<T>::const_iterator MyMatrix<T>::begin() const
{
    return elems.begin();
}

template <typename T>
typename MyMatrix<T>::iterator MyMatrix<T>::end()
{
    return elems.end();
}

template <typename T>
typename MyMatrix<T>::const_iterator MyMatrix<T>::end() const
{
    return elems.end();
}

template <typename T>
typename MyMatrix<T>::iterator MyMatrix<T>::row_begin(size_t row)
{
    return begin() + getCols() * row;
}

template <typename T>
typename MyMatrix<T>::const_iterator MyMatrix<T>::row_begin(size_t row) const
{
    return begin() + getCols() * row;
}

template <typename T>
typename MyMatrix<T>::iterator MyMatrix<T>::row_end(size_t row)
{
    return row_begin(row) + getCols();
}

template <typename T>
typename MyMatrix<T>::const_iterator MyMatrix<T>::row_end(size_t row) const
{
    return row_begin(row) + getCols();
}

template <typename T>
MyMatrix<T>::MutableReference::MutableReference(MyMatrix *owner, size_t row)
    : owner(owner), row(row)
{
}

template <typename T>
T &MyMatrix<T>::MutableReference::operator[](size_t col)
{
    return owner->getAt(row, col);
}

template <typename T>
typename MyMatrix<T>::MutableReference MyMatrix<T>::operator[](size_t row)
{
    return MutableReference(this, row);
}

template <typename T>
MyMatrix<T>::ImmutableReference::ImmutableReference(MyMatrix *owner, size_t row)
    : owner(owner), row(row)
{
}

template <typename T>
const T &MyMatrix<T>::ImmutableReference::operator[](size_t col) const
{
    return owner->getAt(row, col);
}

template <typename T>
typename MyMatrix<T>::ImmutableReference MyMatrix<T>::operator[](size_t row) const
{
    return ImmutableReference(this, row);
}

template <typename T>
bool MyMatrix<T>::operator<(const MyMatrix &other) const
{
    if (rows != other.rows)
    {
        return rows < other.rows;
    }
    if (cols != other.cols)
    {
        return cols < other.cols;
    }

    // STL algorithm reuse
    return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
}

template <typename T>
bool MyMatrix<T>::operator>=(const MyMatrix &other) const
{
    return !(*this < other);
}

template <typename T>
bool MyMatrix<T>::operator!=(const MyMatrix &other) const
{
    return (*this < other) || (other < *this);
}

template <typename T>
bool MyMatrix<T>::operator==(const MyMatrix &other) const
{
    return !(*this < other) && !(other < *this);
}

template <typename T>
bool MyMatrix<T>::operator<=(const MyMatrix &other) const
{
    return !(other < *this);
}

template <typename T>
bool MyMatrix<T>::operator>(const MyMatrix &other) const
{
    return other < *this;
}