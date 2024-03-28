/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:35 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 22:30:30 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat bur0("executor0", 5);
  Bureaucrat bur1("executor1", 25);
  Bureaucrat bur2("executor2", 30);

  AForm* pform0 = new PresidentialPardonForm("home");
  AForm* pform1 = new PresidentialPardonForm("school");
  AForm* pform2 = new PresidentialPardonForm("42seoul");

  std::cout << *pform0 << '\n' << *pform1 << '\n' << *pform2 << '\n';

  bur0.signAForm(*pform0);
  bur0.executeForm(*pform0);

  bur1.signAForm(*pform1);
  bur1.executeForm(*pform1);
  bur0.executeForm(*pform1);

  bur2.signAForm(*pform2);
  bur2.executeForm(*pform2);
  bur0.signAForm(*pform2);
  bur2.executeForm(*pform2);
  bur0.executeForm(*pform2);

  delete pform0;
  delete pform1;
  delete pform2;

  bur0.decrement_grade(40);
  bur1.decrement_grade(47);
  bur2.decrement_grade(50);

  pform0 = new RobotomyRequestForm("home");
  pform1 = new RobotomyRequestForm("school");
  pform2 = new RobotomyRequestForm("42seoul");

  std::cout << *pform0 << '\n' << *pform1 << '\n' << *pform2 << '\n';

  bur0.signAForm(*pform0);
  bur0.executeForm(*pform0);

  bur1.signAForm(*pform1);
  bur1.executeForm(*pform1);
  bur0.executeForm(*pform1);

  bur2.signAForm(*pform2);
  bur2.executeForm(*pform2);
  bur0.signAForm(*pform2);
  bur2.executeForm(*pform2);
  bur0.executeForm(*pform2);

  delete pform0;
  delete pform1;
  delete pform2;

  bur0.decrement_grade(92);
  bur1.decrement_grade(73);
  bur2.decrement_grade(70);

  pform0 = new ShrubberyCreationForm("home");
  pform1 = new ShrubberyCreationForm("school");
  pform2 = new ShrubberyCreationForm("42seoul");

  std::cout << *pform0 << '\n' << *pform1 << '\n' << *pform2 << '\n';

  bur0.signAForm(*pform0);
  bur0.executeForm(*pform0);

  bur1.signAForm(*pform1);
  bur1.executeForm(*pform1);
  bur0.executeForm(*pform1);

  bur2.signAForm(*pform2);
  bur2.executeForm(*pform2);
  bur0.signAForm(*pform2);
  bur2.executeForm(*pform2);
  bur0.executeForm(*pform2);

  delete pform0;
  delete pform1;
  delete pform2;

  return 0;
}
