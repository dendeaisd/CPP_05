#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  /**Orthodox Canonical Form Elements*/
  Bureaucrat() = default;
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other) = default;
  Bureaucrat &operator=(const Bureaucrat &other) = default;
  ~Bureaucrat() = default;

  /**Getters**/
  const std::string &getName() const;
  int getGrade() const;

  /**Grade Manipulation**/
  void incrementGrade();
  void decrementGrade();

  /**Custom exception classes**/
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };
};

/**Insertion operator overload**/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bc);

#endif