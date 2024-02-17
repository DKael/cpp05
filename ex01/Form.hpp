/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:13:34 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 19:32:46 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#define BUFFER_SIZE 1024

class Bureaucrat;

class Form{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	//not use
	Form();
	Form& operator=(const Form& origin);

protected:

public:
	Form(const std::string& _name, int _gradeToSign, int _gradeToExecute);
	Form(const Form& origin);
	~Form();
	std::string getName() const;
	int	getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& signer);
	class GradeException : public std::exception {
		private:
			char message[BUFFER_SIZE];
			size_t len;

			//not use
			GradeException();
			
		public:
			GradeException(const char* who, const char* exceptionMsg);
			const char* what() const throw();
	};

	class GradeTooHighException : public GradeException {
		private:
			//not use
			GradeTooHighException();
			
		public:
			GradeTooHighException(const char* who);
	};

	class GradeTooLowException : public GradeException {
		private:
			//not use
			GradeTooLowException();

		public:
			GradeTooLowException(const char* who);
	};

	class AlreadySignedException : public std::exception {};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif