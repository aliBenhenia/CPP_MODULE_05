#ifndef  AFORM_HPP
#define  AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
 
class Bureaucrat;
class AForm
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
        AForm(); 
        AForm(const AForm &obj);
        AForm(const std:: string name, const int grade_to_sign, const int grade_to_execute);
        virtual void execute(Bureaucrat const & executor) const = 0; 
        //getters
        const std::string getName();
        bool isSigned();
        int get_grade_to_sign();
        int get_grade_to_execute();
        void beSigned(const Bureaucrat obj); 
        ~AForm();
};

#endif