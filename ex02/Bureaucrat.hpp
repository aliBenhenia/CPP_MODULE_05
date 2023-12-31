#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private :
          const std::string name;
          int grade;
    public :
        class GradeTooHighException:public std::exception
        {
            public :
                const char *what()const throw();
        };
        class GradeTooLowException:public std::exception
        {
            public :
                const char *what()const throw();
        };
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat & operator =(const Bureaucrat &obj);
        Bureaucrat(std::string name, int grade);
        std :: string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(AForm &obj);
        void executeForm(AForm const & form);
        ~Bureaucrat();
};
std:: ostream & operator<<(std:: ostream & os, const Bureaucrat &obj);
#endif