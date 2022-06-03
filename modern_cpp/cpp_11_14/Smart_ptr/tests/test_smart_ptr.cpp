#include "../smart_pointer.hpp"

#include <string>
#include <iostream>

using std::string, std::cout, std::endl;

int main()
{
    Smart_pointer<string> myPtr(new string);
    *myPtr = "This is a string";
    cout << *myPtr << endl;

    Smart_pointer<string> other(myPtr);
    cout << *other << endl;
    cout << other.get()->length() << endl;
    cout << "Shared cout is " << other.getSharedCount() << " " << myPtr.getSharedCount() << endl;

    myPtr.reset(new string{"hello"});
    cout << "myPtr Shared cout is " << myPtr.getSharedCount() << endl;
    cout << "other Shared cout is " << other.getSharedCount() << endl;
    cout << "myPtr: " << *myPtr << endl;
    cout << "other: " << *other << endl;
    return 0;
}