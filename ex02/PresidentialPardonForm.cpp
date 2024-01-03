#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
PresidentialPardonForm :: PresidentialPardonForm():AForm(get_target(), 25, 5)
{
    std::cout << "default constructor called " << std::endl;
}
PresidentialPardonForm :: PresidentialPardonForm(std::string target):AForm(target, 25, 5)
{
    
}
PresidentialPardonForm :: PresidentialPardonForm(const PresidentialPardonForm &obj):AForm(obj)
{
    std::cout << "copy constructor called " << std::endl;
}
PresidentialPardonForm & PresidentialPardonForm::operator =(const PresidentialPardonForm &obj)
{
   (void)obj;
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