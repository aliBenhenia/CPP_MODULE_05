#include "Intern.hpp"

Intern :: Intern()
{
    std::cout << "default constructor (Intern)" << std::endl;
}

Intern :: Intern(const Intern &obj)
{
    std::cout << "copy constructor (Intern)" << std::endl;
}
Intern &Intern:: operator=(const Intern &obj)
{
    std::cout << "assignement operator (Intern)" << std::endl;
    return (*this);
}
Form  *Intern::makeForm(const std::string& formName, const std::string& target)
{
    Form *form_ = NULL;
    if (!formName.compare("shrubbery creation"))
        form_ = new ShrubberyCreationForm(target);
    else if (!formName.compare("robotomy request"))
        form_ = new RobotomyRequestForm(target);
    else if (!formName.compare("presidential pardon"))
        form_ = new PresidentialPardonForm(target);
    else
        std::cout << "Error: Unknown form name : " << formName  << std::endl;
    if (form_)
        std::cout << "Intern creates " << formName << std::endl;
    return (form_);
}
Intern :: ~Intern()
{
    std::cout << "destructor (Intern)" << std::endl;
}
