
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {
private: 
	std::string	_target;

protected: 

public: 
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);

	std::string getTarget(void) const;

	void execute(const Bureaucrat& executor) const;

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};
