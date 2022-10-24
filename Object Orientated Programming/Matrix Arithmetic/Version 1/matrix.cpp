#include "matrix.h"
#include <iomanip>
using namespace std;

Matrix operator*(const double& m, const Matrix& rhs_matrix)
{
	const int tempRows = rhs_matrix.rows;
	const int tempCols = rhs_matrix.cols;
	Matrix tempMat(tempRows,tempCols);
    int r=0;
	for( ;r<tempRows; )
	{
		int c=0;
		for( ;c<tempCols; )
		{
        	double mult = m*rhs_matrix.matrix[r][c];
			tempMat.matrix[r][c] = mult;
			c++;
        }
		r++;
    }
    return tempMat;
}
  
Matrix::Matrix(unsigned ro, unsigned co)
{
	const int tempRows = ro;
	const int tempCols = co;
	matrix=new double*[tempRows];
	int r=0;
	for( ;r<tempRows; )
	{
		matrix[r]=new double [tempCols];
        int c=0;
		for( ;c<tempCols; )
		{
            matrix[r][c]=0;
			c++;
        }
		r++;
    }
	rows = tempRows;
	cols = tempCols;
}

Matrix::Matrix(const Matrix& rhs_matrix)
{
	const int tempRows = rhs_matrix.rows;
	const int tempCols = rhs_matrix.cols;
	matrix=new double*[tempRows];
	int r=0;
	for( ;r<tempRows; )
	{
		matrix[r]=new double [tempCols];
        int c=0;
		for( ;c<tempCols; )
		{
            matrix[r][c]=rhs_matrix.matrix[r][c];
			c++;
        }
		r++;
    }
	rows = tempRows;
	cols = tempCols;
}

Matrix::~Matrix()
{
	if(Matrix::matrix!=NULL)
	{
		const int tempRows = rows;
		const int tempCols = cols;
		int r=0;
		for( ;r<tempRows; )
		{
			delete [] matrix[r];
			matrix[r]=NULL;
			r++;
		}
		delete matrix;
		matrix = NULL;
		rows = 0;
		cols = 0;
	}
}

void Matrix::print()
{
	const int tempRows = rows;
	const int tempCols = cols;
	int r=0;
	for( ;r<tempRows; )
	{
        int c=0;
		for( ;c<tempCols; )
		{
			cout<<setw(10)<<matrix[r][c]<<setprecision(3);
			c++;
        }
		cout<<"\n";
		r++;
    }
}
void Matrix::readFile(istream &infile)
{
	const int tempRows = rows;
	const int tempCols = cols;
	int r=0;
	for( ;r<tempRows; )
	{
        int c=0;
		for( ;c<tempCols; )
		{
			infile>>matrix[r][c];
			c++;
        }
		r++;
    }
}

// Insert overloaded = operator signature
const Matrix& Matrix::operator=(const Matrix& rhs_matrix)
{
	if(this != &rhs_matrix)
	{
		const int tempRows = rhs_matrix.rows;
		const int tempCols = rhs_matrix.cols;
		matrix=new double*[tempRows];
		int r=0;
		for( ;r<tempRows; )
		{
			matrix[r]=new double [tempCols];
			int c=0;
			for( ;c<tempCols; )
			{
				matrix[r][c]=rhs_matrix.matrix[r][c];
				c++;
			}
			r++;
		}
		rows = tempRows;
		cols = tempCols;
	}
	return *this;
}

// Matrix mathematical operations
Matrix Matrix::operator+(const Matrix& rhs_matrix)
{
	if(rows != rhs_matrix.rows)
	{	
		throw "Error: adding matrices of different dimensionality";
	}
	else if(cols!=rhs_matrix.cols)
	{	
		throw "Error: adding matrices of different dimensionality";
	}
	else
	{
		const int tempRows = rhs_matrix.rows;
		const int tempCols = rhs_matrix.cols;
		Matrix tempMat(tempRows,tempCols);
		int r=0;
		for( ;r<tempRows; )
		{
			int c=0;
			for( ;c<tempCols; )
			{
				tempMat.matrix[r][c]=matrix[r][c] + rhs_matrix.matrix[r][c];
				c++;
			}
			r++;
		}
		return tempMat;
	}
}
Matrix& Matrix::operator+=(const Matrix& rhs_matrix)
{
	if(rows != rhs_matrix.rows)
	{	
		throw "Error: adding matrices of different dimensionality";
	}
	else if(cols!=rhs_matrix.cols)
	{	
		throw "Error: adding matrices of different dimensionality";
	}
	else
	{
		const int tempRows = rhs_matrix.rows;
		const int tempCols = rhs_matrix.cols;
		Matrix tempMat(tempRows,tempCols);
		int r=0;
		for( ;r<tempRows; )
		{
			int c=0;
			for( ;c<tempCols; )
			{
				tempMat.matrix[r][c]=matrix[r][c] + rhs_matrix.matrix[r][c];
				c++;
			}
			r++;
		}
		*this = tempMat;
		return *this;
	}
}
Matrix Matrix::operator-(const Matrix& rhs_matrix)
{
	if(cols!=rhs_matrix.cols)
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else if(rows != rhs_matrix.rows)
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else
	{
		const int tempRows = rhs_matrix.rows;
		const int tempCols = rhs_matrix.cols;
		Matrix tempMat(tempRows,tempCols);
		int r=0;
		for( ;r<tempRows; )
		{
			int c=0;
			for( ;c<tempCols; )
			{
				tempMat.matrix[r][c]=matrix[r][c] - rhs_matrix.matrix[r][c];
				c++;
			}
			r++;
		}
		return tempMat;
	}
}
Matrix& Matrix::operator-=(const Matrix& rhs_matrix)
{
	if(cols!=rhs_matrix.cols)
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else if(rows != rhs_matrix.rows)
	{
		throw "Error: subtracting matrices of different dimensionality";
	}
	else
	{
		const int tempRows = rhs_matrix.rows;
		const int tempCols = rhs_matrix.cols;
		Matrix tempMat(tempRows,tempCols);
		int r=0;
		for( ;r<tempRows; )
		{
			int c=0;
			for( ;c<tempCols; )
			{
				tempMat.matrix[r][c]=matrix[r][c] - rhs_matrix.matrix[r][c];
				c++;
			}
			r++;
		}
		*this = tempMat;
		return *this;
	}
}

// Matrix/scalar operations
Matrix Matrix::operator*(const double& rhs_matrix)
{
	const int tempRows = rows;
	const int tempCols = cols;
	Matrix tempMat(tempRows,tempCols);
	int r=0;
	for( ;r<tempRows; )
	{
		int c=0;
		for( ;c<tempCols; )
		{
			tempMat.matrix[r][c]=matrix[r][c] * rhs_matrix;
			c++;
		}
		r++;
	}
	return tempMat;
}
Matrix& Matrix::operator*=(const double& rhs_matrix)
{
	const int tempRows = rows;
	const int tempCols = cols;
	Matrix tempMat(tempRows,tempCols);
	int r=0;
	for( ;r<tempRows; )
	{
		int c=0;
		for( ;c<tempCols; )
		{
			tempMat.matrix[r][c]=matrix[r][c] * rhs_matrix;
			c++;
		}
		r++;
	}
	*this = tempMat;
	return *this;
}
Matrix Matrix::operator/(const double& rhs_matrix)
{
	if(rhs_matrix==0)
	{
		throw "Error: division by zero";
	}
	else
	{
		const int tempRows = rows;
		const int tempCols = cols;
		Matrix tempMat(tempRows,tempCols);
		int r=0;
		for( ;r<tempRows; )
		{
			int c=0;
			for( ;c<tempCols; )
			{
				tempMat.matrix[r][c]=matrix[r][c] / rhs_matrix;
				c++;
			}
			r++;
		}
		return tempMat;
	}
}

Matrix Matrix::operator*(const Matrix& rhs_matrix)
{
	if(cols!=rhs_matrix.rows)
	{
		throw "Error: invalid matrix multiplication";
	}
	else
	{
		const int tempRows = rows;
		const int tempRows2 = rhs_matrix.rows;
		const int tempCols = rhs_matrix.cols;
		Matrix tempMat(tempRows,tempCols);
		int r=0;
		for( ;r<tempRows; )
		{
			int c=0;
			for( ;c<tempCols; )
			{
				double mat_t = 0;
				for(int k=0; k<tempRows2; k++)
				{
					mat_t+=matrix[r][k]*rhs_matrix.matrix[k][c];
				}
				tempMat.matrix[r][c] = mat_t;
				c++;
			}
			r++;
		}
		return tempMat;
	}
}
Matrix& Matrix::operator*=(const Matrix& rhs_matrix)
{
	if(cols!=rhs_matrix.rows)
	{
		throw "Error: invalid matrix multiplication";
	}
	else
	{
		const int tempRows = rows;
		const int tempRows2 = rhs_matrix.rows;
		const int tempCols = rhs_matrix.cols;
		Matrix tempMat(tempRows,tempCols);
		int r=0;
		for( ;r<tempRows; )
		{
			int c=0;
			for( ;c<tempCols; )
			{
				double mat_t = 0;
				int k=0;
				for( ; k<tempRows2; )
				{
					mat_t+=matrix[r][k]*rhs_matrix.matrix[k][c];
					k++;
				}
				tempMat.matrix[r][c] = mat_t;
				c++;
			}
			r++;
		}
		*this = tempMat;
		return *this;
	}
}
Matrix Matrix::operator^(int pow)
{
	if(rows!=cols)
	{
		throw "Error: non-square matrix provided";
    }
	else if(pow<0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		if(pow==0)
		{
			const int tempRows = rows;
			const int tempCols = cols;
			Matrix tempMat(*this);
			int r=0;
			for( ;r<tempRows; )
			{
				int c=0;
				for( ;c<tempCols; )
				{
					if(r!=c)
					{
						tempMat.matrix[r][c]=0;
					}
					else
					{
						tempMat.matrix[r][c]=1;
					}
					c++;
				}
				r++;
			}
			return tempMat;
		}
		else
		{
			Matrix tempMat(*this);
			int i=0;
			for( ;i<(pow-1); )
			{
				tempMat*= *this;
				i++;
			}
			return tempMat;
		}
	}
	Matrix tempMat(*this);
	return tempMat;
}
Matrix& Matrix::operator^=(int pow)
{
	if(rows!=cols)
	{
		throw "Error: non-square matrix provided";
    }
	else if(pow<0)
	{
		throw "Error: negative power is not supported";
    }
	else
	{
		if(pow==0)
		{
			const int tempRows = rows;
			const int tempCols = cols;
			Matrix tempMat(*this);
			int r=0;
			for( ;r<tempRows; )
			{
				int c=0;
				for( ;c<tempCols; )
				{
					if(r!=c)
					{
						tempMat.matrix[r][c]=0;
					}
					else
					{
						tempMat.matrix[r][c]=1;
					}
					c++;
				}
				r++;
			}
			*this = tempMat;
			return *this;
		}
		else
		{
			Matrix tempMat(*this);
			int r=0;
			for( ;r<(pow-1); )
			{
				tempMat*= *this;
				r++;
			}
			*this = tempMat;
			return *this;
		}
	}
	return *this;
}

// Access the individual elements
double& Matrix::operator()(const unsigned r, const unsigned c)
{
	if(c<0 || c>=cols)
	{
		throw "Error: invalid column i";
	}
	else if(r<0 || r>=rows)
	{
		throw "Error: invalid row i";
	}
	return matrix[r][c];
}
const double& Matrix::operator()(const unsigned r, const unsigned c) const
{
	if(c<0 || c>=cols)
	{
		throw "Error: invalid column i";
	}
	else if(r<0 || r>=rows)
	{
		throw "Error: invalid row i";
	}
	return matrix[r][c];
}
Vector Matrix::operator[](const unsigned r) const
{
	if(r<0 || r>=rows)
	{
		throw "Error: invalid row i";
	}
	Vector tempMat(cols);
	for(int c = 0;c<cols; )
	{
		tempMat[c] = matrix[r][c];
		c++;
	}
	return tempMat;
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
	const int tempRows = rows;
	const int tempCols = cols;
	Matrix tempMat(tempCols, tempRows);
	int r=0;
	for( ;r<tempRows; )
	{
		int c=0;
		for( ;c<tempCols; )
		{
			tempMat.matrix[c][r]=matrix[r][c];
			c++;
		}
		r++;
	}
	return tempMat;
}

// Linear equations:
Matrix Matrix::operator|(const Matrix& rhs_matrix)
{
	Matrix tempMat(rhs_matrix);
	if(cols != rows)
	{
		throw "Error: non-square matrix provided";
	}
	else if(rhs_matrix.cols != 1)
	{
		throw "Error: incorrect augmentation";
	}
	else if(rhs_matrix.rows != rows)
	{
		throw "Error: incorrect augmentation";
	}
	else
	{
		const int tempRows = rows;
		const int tempCols = cols;
		const int tempRows2 = rhs_matrix.rows;
		const int tempCols2 = rhs_matrix.cols;
		bool check = true;
		Matrix tempMatrix(*this), tempMatrix_2(rhs_matrix), mat_t(*this), tempMatrix_22(rhs_matrix);
		check = true;
		mat_t|=tempMatrix_22;
		int r=0;
		for( ;r<tempRows2; )
		{
			int c=0;
			for( ;c<tempCols2; )
			{
				if(tempMatrix_2.matrix[r][c] != tempMatrix_22.matrix[r][c])
				{
					check = false;
					break;
				}
				c++;
			}
			r++;
		}
		if(check)
		{
			int r=0;
			for( ;r<tempRows; )
			{
				int c=0;
				for( ;c<tempCols; )
				{
					if(tempMatrix.matrix[r][c] != mat_t.matrix[r][c])
					{
						check = false;
						break;
					}
					c++;
				}
				r++;
			}
		}
		if(!check)
		{
			tempMatrix|=tempMatrix_2;
		}
		r=tempRows2-1;
		for( ;r>=0; )
		{
			int c=r+1;
			for( ;c<tempRows2; )
			{
				tempMatrix_2.matrix[r][0] = tempMatrix_2.matrix[r][0] - tempMatrix.matrix[r][c]*tempMatrix_2.matrix[c][0];
				c++;
			}
			if(tempMatrix.matrix[r][r] != 0)
			{
				tempMatrix_2.matrix[r][0] = tempMatrix_2.matrix[r][0] / tempMatrix.matrix[r][r];
			}
			else
			{
				throw "Error: division by zero";
			}
			r--;
		}
		return tempMatrix_2;
	}
	return tempMat;
}

Matrix& Matrix::operator|=(Matrix& rhs_matrix)
{
	if(cols != rows)
	{
		throw "Error: non-square matrix provided";
	}
	else if(rhs_matrix.cols != 1)
	{
		throw "Error: incorrect augmentation";
	}
	else if(rhs_matrix.rows != rows)
	{
		throw "Error: incorrect augmentation";
	}
	else
	{
		const int tempRows = rows;
		const int tempCols = cols;
		double m = 0;
		int r=0;
		for( ;r<tempRows-1; )
		{
			int c=r+1;
			for( ;c<tempCols; )
			{
				if(matrix[r][r] != 0)
				{
					m = matrix[c][r]/matrix[r][r];
					int k=0;
					for( ;k<tempCols; )
					{
						matrix[c][k] = matrix[c][k] - m*matrix[r][k];
						k++;
					}
					rhs_matrix.matrix[c][0] = rhs_matrix.matrix[c][0] - m*rhs_matrix.matrix[r][0];
				}
				else
				{
					throw "Error: division by zero";
				}
				c++;
			}
			r++;
		}
	}
	return *this;
}