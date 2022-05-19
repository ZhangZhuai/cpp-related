#include <iostream>

using std::cout;
using std::endl;

class bar{};

void foo() {
    cout << "allocate memory in heap" << endl;
    bar* ptr = new bar();
    delete ptr;
}

bar* make_bar() {
    bar* ptr = nullptr;
    try {
        ptr = new bar();
    } catch (...) {
        delete ptr;
        throw;
    }
    return ptr;
}

void foo1() {
    cout << "allocate memory in stack" << endl;
    bar* ptr = make_bar();
    delete ptr;
}

int main() {
    foo();
    foo1();
    return 0;
}