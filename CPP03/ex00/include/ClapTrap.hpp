#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string.h>
#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _HP;
        int _EP;
        int _AP;
        
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &p);
        ClapTrap &operator=(const ClapTrap &p);
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    
};

#endif