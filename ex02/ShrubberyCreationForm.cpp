#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm :: ShrubberyCreationForm():AForm(get_target(), 145, 137)
{
     
}

ShrubberyCreationForm :: ShrubberyCreationForm(std::string target):AForm(target, 145, 137)
{
    
}

ShrubberyCreationForm :: ShrubberyCreationForm(const ShrubberyCreationForm &obj):AForm(obj)
{
     
}

ShrubberyCreationForm & ShrubberyCreationForm::operator =(const ShrubberyCreationForm &obj)
{
   (void)obj;
   return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
    if (get_is_signed() == false)
        throw FormNotSignedException();
    if(executor.getGrade() <= get_grade_to_execute())
    {
        std::ofstream out_file(get_target() + "_shrubbery");
        if (out_file.is_open())
        {
            out_file << "       || " << std::endl;
            out_file << "      |||| " << std::endl;
            out_file << "    |||||||||||" << std::endl;
            out_file << "   |||||||||||||" << std::endl;
            out_file << "  ||||||||||||||||" << std::endl;
            out_file << "||||||||||||||||||||" << std::endl;
            out_file.close();
        }
        else
            throw my_error();
    }
    else
        throw GradeTooHighException();
}

ShrubberyCreationForm :: ~ShrubberyCreationForm()
{
     
}
