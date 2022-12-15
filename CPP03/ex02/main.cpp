/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:22:50 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/29 10:14:56 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/ClapTrap.hpp"
#include "./include/ScavTrap.hpp"
#include "./include/FragTrap.hpp"

int main()
{
	ClapTrap b("Jacques");
	FragTrap a("Jean-Jean");
	b.attack("nothing");
	a.highFivesGuys();
	return (0);
}