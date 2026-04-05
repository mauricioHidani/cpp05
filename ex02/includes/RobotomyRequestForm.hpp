
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm {
private: 
	std::string	_target;

protected: 

public: 
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm(void);

	std::string getTarget(void) const;

	void execute(const Bureaucrat& executor) const;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};
