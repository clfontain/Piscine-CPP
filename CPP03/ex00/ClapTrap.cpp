#include "./include/ClapTrap.hpp"

void ClapTrap::attack(const std::string &target)
{
	if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
	else
	{	
		if (this->_EP != 0)
		{
 			this->_EP -= 1; 
			std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AP << " points of damage !" << std::endl; 
		}
		else
			std::cout << "ClapTrap " << this->_name << " has not enough energy points." << std::endl; 
	}		
}

// ClapTrap <name> attacks <target>, causing <damage> points of damage!

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((int)amount < 0)
	{
		std::cout << "ClapTrap " << this->_name << " Not a valid value." << std::endl; 
		return;
	}
	if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
	else
	{
		if (this->_EP != 0)
		{
 			this->_EP -= 1;
 			this->_HP += amount;
			std::cout << "ClapTrap " << this->_name << " recover " << amount << " hit points !" << std::endl; 
		}
		else
			std::cout << "ClapTrap " << this->_name << " has not enough energy points." << std::endl; 
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount < 0)
	{
		std::cout << "ClapTrap " << this->_name << " Not a valid value." << std::endl; 
		return;
	}	
	if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " take " << amount << " damage, ouille ouille ouille !" << std::endl; 
		if (this->_HP > 0)
 			this->_HP -= amount;
		if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead, RIP !" << std::endl; 
	}
}




ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AP(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &p)
{
	std::cout << "Copy assignement operation called" << std::endl;
	this->_name = p._name;
	this->_HP = p._HP;
	this->_EP = p._EP;
	this->_AP = p._AP;

	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &p)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(p);
}


ClapTrap::ClapTrap(): _HP(10), _EP(10), _AP(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}