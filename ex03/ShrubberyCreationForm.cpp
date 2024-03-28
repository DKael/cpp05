/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:18:45 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 23:04:21 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int ShrubberyCreationForm::count = 0;

std::string ShrubberyCreationForm::intToString(int num) {
  std::ostringstream strm;
  strm << num;
  return strm.str();
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm" + intToString(ShrubberyCreationForm::count),
            145, 137),
      target("") {
  ShrubberyCreationForm::count++;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target)
    : AForm("ShrubberyCreationForm" + intToString(ShrubberyCreationForm::count),
            145, 137),
      target(_target) {
  ShrubberyCreationForm::count++;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm& origin)
    : AForm("ShrubberyCreationForm" + intToString(ShrubberyCreationForm::count),
            145, 137),
      target(origin.target) {
  ShrubberyCreationForm::count++;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& origin) {
  target = origin.target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { ; }

void ShrubberyCreationForm::executeDetail() const {
  const char* fileName = (target + "_shrubbery").c_str();
  std::ofstream out(fileName);
  std::string shrubbery =
      "               ,@@@@@@@,\n"
      "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
      "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
      "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
      "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
      "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
      "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
      "       |o|        | |         | |\n"
      "       |.|        | |         | |\n"
      "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
  if (out.is_open() == false)
    throw std::ofstream::failure(std::string("File open error!"));
  out << shrubbery;
  out.close();
}
