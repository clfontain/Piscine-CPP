/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:42:30 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/15 13:47:33 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:

		Zombie ( void );
		~Zombie ( void );
		void announce (void);
		void set_name(std::string name);
	private:
		std::string _name;
	
};

Zombie* zombieHorde( int N, std::string name );

#endif