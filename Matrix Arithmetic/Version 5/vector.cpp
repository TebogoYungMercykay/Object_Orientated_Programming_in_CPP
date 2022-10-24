#include "vector.h"
#include <iomanip>

Vector operator*(const double& multipler, const Vector& rhs)
{
	Vector obj(rhs.getSize());
	for(int c=0;c<rhs.getSize();c++)
	{
		obj.vector[c]=multipler*rhs.vector[c];
	}
	return obj;
}
Vector::Vector(unsigned s)
{
	this->size = s;
	this->vector = new double[this->getSize()];
	for(int c=0;c<this->getSize();c++)
	{
		this->vector[c] = 0;
	}
}
Vector::Vector(const Vector& rhs)
{
	this->size = rhs.getSize();
	this->vector = new double[this->getSize()];
	for(int c=0;c<this->getSize();c++)
	{
		this->vector[c] = rhs.vector[c];
	}
}
Vector::~Vector()
{
	delete [] this->vector;
	this->vector = NULL;
}

void Vector::print()
{
	for(int G=0;G<this->getSize();G++)
	{	
		std::cout<<setw(10);
		std::cout<<this->vector[G]<<setprecision(3);
	}
	std::cout<<"\n";
}
void Vector::readFile(istream &infile)
{
	for(int G=0;G<this->getSize();G++)
	{ 	
		infile>>this->vector[G];
	}
}

// Insert overloaded = operator signature
const Vector& Vector::operator=(const Vector& rhs)
{
	if(this == &rhs) return *this;
	this->size = rhs.getSize();
	this->vector = new double[this->getSize()];
	for(int c=0;c<this->getSize();c++)
	{
		this->vector[c] = rhs.vector[c];
	}
	return *this;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector& rhs)
{
	Vector Mat_Array(rhs.getSize());
	if(this->getSize() != rhs.getSize())
	{
		throw "Error: adding vectors of different dimensionality";
	}
	else
	{
		for(int Index=0; Index<rhs.getSize(); Index++)
		{
			Mat_Array.vector[ Index]=this->vector[ Index]+rhs.vector[ Index];
		}
	}
	return Mat_Array;
}
Vector& Vector::operator+=(const Vector& rhs)
{
	if(this->getSize() != rhs.getSize())
	{
		throw "Error: adding vectors of different dimensionality";
	}
	else
	{
		for(int Index=0; Index<rhs.getSize(); Index++)
		{
			this->vector[ Index]=this->vector[ Index]+rhs.vector[ Index];
		}
	}
	return *this;
}
Vector Vector::operator-(const Vector& rhs)
{
	Vector Mat_Array(rhs.getSize());
	if(this->getSize() != rhs.getSize())
	{
		throw "Error: subtracting vectors of different dimensionality";
	}
	else
	{
		for(int Index=0; Index<rhs.getSize(); Index++)
		{
			Mat_Array.vector[ Index]=this->vector[ Index]-rhs.vector[ Index];
		}
	}
	return Mat_Array;
}
Vector& Vector::operator-=(const Vector& rhs)
{
	if(this->getSize() != rhs.getSize())
	{
		throw "Error: subtracting vectors of different dimensionality";
	}
	else
	{
		for(int Index=0; Index<rhs.getSize(); Index++)
		{
			this->vector[ Index]=this->vector[ Index]-rhs.vector[ Index];
		}
	}
	return *this;
}
Vector Vector::operator^(int pow)
{
	Vector Mat_Array2(*this);
	if(pow<0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		if(pow==0)
		{
			for(int Index=0;Index<this->getSize();Index++)
			{
				Mat_Array2.vector[ Index]=1;
			}
			return Mat_Array2;
		}
		else if(pow==1)
		{
			return Mat_Array2;
		}
		else if(pow>1)
		{
			for(int Index=0; Index<Mat_Array2.getSize(); Index++)
			{
				double temp1 = Mat_Array2.vector[ Index];
				double temp2 = Mat_Array2.vector[ Index];
				for(int Index=0;Index<(pow-1);Index++)
				{
					temp1*=temp2;
				}
				Mat_Array2.vector[ Index] = temp1;
			}
			return Mat_Array2;
		}
            
	}
	return Mat_Array2;
}
Vector& Vector::operator^=(int pow)
{
	if(pow<0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		if(pow==0)
		{
			for(int Index=0;Index<this->getSize();Index++)
			{
				this->vector[ Index]=1;
			}
			return *this;
		}
		else if(pow==1)
		{
			return *this;
		}
		else if(pow>1)
		{
			for(int Index=0; Index<this->getSize(); Index++)
			{
				double temp1 = this->vector[ Index];
				double temp2 = this->vector[ Index];
				for(int Index=0;Index<(pow-1);Index++)
				{
					temp1*=temp2;
				}
				this->vector[ Index] = temp1;
			}
		}
	}
	return *this;
}


// Vector/scalar operations
Vector Vector::operator*(const double& rhs)
{
	Vector Mat_Array(this->getSize());
	for(int Index=0; Index<this->getSize(); Index++)
	{
		Mat_Array.vector[ Index]=this->vector[ Index]*rhs;
	}
	return Mat_Array;
}
Vector& Vector::operator*=(const double& rhs)
{
	for(int Index=0; Index<this->getSize(); Index++)
	{
		this->vector[ Index]=this->vector[ Index]*rhs;
	}
	return *this;
}
Vector Vector::operator/(const double& rhs)
{
	Vector Mat_Array(this->getSize());
	if(rhs==0)
	{
		throw "Error: division by zero";
	}
	else
	{
		for(int Index=0; Index<this->getSize(); Index++)
		{
			Mat_Array.vector[ Index]=this->vector[ Index]/rhs;
		}
	}
	return Mat_Array;
}


// Access the individual elements
double& Vector::operator[](const unsigned r)
{
	if(r<0 || r>=this->size)
	{
		throw "Error: invalid row i";
	}
	return this->vector[r];
}
const double& Vector::operator[](const unsigned r) const{
	if(r<0 || r>=this->size)
	{
		throw "Error: invalid row i";
	}
	return this->vector[r];
}


// Getters and setters:
unsigned Vector::getSize() const{
	return this->size;
} // Return number of rows

Vector Vector::operator~()
{
	Vector Mat_Array(this->getSize());
	for(int Index=0; Index<this->getSize(); Index++)
	{
		Mat_Array.vector[Index] = this->vector[(this->getSize()-1)-Index];
	}
    return Mat_Array;
} // reverse