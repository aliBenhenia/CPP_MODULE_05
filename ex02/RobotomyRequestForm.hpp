#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM
#include "AForm.hpp"
#include <fstream>
class RobotomyRequestForm:public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm & operator =(const RobotomyRequestForm &obj);
        void execute(Bureaucrat const & executor)const;
        ~RobotomyRequestForm();
};
#endif