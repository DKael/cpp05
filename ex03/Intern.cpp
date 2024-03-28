/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:07:29 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/18 01:56:15 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::makePresidentialPardonForm(const std::string _target) {
  return new PresidentialPardonForm(_target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string _target) {
  return new RobotomyRequestForm(_target);
}

AForm* Intern::makeShrubberyCreationForm(const std::string _target) {
  return new ShrubberyCreationForm(_target);
}

Intern::Intern() { ; }

Intern::Intern(const Intern& origin) { (void)origin; }

Intern& Intern::operator=(const Intern& origin) {
  (void)origin;
  return *this;
}

Intern::~Intern() { ; }

AForm* Intern::makeForm(const std::string& _name, const std::string& _target) {
  static std::string formType[3] = {std::string("presidential pardon"),
                                    std::string("robotomy request"),
                                    std::string("shrubbery creation")};
  static AForm* (Intern::*func_ptr[3])(std::string _target) = {
      &Intern::makePresidentialPardonForm,
      &Intern::makeRobotomyRequestForm,
      &Intern::makeShrubberyCreationForm,
  };
  for (int i = 0; i < 3; i++) {
    if (_name == formType[i]) {
      std::cout << "Intern creates " << formType[i] << " form.\n";
      return (this->*func_ptr[i])(_target);
    }
  }
  throw InvalidForm();
  return NULL;
}
