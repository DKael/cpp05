/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:33 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 18:14:31 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define BUFFER_SIZE 1024

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

	class GradeTooHighException : public std::exception {
		private:
			// const std::string who;
			// std::string message;
			char message[BUFFER_SIZE];
			size_t len;

			//not use
			GradeTooHighException();
			
		public:
			// virtual ~GradeTooHighException() _NOEXCEPT;
			// GradeTooHighException(const std::string& _who);
			GradeTooHighException(const char* who);
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		private:
			// const std::string who;
			// std::string message;
			char message[BUFFER_SIZE];
			size_t len;

			//not use
			GradeTooLowException();

		public:
			// virtual ~GradeTooLowException() _NOEXCEPT;
			// GradeTooLowException(const std::string& _who);
			GradeTooLowException(const char* who);
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif