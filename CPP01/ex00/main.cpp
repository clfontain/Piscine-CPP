/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:42:19 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/15 12:26:06 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Zombie.hpp"

int main()
{

	Zombie zomblard("stackos");
	zomblard.announce();
	Zombie *test = newZombie("heapos");
	test->announce();
	randomChump("chumpos");
	delete test;
	return (0);
}

