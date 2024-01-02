#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat()
{
    std ::  cout << "default constructor called " << std::endl;
}
Bureaucrat ::  Bureaucrat(const Bureaucrat &obj):name(obj.name)
{
    this->grade = obj.grade;
    std ::  cout << "copy constructor called " << std::endl;
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
    Bureaucrat ob(obj.name, obj.grade);
    this->grade = obj.grade;
    std ::  cout << "copy assignement constructor called " << std::endl;
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

Bureaucrat :: ~Bureaucrat()
{
    std ::  cout << "destructor called " << std::endl;
}