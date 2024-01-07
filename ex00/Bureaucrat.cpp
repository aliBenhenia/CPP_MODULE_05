#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat()
{
    
}

Bureaucrat ::  Bureaucrat(const Bureaucrat &obj):name(obj.name)
{
    this->grade = obj.grade;
     
}

Bureaucrat::Bureaucrat(std::string name, int grade_):name(name)
{
    if (grade_ < 1)
        throw GradeTooHighException();
    else if (grade_ > 150)
        throw GradeTooLowException();
    this->grade = grade_;
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
    return ("Grade is too low ");
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
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat :: decrement()
{
    if (grade  >= 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream & operator<<(std:: ostream & os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (os);
}

Bureaucrat :: ~Bureaucrat()
{
     
}