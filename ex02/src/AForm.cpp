
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
	:	_name("undefined"),
		_gradeToSign(150),
		_gradeToExecute(150) {

	_signed = false;
}

AForm::AForm(const std::string name, const int& gradeToSign, const int& gradeToExecute)
	:	_name(name), 
		_gradeToSign(gradeToSign), 
		_gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();

	if (_gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150)
		throw GradeTooLowException();

	_signed = false;
}

AForm::AForm(const AForm& other)
	:	_name(other.getName()), 
		_gradeToSign(other.getGradeToSign()), 
		_gradeToExecute(other.getGradeToExecute()) {

	_signed = other.isSigned();
}

AForm::~AForm(void) {
}

std::string AForm::getName(void) const {
	return _name;
}

int AForm::getGradeToSign(void) const {
	return _gradeToSign;
}

int AForm::getGradeToExecute(void) const {
	return _gradeToExecute;
}

bool AForm::isSigned(void) const {
	return _signed;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();

	_signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	out << "Form " << obj.getName()
		<< ", it requires grade " << obj.getGradeToSign() << " to be signed"
		<< " and grade " << obj.getGradeToExecute() << " to execute";

	return out;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "the grade is higher than what is necessary";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "the grade is less than what is necessary";
}

const char* AForm::UnsignedFormException::what() const throw() {
	return "the form is not signed";
}
