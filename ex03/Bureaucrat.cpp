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

void Bureaucrat::incrementGrade() {
  _grade--;
  if (_grade < 1)
    throw GradeTooHighException();
}
void Bureaucrat::decrementGrade() {
  _grade++;
  if (_grade > 150)
    throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return RED "Grade is too high!" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return RED "Grade is too low!" RESET;
}

void Bureaucrat::signForm(AForm &form) const {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << _name << " couldn’t sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << _name << " couldn’t execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc) {
  out << BLUE << bc.getName() << RESET << "🧑‍💻 , bureaucrat grade "
      << DPINK << bc.getGrade() << RESET;
  return out;
}