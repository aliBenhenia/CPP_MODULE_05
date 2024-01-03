#include "Form.hpp"

Form :: Form():name("default"),grade_to_execute(1),grade_to_sign(1),is_signed(false)
{
     std ::  cout << "default constructor called" << std::endl;
}
Form :: Form(const Form &obj):name(obj.name),grade_to_execute(obj.grade_to_execute),grade_to_sign(obj.grade_to_sign),is_signed(obj.is_signed)
{
     std ::  cout << "copy constructor called" << std::endl;
}

Form ::  Form(const std:: string name, const int grade_to_sign, const int grade_to_execute):name(name),grade_to_execute(grade_to_execute),grade_to_sign(grade_to_sign),is_signed(false)
{
     if (grade_to_execute < 1 || grade_to_sign < 1)
          throw GradeTooHighException();
     if (grade_to_execute > 150 || grade_to_sign > 150)
          throw GradeTooLowException();
     std ::  cout << "parameter constructor called" << std::endl;
}

Form &Form :: operator =(const Form &obj)
{
    this->is_signed = obj.is_signed;
    std::cout << " assignement constructor called" << std::endl;
    return (*this);
}

const char *Form::GradeTooHighException:: what() const throw()
{
    return ("Grade is too High for the form");
}

const char *Form::GradeTooLowException:: what() const throw()
{
    return ("Grade is too low for the form");
}
// getters
const std::string Form :: getName()const
{
     return (name);
}

bool Form :: isSigned()const
{
     return (is_signed);
}

int Form :: get_grade_to_sign()const
{
     return (grade_to_sign);
}

int Form :: get_grade_to_execute()const
{
     return (grade_to_execute);
}

void Form :: beSigned(const Bureaucrat &obj) 
{
     if (obj.getGrade() <= grade_to_sign)
          is_signed = true;
     else
          throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form: " << form.getName()
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.get_grade_to_sign()
       << ", Execute Grade: " << form.get_grade_to_execute();
    return os;
}

Form :: ~Form()
{
     std ::  cout << "destructor called" << std::endl;
}