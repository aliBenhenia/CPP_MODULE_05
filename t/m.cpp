#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade too low";
        }
    };

    Form(const std::string& name, int signGrade, int executeGrade)
        : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
        if (signGrade < 1 || signGrade > 150 || executeGrade < 1 || executeGrade > 150) {
            throw GradeTooHighException();
        }
    }

    const std::string& getName() const {
        return name;
    }

    bool getIsSigned() const {
        return isSigned;
    }

    int getSignGrade() const {
        return signGrade;
    }

    int getExecuteGrade() const {
        return executeGrade;
    }

    void beSigned(const Bureaucrat& bureaucrat);

    void signForm(const Bureaucrat& bureaucrat);

    friend std::ostream& operator<<(std::ostream& os, const Form& form);

private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;
};

class Bureaucrat {
public:
    Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
        if (grade < 1 || grade > 150) {
            throw Form::GradeTooHighException();
        }
    }

    const std::string& getName() const {
        return name;
    }

    int getGrade() const {
        return grade;
    }

    void signForm(Form& form) const;

private:
    const std::string name;
    int grade;
};

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= signGrade) {
        isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

void Form::signForm(const Bureaucrat& bureaucrat) {
    try {
        beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signed " << name << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << bureaucrat.getName() << " couldn't sign " << name << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(Form& form) const {
    form.signForm(*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 5);
        Form form("Tax Form", 10, 20);

        std::cout << "Before signing:\n" << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << "\nAfter signing:\n" << form << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
