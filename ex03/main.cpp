#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern ob1;
	Intern ob2;
	Intern ob3;
	Intern ob4;
	Intern ob5;
	Intern ob6;	

	Form *t1 = ob1.makeForm("shrubbery creation", "julia"); 

	Form *t2 = ob2.makeForm("robotomy request", "mary");

	Form *t3 = ob3.makeForm("presidential pardon", "alexa");

	Form *t4 = ob4.makeForm("presidential pardon111", "alexa");

	Form *t5 = ob5.makeForm(".......", "alexa2");

	Form *t6 = ob6.makeForm("//", "");
	
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
	return 0;
}
