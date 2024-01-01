#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm:public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm & operator =(const ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();


};
#endif