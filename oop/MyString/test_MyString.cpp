#include "MyString.h"

using std::cout;
using std::endl;
int main()
{
    // Constructor with no arguments
    MyString a;

    // Convert string literal to
    // char array
    char temp[] = "Hello";

    // Constructor with one argument
    MyString b{temp};

    // Copy constructor
    MyString c{a};

    // One arg constructor called,
    // then the move constructor
    MyString d{MyString{temp}};

    // Remove last character from
    // MyString b
    b.pop_bk();

    // Print string b
    cout << "MyString b: " << b << endl;

    // Append last character from
    // MyString b
    b.push_bk('o');

    // Print string b
    cout << "MyString b: " << b << endl;

    // Print length of string b
    cout << "Length of MyString b: " << b << endl;

    char arr[80];

    // Copy string b chars from
    // length 0 to 3
    b.copy(arr, 3, 0);

    // Print string arr
    cout << "arr is: "
         << arr << endl;

    // Swap d and b
    d.swap(b);

    // Print d and b
    cout << d << " " << b << endl;

    // Concatenate b and b with overloading '+' operator
    d = b + b;

    // Print string d
    cout << "string d: " << d << endl;

    return 0;
}