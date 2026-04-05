
#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_signed;

public:
	AForm(void);
	AForm(const std::string name, const int& gradeToSign, const int& gradeToExecute);
	AForm(const AForm& other);
	~AForm(void);

	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool isSigned(void) const;
	
	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& bureaucrat) const = 0;

public:
	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class UnsignedFormException: public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);