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
   AForm::operator=(obj);
   return (*this);
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
    
}
ShrubberyCreationForm :: ~ShrubberyCreationForm()
{
    std ::  cout << "destructor constructor called " << std::endl;
}