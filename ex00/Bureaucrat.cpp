#include "Bureaucrat.hpp"

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
  std::cout << "Assignment operator called." << std::endl;
  return(*this); 
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return(os);
}

const std::string& Bureaucrat::getName() const {
  return (this->name_);
}

int Bureaucrat::getGrade() const {
  return (this->grade_);
}

void Bureaucrat::incrementGrade(){
  if (grade_ - 1 < 1) {
    throw GradeTooHighException();
  }
  grade_--;
}

void Bureaucrat::decrementGrade(){
  if (grade_ + 1 > 150) {
    throw GradeTooLowException();
  }
  grade_++;
}
const char* GradeTooHighException::what() const throw(){
  return("Grade too high.");
}

const char* GradeTooLowException::what() const throw(){
  return("Grade too low.");
}

