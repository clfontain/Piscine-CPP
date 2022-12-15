#include "./include/Form.hpp"
#include "./include/Bureaucrat.hpp"

// Constructors
Form::Form()
	: _name("A38"), _state(false), _GradeSigned(150), _GradeExec(150)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}



Form::Form(const Form &copy)  : _name(copy._name), _state(copy._state), _GradeSigned(copy._GradeSigned), _GradeExec(copy._GradeExec)
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}



Form::Form(const std::string name, const int GradeSigned, const int GradeExec) :
	 _name(name), _state(false), _GradeSigned(GradeSigned), _GradeExec(GradeExec)
{	
	if (GradeSigned < 1 || GradeExec < 1)
		throw Form::GradeTooHighException();
	if (GradeSigned > 150 || GradeExec > 150)
		throw Form::GradeTooLowException();
}


Form & Form::operator=(const Form &cpy)
{
	this->_state = cpy._state;
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

std::string Form::getName( void ) const
{
	return (this->_name);
}

bool Form::getState( void) const
{
	return (this->_state);
}

int Form::getSigned( void ) const
{
    return (this->_GradeSigned);
}

int Form::getExec( void ) const
{
    return (this->_GradeExec);
}

std::ostream &operator<<(std::ostream &out, const Form &c)
{
	out << "Form : " << c.getName() << ", is signed ? " << c.getState() << ", grade Sign " << c.getSigned() << ", Grade Execution " << c.getExec();
	return (out);
}

void	Form::beSigned(const Bureaucrat &e)
{
	if (this->_state == false)
	{
		if (e.getGrade() <= this->getSigned())
			this->_state = true;
		else
			throw Form::GradeTooLowException();
	}
	else
		throw Form::AlreadySigned();
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExec())
		throw Form::GradeTooLowException();
	if (this->getState() == false)
		throw Form::IsnotSigned();
}		