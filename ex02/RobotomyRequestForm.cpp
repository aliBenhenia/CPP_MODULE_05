#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
RobotomyRequestForm :: RobotomyRequestForm():AForm(get_target(), 72, 45)
{
    std::cout << "default constructor called " << std::endl;
}
RobotomyRequestForm :: RobotomyRequestForm(const RobotomyRequestForm &obj):AForm(obj)
{
    std::cout << "copy constructor called " << std::endl;
}
RobotomyRequestForm & RobotomyRequestForm::operator =(const RobotomyRequestForm &obj)
{
   AForm::operator=(obj);
   return (*this);
}
void RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
    if (get_is_signed() == 0)
        throw FormNotSignedException();
    if(executor.getGrade() <= get_grade_to_execute())
    {
        std::cout << "Drilling noises..." << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << get_target() << " has been robotomized successfully!" << std::endl;
        else
            std::cout << "Robotomy failed for " << get_target() << "." << std::endl;
    }
    else
        throw GradeTooLowException();
}
RobotomyRequestForm :: ~RobotomyRequestForm()
{
    std :: cout << "destructor constructor called " << std::endl;
}