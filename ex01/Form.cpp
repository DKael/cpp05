/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:13:37 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 20:19:56 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
    : name(""), isSigned(false), gradeToSign(150), gradeToExecute(150) {
  ;
}

Form::Form(const std::string& _name, int _gradeToSign, int _gradeToExecute)
    : name(_name),
      isSigned(false),
      gradeToSign(_gradeToSign),
      gradeToExecute(_gradeToExecute) {
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException(this->name.c_str());
  else if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException(this->name.c_str());
}

Form::Form(const Form& origin)
    : name(origin.name),
      isSigned(origin.isSigned),
      gradeToSign(origin.gradeToSign),
      gradeToExecute(origin.gradeToExecute) {
  ;
}

Form& Form::operator=(const Form& origin) {
  int dummy = origin.getGradeToSign();
  std::cout << dummy;
  return *this;
}

Form::~Form() { ; }

std::string Form::getName() const { return name; }

int Form::getIsSigned() const { return isSigned; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat& signer) {
  if (signer.getGrade() > gradeToSign) {
    throw GradeTooLowException(name.c_str());
  } else if (isSigned == true) {
    throw AlreadySignedException();
  }
  isSigned = true;
}

Form::GradeException::GradeException(const char* who,
                                     const char* exceptionMsg) {
  static const char* type = "Form ";
  size_t offset;
  int idx;

  strcpy(message, type);
  len = strlen(type);
  offset = strlen(exceptionMsg) + 1;
  idx = 0;
  while (who[idx] != '\0' && len < BUFFER_SIZE1 - offset) {
    message[len] = who[idx];
    idx++;
    len++;
  }
  strcpy(&message[len], exceptionMsg);
}

const char* Form::GradeException::what() const throw() { return message; }

Form::GradeTooHighException::GradeTooHighException(const char* who)
    : GradeException(who, "'s grade exceed 1!") {
  ;
}

Form::GradeTooLowException::GradeTooLowException(const char* who)
    : GradeException(who, "'s grade below 150!") {
  ;
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
  out << "Form's name : " << obj.getName() << '\n'
      << "Is form signed : " << (obj.getIsSigned() ? "Yes" : "No") << '\n'
      << "Grade to sign : " << obj.getGradeToSign() << '\n'
      << "Grade to execute : " << obj.getGradeToExecute() << '\n';
  return out;
}
