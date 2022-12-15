/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:42:30 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/18 16:54:23 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:

		Zombie (std::string name);
		~Zombie ( void );
		void announce (void);

	private:
		std::string _name;
	
};

Zombie* newZombie( std::string name);
void randomChump (std::string name);

#endif