#include "Intern.hpp"

Intern :: Intern()
{
     
}

Intern :: Intern(const Intern &obj)
{
    (void)obj;
     
}

Intern &Intern:: operator=(const Intern &obj)
{
    (void)obj;
    
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
     
}
