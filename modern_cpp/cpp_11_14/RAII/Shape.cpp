#include "Shape.h"


Shape::Shape() { puts("Shape()"); }
Shape::~Shape() { puts("~Shape()"); }


Circle::Circle() { puts("Circle()"); }
Circle::~Circle() { puts("~Circle()"); }

Triangle::Triangle() { puts("Triangle()"); }
Triangle::~Triangle() { puts("~Triangle()"); }


//Return type if is Shape, will cause object slicing
Shape* create_shape(shape_type type) {
    Shape* tmp = nullptr;
    switch (type) {
    case shape_type::Circle:
        tmp = new Circle();
        break;
    case shape_type::Triangle:
        tmp = new Triangle();
        break;
    }
    return tmp;
}
