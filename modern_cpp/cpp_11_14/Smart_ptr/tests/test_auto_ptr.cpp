// template lining error
#include "../auto_pointer.cpp"

#include "../../RAII/Shape.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    auto_ptr<Shape> ptr1{create_shape(shape_type::Circle)};
    
    //Copy ctor
    auto_ptr<Shape> ptr2{ptr1};
    bool tag1 = !ptr1 && ptr2;
    if (tag1) 
        cout << "Copy ctor:ptr2 gets ptr1's ownship" << endl;

    //Copy alignment
    auto_ptr<Shape> ptr3{create_shape(shape_type::Triangle)};
    ptr1 = ptr3;
    bool tag2 = !ptr3 && ptr1;
    if (tag2)
        cout << "Copy alignment:ptr1 gets ptr3's ownship" << endl;
    return 0;
}