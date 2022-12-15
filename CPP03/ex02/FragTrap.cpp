#include "./include/FragTrap.hpp"

void FragTrap::attack(const std::string &target)
{
	if (this->_HP <= 0)
		std::cout << "FragTrap " << this->_name << " is dead !" << std::endl;
	else
	{	
		if (this->_EP != 0)
		{
 			this->_EP -= 1; 
			std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_AP << " points of damage !" << std::endl; 
		}
		else
			std::cout << "FragTrap " << this->_name << " has not enough energy points." << std::endl; 
	}		
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap needs high fives" << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &p) 
{
	ClapTrap::operator=(p);
	return (*this);
}

FragTrap::FragTrap(const FragTrap &p)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->operator=(p);
}


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_HP = 100;
	this->_EP = 100;
	this->_AP = 30;
		std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	this->_HP = 100;
	this->_EP = 100;
	this->_AP = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}