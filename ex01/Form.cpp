#include "Form.hpp"

Form::Form()
    : _name("Empty Form"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {};

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
}