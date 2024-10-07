#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    std::cout << "===============================" << std::endl;
    std::cout << "Test 1: Default Constructor" << std::endl;
    std::cout << "===============================" << std::endl;
    /*Test: default constructor*/
    Form emptyForm;
    std::cout << emptyForm << std::endl;

    std::cout << "\n===============================" << std::endl;
    std::cout << "Test 2: Bureaucrats and Forms Initialization" << std::endl;
    std::cout << "===============================" << std::endl;
    /*Test: Bureaucrats and Forms*/
    Bureaucrat john("John", 2);
    Bureaucrat jane("Jane", 149);
    Bureaucrat jack("Bob", 50);

    Form formA("Form A", 1, 5);
    Form formB("Form B", 50, 50);
    Form formC("Form C", 150, 150);

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;
    std::cout << formC << std::endl;

    /*Test: John (grade 2) tries to sign Form A (needs grade 1)*/
    john.signForm(formA);
    std::cout << formA << std::endl;

    /*Test: Jack (grade 50) tries to sign Form B (needs grade 50)*/
    jack.signForm(formB);
    std::cout << formB << std::endl;

    /*Test: Jane (grade 149) tries to sign Form C (needs grade 150)*/
    jane.signForm(formC);
    std::cout << formC << std::endl;

    /*Test: Trying to sign an already signed form*/
    jack.signForm(formB);

    /*Test: Creating a form with invalid grades*/
    try {
      Form invalidForm("Invalid Form", 0, 151);
    } catch (const std::exception &e) {
      std::cerr << "Exception caught during form creation: " << e.what()
                << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  return 0;
}
