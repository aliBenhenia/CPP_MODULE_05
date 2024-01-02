#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{  
    try 
    {
        Intern someRandomIntern;
        Form* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat obj("ali", 55);
        // rrf->execute(obj);
    }
    catch(const std::exception &e)
    {
        std::cout << "my expectation is : "<< e.what() << std::endl;
    }
    return 0;
}
