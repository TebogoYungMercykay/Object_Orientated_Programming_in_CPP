#include "matrix.h"
#include <iomanip>
using namespace std;

Matrix operator*(const double& m, const Matrix& second_mat)
{
	Matrix var_Mat(second_mat);
	var_Mat = var_Mat * (m);
    return var_Mat;
}
  
Matrix::Matrix(unsigned ro, unsigned co)
{
	matrix = new double * [ro];
	int r = 0;
	rows = ro;
	cols = co;
	while( r < ro )
	{
		matrix[r] = new double [co];
        int c = 0;
		while( c < co )
		{
            (*(*(matrix + r) + c)) = 0;
			c += 1;
        }
		r += 1;
    }
}

Matrix::Matrix(const Matrix& second_mat)
{
	matrix = new double*[second_mat.rows];
	int r = 0;
	rows = second_mat.rows;
	cols = second_mat.cols;
	while( r < second_mat.rows )
	{
		matrix[r] = new double [second_mat.cols];
        int c = 0;
		while( c < second_mat.cols )
		{
            (*(*(matrix + r) + c)) = (*(*(second_mat.matrix + r) + c));
			c += 1;
        }
		r += 1;
    }
}

Matrix::~Matrix()
{
	if(Matrix::matrix!=NULL)
	{
		int r = 0;
		while( r < rows )
		{
			delete [] matrix[r];
			matrix[r] = NULL;
			r += 1;
		}
		delete matrix;
		matrix = NULL;
	}
}

void Matrix::print()
{
	int r = 0;
	while( r < rows )
	{
        int c = 0;
		while( c < cols )
		{
			cout << setw(10) << (*(*(matrix + r) + c)) << setprecision(3);
			c += 1;
        }
		cout<<"\n";
		r += 1;
    }
}
void Matrix::readFile(istream &infile)
{
	int r = 0;
	while( r < rows )
	{
        int c = 0;
		while( c < cols )
		{
			infile>>(*(*(matrix + r) + c));
			c += 1;
        }
		r += 1;
    }
}

// Insert overloaded = operator signature
const Matrix& Matrix::operator=(const Matrix& second_mat)
{
	if(this != &second_mat)
	{
		matrix = new double*[second_mat.rows];
		int r = 0;
		rows = second_mat.rows;
		cols = second_mat.cols;
		while( r < second_mat.rows )
		{
			matrix[r] = new double [second_mat.cols];
			int c = 0;
			while( c < second_mat.cols )
			{
				(*(*(matrix + r) + c)) = (*(*(second_mat.matrix + r) + c));
				c += 1;
			}
			r += 1;
		}
	}
	return *this;
}

// Matrix mathematical operations
Matrix Matrix::operator+(const Matrix& second_mat)
{
	if(rows != second_mat.rows)
	{	
		throw "Error: adding matrices of different dimensionality";
	}
	else if(cols != second_mat.cols)
	{	
		throw "Error: adding matrices of different dimensionality";
	}
	else
	{
		Matrix var_Mat(second_mat.rows, second_mat.cols);
		int r = 0;
		while( r < second_mat.rows )
		{
			int c = 0;
			while( c < second_mat.cols )
			{
				(*(*(var_Mat.matrix + r) + c)) = (*(*(matrix + r) + c)) + (*(*(second_mat.matrix + r) + c));
				c += 1;
			}
			r += 1;
		}
		return var_Mat;
	}
}
Matrix& Matrix::operator+=(const Matrix& second_mat)
{
	*this = (this->operator+(second_mat));
	return *this;
}
Matrix Matrix::operator-(const Matrix& second_mat)
{
	if(cols != second_mat.cols)
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else if(rows != second_mat.rows)
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else
	{
		Matrix var_Mat(second_mat.rows, second_mat.cols);
		int r = 0;
		while( r < second_mat.rows )
		{
			int c = 0;
			while( c < second_mat.cols )
			{
				(*(*(var_Mat.matrix + r) + c)) = (*(*(matrix + r) + c)) - (*(*(second_mat.matrix + r) + c));
				c += 1;
			}
			r += 1;
		}
		return var_Mat;
	}
}
Matrix& Matrix::operator-=(const Matrix& second_mat)
{
	*this = (this->operator-(second_mat));
	return *this;
}

// Matrix/scalar operations
Matrix Matrix::operator*(const double& second_mat)
{
	Matrix var_Mat(rows, cols);
	int r = 0;
	while( r < rows )
	{
		int c = 0;
		while( c < cols )
		{
			(*(*(var_Mat.matrix + r) + c)) = (*(*(matrix + r) + c)) * second_mat;
			c += 1;
		}
		r += 1;
	}
	return var_Mat;
}
Matrix& Matrix::operator*=(const double& second_mat)
{
	*this = (this->operator*(second_mat));
	return *this;
}
Matrix Matrix::operator/(const double& second_mat)
{
	if(second_mat == 0)
	{
		throw "Error: division by zero";
	}
	else
	{
		Matrix var_Mat(rows, cols);
		int r = 0;
		while( r < rows )
		{
			int c = 0;
			while( c < cols )
			{
				(*(*(var_Mat.matrix + r) + c)) = (*(*(matrix + r) + c)) / second_mat;
				c += 1;
			}
			r += 1;
		}
		return var_Mat;
	}
}

Matrix Matrix::operator*(const Matrix& second_mat)
{
	if(cols != second_mat.rows)
	{
		throw "Error: invalid matrix multiplication";
	}
	else
	{
		Matrix var_Mat(rows, second_mat.cols);
		int r = 0;
		while( r < rows )
		{
			int c = 0;
			while( c < second_mat.cols )
			{
				double mat_t = 0;
				for(int k = 0; k < second_mat.rows; k += 1)
				{
					mat_t += (*(*(matrix + r) + k)) * (*(*(second_mat.matrix + k) + c));
				}
				(*(*(var_Mat.matrix + r) + c)) = mat_t;
				c += 1;
			}
			r += 1;
		}
		return var_Mat;
	}
}
Matrix& Matrix::operator*=(const Matrix& second_mat)
{
	*this = (this->operator*(second_mat));
	return *this;
}
Matrix Matrix::operator^(int pow)
{
	if(rows != cols)
	{
		throw "Error: non-square matrix provided";
    }
	else if(pow < 0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		if(pow == 0)
		{
			Matrix var_Mat(*this);
			int r = 0;
			while( r < rows )
			{
				int c = 0;
				while( c < cols )
				{
					if(r!=c)
					{
						(*(*(var_Mat.matrix + r) + c)) = 0;
					}
					else
					{
						(*(*(var_Mat.matrix + r) + c)) = 1;
					}
					c += 1;
				}
				r += 1;
			}
			return var_Mat;
		}
		else
		{
			Matrix var_Mat(*this);
			int i = 0;
			while( i < (pow-1) )
			{
				var_Mat*= *this;
				i += 1;
			}
			return var_Mat;
		}
	}
	Matrix var_Mat(*this);
	return var_Mat;
}
Matrix& Matrix::operator^=(int pow)
{
	*this = (this->operator^(pow));
	return *this;
}

// Access the individual elements
double& Matrix::operator()(const unsigned r, const unsigned c)
{
	if(c < 0 || c >= cols)
	{
		throw "Error: invalid column i";
	}
	else if(r < 0 || r >= rows)
	{
		throw "Error: invalid row i";
	}
	return (*(*(matrix + r) + c));
}
const double& Matrix::operator()(const unsigned r, const unsigned c) const
{
	if(c < 0 || c >= cols)
	{
		throw "Error: invalid column i";
	}
	else if(r < 0 || r >= rows)
	{
		throw "Error: invalid row i";
	}
	return (*(*(matrix + r) + c));
}
Vector Matrix::operator[](const unsigned r) const
{
	if(r < 0 || r >= rows)
	{
		throw "Error: invalid row i";
	}
	Vector var_Mat(cols);
	for(int c = 0; c < cols; )
	{
		var_Mat[c] = (*(*(matrix + r) + c));
		c += 1;
	}
	return var_Mat;
}

// Getters and setters:
unsigned Matrix::getRows() const
{
	return rows;
}
unsigned Matrix::getCols() const
{
	return cols;
}

// transpose
Matrix Matrix::operator~()
{
	Matrix var_Mat(cols, rows);
	int r = 0;
	while( r < rows )
	{
		int c = 0;
		while( c < cols )
		{
			(*(*(var_Mat.matrix + c) + r)) = (*(*(matrix + r) + c));
			c += 1;
		}
		r += 1;
	}
	return var_Mat;
}

// Linear equations:
Matrix Matrix::operator|(const Matrix& second_mat)
{
	Matrix var_Mat(second_mat);
	if(cols != rows)
	{
		throw "Error: non-square matrix provided";
	}
	else if(second_mat.cols != 1)
	{
		throw "Error: incorrect augmentation";
	}
	else if(second_mat.rows != rows)
	{
		throw "Error: incorrect augmentation";
	}
	else
	{
		bool check = true;
		Matrix var_Matrix(*this), var_Matrix_2(second_mat), mat_t(*this), var_Matrix_22(second_mat);
		check = true;
		mat_t.operator|=(var_Matrix_22);
		int r = 0;
		while( r < second_mat.rows )
		{
			int c = 0;
			while( c <  second_mat.cols )
			{
				if((*(*(var_Matrix_2.matrix + r) + c)) != (*(*(var_Matrix_22.matrix + r) + c)))
				{
					check = false;
					break;
				}
				c += 1;
			}
			r += 1;
		}
		if(check)
		{
			int r = 0;
			while( r < rows )
			{
				int c = 0;
				while( c < cols )
				{
					if((*(*(var_Matrix.matrix + r) + c)) != (*(*(mat_t.matrix + r) + c)))
					{
						check = false;
						break;
					}
					c += 1;
				}
				r += 1;
			}
		}
		if(!check)
		{
			var_Matrix.operator|=(var_Matrix_2);
		}
		r = second_mat.rows-1;
		while( r>= 0 )
		{
			int c = r+1;
			while( c < second_mat.rows )
			{
				(*(*(var_Matrix_2.matrix + r) + 0)) = (*(*(var_Matrix_2.matrix + r) + 0)) - (*(*(var_Matrix.matrix + r) + c)) * (*(*(var_Matrix_2.matrix + c) + 0));
				c += 1;
			}
			if((*(*(var_Matrix.matrix + r) + r)) != 0)
			{
				(*(*(var_Matrix_2.matrix + r) + 0)) = (*(*(var_Matrix_2.matrix + r) + 0)) / (*(*(var_Matrix.matrix + r) + r));
			}
			else
			{
				throw "Error: division by zero";
			}
			r--;
		}
		return var_Matrix_2;
	}
	return var_Mat;
}

Matrix& Matrix::operator|=(Matrix& second_mat)
{
	if(cols != rows)
	{
		throw "Error: non-square matrix provided";
	}
	else if(second_mat.cols != 1)
	{
		throw "Error: incorrect augmentation";
	}
	else if(second_mat.rows != rows)
	{
		throw "Error: incorrect augmentation";
	}
	else
	{
		int r = 0;
		double m = 0;
		while( r < rows-1 )
		{
			int c = r+1;
			while( c < cols )
			{
				if(matrix[r][r] != 0)
				{
					m = matrix[c][r] / matrix[r][r];
					int k = 0;
					while( k < cols )
					{
						matrix[c][k] = matrix[c][k] - m*(*(*(matrix + r) + k));
						k += 1;
					}
					(*(*(second_mat.matrix + c) + 0)) = (*(*(second_mat.matrix + c) + 0)) - m*(*(*(second_mat.matrix + r) + 0));
				}
				else
				{
					throw "Error: division by zero";
				}
				c += 1;
			}
			r += 1;
		}
	}
	return *this;
}