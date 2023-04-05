
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
class Rpn
{
	public :
		Rpn();
		~Rpn();
		Rpn(const Rpn &cpy);
		Rpn &operator=(const Rpn &cpy);
		int process(std::string str);
		int is_operand(char c);
		int	switch_time(int a, int b, char op);
		int getTop( void ) const;
	private:
		std::stack<int> pile;

};

#endif
