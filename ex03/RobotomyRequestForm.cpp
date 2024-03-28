/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:18:35 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 22:10:27 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::count = 0;

std::string RobotomyRequestForm::intToString(int num) {
  std::ostringstream strm;
  strm << num;
  return strm.str();
}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm" + intToString(RobotomyRequestForm::count), 72,
            45),
      target("") {
  RobotomyRequestForm::count++;
  srand(static_cast<unsigned int>(time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target)
    : AForm("RobotomyRequestForm" + intToString(RobotomyRequestForm::count), 72,
            45),
      target(_target) {
  RobotomyRequestForm::count++;
  srand(static_cast<unsigned int>(time(NULL)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
    : AForm("RobotomyRequestForm" + intToString(RobotomyRequestForm::count), 72,
            45),
      target(origin.target) {
  RobotomyRequestForm::count++;
  srand(static_cast<unsigned int>(time(NULL)));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& origin) {
  target = origin.target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { ; }

void RobotomyRequestForm::executeDetail() const {
  std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzz!\n";
  if (rand() % 2) {
    std::cout << target << " has been robotomized successfully!\n";
  } else {
    std::cout << target << " robotomized fail!\n";
  }
}
