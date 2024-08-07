#include "Bureaucrat.hpp"
#include <algorithm>

Bureaucrat::Bureaucrat() : name_("None"), grade_(150) {
  std::cout << "Default constructor called." << std::endl; 
};

Bureaucrat::~Bureaucrat() {
  std::cout << "Destructor called." << std::endl; 
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
  std::cout << "Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.getName()), grade_(other.getGrade()){
  std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    grade_ = other.getGrade();
  }
  std::cout << "Assign operator called." << std::endl;
  return(*this); 
}
