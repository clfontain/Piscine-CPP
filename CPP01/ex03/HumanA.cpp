/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:35:59 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/16 14:00:54 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/HumanA.hpp"

void HumanA::attack( void)
{
	std::cout <<  "attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA (void )
{
	return;
}