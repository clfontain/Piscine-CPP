#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe") ,_grade(0)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : _name(cpy._name)
{
    *this = cpy;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &cpy)
{
    this->_grade = cpy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}


// Getters

std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (this->_grade);
}

// Setters

void Bureaucrat::setGrade(const int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();    
    this->_grade = grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", Bureaucrat grade " <<c.getGrade();
	return (out);
}

void    Bureaucrat::incrementGrade( void )
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::decrementGrade( void )
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

void Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.to_execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
    
    
}