#include "Bureaucrat.hpp"


int main()
{
   try 
   {
        Bureaucrat b1("ali", 55);
        std :: cout << b1 << std::endl;
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        b1.increment();
        std :: cout << b1 << std::endl;
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement(); 
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        b1.decrement();
        std :: cout << b1 << std::endl;

        Bureaucrat t1("julia", 3);
        t1.increment();
        std::cout <<"the grade of : "<< t1.getName() << " is : " <<  t1.getGrade()<< std::endl;


        Bureaucrat t2("julia", 3233);
        t2.increment();
        std::cout <<"the grade of : "<< t2.getName() << " is : " <<  t2.getGrade()<< std::endl;
   }
   catch(const std::exception& e)
   {
        std::cout << e.what() << std::endl;
   }
    return (0);
}
