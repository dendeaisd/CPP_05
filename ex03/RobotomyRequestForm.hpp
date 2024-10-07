#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <string>

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm(const std::string &target);
  ~RobotomyRequestForm() {};

  void execute(Bureaucrat const &executor) const override;
};