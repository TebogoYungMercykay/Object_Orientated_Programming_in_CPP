#include "vector.h"

#include <iostream>
#include <fstream>
#include <iomanip>

Vector::Vector(unsigned s)
{
    this -> size = s;

    vector = new double[size];

    for(int i = 0; i < size; i++)
    {
        vector[i] = 0;
    }
}

Vector::Vector(const Vector &rhs)
{
    this -> size = rhs.size;

    vector = new double[size];

    for(int i = 0; i < size; i++)
    {
        vector[i] = rhs.vector[i];
    }
}

Vector::~Vector()
{
    delete [] vector;
    vector = NULL;
}

const Vector& Vector::operator=(const Vector& rhs)
{
    if(this != &rhs)
    {
        delete [] vector;
        vector = NULL;
        size = rhs.size;
        vector = new double[rhs.size];
        for(int i = 0; i < size; i++)
        {
            vector[i] = rhs.vector[i];
        }
    }
        
    return *this;
}

void Vector::readFile(istream &infile)
{
    for(int i = 0; i < size; i++)
    {
        infile >> vector[i];
    }
}

void Vector::print()
{
    for(int s = 0; s < size; s++)
    {
        cout << setw(10) << setprecision(3) << vector[s];
    }
    cout << endl;
}

double& Vector::operator[](const unsigned r)
{
    if(r >= size || r < 0)
    {
        throw "Error: invalid row index";
    }
    return vector[r];
}

const double& Vector::operator[](const unsigned r) const
{
    if(r >= size || r < 0)
    {
        throw "Error: invalid row index";
    }
    return vector[r];
}

unsigned Vector::getSize() const
{
    return size;
}

Vector operator*(const double& j, const Vector& k)
{
    Vector temp(k.size);

    for(int i = 0; i < k.size; i++)
    {
        temp.vector[i] = j * k.vector[i];
    }

    return temp;
}

Vector Vector::operator*(const double& rhs)
{
    Vector temp(size);

    for(int i = 0; i < size; i++)
    {
        temp.vector[i] = rhs * vector[i];
    }

    return temp;
}

Vector& Vector::operator*=(const double& rhs)
{
    for(int i = 0; i < size; i++)
    {
        vector[i] = rhs * vector[i];
    }

    return *this;
}

Vector Vector::operator/(const double& rhs)
{
    Vector temp(size);
    if(rhs == 0)
    {
        throw "Error: division by zero";
    }

    else
    {
        for(int i = 0; i < size; i++)
        {
            temp.vector[i] = vector[i] / rhs;
        }
    }

    return temp;
}

Vector Vector::operator+(const Vector& rhs)
{
    Vector temp(size);

    if(size != rhs.size)
    {
        throw "Error: adding vectors of different dimensionality";
        return rhs;
    }

    else
    {
        for(int i = 0; i < size; i++)
        {
            temp.vector[i] = vector[i] + rhs.vector[i];
        }
    }

    return temp;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    if(size != rhs.size)
    {
        throw "Error: adding vectors of different dimensionality";
        return *this;
    }

    else
    {
        for(int i = 0; i < size; i++)
        {
            vector[i] = vector[i] + rhs.vector[i];
        }
    }

    return *this;
}

Vector Vector::operator-(const Vector& rhs)
{
    Vector temp(size);

    if(size != rhs.size)
    {
        throw "Error: subtracting vectors of different dimensionality";
        return rhs;
    }

    else
    {
        for(int i = 0; i < size; i++)
        {
            temp.vector[i] = vector[i] - rhs.vector[i];
        }
    }

    return temp;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    if(size != rhs.size)
    {
        throw "Error: subtracting vectors of different dimensionality";
        return *this;
    }

    else
    {
        for(int i = 0; i < size; i++)
        {
            vector[i] = vector[i] - rhs.vector[i];
        }
    }

    return *this;
}

Vector Vector::operator^(int pow)
{
    if(pow < 0)
    {
        throw "Error: negative power is not supported";
        return *this;
    }
    if(pow == 0)
    {
        Vector temp(size);

        for(int i = 0; i < size; i++)
        {
            temp.vector[i] = 1;
        }

        return temp;
    }
    else
    {
        Vector temp(*this);

        for(int i = 1; i < pow; i++)
        {
            for(int j = 0; j < size; j++)
            {
                temp.vector[j] = temp.vector[j] * vector[j];
            }
            
        }

        return temp;
    }
}

Vector& Vector::operator^=(int pow)
{
    if(pow < 0)
    {
        throw "Error: negative power is not supported";
        return *this;
    }
    if(pow == 0)
    {
        Vector temp(size);

        for(int i = 0; i < size; i++)
        {
            temp.vector[i] = 1;
        }

        *this = temp;
        return *this;
    }
    else
    {
        Vector temp(*this);

        for(int i = 1; i < pow; i++)
        {
            for(int j = 0; j < size; j++)
            {
                temp.vector[j] = temp.vector[j] * vector[j];
            }
            
        }

        *this = temp;
        return *this;
    }
}

Vector Vector::operator~()
{
    Vector temp(size);

    int j = size - 1;

    for(int i = 0; i < size; i++)
    {
        temp.vector[j] = vector[i];
        j--;
    }

    return temp;
}