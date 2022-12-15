/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:34:35 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/15 15:00:17 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{

	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].set_name(name);
	}
	return (horde);
}