/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:18:27 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 21:27:40 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

int PresidentialPardonForm::count = 0;

std::string PresidentialPardonForm::intToString(int num) {
  std::ostringstream strm;
  strm << num;
  return strm.str();
}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(
          "PresidentialPardonForm" + intToString(PresidentialPardonForm::count),
          25, 5),
      target("") {
  PresidentialPardonForm::count++;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target)
    : AForm(
          "PresidentialPardonForm" + intToString(PresidentialPardonForm::count),
          25, 5),
      target(_target) {
  PresidentialPardonForm::count++;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& origin)
    : AForm(
          "PresidentialPardonForm" + intToString(PresidentialPardonForm::count),
          25, 5),
      target(origin.target) {
  PresidentialPardonForm::count++;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& origin) {
  target = origin.target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { ; }

void PresidentialPardonForm::executeDetail() const {
  std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
