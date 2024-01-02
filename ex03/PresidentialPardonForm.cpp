#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
PresidentialPardonForm :: PresidentialPardonForm():Form(get_target(), 25, 5)
{
    std::cout << "default constructor called " << std::endl;
}
PresidentialPardonForm :: PresidentialPardonForm(std::string target):Form(target, 25, 5)
{
    
}
PresidentialPardonForm :: PresidentialPardonForm(const PresidentialPardonForm &obj):Form(obj)
{
    std::cout << "copy constructor called " << std::endl;
}
PresidentialPardonForm & PresidentialPardonForm::operator =(const PresidentialPardonForm &obj)
{
   Form::operator=(obj);
   return (*this);
}
void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
    if (get_is_signed() == 0)
        throw FormNotSignedException();
    if(executor.getGrade() <= get_grade_to_execute())
        std::cout << get_target() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    else
        throw GradeTooLowException();
}
PresidentialPardonForm :: ~PresidentialPardonForm()
{
    std :: cout << "destructor constructor called " << std::endl;
}