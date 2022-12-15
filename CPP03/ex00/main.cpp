
#include "./include/ClapTrap.hpp"

int main()
{
	ClapTrap test("jean louis");
	ClapTrap cpy(test);
	test.attack("René");
	test.takeDamage(8);
	test.beRepaired(-5);
	test.takeDamage(-15);
	cpy.attack("René");
	return (0);
}