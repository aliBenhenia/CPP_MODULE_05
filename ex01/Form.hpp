#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
 
class Bureaucrat;
class Form
{
    private :
        const std:: string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        class GradeTooHighException:public std::exception
        {
            public:
                const char *what()const throw();
        };
        class GradeTooLowException:public std::exception
        {
            public :
                const char *what()const throw();
        };
        Form(); 
        Form(const Form &obj);
        Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
        Form & operator =(const Form &obj);
 
        const std::string getName()const;
        bool isSigned()const;
        int get_grade_to_sign()const;
        int get_grade_to_execute()const;
        void beSigned(const Bureaucrat &obj);
        ~Form();
};
std:: ostream & operator<<(std:: ostream & os, const Form &obj);

#endif