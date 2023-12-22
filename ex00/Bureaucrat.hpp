#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
class Bureaucrat
{
    private :
        std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat & operator =(const Bureaucrat &obj);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
};
#endif