#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm() {}

  void execute(Bureaucrat const &executor) const override;
};
