/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:13:37 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 19:25:36 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name(""), isSigned(false), gradeToSign(150), gradeToExecute(150) 
{
	;
}

AForm::AForm(const std::string& _name, int _gradeToSign, int _gradeToExecute) 
	: name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException(this->name.c_str());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException(this->name.c_str());
}

AForm::AForm(const AForm& origin) : name(origin.name), isSigned(origin.isSigned), 
	gradeToSign(origin.gradeToSign), gradeToExecute(origin.gradeToExecute) {
	;
}

AForm& AForm::operator=(const AForm& origin) {
	int dummy = origin.getGradeToSign();
	std::cout << dummy;
	return *this;
}

AForm::~AForm() {
	;
}

std::string AForm::getName() const {
	return name;
}

int	AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > gradeToSign) {
		throw GradeTooLowException(name.c_str());
	} else if (isSigned == true) {
		throw AlreadySignedException();
	}
	isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (isSigned == false) {
		throw NotSignedException();
	} else if (gradeToExecute < executor.getGrade()) {
		throw Bureaucrat::GradeTooLowException(executor.getName().c_str());
	}
	this->executeDetail();
}

AForm::GradeException::GradeException(const char* who, const char* exceptionMsg) {
	static const char* type = "AForm ";
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

const char* AForm::GradeException::what() const throw() {
	return message;
}

AForm::GradeTooHighException::GradeTooHighException(const char* who)
	: GradeException(who, "'s grade exceed 1!") {
	;
}

AForm::GradeTooLowException::GradeTooLowException(const char* who) 
	: GradeException(who, "'s grade below 150!") {
	;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << "AForm's name : " << obj.getName() << '\n' \
		<< "Is AForm signed : " << (obj.getIsSigned() ? "Yes" : "No") << '\n' \
		<< "Grade to sign : " << obj.getGradeToSign() << '\n' \
		<< "Grade to execute : " << obj.getGradeToExecute() << '\n';
	return out;
}
