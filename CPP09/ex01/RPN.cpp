#include "RPN.hpp"

Rpn::Rpn()
{

}

Rpn::~Rpn(){

}
Rpn::Rpn(const Rpn &cpy)
{
	this->pile = cpy.pile;
}
Rpn &Rpn::operator=(const Rpn &cpy)
{
	this->pile = cpy.pile;
	return (*this);
}

int Rpn::is_operand(char c)
{
	if (c != '*' && c != '/' && c != '-' && c != '+')
		return (0);
	else
		return (1);
}

int	Rpn::switch_time(int a, int b, char op)
{
	switch(op)
	{
		case '+':
			pile.push(a + b);
			break;
		case '-':
			pile.push(a - b);
			break;
		case '/':
			if (b == 0)
			{
				std::cout << "Error\n Impossible division\n";
				return (1);
			}
			pile.push(a / b);
			break;
		case '*':
			pile.push(a * b);
			break;
		default:
		{
			std::cout << "Error\n";
			return (1);
		}	


	}	
	return (0);
}

int Rpn::getTop( void ) const
{
	return (pile.top());
}

int Rpn::process(std::string str)
{
	int a;
	int b;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (isspace(str[i]))
			continue;
		if (isdigit(str[i]))
		{
			if (i != 1 && isdigit(str[i - 1]) == 0)
				pile.push((str[i] - 48));
			else
			{
				std::cout << "ERROR\ntoo big range number\n";
				return (1);
			}
		}
		else if (is_operand(str[i]))
		{
			if (pile.size() >= 2)
			{
				a = pile.top();
				pile.pop();
				b = pile.top();
				pile.pop();
				if (switch_time(a, b, str[i]) == 1)
					return (1);
			}
			else
			{
				std::cout << "ERROR\nNot enough number in stack\n";
				return (1);
			}
		}
		else
		{
			std::cout << "ERROR\nNot a valid char\n";
			return (1);
		}

	}
	if (pile.size() != 1)
	{
		std::cout << "ERROR\nNot enough operant in stack\n";
		return (1);
	}	
	else
		return (0);
}
