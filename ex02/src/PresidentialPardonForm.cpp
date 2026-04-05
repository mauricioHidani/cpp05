
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("Presidential Pardon", 25, 5),
		_target("undefined") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:	AForm("Presidential Pardon", 25, 5),
		_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
		_target(other.getTarget()) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw UnsignedFormException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	
	std::cout << getTarget() << " was forgiven by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(other);
	}

	return *this;
}
