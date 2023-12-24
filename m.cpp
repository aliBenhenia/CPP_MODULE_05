#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    std::string name; 
    int grade;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too low";
        }
    };

    Bureaucrat(const std::string& name, int grade) : name(name) {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        this->grade = grade;
    }

    const std::string& getName() const {
        return name;
    }

    int getGrade() const {
        return grade;
    }

    void incrementGrade() {
        if (grade - 1 < 1)
            throw GradeTooHighException();
        grade--;
    }

    void decrementGrade() {
        if (grade + 1 > 150)
            throw GradeTooLowException();
        grade++;
    }

    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
        os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
        return os;
    }
};

class A
{
    public :
        int geto(int x) throw()
        {
            throw 99;
            return x;
        }
};

int main() {
    A obj;
    std :: cout << obj.geto(2) << std::endl;
    try {
        Bureaucrat bureaucrat("John Doe", 50);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;

        // This should throw GradeTooHighException
        Bureaucrat highGradeBureaucrat("Alice", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
