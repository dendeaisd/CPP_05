#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc) {
  out << bc.getName() << ", bureaucrat grade " << bc.getGrade();
  return out;
}