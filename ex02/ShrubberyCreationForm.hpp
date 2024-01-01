#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm:public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm & operator =(const ShrubberyCreationForm &obj);
        void execute(Bureaucrat const & executor)const;
        ~ShrubberyCreationForm();
};
#endif