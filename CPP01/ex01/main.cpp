/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:42:19 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/18 16:57:22 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Zombie.hpp"

int main()
{
	int n;

	n = 14;
	Zombie *horde = zombieHorde(n, "Jean-Louis");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}

