#pragma once

#include "AForm.hpp"

#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm(const std::string &target);
  void execute(Bureaucrat const &executor) const override;
};