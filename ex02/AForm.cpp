#include "AForm.hpp"

AForm :: AForm():target("none"),grade_to_execute(0),grade_to_sign(0)
{
     std ::  cout << "default constructor called" << std::endl;
}

AForm :: AForm(const AForm &obj):target("none"),grade_to_execute(0),grade_to_sign(0)
{
     std ::  cout << "copy constructor called" << std::endl;
}
AForm ::  AForm(const std:: string target, const int grade_to_sign, const int grade_to_execute):target(target),grade_to_execute(grade_to_execute),grade_to_sign(grade_to_sign)
{
     if (grade_to_execute < 1 || grade_to_sign < 1)
          throw GradeTooHighException();
     if (grade_to_execute > 150 || grade_to_sign > 150)
          throw GradeTooLowException();
     std ::  cout << "parameter constructor called" << std::endl;
}

// member function 
const char *AForm::GradeTooHighException:: what() const throw()
{
    return ("Grade is too High for the Aform");
}
const char *AForm::GradeTooLowException:: what() const throw()
{
    return ("Grade is low High for the Aform");
}
const char *AForm::my_error:: what() const throw()
{
    return ("Unable to create a file!");
}
// getters
const std::string AForm :: getName()
{
     return (target);
}
bool AForm :: isSigned()
{
     return (is_signed);
}
int AForm :: get_grade_to_sign()const
{
     return (grade_to_sign);
}
int AForm :: get_grade_to_execute()const
{
     return (grade_to_execute);
}
void AForm :: beSigned(const Bureaucrat obj) 
{
     if (obj.getGrade() <= grade_to_sign)
          is_signed = true;
     else
          throw GradeTooLowException();
}
AForm& AForm::operator=(const AForm& other)
{
     this->is_signed = other.is_signed;
     return(*this);
}
bool AForm::get_is_signed()const
{
     return (is_signed);
}
const std::string AForm::get_target()const
{
     return(target);
}
AForm :: ~AForm()
{
     std ::  cout << "destructor called" << std::endl;
}