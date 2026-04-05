
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("Robotomy Request", 72, 45),
		_target("undefined") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:	AForm("Robotomy Request", 72, 45), 
		_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
		_target(other.getTarget()) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

std::string RobotomyRequestForm::getTarget(void) const {
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw UnsignedFormException();
	if (getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();

	std::cout << "Bzzzzzzz... "
			  << getTarget() << " was successfully robotized" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->~RobotomyRequestForm();
		new (this) RobotomyRequestForm(other);
	}

	return *this;
}
