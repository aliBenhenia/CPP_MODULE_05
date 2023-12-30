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
            public :
                const char *what()const throw();
        };
        class GradeTooLowException:public std::exception
        {
            public :
                const char *what()const throw();
        };
        Form(); 
        Form(const Form &obj);
        Form(const std:: string name,  bool is_signed, const int grade_to_sign, const int grade_to_execute);
        //getters
        const std::string getName();
        bool isSigned();
        int get_grade_to_sign();
        int get_grade_to_execute();
        void beSigned(const Bureaucrat obj); 
        ~Form();
};

#endif