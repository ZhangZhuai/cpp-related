#include "RingBuffer.hpp"
#include <iostream>

int main()
{
    Ring_buffer<uint32_t> circular(3);
    std::cout << circular.getCapacity() << " " << circular.getSize() << " " << circular.empty() << " " << circular.full() << std::endl;
    uint32_t x = 10;
    for (int i = 0; i < 3; ++i)
    {
        circular.enqueue(x + i * 10);
        std::cout << circular.getCapacity() << " " << circular.getSize() << " " << circular.empty() << " " << circular.full() << std::endl;
    }
    auto res = circular.dequeue();
    std::cout << circular.getCapacity() << " " << circular.getSize() << " " << circular.empty() << " " << circular.full() << std::endl;
    if (res)
    {
        std::cout << (*res) << std::endl;
    }
    for (int i = 0; i < 3; ++i)
    {
        circular.enqueue(x + (i + 1) * 20);
        std::cout << circular.getCapacity() << " " << circular.getSize() << " " << circular.empty() << " " << circular.full() << std::endl;
    }
    for (int i = 0 ; i < 3; ++i) {
        std::cout << *circular.dequeue() << std::endl;
    }
    return 0;
}
