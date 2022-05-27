#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <cstring>
using std::istream;
using std::ostream;
class MyString
{
    // Prototype for stream insertion
    friend ostream &operator<<(ostream &os, const MyString &obj)
    {
        os << obj.m_str;
        return os;
    }

    // Prototype for stream extraction
    friend istream &operator<<(istream &is, const MyString &obj);

    friend MyString operator+(const MyString &lhs, const MyString &rhs);

    char *m_str;

public:
    MyString();

    MyString(char *val);

    size_t getSize() const { return strlen(m_str); }

    void pop_bk();

    void push_bk(char);

    void copy(char s[], int len, int pos);

    void swap(MyString &rhs);

    // Copy constructor
    MyString(const MyString &source);

    // Move constructor
    MyString(MyString &&source);

    // Overload the assignment operator
    MyString &operator=(const MyString &rhs);

    ~MyString() { delete[] m_str; }
};

istream &operator>>(istream &is, MyString &obj)
{
    char *buff = new char[1000];
    // memset warning
    memset(&buff[0], 0, sizeof(buff));
    is >> buff;
    obj = MyString{buff};
    delete[] buff;
    return is;
}

#endif // MyString