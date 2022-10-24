#include "vector.h"
#include <iomanip>

Vector operator*(const double& m, const Vector& rhs){
	const int vec_size = rhs.getSize();
	Vector object_Vector(vec_size);
	for(int c=0; c<vec_size; c++){
		object_Vector.vector[c] = m*rhs.vector[c];
	}
	return object_Vector;
}
Vector::Vector(unsigned s){
	const int vec_size = s;
	Vector::vector = new double[vec_size];
	for(int c=0;c<vec_size;c++){
		Vector::vector[c] = 0;
	}
	Vector::size = vec_size;
}
Vector::Vector(const Vector& rhs){
	const int vec_size = rhs.getSize();
	Vector::vector = new double[vec_size];
	for(int c=0;c<vec_size;c++){
		Vector::vector[c] = rhs.vector[c];
	}
	Vector::size = vec_size;
}
Vector::~Vector(){
	delete [] Vector::vector;
	Vector::vector = NULL;
}

void Vector::print(){
	const int vec_size = Vector::getSize();
	for(int c=0;c<vec_size;c++){
		std::cout<<setw(10)<<Vector::vector[c]<<setprecision(3);
	}
	std::cout<<std::endl;
}
void Vector::readFile(istream &infile){
	const int vec_size = Vector::getSize();
	for(int c=0;c<vec_size;c++){
		infile>>Vector::vector[c];
	}
}

// Insert overloaded = operator signature
const Vector& Vector::operator=(const Vector& rhs){
	if(this == &rhs) return *this;
	else{
		const int vec_size = rhs.getSize();
		Vector::vector = new double[vec_size];
		for(int c=0;c<vec_size;c++){
			Vector::vector[c] = rhs.vector[c];
		}
		Vector::size = vec_size;
	}
	return *this;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector& rhs){
	if(Vector::getSize() != rhs.getSize()){
		throw "Error: adding vectors of different dimensionality";
	}
	else{
		const int vec_size = rhs.getSize();
		Vector object_Vector(vec_size);
		for(int c=0; c<vec_size; c++){
			object_Vector.vector[c]=Vector::vector[c]+rhs.vector[c];
		}
		return object_Vector;
	}
}
Vector& Vector::operator+=(const Vector& rhs){
	if(Vector::getSize() != rhs.getSize()){
		throw "Error: adding vectors of different dimensionality";
	}
	else{
		const int vec_size = rhs.getSize();
		Vector object_Vector(vec_size);
		for(int c=0; c<vec_size; c++){
			object_Vector.vector[c]=Vector::vector[c]+rhs.vector[c];
		}
		*this = object_Vector;
		return *this;
	}
}
Vector Vector::operator-(const Vector& rhs){
	if(Vector::getSize() != rhs.getSize()){
		throw "Error: subtracting vectors of different dimensionality";
	}
	else{
		const int vec_size = rhs.getSize();
		Vector object_Vector(vec_size);
		for(int c=0; c<vec_size; c++){
			object_Vector.vector[c]=Vector::vector[c]-rhs.vector[c];
		}
		return object_Vector;
	}
}
Vector& Vector::operator-=(const Vector& rhs){
	if(Vector::getSize() != rhs.getSize()){
		throw "Error: subtracting vectors of different dimensionality";
	}
	else{
		const int vec_size = rhs.getSize();
		Vector object_Vector(vec_size);
		for(int c=0; c<vec_size; c++){
			object_Vector.vector[c]=Vector::vector[c]-rhs.vector[c];
		}
		*this = object_Vector;
		return *this;
	}
}
Vector Vector::operator^(int pow){
	if(pow<0){
		throw "Error: negative power is not supported";
    }
	else{
		if(pow==0){
			const int vec_size = Vector::getSize();
			Vector object_Vector(*this);
			for(int c=0; c<vec_size; c++){
				object_Vector.vector[c]=1;
			}
			return object_Vector;
		}
		else{
			const int vec_size = Vector::getSize();
			Vector object_Vector(*this);
			for(int c=0; c<vec_size; c++){
				double temp1 = object_Vector.vector[c], temp2 = temp1;
				for(int c2=0; c2<pow-1; c2++){
					temp1*=temp2;
				}
				object_Vector.vector[c] = temp1;
			}
			return object_Vector;
		}
            
	}
	Vector object_Vector(*this);
	return object_Vector;
}
Vector& Vector::operator^=(int pow){
	if(pow<0){
		throw "Error: negative power is not supported";
    }
	else{
		if(pow==0){
			const int vec_size = Vector::getSize();
			Vector object_Vector(*this);
			for(int c=0; c<vec_size; c++){
				object_Vector.vector[c]=1;
			}
			*this = object_Vector;
		}
		else{
			const int vec_size = Vector::getSize();
			Vector object_Vector(*this);
			for(int c=0; c<vec_size; c++){
				double temp1 = object_Vector.vector[c], temp2 = temp1;
				for(int c2=0; c2<pow-1; c2++){
					temp1*=temp2;
				}
				object_Vector.vector[c] = temp1;
			}
			*this = object_Vector;
		}
            
	}
	return *this;
}

// Vector/scalar operations
Vector Vector::operator*(const double& rhs){
	const int vec_size = Vector::getSize();
	Vector object_Vector(vec_size);
	for(int c=0; c<vec_size; c++){
		object_Vector.vector[c]=Vector::vector[c]*rhs;
	}
	return object_Vector;
}
Vector& Vector::operator*=(const double& rhs){
	const int vec_size = Vector::getSize();
	Vector object_Vector(vec_size);
	for(int c=0; c<vec_size; c++){
		object_Vector.vector[c]=Vector::vector[c]*rhs;
	}
	*this = object_Vector;
	return *this;
}
Vector Vector::operator/(const double& rhs){
	if(rhs==0){
		throw "Error: division by zero";
	}
	else{
		const int vec_size = Vector::getSize();
		Vector object_Vector(vec_size);
		for(int c=0; c<vec_size; c++){
			object_Vector.vector[c]=Vector::vector[c]/rhs;
		}
		return object_Vector;
	}
}

// Access the individual elements
double& Vector::operator[](const unsigned r){
	if(r<0 || r>=size)
    {
        throw ("Error: invalid row index");
    }
	return Vector::vector[r];
}
const double& Vector::operator[](const unsigned r) const{
	if(r<0 || r>=size)
    {
        throw ("Error: invalid row index");
    }
	return Vector::vector[r];
}

unsigned Vector::getSize() const{
	return Vector::size;
}

Vector Vector::operator~(){
	const int vec_size = Vector::getSize();
	Vector object_Vector(vec_size);
	for(int c=0; c<vec_size; c++){
		object_Vector.vector[c] = Vector::vector[(Vector::getSize()-1)-c];
	}
	return object_Vector;
}