/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:26:31 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/15 12:26:33 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Zombie.hpp"

void randomChump(std::string name)
{
	Zombie new_zombie(name);
	new_zombie.announce();
	return ;
}