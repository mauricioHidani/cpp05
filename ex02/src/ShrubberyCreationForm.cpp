
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("Shrubbery Creation", 145, 137),
		_target("undefined") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	AForm("Shrubbery Creation", 145, 137), 
		_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), 
		_target(other.getTarget()) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	std::ofstream	fileStream;
	std::string		fileName = _target + "_shrubbery";

	if (!isSigned())
		throw UnsignedFormException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	fileStream.open(fileName.c_str(), std::ios::out);
	if (!fileStream.is_open())
		throw std::runtime_error("Path not found or no permissions");

	fileStream << "       _-_"			<< std::endl
			   << "    /~~   ~~\\"		<< std::endl
			   << " /~~         ~~\\"	<< std::endl
			   << "{               }"	<< std::endl
			   << " \\  _ - ^ - _  /"	<< std::endl
			   << "   ~  \\\\ //  ~"	<< std::endl
			   << "_- -   | | _- _"		<< std::endl
			   << "  _ -  | |   -_"		<< std::endl
			   << "      // \\\\"		<< std::endl;
	fileStream.close();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		this->~ShrubberyCreationForm();
		new (this) ShrubberyCreationForm(other);
	}

	return *this;
}
