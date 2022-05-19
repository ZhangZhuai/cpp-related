#ifndef __SHAPE_H
#define __SHAPE_H

#include <string>

enum class shape_type {
    Circle,
    Triangle,
};


class Shape {
public:
    Shape();
    ~Shape();
};

class Circle : public Shape {
public:
    Circle();
    ~Circle();
};

class Triangle : public Shape {
public:
    Triangle();
    ~Triangle();
};

//Return type if is Shape, will cause object slicing
Shape* create_shape(shape_type type);
#endif