#include "scoped_pointer.h"
#include "../RAII/Shape.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    scoped_ptr<Shape> ptr1{create_shape(shape_type::Circle)};
    //scoped_ptr<Shape> ptr2{ptr1};
    //can not copy construct and align!!

    return 0;
}