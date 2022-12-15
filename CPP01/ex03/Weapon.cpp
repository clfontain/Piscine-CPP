/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:57:02 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/16 12:25:38 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Weapon.hpp"

std::string &Weapon::getType(void)
{
	std::string &ref = _type;
	return (ref);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon( std::string name ) 
{
	this->_type = name;
	return;
}

Weapon::~Weapon (void )
{
	return;
}