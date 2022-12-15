/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:50:08 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/16 13:59:00 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

	public:

		HumanA (std::string name, Weapon& weapon);
		void attack( void );
		~HumanA ( void );

	private:
		std::string _name;
		Weapon& _weapon;
	
};

#endif