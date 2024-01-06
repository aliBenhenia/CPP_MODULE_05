#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
ShrubberyCreationForm :: ShrubberyCreationForm():Form(get_target(), 145, 137)
{
    std::cout << "default constructor called " << std::endl;
}

ShrubberyCreationForm :: ShrubberyCreationForm(std::string target):Form(target, 145, 137)
{
    std::cout << "default constructor called " << std::endl;
}

ShrubberyCreationForm :: ShrubberyCreationForm(const ShrubberyCreationForm &obj):Form(obj)
{
    std::cout << "copy constructor called " << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator =(const ShrubberyCreationForm &obj)
{
   Form::operator=(obj);
   return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
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

ShrubberyCreationForm :: ~ShrubberyCreationForm()
{
    std :: cout << "destructor  called " << std::endl;
}
