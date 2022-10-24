#include "vector.h"
#include <iomanip>
using namespace std;

Vector operator*(const double& m, const Vector& rhs)
{
	Vector var_Vector(rhs);
	var_Vector = var_Vector * (m);
	return var_Vector;
}

Vector::Vector(unsigned s)
{
	int c = 0;
	vector = new double[s];
	while( c < s )
	{
		(*(vector + c)) = 0;
		c += 1;
	}
	size = s;
}

Vector::Vector(const Vector& rhs)
{
	vector = new double[rhs.size];
	int c = 0;
	while( c < rhs.size )
	{
		(*(vector + c)) = (*(rhs.vector + c));
		c += 1;
	}
	size = rhs.size;
}

Vector::~Vector()
{
	delete [] vector;
	vector = NULL;
}

void Vector::print()
{
	int c = 0;
	while( c < size )
	{
		cout<<setw(10)<<(*(vector + c))<<setprecision(3);
		c += 1;
	}
	cout<<endl;
}
void Vector::readFile(istream &infile)
{
	int c = 0;
	while( c < size )
	{
		infile>>(*(vector + c));
		c += 1;
	}
}

// Insert overloaded = operator signature
const Vector& Vector::operator=(const Vector& rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	else
	{
		size = rhs.size;
		vector = new double[rhs.size];
		int c = 0;
		while( c < rhs.size )
		{
			(*(vector + c)) = (*(rhs.vector + c));
			c += 1;
		}
	}
	return *this;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector& rhs)
{
	if(size != rhs.size)
	{
		throw "Error: adding vectors of different dimensionality";
	}
	else
	{
		Vector var_Vector(rhs.size);
		int c = 0;
		while( c < rhs.size )
		{
			(*(var_Vector.vector + c)) = (*(vector + c)) + (*(rhs.vector + c));
			c += 1;
		}
		return var_Vector;
	}
}
Vector& Vector::operator+=(const Vector& rhs)
{
	*this = (this->operator+(rhs));
	return *this;
}
Vector Vector::operator-(const Vector& rhs)
{
	if(size != rhs.size)
	{
		throw "Error: subtracting vectors of different dimensionality";
	}
	else
	{
		Vector var_Vector(rhs.size);
		int c = 0;
		while( c < rhs.size )
		{
			(*(var_Vector.vector + c)) = (*(vector + c)) - (*(rhs.vector + c));
			c += 1;
		}
		return var_Vector;
	}
}
Vector& Vector::operator-=(const Vector& rhs)
{
	*this = (this->operator-(rhs));
	return *this;
}
Vector Vector::operator^(int pow)
{
	if(pow==0)
	{
		Vector var_Vector(*this);
		int c = 0;
		while( c < size )
		{
			(*(var_Vector.vector + c)) = 1;
			c += 1;
		}
		return var_Vector;
	}
	if(pow<0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		Vector var_Vector(*this);
		int c = 0;
		while( c < size )
		{
			double var_1 = (*(var_Vector.vector + c)), var_2 = var_1;
			int c2 = 0;
			while(  c2 < pow-1 )
			{
				var_1 *= var_2;
				c2 += 1;
			}
			(*(var_Vector.vector + c)) = var_1;
			c += 1;
		}
		return var_Vector;
	}
	Vector var_Vector(*this);
	return var_Vector;
}
Vector& Vector::operator^=(int pow)
{
	*this = (this->operator^(pow));
	return *this;
}

// Vector/scalar operations
Vector Vector::operator*(const double& rhs)
{
	Vector var_Vector(size);
	int c = 0;
	while( c < size )
	{
		(*(var_Vector.vector + c)) = (*(vector + c)) * rhs;
		c += 1;
	}
	return var_Vector;
}
Vector& Vector::operator*=(const double& rhs)
{
	*this = (this->operator*(rhs));
	return *this;
}
Vector Vector::operator/(const double& rhs)
{
	if(rhs == 0)
	{
		throw "Error: division by zero";
	}
	else
	{
		Vector var_Vector(size);
		int c = 0;
		while( c < size )
		{
			(*(var_Vector.vector + c)) = (*(vector + c)) / rhs;
			c += 1;
		}
		return var_Vector;
	}
}

// Access the individual elements
double& Vector::operator[](const unsigned r)
{
	if(r < 0 || r >= size)
	{
		throw "Error: invalid row index";
	}
	return vector[r];
}
const double& Vector::operator[](const unsigned r) const
{
	if(r < 0 || r >= size)
	{
		throw "Error: invalid row index";
	}
	return vector[r];
}

unsigned Vector::getSize() const
{
	return size;
}

Vector Vector::operator~()
{
	Vector var_Vector(size);
	int c = 0;
	while( c < size )
	{
		(*(var_Vector.vector + c)) = (*(vector + ((size-1) - c)));
		c += 1;
	}
	return var_Vector;
}