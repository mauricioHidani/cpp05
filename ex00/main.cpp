/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:00:28 by mhidani           #+#    #+#             */
/*   Updated: 2026/04/03 14:50:46 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main(void) {
	{
		std::cout << "Test 1 ====================================" << std::endl;
		
		/** Check the precedence of the bureaucrat's exceptions and also whether 
		 * the grade initialization fails when is below the limit
		 */
		Bureaucrat*	b1 = NULL;
		try {
			const std::string	name	= "Jean-Batiste Colbert";
			const int			grade	= 152;
			b1 = new Bureaucrat(name, grade);

		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		}

		/** Check the inheritance of exceptions in your dynamic polymorphic 
		 * access, which doesn't specify the type of exception thrown. And also 
		 * the failure when the limit is higher
		 */
		Bureaucrat* b2 = NULL;
		try {
			const std::string	name	= "Otto von Bismarck";
			const int			grade	= -2;
			b2 = new Bureaucrat(name, grade);

		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		if (b1 != NULL)
			delete b1;
		if (b2 != NULL)
			delete b2;
	}
	{
		std::cout << "Test 2 ====================================" << std::endl;

		// Check exception when the bureaucrat's grade up
		Bureaucrat b1("Otto von Bismarck", 1);
		try {
			b1.upGrade();
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		// Check exception when the bureaucrat's grade down
		Bureaucrat b2("Jean-Batiste Colbert", 150);
		try {
			b2.downGrede();
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "Test 3 ====================================" << std::endl;
		
		// A test that never fails
		Bureaucrat b1("Otto von Bismarck", 43);
		try {
			b1.upGrade();
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << b1 << std::endl;
	}
	return 0;
}
