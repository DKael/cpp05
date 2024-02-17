/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:35 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/17 19:56:41 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat bur1("name1", 50);
	try{
		Form form1("form1", 50,50);
		//Form form2("form2", 151,151);
		Form form2("form2", 150,150);
		//Form form3("form3", 0,0);
		Form form3("form3", 1,1);
		
		std::cout << form1 << '\n' << form2 << '\n' << form3 << '\n';
		bur1.signForm(form1);
		bur1.signForm(form2);
		bur1.signForm(form2);
		bur1.signForm(form3);
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
