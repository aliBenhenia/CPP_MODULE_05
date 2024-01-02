#include "Form.hpp"

Form :: Form():name("none"),grade_to_execute(0),grade_to_sign(0)
{
     std ::  cout << "default constructor called" << std::endl;
}

Form :: Form(const Form &obj):name(obj.name),grade_to_execute(obj.grade_to_execute),grade_to_sign(obj.grade_to_sign)
{
     std ::  cout << "copy constructor called" << std::endl;
}
Form ::  Form(const std:: string name, const int grade_to_sign, const int grade_to_execute):name(name),grade_to_execute(grade_to_execute),grade_to_sign(grade_to_sign)
{
     if (grade_to_execute < 1 || grade_to_sign < 1)
          throw GradeTooHighException();
     if (grade_to_execute > 150 || grade_to_sign > 150)
          throw GradeTooLowException();
     std ::  cout << "parameter constructor called" << std::endl;
}
// member function 
const char *Form::GradeTooHighException:: what() const throw()
{
    return ("Grade is too High for the form");
}
const char *Form::GradeTooLowException:: what() const throw()
{
    return ("Grade is low High for the form");
}
// getters
const std::string Form :: getName()
{
     return (name);
}
bool Form :: isSigned()
{
     return (is_signed);
}
int Form :: get_grade_to_sign()
{
     return (grade_to_sign);
}
int Form :: get_grade_to_execute()
{
     return (grade_to_execute);
}
void Form :: beSigned(const Bureaucrat obj) 
{
     if (obj.getGrade() <= grade_to_sign)
          is_signed = true;
     else
          throw GradeTooLowException();
}

Form :: ~Form()
{
     std ::  cout << "destructor called" << std::endl;
}