#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


void dd()
{
    system("leaks fixed");
}

int main()
{
    Intern ob1;
    Intern ob2;
    Intern ob3;
    Intern ob4;

    Form *t1 = ob1.makeForm("shrubbery creation", "julia");
    Form *t2 = ob2.makeForm("robotomy request", "mary");
    Form *t3 = ob3.makeForm("presidential pardon", "alexa");
    Form *t4 = ob4.makeForm("presidential ffff", "alexa");
    delete t1;
    delete t2;
    delete t3;
    delete t4;

    return 0;
}
