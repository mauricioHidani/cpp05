
#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_signed;

public:
	Form(void);
	Form(const std::string name, const int& gradeToSign, const int& gradeToExecute);
	Form(const Form& other);
	~Form(void);

	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool isSigned(void) const;
	
	void beSigned(Bureaucrat& bureaucrat);

	Form& operator=(const Form& other);

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

std::ostream& operator<<(std::ostream& out, const Form& obj);