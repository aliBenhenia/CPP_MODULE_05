#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
RobotomyRequestForm :: RobotomyRequestForm():Form(get_target(), 72, 45)
{
     
}
RobotomyRequestForm :: RobotomyRequestForm(std::string target):Form(target, 72, 45)
{
    
}
RobotomyRequestForm :: RobotomyRequestForm(const RobotomyRequestForm &obj):Form(obj)
{
    
}
RobotomyRequestForm & RobotomyRequestForm::operator =(const RobotomyRequestForm &obj)
{
   Form::operator=(obj);
   return (*this);
}
void RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
    std::srand(std::time(0));
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
    
}