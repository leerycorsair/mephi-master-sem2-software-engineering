#include <iostream>

auto Factory(int initialValue)
{
    int count = initialValue;
    auto ff = [count]() mutable
    {
        return count++;
    };
    return ff;
}

int main()
{
    auto Counter1 = Factory(0);
    std::cout << Counter1() << std::endl; // 0
    std::cout << Counter1() << std::endl; // 1
    auto Counter2 = Factory(10);
    std::cout << Counter2() << std::endl; // 10
    std::cout << Counter2() << std::endl; // 11
    std::cout << Counter2() << std::endl; // 12
    auto Counter3 = Factory(-5);
    std::cout << Counter3() << std::endl; // -5
    std::cout << Counter3() << std::endl; // -4
    system("pause");
}
