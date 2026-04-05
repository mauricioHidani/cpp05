/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:01:04 by mhidani           #+#    #+#             */
/*   Updated: 2026/04/05 19:44:10 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
 
void printTest(std::ostream& out, const int idx, const std::string tba) {
	out << "test " << idx << " ";
	for (int i = 0; i < 73; i++)
		out << "=";
	out << std::endl;
	out << tba;
	out << std::endl;
	for (int i = 0; i < 80; i++)
		out << ".";
	out << std::endl;
}

int	main(void) {
	int	index = 1;

	{ // TEST ==================================================================
		printTest(std::cout, index++,
			"Failure: president form doesn't exist"
		);

		Intern*	intern = new Intern();
		AForm*	form = NULL;
		
		try {
			form = intern->makeForm("salt", "test form");
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		delete form;
		delete intern;
	} std::cout << std::endl;

	{ // TEST ==================================================================
		printTest(std::cout, index++,
			"Success: all forms name exists and create the forms"
		);

		Intern		intern;
		Bureaucrat	mathematician("Augusta Ada Byron King", 1);
		AForm*		presidential = NULL;
		AForm*		robotomy = NULL;
		AForm*		shrubbery = NULL;

		try {
			presidential = intern.makeForm("presidential pardon", "pardon");
			robotomy = intern.makeForm("robotomy request", "request");
			shrubbery = intern.makeForm("shrubbery creation", "creation");

		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		mathematician.signForm(*presidential);
		mathematician.signForm(*robotomy);
		mathematician.signForm(*shrubbery);

		std::cout << std::endl;

		mathematician.executeForm(*presidential);
		mathematician.executeForm(*robotomy);
		mathematician.executeForm(*shrubbery);

		delete shrubbery;
		delete robotomy;
		delete presidential;
	} std::cout << std::endl;
	return 0;
}
