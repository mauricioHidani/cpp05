
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Intern {
private: 
	
protected: 
	AForm* makePresidentialPardon(const std::string& target);
	AForm* makeRobotomyRequest(const std::string& target);
	AForm* makeShrubberyCreation(const std::string& target);

public: 
	Intern(void);
	~Intern(void);

	AForm* makeForm(const std::string& name, const std::string& target);
};
