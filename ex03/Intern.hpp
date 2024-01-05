#ifndef INTERN_HPP
#define INTERN_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        typedef struct my_form
        {
            std:: string name;
            Form *object;
        }t_my_form;
    public:
        Intern();
        Intern(const Intern &obj);
        Intern & operator =(const Intern &obj);
        Form* makeForm(const std::string& formName, const std::string& target);
        ~Intern();
};

#endif