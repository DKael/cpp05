/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:31 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/14 18:10:50 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& _name) : name(_name), grade(150) {
	;
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin) : name(origin.name), grade(origin.grade) {
	;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin) {
	grade = origin.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	;
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::increment_grade(int n) {
	if (grade - n < 1) {
		throw GradeTooHighException(this->name.c_str());
		//throw GradeTooHighException(this->name);
	}
	else {
		grade -= n;
	}
}

void Bureaucrat::decrement_grade(int n) {
	
	if (grade + n > 150) {
		throw GradeTooLowException(this->name.c_str());
		//throw GradeTooLowException(this->name);
	}
	else {
		grade += n;
	}
}

// Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& _who) : who(_who)
// {
// 	message = who + "'s grade exceed 0. grade unchanged.";
// }

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* who) {
	
	static const char* exception_msg = "'s grade exceed 1. Grade unchanged.";
	
	len = 0;
	while (who[len] != '\0' && len < BUFFER_SIZE - strlen(exception_msg) - 1) {
		message[len] = who[len];
		len++;
	}
	strcpy(&message[len], exception_msg);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	//return message.c_str();
	return message;
}

// Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& _who) : who(_who)
// {
// 	message = who + "'s grade is is below 150. grade unchanged.";
// }

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* who) {
	
	static const char* exception_msg = "'s grade below 150. Grade unchanged.";
	
	len = 0;
	while (who[len] != '\0' && len < BUFFER_SIZE - strlen(exception_msg) - 1) {
		message[len] = who[len];
		len++;
	}
	strcpy(&message[len], exception_msg);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	//return message.c_str();
	return message;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return out;
}
