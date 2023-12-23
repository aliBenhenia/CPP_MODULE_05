#include "Bureaucrat.hpp"


int main()
{
   try
   {
        Bureaucrat b1("ali", 55);
        std :: cout << b1.getGrade() << std::endl;
        

        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        std :: cout << b1.getGrade() << std::endl;
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        std :: cout << b1.getGrade() << std::endl;


        Bureaucrat b2("nor", 44334);
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
    return 0;
}
