/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:05:30 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/16 14:22:12 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/HumanB.hpp"

void HumanB::setWeapon( Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}

void HumanB::attack( void)
{
	std::cout <<  "attacks with their " << this->_weapon->getType() << std::endl;
}

HumanB::HumanB( std::string name) : _name(name)
{
	this->_weapon = NULL;
	return;
}

HumanB::~HumanB (void )
{
	return;
}