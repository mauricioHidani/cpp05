
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
	:	_name("undefined"),
		_gradeToSign(150),
		_gradeToExecute(150) {

	_signed = false;
}

Form::Form(const std::string name, const int& gradeToSign, const int& gradeToExecute)
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

Form::Form(const Form& other)
	:	_name(other.getName()), 
		_gradeToSign(other.getGradeToSign()), 
		_gradeToExecute(other.getGradeToExecute()) {

	_signed = other.isSigned();
}

Form::~Form(void) {
}

std::string Form::getName(void) const {
	return _name;
}

int Form::getGradeToSign(void) const {
	return _gradeToSign;
}

int Form::getGradeToExecute(void) const {
	return _gradeToExecute;
}

bool Form::isSigned(void) const {
	return _signed;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();

	_signed = true;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->~Form();
		new (this) Form(other);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << "Form " << obj.getName()
		<< ", it requires grade " << obj.getGradeToSign() << " to be signed"
		<< " and grade " << obj.getGradeToExecute() << " to execute";

	return out;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "the grade is higher than what is necessary";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "the grade is less than what is necessary";
}

