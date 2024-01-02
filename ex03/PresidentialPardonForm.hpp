#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM
#include "Form.hpp"
#include <fstream>
class PresidentialPardonForm:public Form
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm & operator =(const PresidentialPardonForm &obj);
        void execute(Bureaucrat const & executor)const;
        ~PresidentialPardonForm();
};
#endif