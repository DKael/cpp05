/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:33 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 19:32:55 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define BUFFER_SIZE 1024

class Form;

class Bureaucrat {
private:
	const std::string name;
	int grade;

	//not use
	Bureaucrat();

protected:

public:
	Bureaucrat(const std::string& _name);
	Bureaucrat(const std::string& _name, const int _grade);
	Bureaucrat(const Bureaucrat& origin);
	Bureaucrat& operator=(const Bureaucrat& origin);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void increment_grade(int n);
	void decrement_grade(int n);
	void signForm(Form& form);

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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif