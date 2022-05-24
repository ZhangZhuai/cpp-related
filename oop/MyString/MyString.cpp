#include "MyString.h"

MyString::MyString() : m_str {new char[1]} {
    m_str[0] = '\0';
}

MyString::MyString(char* str) {
    if (str == nullptr) {
        m_str = new char[1];
        m_str[0] = '\0';
    } else {
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }
}

//Copy constructor
MyString::MyString(const MyString& source) {
    m_str = new char[strlen(source.m_str) + 1];
    strcpy(m_str, source.m_str);
    m_str[strlen(source.m_str)] = '\0';
}

//Move constructor
MyString::MyString(MyString&& source) {
    m_str = source.m_str;
    source.m_str = nullptr;
}

//Overload the assignment operator
MyString& MyString::operator=(const MyString& rhs) {
    if (this == &rhs) return (*this);
    delete[] m_str;
    m_str = new char[strlen(rhs.m_str) + 1];
    strcpy(m_str, rhs.m_str);
    m_str[strlen(rhs.m_str)] = '\0';
    return *this;
}


istream& operator>>(istream& is, MyString& obj) {
    char* buff = new char[1000];
    //memset warning
    memset(&buff[0], 0, sizeof(buff));
    is >> buff;
    obj = MyString{buff};
    delete[] buff;
    return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    int len = lhs.getSize() + rhs.getSize();
    char* buff = new char[len + 1];
    strcpy(buff, lhs.m_str);
    strcat(buff, rhs.m_str);
    buff[len] = '\0';

    MyString temp{buff};
    delete[] buff;

    return temp;
}

void MyString::swap(MyString& rhs) {
    MyString tmp{rhs};
    rhs = *this;
    *this = tmp;
}

void MyString::copy(char s[], int len, int pos) {
    for (int i = 0; i < len; ++i) {
        s[i] = m_str[pos + 1];
    }
    s[len] = '\0';
}

void MyString::push_bk(char a) {
    int len = getSize();
    char* buff = new char[len + 2];
    for (int i = 0; i < len; ++i) {
        buff[i] = m_str[i];
    }
    buff[len] = a;
    buff[len + 1] = '\0';

    *this = MyString{buff};
    delete[] buff;
}

void MyString::pop_bk() {
    int len = getSize();
    char* buff = new char[len];
    for (int i = 0; i < len - 1; ++i) {
        buff[i] = m_str[i];
    }
    buff[len - 1] = '\0';
    *this = MyString{buff};
    delete[] buff;
}