/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:50:28 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/18 17:05:58 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

	public:

		HumanB (std::string name);
		void attack( void );
		void setWeapon(Weapon &new_weapon);
		~HumanB ( void );

	private:
		std::string _name;
		Weapon *_weapon;
	
};

#endif