/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:00:53 by mhidani           #+#    #+#             */
/*   Updated: 2026/04/05 15:45:57 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	{
		printTest(std::cout, index++, 
			"Successfull: grade is same"
		);

		Form		form("Voting", 23, 2);
		Bureaucrat	bureaucrat("Juliete Petterson", 23);
		bureaucrat.signForm(form);

		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
	}
	{
		printTest(std::cout, index++,
			"Successfull: bureaucrat's grade is higher to sign form"
		);

		Form		form("Financial Manager", 22, 42);
		Bureaucrat	bureaucrat("Jean-Batiste Colbert", 1);
		bureaucrat.signForm(form);

		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
	}
	{
		printTest(std::cout, index++, 
			"Failed: grade is less to sign form"
		);

		Form	form("IPO", 1, 1);
		Bureaucrat	bureaucrat("Otto von Bismarck", 2);
		bureaucrat.signForm(form);

		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << bureaucrat << std::endl;
	}
	return 0;
}
