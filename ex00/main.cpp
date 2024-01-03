#include "Bureaucrat.hpp"


int main()
{
   try 
   {
        // Bureaucrat b1("ali", 55);
        // std :: cout << b1<< std::endl;
        // b1.increment();
        // b1.increment();
        // b1.increment();
        // b1.increment();
        // b1.increment();
        // std :: cout << b1 << std::endl;
        // b1.decrement();
        // b1.decrement();
        // b1.decrement();
        // b1.decrement(); 
        // b1.decrement();
        // std :: cout << b1 << std::endl;

        Bureaucrat t1("aa", 3);
        t1.increment();
        std::cout << t1.getGrade()<< std::endl;
       
   }
   catch(const std::exception& e)
   {
     std::cout << e.what() << std::endl;
   }
    return 0;
}
