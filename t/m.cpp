#include <iostream>
#include <fstream>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding rand() function

class Bureaucrat;

class AForm {
private:
    std::string target;
    bool signedStatus;
    const int signGrade;
    const int execGrade;

public:
    AForm(std::string target, int signGrade, int execGrade)
        : target(target), signedStatus(false), signGrade(signGrade), execGrade(execGrade) {}

    virtual ~AForm() {}

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;

    // Getters
    std::string getTarget() const { return target; }
    bool isSigned() const { return signedStatus; }
    int getSignGrade() const { return signGrade; }
    int getExecGrade() const { return execGrade; }
};

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(std::string target)
        : AForm(target, 145, 137) {}

    void execute(const Bureaucrat& executor) const override;
};

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(std::string target)
        : AForm(target, 72, 45) {}

    void execute(const Bureaucrat& executor) const override;
};

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(std::string target)
        : AForm(target, 25, 5) {}

    void execute(const Bureaucrat& executor) const override;
};

class Bureaucrat {
private:
    std::string name;
    int grade;

public:
    Bureaucrat(std::string name, int grade) : name(name), grade(grade) {}

    void signForm(AForm& form);

    void executeForm(const AForm& form) const;
    
    // Getters
    std::string getName() const { return name; }
    int getGrade() const { return grade; }
};

// Define exceptions
class FormNotSignedException : public std::exception {
public:
    const char* what() const throw() {
        return "Form is not signed.";
    }
};

class GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade is too high.";
    }
};

class GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade is too low.";
    }
};

// Implementation of member functions

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade) {
        signedStatus = true;
        std::cout << bureaucrat.getName() << " signs " << target << "'s form." << std::endl;
    } else {
        throw GradeTooLowException();
    }
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
    } catch (const std::exception& e) {
        std::cerr << getName() << " cannot sign the form. Reason: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getTarget() << "'s form." << std::endl;
    } 
    catch (const std::exception& e)
    {
        std::cerr << getName() << " cannot execute the form. Reason: " << e.what() << std::endl;
    }
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }

    if (executor.getGrade() <= getExecGrade()) 
    {
        std::ofstream outFile(getTarget() + "_shrubbery");
        if (outFile.is_open()) {
            outFile << "ASCII trees go here." << std::endl;
            outFile.close();
        } else {
            throw std::runtime_error("Unable to create file for shrubbery creation.");
        }
    } 
    else 
    {
        throw GradeTooLowException();
    }
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }

    if (executor.getGrade() <= getExecGrade()) {
        std::cout << "Drilling noises..." << std::endl;
        // Simulate a 50% success rate for robotomy
        if (rand() % 2 == 0) {
            std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "Robotomy failed for " << getTarget() << "." << std::endl;
        }
    } else {
        throw GradeTooLowException();
    }
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }

    if (executor.getGrade() <= getExecGrade()) {
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    } else {
        throw GradeTooLowException();
    }
}

int main() {
    // Seed the random number generator for RobotomyRequestForm
    std::srand(std::time(0));

    Bureaucrat bureaucrat("John Doe", 10);
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("target");
    PresidentialPardonForm pardonForm("criminal");

    bureaucrat.signForm(shrubberyForm);
    bureaucrat.signForm(robotomyForm);
    bureaucrat.signForm(pardonForm);

    bureaucrat.executeForm(shrubberyForm);
    bureaucrat.executeForm(robotomyForm);
    bureaucrat.executeForm(pardonForm);

    return 0;
}
