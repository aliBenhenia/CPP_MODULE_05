#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat obj("wd", 889);
    Bureaucrat obj1;
    Bureaucrat obj2 = obj;
    Bureaucrat obj3(obj2);
    return 0;
}
