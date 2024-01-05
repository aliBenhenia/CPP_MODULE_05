#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{

    std::srand(std::time(0));

    Bureaucrat bureaucrat("John Doe", 10);
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("target");
    PresidentialPardonForm pardonForm("criminal");

    bureaucrat.signForm(shrubberyForm);
    bureaucrat.signForm(robotomyForm);
    bureaucrat.signForm(pardonForm);

    bureaucrat.executeForm(shrubberyForm);
    bureaucrat.executeForm(robotomyForm);
    bureaucrat.executeForm(pardonForm);
    return 0;
}
