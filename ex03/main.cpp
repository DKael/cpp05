/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:35 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/18 01:57:14 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat bur0("executor0", 5);
	Bureaucrat bur1("executor1", 25);
	Bureaucrat bur2("executor2", 30);

	Intern intern0;

	AForm* pform0;
	AForm* pform1;
	AForm* pform2;

	try {
		pform0 = intern0.makeForm("unknown", "unknown");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform0 = intern0.makeForm("presidential pardon", "Home");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform1 = intern0.makeForm("presidential pardon", "school");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform2 = intern0.makeForm("presidential pardon", "42seoul");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	std::cout << *pform0 << '\n' << *pform1 << '\n' << *pform2 << '\n';

	bur0.signAForm(*pform0);
	bur0.executeForm(*pform0);

	bur1.signAForm(*pform1);
	bur1.executeForm(*pform1);
	bur0.executeForm(*pform1);

	bur2.signAForm(*pform2);
	bur2.executeForm(*pform2);
	bur0.signAForm(*pform2);
	bur2.executeForm(*pform2);
	bur0.executeForm(*pform2);

	delete pform0;
	delete pform1;
	delete pform2;

	bur0.decrement_grade(40);
	bur1.decrement_grade(47);
	bur2.decrement_grade(50);

	try {
		pform0 = intern0.makeForm("unknown", "unknown");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform0 = intern0.makeForm("robotomy request", "Home");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform1 = intern0.makeForm("robotomy request", "school");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform2 = intern0.makeForm("robotomy request", "42seoul");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	std::cout << *pform0 << '\n' << *pform1 << '\n' << *pform2 << '\n';

	bur0.signAForm(*pform0);
	bur0.executeForm(*pform0);

	bur1.signAForm(*pform1);
	bur1.executeForm(*pform1);
	bur0.executeForm(*pform1);

	bur2.signAForm(*pform2);
	bur2.executeForm(*pform2);
	bur0.signAForm(*pform2);
	bur2.executeForm(*pform2);
	bur0.executeForm(*pform2);

	delete pform0;
	delete pform1;
	delete pform2;

	bur0.decrement_grade(92);
	bur1.decrement_grade(73);
	bur2.decrement_grade(70);

	try {
		pform0 = intern0.makeForm("unknown", "unknown");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform0 = intern0.makeForm("shrubbery creation", "Home");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform1 = intern0.makeForm("shrubbery creation", "school");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	try {
		pform2 = intern0.makeForm("shrubbery creation", "42seoul");
	} catch (Intern::InvalidForm& e) {
		std::cerr << "Invalid form type!\n";
	}

	std::cout << *pform0 << '\n' << *pform1 << '\n' << *pform2 << '\n';

	bur0.signAForm(*pform0);
	bur0.executeForm(*pform0);

	bur1.signAForm(*pform1);
	bur1.executeForm(*pform1);
	bur0.executeForm(*pform1);

	bur2.signAForm(*pform2);
	bur2.executeForm(*pform2);
	bur0.signAForm(*pform2);
	bur2.executeForm(*pform2);
	bur0.executeForm(*pform2);

	delete pform0;
	delete pform1;
	delete pform2;

	return 0;
}
