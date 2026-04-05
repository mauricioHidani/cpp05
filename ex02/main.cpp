/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:00:59 by mhidani           #+#    #+#             */
/*   Updated: 2026/04/05 15:39:25 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
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
			"Failure: Execution fails if the form has not been signed"
		);

		ShrubberyCreationForm shrubbery("Forest");
		Bureaucrat juliete("Juliete Petterson", 100);
		std::cout << shrubbery << std::endl;
		std::cout << juliete << std::endl;
		juliete.executeForm(shrubbery);
		std::cout << std::endl;

		RobotomyRequestForm robotom("Drill");
		Bureaucrat steffan("Steffan", 42);
		std::cout << robotom << std::endl;
		std::cout << steffan << std::endl;
		steffan.executeForm(robotom);
		std::cout << std::endl;

		PresidentialPardonForm presidential("Funding Authorization");
		Bureaucrat secretaryEconomy("Secretary of the Economy", 2);
		std::cout << presidential << std::endl;
		std::cout << secretaryEconomy << std::endl;
		secretaryEconomy.executeForm(presidential);

	} std::cout << std::endl;

	{ // TEST ==================================================================
		printTest(std::cout, index++, 
			"Failure: The grade is lower than what is required to pass"
		);

		ShrubberyCreationForm shrubbery("Forest");
		Bureaucrat juliete("Juliete Petterson", 138);
		std::cout << shrubbery << std::endl;
		std::cout << juliete << std::endl;
		juliete.signForm(shrubbery);
		juliete.executeForm(shrubbery);
		std::cout << std::endl;

		RobotomyRequestForm robotom("Drill");
		Bureaucrat steffan("Steffan", 46);
		std::cout << robotom << std::endl;
		std::cout << steffan << std::endl;
		steffan.signForm(robotom);
		steffan.executeForm(robotom);
		std::cout << std::endl;

		PresidentialPardonForm presidential("Funding Authorization");
		Bureaucrat secretaryEconomy("Secretary of the Economy", 6);
		std::cout << presidential << std::endl;
		std::cout << secretaryEconomy << std::endl;
		secretaryEconomy.signForm(presidential);
		secretaryEconomy.executeForm(presidential);

	} std::cout << std::endl;

	{ // TEST ==================================================================
		printTest(std::cout, index++, 
			"Success: Execute form when bureaucrat grade is higher than the execute"
		);

		ShrubberyCreationForm shrubbery("Forest");
		Bureaucrat juliete("Juliete Petterson", 100);
		std::cout << shrubbery << std::endl;
		std::cout << juliete << std::endl;
		juliete.signForm(shrubbery);
		juliete.executeForm(shrubbery);
		std::cout << std::endl;

		RobotomyRequestForm robotom("Drill");
		Bureaucrat steffan("Steffan", 42);
		std::cout << robotom << std::endl;
		std::cout << steffan << std::endl;
		steffan.signForm(robotom);
		steffan.executeForm(robotom);
		std::cout << std::endl;

		PresidentialPardonForm presidential("Funding Authorization");
		Bureaucrat secretaryEconomy("Secretary of the Economy", 2);
		std::cout << presidential << std::endl;
		std::cout << secretaryEconomy << std::endl;
		secretaryEconomy.signForm(presidential);
		secretaryEconomy.executeForm(presidential);

	} std::cout << std::endl;
	return 0;
}
