
#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

protected:

public:
	Bureaucrat(void);
	Bureaucrat(const std::string& name, const int& grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat(void);
	
	std::string getName(void) const;
	int getGrade(void) const;
	void upGrade(void);
	void downGrede(void);

	Bureaucrat& operator=(const Bureaucrat& other);

public:
	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
