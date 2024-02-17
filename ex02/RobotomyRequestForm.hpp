/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:21:39 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 21:59:11 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	static int count;
	std::string target;

	std::string intToString(int num);

	//not use
	RobotomyRequestForm();
	
protected:

public:
	RobotomyRequestForm(const std::string& _target);
	RobotomyRequestForm(const RobotomyRequestForm& origin);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
	~RobotomyRequestForm();
	void executeDetail() const;
};

#endif