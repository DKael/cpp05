/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:21:48 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 21:28:53 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <sstream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  static int count;
  std::string target;

  std::string intToString(int num);

  // not use
  PresidentialPardonForm();

 protected:
 public:
  PresidentialPardonForm(const std::string& _target);
  PresidentialPardonForm(const PresidentialPardonForm& origin);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);
  ~PresidentialPardonForm();
  void executeDetail() const;
};

#endif