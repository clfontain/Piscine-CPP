#include "./include/ShrubberyCreationForm.hpp"
#include "./include/Form.hpp"
#include "./include/Bureaucrat.hpp"


// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137), _target("default")
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("Shrubbery", 145, 137), _target(target)
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy.getName(), copy.getSigned(), copy.getExec()), _target(copy._target)
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	(void)assign;
	return *this;
}

void ShrubberyCreationForm::to_execute(Bureaucrat const & executor) const
{
	this->execute(executor);
	std::string outfile_name = this->_target;
	outfile_name.append("_shrubbery");
	std::ofstream outfile(outfile_name.data());
	try
	{
		if (outfile.is_open() == false)
			throw Form::FilenotOpen();		
	}
	catch(const std::exception& e)
	{
		throw Form::FilenotOpen();
		
	}
	outfile << "              ,@@@@@@@, "<< std::endl;
	outfile << "      ,,,.   ,@@@@@@/@@,  .oo8888o. "<< std::endl;
	outfile << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o "<< std::endl;
	outfile << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' "<< std::endl;
	outfile << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' "<< std::endl;
	outfile << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' "<< std::endl;
	outfile << "  `&%\\ ` /%&'    |.|        \\ '|8' "<< std::endl;
	outfile << "      |o|        | |         | | "<< std::endl;
	outfile << "      |.|        | |         | | "<< std::endl;
	outfile << "   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ "<< std::endl;
	outfile.close();
}