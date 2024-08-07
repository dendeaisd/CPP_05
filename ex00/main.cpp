#include "Bureaucrat.hpp"
#define BLUE "\033[36m"
#define PINK "\033[38;2;255;182;193m"
#define RESET "\033[0m"

int main() {
  std::cout << BLUE
            << "\nTest: Creating a Bureaucrat with an invalid high grade (-5)"
            << RESET << std::endl;
  try {
    Bureaucrat one("buro0", -5);
  } catch (std::exception &e) {
    std::cerr << PINK << "Exception: " << e.what() << RESET << '\n';
  }

  std::cout << BLUE
            << "\nTest: Creating a Bureaucrat with a valid grade and testing"
            << RESET << std::endl;
  try {
    Bureaucrat two("buro1", 1);
    std::cout << two << std::endl;
    two.incrementGrade(); // This should throw an exception
    std::cout << two << std::endl;
  } catch (const std::exception &e) {
    std::cerr << PINK << "Exception: " << e.what() << RESET << '\n';
  }

  try {
    Bureaucrat two("buro1", 2);
    std::cout << two << std::endl;
    two.incrementGrade();
    std::cout << two << std::endl;
    two.decrementGrade();
    two.decrementGrade(); // This should throw an exception
    std::cout << two << std::endl;
  } catch (const std::exception &e) {
    std::cerr << PINK << "Exception: " << e.what() << RESET << '\n';
  }

  std::cout << BLUE
            << "\nTest: Creating a Bureaucrat with the lowest valid grade and "
               "decrementing"
            << RESET << std::endl;
  try {
    Bureaucrat three("buro2", 150);
    std::cout << three << std::endl;
    three.decrementGrade(); // This should throw an exception
    std::cout << three << std::endl;
  } catch (const std::exception &e) {
    std::cerr << PINK << "Exception: " << e.what() << RESET << '\n';
  }

  std::cout << BLUE
            << "\nTest: Creating Bureaucrat with an invalid low grade (157)"
            << RESET << std::endl;
  try {
    Bureaucrat four("buro3", 157);
  } catch (const std::exception &e) {
    std::cerr << PINK << "Exception: " << e.what() << RESET << '\n';
  }

  std::cout << BLUE << "\nTest: Copy constructor and assignment operator"
            << RESET << std::endl;
  try {
    Bureaucrat five("buro4", 50);
    std::cout << five << std::endl;
    std::cout << BLUE << "Copy constructor:" << RESET << std::endl;
    Bureaucrat six(five);
    std::cout << six << std::endl;

    std::cout << BLUE << "Assignment operator:" << RESET << std::endl;
    Bureaucrat seven("buro5", 100);
    std::cout << seven << std::endl;
    seven = five; // Copy assignment operator
    std::cout << seven << std::endl;
  } catch (const std::exception &e) {
    std::cerr << PINK << "Exception: " << e.what() << RESET << '\n';
  }

  return 0;
}
