#include "./include/Scale.hpp"

// Constructors
Scale::Scale() : _f(false), _point(false), _of(false), _nan(false) ,_fval(0), _dval(0), _ival(0), _cval(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Scale\e[0m" << std::endl;
}

Scale::Scale(const Scale &copy) : _f(copy._f) , _point(copy._point) , _of(copy._of) , _nan(copy._nan) , _fval(copy._fval) , _dval(copy._dval) , _ival(copy._ival) , _cval(copy._cval) 
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Scale\e[0m" << std::endl;
}


// Destructor
Scale::~Scale()
{
	std::cout << "\e[0;31mDestructor called of Scale\e[0m" << std::endl;
}


// Operators
Scale & Scale::operator=(const Scale &assign)
{
	(void) assign;
	return *this;
}

void Scale::convert_char(std::string str)
{
	this->_cval = static_cast<char>(str[0]);
	this->_ival = static_cast<int>(this->_cval);
	this->_fval = static_cast<float>(this->_cval);
	this->_dval = static_cast<double>(this->_cval);
}

void Scale::convert_float(std::string str)
{
	this->_fval = static_cast<float>(std::atof(str.c_str()));
	this->_dval = static_cast<double>(this->_fval);
	if (this->_dval > INT_MAX || this->_dval < INT_MIN)
		this->_of = true;
	else
	{	
		this->_cval = static_cast<char>(this->_fval);
		this->_ival = static_cast<int>((this->_fval));
	}	
}

void Scale::convert_double(std::string str)
{
	this->_dval = std::atof(str.c_str());
	if (this->_dval > INT_MAX || this->_dval < INT_MIN)
	{
		this->_of = true;
		this->_fval = static_cast<float>(this->_dval);
	}
	else
	{
		this->_dval = static_cast<double>(std::atof(str.c_str()));
		this->_ival = static_cast<int>((this->_dval));
		this->_fval = static_cast<float>(this->_dval);
		this->_cval = static_cast<char>(this->_dval);
	}	
}

void Scale::convert_int(std::string str)
{
	this->_dval = std::atof(str.c_str());
	if (this->_dval > INT_MAX || this->_dval < INT_MIN)
	{
		this->_of = true;
		this->_fval = static_cast<float>(this->_dval);
	}
	else
	{
		this->_ival = static_cast<int>(std::atoi(str.c_str()));
		this->_cval = static_cast<char>(this->_ival);
		this->_fval = static_cast<float>(this->_ival);
		this->_dval = static_cast<double>(this->_ival);
	}	
}	



void Scale::check_type(std::string str)
{
	if (this->_f == true)
		this->convert_float(str);
	else if (this->_point == true)
		this->convert_double(str);
	else if (this->_nan != true)
		this->convert_int(str);
}

void Scale::is_a_number(std::string str)
{
	size_t i;
	size_t len;
	i = 0;
	len = str.length();
	if (str == "nan" || str == "nanf")
	{
		this->_nan = true;
		this->_dval = std::numeric_limits<double>::quiet_NaN();
		this->_fval = std::numeric_limits<float>::quiet_NaN();
		return ;
	}
	if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "inf" || str == "inff" )
	{
		this->_of = true;
		if (str[0] == '-')
		{
			this->_dval = -1 * std::numeric_limits<double>::infinity();
			this->_fval = -1 * std::numeric_limits<float>::infinity();
		}
		else
		{
			this->_dval = -1 * std::numeric_limits<double>::infinity();
			this->_fval = -1 * std::numeric_limits<float>::infinity();
		}
		return;
	}
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[len - 1] == 'f')
	{
		this->_f = true;
		len--;
	}	
	while (i < len)
	{
		if (str[i] == '.')
		{
			if (i == len - 1)
				throw Scale::FormatNumberException();
			if (this->_point == false)
				this->_point = true;
			else
				throw Scale::FormatNumberException();
		}
		else if (!isdigit(str[i]))
			throw Scale::NotDigitException();
		i++;
	}
	if (this->_f == true && this->_point == false)
		throw Scale::FormatNumberException();
	
}

void Scale::parsing(std::string str)
{
	int len;
	len = str.length();
	if (len == 1)
	{
		if (isdigit(str[0]))
			this->convert_int(str);
		else
			this->convert_char(str);
	}
	else
	{
		this->is_a_number(str);
		this->check_type(str);

	}
		
}

bool Scale::getOf( void) const
{
	return (this->_of);
}

char Scale::getChar( void) const
{
	return (this->_cval);
}

int Scale::getInt( void) const
{
	return (this->_ival);
}
float Scale::getFloat( void) const
{
	return (this->_fval);
}
double Scale::getDouble( void) const
{
	return (this->_dval);
}

bool Scale::getNan( void) const
{
	return (this->_nan);
}

std::ostream &operator<<(std::ostream &out, const Scale &c)
{

	//******** CHAR ********//
	if (c.getInt() > CHAR_MAX || c.getInt() < CHAR_MIN || c.getNan() || c.getOf())
		out << "char   : " << "Impossible" << std::endl;
	else if (!isprint(c.getInt()))
		out << "char   : " << "Non displayable" << std::endl;
	else
		out << "char   : '" << c.getChar() << "'" <<std::endl;

	//******** INT ********//
	if (c.getNan() || c.getOf() == true)
		out << "int    : " << "Impossible" << std::endl;
	else	
		out << "int    : " << c.getInt() << std::endl;

	//******** FLOAT ********//	
	if (c.getInt() == c.getFloat())
		out << "float  : " << c.getFloat() << ".0f" << std::endl;
	else
		out << "float  : " << c.getFloat() << "f" << std::endl;

	//******** DOUBLE ********//	
	if (c.getInt() == c.getDouble())	
		out << "double : " << c.getDouble() << ".0";
	else
		out << "double : " << c.getDouble();
	return out;
}