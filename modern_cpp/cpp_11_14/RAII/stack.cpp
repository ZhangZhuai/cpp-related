#include <iostream>

using std::cout;
using std::endl;

class Obj {
public:
    Obj() { puts("Obj()"); };
    ~Obj() { puts("~Obj()"); };
};

void foo(int n) {
    Obj obj;
    if (n == 1) 
        throw "err"; 
}

int main() {
    try {
        foo(0);
        foo(1);
    } catch(const char* s) {
        puts(s);
    }
    return 0;
}