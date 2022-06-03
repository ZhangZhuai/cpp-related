#include "../unique_pointer.hpp"
#include "../../RAII/Shape.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    unique_ptr<Shape> ptr1{create_shape(shape_type::Circle)};
    
    //Copy ctor should be explicitly declared with move ctor
    //unique_ptr<Shape> ptr2{ptr1};

    //Copy alignment should be explicitly declared with move alignment
    unique_ptr<Shape> ptr3{create_shape(shape_type::Triangle)};
    //ptr1 = ptr3;
    
    ptr3 = std::move(ptr1);
    unique_ptr<Shape> ptr4(std::move(ptr3));

    return 0;
}