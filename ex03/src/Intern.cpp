
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
}

Intern::~Intern(void) {
}

AForm* Intern::makePresidentialPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequest(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyCreation(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	std::string upperName;

	const std::string types[] = {
		"PRESIDENTIAL PARDON", 
		"ROBOTOMY REQUEST", 
		"SHRUBBERY CREATION"
	};
	AForm* (Intern::*make[])(const std::string&) = {
		&Intern::makePresidentialPardon,
		&Intern::makeRobotomyRequest, 
		&Intern::makeShrubberyCreation
	};

	for (size_t i = 0; i < name.length(); i++)
		upperName += static_cast<char>(
			std::toupper(static_cast<unsigned char>(name[i]))
		);

	for (int i = 0; i < 3; i++) {
		if (upperName == types[i]) {
			std::cout << "Inter create " << name << std::endl;
			return (this->*make[i])(target);
		}
	}
	throw std::runtime_error("The form name was not found");
}
