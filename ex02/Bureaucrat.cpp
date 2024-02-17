/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:31 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 22:42:58 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150) {
	;
}

Bureaucrat::Bureaucrat(const std::string& _name) : name(_name), grade(150) {
	;
}

Bureaucrat::Bureaucrat(const std::string& _name, const int _grade) : name(_name), grade(_grade) {
	if (grade > 150)
		throw GradeTooLowException(this->name.c_str());
	else if (grade < 1)
		throw GradeTooHighException(this->name.c_str());
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
	}
	else {
		grade -= n;
	}
}

void Bureaucrat::decrement_grade(int n) {
	
	if (grade + n > 150) {
		throw GradeTooLowException(this->name.c_str());
	}
	else {
		grade += n;
	}
}

void Bureaucrat::signAForm(AForm& form) {
	try{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << '\n';
	} catch(const AForm::GradeTooLowException& e1) {
		std::cerr << name << " couldn’t sign " << form.getName() \
			<< " because signer's grade is lower than form's grade to sign!\n";
	} catch(const AForm::AlreadySignedException& e2) {
		std::cerr << name << " couldn’t sign " << form.getName() \
			<< " because it is already signed!\n";
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << '\n';
	} catch(const AForm::NotSignedException& e1) {
		std::cerr << name << " couldn’t execute " << form.getName() \
			<< " because form isn't signed!\n";
	} catch(const Bureaucrat::GradeTooLowException& e2) {
		std::cerr << name << " couldn’t execute " << form.getName() \
			<< " because executor's grade is lower than form's grade to execute!\n";
	} catch(const std::exception& e3) {
		std::cerr << e3.what() << '\n';
	}
}

Bureaucrat::GradeException::GradeException(const char* who, const char* exceptionMsg) {
	static const char* type = "Bureaucrat ";
	size_t offset;
	int idx;
	
	strcpy(message, type);
	len = strlen(type);
	offset = strlen(exceptionMsg) + 1;
	idx = 0;
	while (who[idx] != '\0' && len < BUFFER_SIZE0 - offset) {
		message[len] = who[idx];
		idx++;
		len++;
	}
	strcpy(&message[len], exceptionMsg);
}

const char* Bureaucrat::GradeException::what() const throw() {
	return message;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* who)
	: GradeException(who, "'s grade exceed 1!") {
	;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* who) 
	: GradeException(who, "'s grade below 150!") {
	;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return out;
}
