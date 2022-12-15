#include "./include/ScavTrap.hpp"

void ScavTrap::attack(const std::string &target)
{
	if (this->_HP <= 0)
		std::cout << "ScavTrap " << this->_name << " is dead !" << std::endl;
	else
	{	
		if (this->_EP != 0)
		{
 			this->_EP -= 1; 
			std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_AP << " points of damage !" << std::endl; 
		}
		else
			std::cout << "ScavTrap " << this->_name << " has not enough energy points." << std::endl; 
	}		
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in gate keeper mode" << std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &p) 
{
	ClapTrap::operator=(p);
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &p)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->operator=(p);
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_HP = 100;
	this->_EP = 50;
	this->_AP = 20;
		std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_HP = 100;
	this->_EP = 50;
	this->_AP = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}