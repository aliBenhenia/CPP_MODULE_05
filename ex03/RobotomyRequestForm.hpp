#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM
#include "Form.hpp"
#include <fstream>
class RobotomyRequestForm:public Form
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