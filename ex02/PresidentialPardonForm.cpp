#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
PresidentialPardonForm :: PresidentialPardonForm()
{
    std::cout << "default constructor called " << std::endl;
}
PresidentialPardonForm :: PresidentialPardonForm(const PresidentialPardonForm &obj):AForm(obj)
{
    std::cout << "copy constructor called " << std::endl;
}
PresidentialPardonForm & PresidentialPardonForm::operator =(const PresidentialPardonForm &obj)
{
   AForm::operator=(obj);
   return (*this);
}
void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
    if (get_is_signed() == 0)
        throw FormNotSignedException();
    if(executor.getGrade() <= get_grade_to_execute())
    {
        std::ofstream out_file(get_target() + "_shrubbery");
        if (out_file.is_open())
        {
            out_file << "ASCII trees go here." << std::endl;
            out_file.close();
        }
        else
            throw my_error();
    }
    else
        throw GradeTooHighException();
}
PresidentialPardonForm :: ~PresidentialPardonForm()
{
    std :: cout << "destructor constructor called " << std::endl;
}