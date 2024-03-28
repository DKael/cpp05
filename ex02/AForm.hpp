/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:13:34 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 19:32:46 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

#define BUFFER_SIZE1 1024

class Bureaucrat;

class AForm {
 private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;

  // not use
  AForm();
  AForm& operator=(const AForm& origin);

 protected:
 public:
  AForm(const std::string& _name, int _gradeToSign, int _gradeToExecute);
  AForm(const AForm& origin);
  virtual ~AForm();
  std::string getName() const;
  int getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(const Bureaucrat& signer);
  void execute(Bureaucrat const& executor) const;
  virtual void executeDetail() const = 0;
  class GradeException : public std::exception {
   private:
    char message[BUFFER_SIZE1];
    size_t len;

    // not use
    GradeException();

   public:
    GradeException(const char* who, const char* exceptionMsg);
    const char* what() const throw();
  };

  class GradeTooHighException : public GradeException {
   private:
    // not use
    GradeTooHighException();

   public:
    GradeTooHighException(const char* who);
  };

  class GradeTooLowException : public GradeException {
   private:
    // not use
    GradeTooLowException();

   public:
    GradeTooLowException(const char* who);
  };

  class AlreadySignedException : public std::exception {};

  class NotSignedException : public std::exception {};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif