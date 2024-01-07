#include "Form.hpp"

Form :: Form():target("none"),grade_to_sign(0),grade_to_execute(0)
{
      
}

Form :: Form(const Form &obj):target(obj.target),grade_to_sign(obj.grade_to_sign),grade_to_execute(obj.grade_to_execute)
{
    
}
Form ::  Form(const std:: string target, const int grade_to_sign, const int grade_to_execute):target(target),grade_to_sign(grade_to_sign),grade_to_execute(grade_to_execute)
{
     if (grade_to_execute < 1 || grade_to_sign < 1)
          throw GradeTooHighException();
     if (grade_to_execute > 150 || grade_to_sign > 150)
          throw GradeTooLowException();
     
}


const char *Form::GradeTooHighException:: what() const throw()
{
    return ("Grade is too High for the form");
}
const char *Form::GradeTooLowException:: what() const throw()
{
    return ("Grade is low High for the form");
}
const char *Form::my_error:: what() const throw()
{
    return ("Unable to create a file!");
}

const std::string Form :: getName()
{
     return (target);
}
bool Form :: isSigned()
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
void Form :: beSigned(const Bureaucrat obj) 
{
     if (obj.getGrade() <= grade_to_sign)
          is_signed = true;
     else
          throw GradeTooLowException();
}
Form& Form::operator=(const Form& other)
{
     this->is_signed = other.is_signed;
     return(*this);
}

bool Form::get_is_signed()const
{
     return (is_signed);
}

const std::string Form::get_target()const
{
     return(target);
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form: " << form.get_target()
       << ", Signed: " << (form.get_is_signed() ? "Yes" : "No")
       << ", Sign Grade: " << form.get_grade_to_sign()
       << ", Execute Grade: " << form.get_grade_to_execute();
    return os;
}
Form :: ~Form()
{
     
}