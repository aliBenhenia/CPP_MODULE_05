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

Form  *Intern::makeForm(std::string formName, const std::string target)
{
    Form *form_ = NULL;
    int i = 0;
    t_my_form data[3] = {
        {"shrubbery creation",new ShrubberyCreationForm(target)},
        {"robotomy request",new RobotomyRequestForm(target)},
        {"presidential pardon",new PresidentialPardonForm(target)},
    };
    while (i < 3)
    {
        if (data[i].name == formName)
            form_ = data[i].object;
        else
            delete data[i].object;
        i++;
    }
    if (form_ != NULL)
        std::cout << "Intern creates " << formName << std::endl;
    else
        std::cout << "Error: Unknown form name : " << formName  << std::endl;
    return (form_);
}

Intern :: ~Intern()
{
    std::cout << "destructor (Intern)" << std::endl;
}
