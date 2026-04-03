
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:	_name("undefined"),
		_grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	:	_name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	_name(other.getName()) {
	if (other.getGrade() < 1)
		throw GradeTooHighException();
	if (other.getGrade() > 150)
		throw GradeTooLowException();
	_grade = other.getGrade();	
}

Bureaucrat::~Bureaucrat(void) {
}

std::string	Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::upGrade(void) {
	const int	newGrade = getGrade() - 1;

	if (newGrade < 1)
		throw GradeTooHighException();
	_grade = newGrade;
}

void Bureaucrat::downGrede(void) {
	const int	newGrade = getGrade() + 1;

	if (newGrade > 150)
		throw GradeTooLowException();
	_grade = newGrade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->~Bureaucrat();
		new (this) Bureaucrat(other.getName(), other.getGrade());
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bareaucrat with grade " << obj.getGrade()
		<< std::endl;
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is biggest than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is less than 150";
}
