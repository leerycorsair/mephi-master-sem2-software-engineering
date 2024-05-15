#include <iostream>

auto Factory()
{
    static int instanceCount = 0;
    int count = instanceCount;
    instanceCount++;
    auto ff = [count]() mutable
    {
        return count++;
    };
    return ff;
}

int main()
{
    auto Counter1 = Factory();
    std::cout << Counter1() << std::endl; // 0
    std::cout << Counter1() << std::endl; // 1

    auto Counter2 = Factory();
    std::cout << Counter2() << std::endl; // 1
    std::cout << Counter2() << std::endl; // 2
    std::cout << Counter2() << std::endl; // 3

    auto Counter3 = Factory();
    std::cout << Counter3() << std::endl; // 2
    std::cout << Counter3() << std::endl; // 3

    system("pause");
}
