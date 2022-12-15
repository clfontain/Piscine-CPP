#include "./include/PresidentialPardonForm.hpp"
#include "./include/Form.hpp"
#include "./include/Bureaucrat.hpp"


// Constructors
PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5), _target("default")
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("Presidential", 25, 5), _target(target)
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy.getName(), copy.getSigned(), copy.getExec()), _target(copy._target)
{
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	(void)assign;
	return *this;
}

void PresidentialPardonForm::to_execute(Bureaucrat const & executor) const
{
	this->execute(executor);
	std::cout << this->_target << " was pardoned by Zaphod Beeblebrox" << std::endl;

}