#include "Bureaucrat.hpp"


Bureaucrat :: Bureaucrat()
{
     
}

Bureaucrat ::  Bureaucrat(const Bureaucrat &obj):name(obj.name)
{
    this->grade = obj.grade;
     
}
Bureaucrat ::  Bureaucrat(std::string name, int grade):name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}
Bureaucrat &Bureaucrat :: operator =(const Bureaucrat &obj)
{
    this->grade = obj.grade;
     
    return (*this);
}
 
const char *Bureaucrat::GradeTooHighException:: what() const throw()
{
    return ("Grade is too High");
}
const char *Bureaucrat::GradeTooLowException:: what() const throw()
{
    return ("Grade is low ");
}

std :: string Bureaucrat :: getName() const
{
    return (name);
}
int Bureaucrat :: getGrade() const
{
    return (grade);
} 

void Bureaucrat :: increment()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat :: decrement()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade--;
}

std:: ostream & operator<<(std:: ostream & os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (os);
}
void Bureaucrat::signForm(Form &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << name << " signed " << obj.getName() << std::endl;
    }
    catch(const Form :: GradeTooLowException &e)
    {
        std::cout << name << "CA signed " << obj.getName() << " becuase " << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(Form const & form)
{
    try 
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.get_target() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << getName() << " cannot execute the form. Reason: " << e.what() << std::endl;
    }
}

Bureaucrat :: ~Bureaucrat()
{
     
}