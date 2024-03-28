/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:21:25 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 22:54:50 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>
#include <sstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  static int count;
  std::string target;

  std::string intToString(int num);

  // not use
  ShrubberyCreationForm();

 protected:
 public:
  ShrubberyCreationForm(const std::string& _target);
  ShrubberyCreationForm(const ShrubberyCreationForm& origin);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& origin);
  ~ShrubberyCreationForm();
  void executeDetail() const;
};

#endif