#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{  
    try 
    {
        Intern ob1;
        Intern ob2;
        Intern ob3;
        Intern ob4;

        Form *t1 = ob1.makeForm("shrubbery creation", "julia");
        Form *t2 = ob2.makeForm("robotomy request", "mary");
        Form *t3 = ob3.makeForm("presidential pardon", "alexa");
        Form *t4 = ob4.makeForm("presidential gg", "alexa");
    }
    catch(const std::exception &e)
    {
        std::cout << "my expectation is : "<< e.what() << std::endl;
    }
    return 0;
}
