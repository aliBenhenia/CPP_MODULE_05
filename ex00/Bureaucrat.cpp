#include "Bureaucrat.hpp"

Bureaucrat :: Bureaucrat()
{
    std ::  cout << "default constructor called " << std::endl;
}
Bureaucrat ::  Bureaucrat(const Bureaucrat &obj)
{
    this->grade = obj.grade;
    this->name = obj.name;
    std ::  cout << "copy constructor called " << std::endl;
}
Bureaucrat ::  Bureaucrat(std::string name, int grade)
{
    this->grade = grade;
    this->name =  name;
}
Bureaucrat &Bureaucrat :: operator =(const Bureaucrat &obj)
{
    this->grade = obj.grade;
    this->name = obj.name;
    std ::  cout << "copy assignement constructor called " << std::endl;
    return (*this);
}
Bureaucrat :: ~Bureaucrat()
{
    std ::  cout << "destructor called " << std::endl;
}