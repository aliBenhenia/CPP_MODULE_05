#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat()
{
    // std ::  cout << "default constructor called " << std::endl;
}

Bureaucrat ::  Bureaucrat(const Bureaucrat &obj):name(obj.name)
{
    this->grade = obj.grade;
    // std ::  cout << "copy constructor called " << std::endl;
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
    // std ::  cout << "copy assignement constructor called " << std::endl;
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

void Bureaucrat::signForm(AForm &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << name << " signed " << obj.getName() << std::endl;
    }
    catch(const AForm :: GradeTooLowException &e)
    {
        std::cout << name << "CA signed " << obj.getName() << " becuase " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try 
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.get_target() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << getName() << " cannot execute the form. Reason: " << e.what() << std::endl;
    }
}

Bureaucrat :: ~Bureaucrat()
{
    // std ::  cout << "destructor called " << std::endl;
}
