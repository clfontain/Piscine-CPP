#include "./include/RobotomyRequestForm.hpp"
#include "./include/Form.hpp"
#include "./include/Bureaucrat.hpp"


// Constructors
RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45), _target("default")
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("Robotomy", 72, 45), _target(target)
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy.getName(), copy.getSigned(), copy.getExec()), _target(copy._target)
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	(void)assign;
	return *this;
}

void RobotomyRequestForm::to_execute(Bureaucrat const & executor) const
{
	this->execute(executor);
	std::srand(std::time(0));
    int rand = std::rand();
	std::cout << "Vroom Vriim drill sounds" << std::endl;
	if (rand % 2 == 0)
		std::cout << "operation succeed on " << this->_target << std::endl;
	if (rand % 2 == 1)
		std::cout << "operation failed on" << this->_target << std::endl;
}