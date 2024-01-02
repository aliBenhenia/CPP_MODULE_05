#include <iostream>
#include <stdexcept>
#include <string>

class Form {
public:
    Form(const std::string& name, const std::string& target) : name(name), target(target) {}

    virtual ~Form() {}

    virtual void execute() const = 0;

private:
    std::string name;
    std::string target;
};

class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm(const std::string& target) : Form("shrubbery creation", target) {}

    void execute() const override {
        // Implementation for ShrubberyCreationForm execution
        std::cout << "ShrubberyCreationForm executed on target: " << target << std::endl;
    }
};

class RobotomyRequestForm : public Form {
public:
    RobotomyRequestForm(const std::string& target) : Form("robotomy request", target) {}

    void execute() const override {
        // Implementation for RobotomyRequestForm execution
        std::cout << "RobotomyRequestForm executed on target: " << target << std::endl;
    }
};

class PresidentialPardonForm : public Form {
public:
    PresidentialPardonForm(const std::string& target) : Form("presidential pardon", target) {}

    void execute() const override {
        // Implementation for PresidentialPardonForm execution
        std::cout << "PresidentialPardonForm executed on target: " << target << std::endl;
    }
};

class Intern 
{
    public:
        Form* makeForm(const std::string& formName, const std::string& target) {
        Form* form = nullptr;

            if (formName == "shrubbery creation") {
                form = new ShrubberyCreationForm(target);
            } else if (formName == "robotomy request") {
                form = new RobotomyRequestForm(target);
            } else if (formName == "presidential pardon") {
                form = new PresidentialPardonForm(target);
            } else {
                std::cerr << "Error: Unknown form name '" << formName << "'" << std::endl;
            }

            if (form) {
                std::cout << "Intern creates " << formName << std::endl;
            }

        return form;
    }
};

int main() {
    Intern someRandomIntern;
    Form* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    // Use the created form
    if (rrf) {
        rrf->execute();
        delete rrf;  // Remember to delete the dynamically allocated object
    }

    return 0;
}
