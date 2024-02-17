/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:07:25 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/18 01:40:59 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
	AForm* makePresidentialPardonForm(const std::string _target);
	AForm* makeRobotomyRequestForm(const std::string _target);
	AForm* makeShrubberyCreationForm(const std::string _target);

protected:

public:
	Intern();
	Intern(const Intern& origin);
	Intern& operator=(const Intern& origin);
	~Intern();
	AForm* makeForm(const std::string& _name, const std::string& _target);

	class InvalidForm : public std::exception {};
};

#endif