
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm {
private: 
	std::string	_target;

protected: 

public: 
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);

	std::string getTarget(void) const;

	void execute(const Bureaucrat& executor) const;

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
};
