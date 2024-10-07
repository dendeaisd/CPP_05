#include "Form.hpp"

/*Default constuctor*/
Form::Form()
    : _name("Empty Form"), _isSigned(false), _gradeToSign(150),
      _gradeToExecute(150) {};

/*Parametrized constructor*/
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
}

/*Copy constructor*/
Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

/*Assignment operator*/
Form &Form::operator=(const Form &other) {
  if (this != &other)
    _isSigned = other._isSigned;
  return *this;
}

/*Destructor*/
Form::~Form() {};