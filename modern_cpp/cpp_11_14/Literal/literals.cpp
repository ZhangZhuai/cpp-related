#include <iostream>
#include <complex>
#include <string>
//-std=c++17

using namespace std::literals::complex_literals;
using namespace std::literals::string_literals;
using std::cout;
using std::endl;

struct length {
    double value;
    enum unit {
        metre,
        kilometre,
        contimetre,
    };
    static constexpr double factors[3] = {1.0, 1000.0, 1e-3};

    explicit length(double v, unit u = metre) {
        value = v * factors[u];
    }
};

length operator+(const length& lhs, const length& rhs) {
    return length(lhs.value + rhs.value);
}

//User defined literals
length operator"" _m(long double v) {
    return length(v, length::metre);
}

length operator"" _km(long double v) {
    return length(v, length::kilometre);
}


int main() {
    cout << "Complex i * i = " << 1i * 1i << endl;
    cout << "Hello world"s.substr(0, 5) << endl;
    length l1 = 1.0_m + 1.1_km;
    cout << l1.value << endl;
    return 0;
}