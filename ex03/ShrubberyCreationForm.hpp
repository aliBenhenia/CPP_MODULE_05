#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>
class ShrubberyCreationForm:public Form
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm & operator =(const ShrubberyCreationForm &obj);
        void execute(Bureaucrat const & executor)const;
        ~ShrubberyCreationForm();
};
#endif