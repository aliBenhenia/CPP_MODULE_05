#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    try
    {
        Bureaucrat bureaucrat("John ", 11);
        ShrubberyCreationForm shrubberyForm("julia");
        RobotomyRequestForm robotomyForm("emrah");
        PresidentialPardonForm pardonForm("burak");

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.signForm(robotomyForm);
        bureaucrat.signForm(pardonForm);

        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
