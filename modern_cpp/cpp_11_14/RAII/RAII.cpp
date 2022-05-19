#include "Shape.h"

class shape_wrapper {
public:
    explicit shape_wrapper(
        Shape* ptr = nullptr) : ptr_{ptr} {}

    ~shape_wrapper() {
        delete ptr_;
    }

    Shape* get() const {
        return ptr_;
    }
private:
    Shape* ptr_;
};

void foo() {
    shape_wrapper ptr(create_shape(shape_type::Circle));
}

int main() {
    //In heap
    Shape* sp = create_shape(shape_type::Circle);
    delete sp;

    //RAII based on stack and dtor
    foo();
    return 0;
}
