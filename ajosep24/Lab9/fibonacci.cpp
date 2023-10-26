#include <iostream>

int fibonacci(int first, int second, int term, int iterations)
{
    if (term >= iterations)
    {
        std::cout << first;
        return 0;
    }
    else
    {
        std::cout << first << ", ";
    }
    return fibonacci(second, first + second, ++term, iterations);
}

int main()
{
    std::cout << "Input number for fibonnaci sequence term: ";
    int input;
    std::cin >> input;
    fibonacci(0, 1, 1, input);
    return 0;
}