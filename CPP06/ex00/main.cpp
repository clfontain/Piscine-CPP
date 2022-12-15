/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:57:02 by cfontain          #+#    #+#             */
/*   Updated: 2022/12/07 12:42:04 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>     
#include <math.h>
#include <iostream>
#include <iomanip>
#include "./include/Scale.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	Scale scale;
	try
	{
		scale.parsing(argv[1]);
		std::cout << scale << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	

	return (0);    
}