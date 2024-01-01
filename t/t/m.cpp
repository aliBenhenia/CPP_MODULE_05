#include<iostream>
#include <stdexcept>
#include <cstdlib>



int main()
{
    std::srand(std::time(0));
     std::cout << std::rand() % 1122 << std::endl;
    return 0;
}
