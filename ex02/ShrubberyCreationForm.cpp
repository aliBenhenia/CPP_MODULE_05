#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
ShrubberyCreationForm :: ShrubberyCreationForm()
{
    std ::  cout << "default constructor called " << std::endl;
}
ShrubberyCreationForm :: ShrubberyCreationForm(const ShrubberyCreationForm &obj):AForm(obj)
{
    std ::  cout << "copy constructor called " << std::endl;
}
ShrubberyCreationForm & ShrubberyCreationForm::operator =(const ShrubberyCreationForm &obj)
{
   
}