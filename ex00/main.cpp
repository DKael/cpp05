/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:47:35 by hyungdki          #+#    #+#             */
/*   Updated: 2024/02/14 18:09:13 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  Bureaucrat bur1("name1");
  Bureaucrat bur2(bur1);
  Bureaucrat bur3("name3");

  try {
    bur2.increment_grade(100);
    bur3.increment_grade(149);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << bur1 << "\n" << bur2 << "\n" << bur3 << "\n";

  try {
    bur1.decrement_grade(1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    bur3.increment_grade(149);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
