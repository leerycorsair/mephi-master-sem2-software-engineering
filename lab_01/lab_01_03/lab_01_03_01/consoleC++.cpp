#include <iostream>
auto Factory()
{
    int count = 0;
    auto ff = [count]() mutable
    {
        return count++;
    };
    return ff;
}
int main()
{
    auto Counter1 = Factory();
    std::cout << Counter1() << std::endl;
    std::cout << Counter1() << std::endl;
    auto Counter2 = Factory();
    std::cout << Counter2() << std::endl;
    std::cout << Counter2() << std::endl;
    std::cout << Counter2() << std::endl;
    system("pause");
}
