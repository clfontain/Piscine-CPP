/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:49:35 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/16 12:25:13 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>


class Weapon {

	public:

		Weapon (std::string name);
		~Weapon ( void );
		std::string &getType();
		void setType(std::string type);
	private:
		std::string _type;
	
};


#endif