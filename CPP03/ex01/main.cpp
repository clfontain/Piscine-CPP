/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:22:50 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/29 10:14:43 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/ClapTrap.hpp"
#include "./include/ScavTrap.hpp"

int main()
{
	ScavTrap a("Rene");
	ClapTrap b("Jean-Louis");
	ScavTrap c = a;
	ScavTrap d(a);
	d.attack("Robert");
	d.takeDamage(-8);
	d.guardGate();
	b.attack("Philippe");
	return (0);
}