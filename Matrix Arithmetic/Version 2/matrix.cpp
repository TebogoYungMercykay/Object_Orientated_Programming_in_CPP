#include "matrix.h"
#include <iomanip>
using namespace std;

Matrix operator*(const double& m, const Matrix& rhs_matrix){
	const int mat_rows = rhs_matrix.getRows();
	const int mat_cols = rhs_matrix.getCols();
	Matrix obj(mat_rows,mat_cols);
    for(int r=0;r<mat_rows;r++){
		for(int c=0;c<mat_cols;c++){
        	double mult = m*rhs_matrix.matrix[r][c];
			obj.matrix[r][c] = mult;
        }
    }
    return obj;
}
  
Matrix::Matrix(unsigned r, unsigned c){
	const int mat_rows = r;
	const int mat_cols = c;
	Matrix::matrix=new double*[mat_rows];
	for(int r=0;r<mat_rows;r++){
		Matrix::matrix[r]=new double [mat_cols];
        for(int c=0;c<mat_cols;c++){
            Matrix::matrix[r][c]=0;
        }
    }
	Matrix::rows = mat_rows;
	Matrix::cols = mat_cols;
}
Matrix::Matrix(const Matrix& rhs_matrix){
	const int mat_rows = rhs_matrix.getRows();
	const int mat_cols = rhs_matrix.getCols();
	Matrix::matrix=new double*[mat_rows];
	for(int r=0;r<mat_rows;r++){
		Matrix::matrix[r]=new double [mat_cols];
        for(int c=0;c<mat_cols;c++){
            Matrix::matrix[r][c]=rhs_matrix.matrix[r][c];
        }
    }
	Matrix::rows = mat_rows;
	Matrix::cols = mat_cols;
}
Matrix::~Matrix(){
	if(Matrix::matrix!=NULL){
		const int mat_rows = Matrix::getRows();
		const int mat_cols = Matrix::getCols();
		for(int r=0;r<mat_rows;r++){
			delete [] Matrix::matrix[r];
			Matrix::matrix[r]=NULL;
		}
		delete Matrix::matrix;
		Matrix::matrix = NULL;
		Matrix::rows = 0;
		Matrix::cols = 0;
	}
}

void Matrix::print(){
	const int mat_rows = Matrix::getRows();
	const int mat_cols = Matrix::getCols();
	for(int r=0;r<mat_rows;r++){
        for(int c=0;c<mat_cols;c++){
			std::cout<<setw(10)<<Matrix::matrix[r][c]<<setprecision(3);
        }
		std::cout<<"\n";
    }
}
void Matrix::readFile(istream &infile){
	const int mat_rows = Matrix::getRows();
	const int mat_cols = Matrix::getCols();
	for(int r=0;r<mat_rows;r++){
        for(int c=0;c<mat_cols;c++){
			infile>>Matrix::matrix[r][c];
        }
    }
}

// Insert overloaded = operator signature
const Matrix& Matrix::operator=(const Matrix& rhs_matrix){
	if(this != &rhs_matrix){
		delete Matrix::matrix;
		Matrix::matrix = NULL;
		const int mat_rows = rhs_matrix.getRows();
		const int mat_cols = rhs_matrix.getCols();
		Matrix::matrix=new double*[mat_rows];
		for(int r=0;r<mat_rows;r++){
			Matrix::matrix[r]=new double [mat_cols];
			for(int c=0;c<mat_cols;c++){
				Matrix::matrix[r][c]=rhs_matrix.matrix[r][c];
			}
		}
		Matrix::rows = mat_rows;
		Matrix::cols = mat_cols;
	}
	return *this;
}

// Matrix mathematical operations
Matrix Matrix::operator+(const Matrix& rhs_matrix){
	if(Matrix::rows != rhs_matrix.getRows()){	
		throw "Error: adding matrices of different dimensionality";
	}
	else if(Matrix::cols!=rhs_matrix.getCols()){	
		throw "Error: adding matrices of different dimensionality";
	}
	else{
		const int mat_rows = rhs_matrix.getRows();
		const int mat_cols = rhs_matrix.getCols();
		Matrix obj(mat_rows,mat_cols);
		for(int r=0;r<mat_rows;r++){
			for(int c=0;c<mat_cols;c++){
				obj.matrix[r][c]=Matrix::matrix[r][c] + rhs_matrix.matrix[r][c];
			}
		}
		return obj;
	}
}
Matrix& Matrix::operator+=(const Matrix& rhs_matrix){
	if(Matrix::rows != rhs_matrix.getRows()){	
		throw "Error: adding matrices of different dimensionality";
	}
	else if(Matrix::cols!=rhs_matrix.getCols()){	
		throw "Error: adding matrices of different dimensionality";
	}
	else{
		const int mat_rows = rhs_matrix.getRows();
		const int mat_cols = rhs_matrix.getCols();
		Matrix obj(mat_rows,mat_cols);
		for(int r=0;r<mat_rows;r++){
			for(int c=0;c<mat_cols;c++){
				obj.matrix[r][c]=Matrix::matrix[r][c] + rhs_matrix.matrix[r][c];
			}
		}
		*this = obj;
		return *this;
	}
}
Matrix Matrix::operator-(const Matrix& rhs_matrix){
	if(Matrix::cols!=rhs_matrix.getCols()){
		throw "Error: subtracting matrices of different dimensionality";
	}
	else if(Matrix::rows != rhs_matrix.getRows()){
		throw "Error: subtracting matrices of different dimensionality";
	}
	else{
		const int mat_rows = rhs_matrix.getRows();
		const int mat_cols = rhs_matrix.getCols();
		Matrix obj(mat_rows,mat_cols);
		for(int r=0;r<mat_rows;r++){
			for(int c=0;c<mat_cols;c++){
				obj.matrix[r][c]=Matrix::matrix[r][c] - rhs_matrix.matrix[r][c];
			}
		}
		return obj;
	}
}
Matrix& Matrix::operator-=(const Matrix& rhs_matrix){
	if(Matrix::cols!=rhs_matrix.getCols()){
		throw "Error: subtracting matrices of different dimensionality";
	}
	else if(Matrix::rows != rhs_matrix.getRows()){
		throw "Error: subtracting matrices of different dimensionality";
	}
	else{
		const int mat_rows = rhs_matrix.getRows();
		const int mat_cols = rhs_matrix.getCols();
		Matrix obj(mat_rows,mat_cols);
		for(int r=0;r<mat_rows;r++){
			for(int c=0;c<mat_cols;c++){
				obj.matrix[r][c]=Matrix::matrix[r][c] - rhs_matrix.matrix[r][c];
			}
		}
		*this = obj;
		return *this;
	}
}

// Matrix/scalar operations
Matrix Matrix::operator*(const double& rhs_matrix){
	const int mat_rows = Matrix::getRows();
	const int mat_cols = Matrix::getCols();
	Matrix obj(mat_rows,mat_cols);
	for(int r=0;r<mat_rows;r++){
		for(int c=0;c<mat_cols;c++){
			obj.matrix[r][c]=Matrix::matrix[r][c] * rhs_matrix;
		}
	}
	return obj;
}
Matrix& Matrix::operator*=(const double& rhs_matrix){
	const int mat_rows = Matrix::getRows();
	const int mat_cols = Matrix::getCols();
	Matrix obj(mat_rows,mat_cols);
	for(int r=0;r<mat_rows;r++){
		for(int c=0;c<mat_cols;c++){
			obj.matrix[r][c]=Matrix::matrix[r][c] * rhs_matrix;
		}
	}
	*this = obj;
	return *this;
}
Matrix Matrix::operator/(const double& rhs_matrix){
	if(rhs_matrix==0){
		throw "Error: division by zero";
	}
	else{
		const int mat_rows = Matrix::getRows();
		const int mat_cols = Matrix::getCols();
		Matrix obj(mat_rows,mat_cols);
		for(int r=0;r<mat_rows;r++){
			for(int c=0;c<mat_cols;c++){
				obj.matrix[r][c]=Matrix::matrix[r][c] / rhs_matrix;
			}
		}
		return obj;
	}
}

Matrix Matrix::operator*(const Matrix& rhs_matrix){
	if(Matrix::cols!=rhs_matrix.getRows()){
		throw "Error: invalid matrix multiplication";
	}
	else{
		const int mat_rows = Matrix::getRows();
		const int mat_rows2 = rhs_matrix.getRows();
		const int mat_cols = rhs_matrix.getCols();
		Matrix obj(mat_rows,mat_cols);
		for(int r=0;r<mat_rows;r++){
			for(int c=0;c<mat_cols;c++){
				double mat_t = 0;
				for(int k=0; k<mat_rows2; k++){
					mat_t+=Matrix::matrix[r][k]*rhs_matrix.matrix[k][c];
				}
				obj.matrix[r][c] = mat_t;
			}
		}
		return obj;
	}
}
Matrix& Matrix::operator*=(const Matrix& rhs_matrix){
	if(Matrix::cols!=rhs_matrix.getRows()){
		throw "Error: invalid matrix multiplication";
	}
	else{
		const int mat_rows = Matrix::getRows();
		const int mat_rows2 = rhs_matrix.getRows();
		const int mat_cols = rhs_matrix.getCols();
		Matrix obj(mat_rows,mat_cols);
		for(int r=0;r<mat_rows;r++){
			for(int c=0;c<mat_cols;c++){
				double mat_t = 0;
				for(int k=0; k<mat_rows2; k++){
					mat_t+=Matrix::matrix[r][k]*rhs_matrix.matrix[k][c];
				}
				obj.matrix[r][c] = mat_t;
			}
		}
		*this = obj;
		return *this;
	}
}
Matrix Matrix::operator^(int pow){
	if(Matrix::getRows()!=Matrix::getCols()){
		throw "Error: non-square matrix provided";
    }
	else if(pow<0){
		throw "Error: negative power is not supported";
    }
	else{
		if(pow==0){
			const int mat_rows = Matrix::getRows();
			const int mat_cols = Matrix::getCols();
			Matrix obj(*this);
			for(int r=0;r<mat_rows;r++){
				for(int c=0;c<mat_cols;c++){
					if(r!=c){
						obj.matrix[r][c]=0;
					}
					else{
						obj.matrix[r][c]=1;
					}
				}
			}
			return obj;
		}
		else{
			Matrix obj(*this);
			for(int i=0;i<(pow-1);i++){
				obj*= *this;
			}
			return obj;
		}
	}
	Matrix obj(*this);
	return obj;
}
Matrix& Matrix::operator^=(int pow){
	if(Matrix::getRows()!=Matrix::getCols()){
		throw "Error: non-square matrix provided";
    }
	else if(pow<0){
		throw "Error: negative power is not supported";
    }
	else{
		if(pow==0){
			const int mat_rows = Matrix::getRows();
			const int mat_cols = Matrix::getCols();
			Matrix obj(*this);
			for(int r=0;r<mat_rows;r++){
				for(int c=0;c<mat_cols;c++){
					if(r!=c){
						obj.matrix[r][c]=0;
					}
					else{
						obj.matrix[r][c]=1;
					}
				}
			}
			*this = obj;
			return *this;
		}
		else{
			Matrix obj(*this);
			for(int r=0;r<(pow-1);r++){
				obj*= *this;
			}
			*this = obj;
			return *this;
		}
	}
	return *this;
}

int boundsCheck(const unsigned r, const unsigned c, unsigned r2, unsigned c2){
	if(r<0 || r>=r2){
		return 1;
	}
	else if(c<0 || c>=c2){
		return 2;
	}
	return 3;
}
// Access the individual elements
double& Matrix::operator()(const unsigned r, const unsigned c){
	if(boundsCheck(r,c,Matrix::rows,Matrix::cols)==3){
		return matrix[r][c];
	}
	else if(boundsCheck(r,c,Matrix::rows,Matrix::cols)==1){
		throw "Error: invalid row index";
	}
	throw "Error: invalid column index";
}
const double& Matrix::operator()(const unsigned r, const unsigned c) const{
	if(boundsCheck(r,c,Matrix::rows,Matrix::cols)==3){
		return matrix[r][c];
	}
	else if(boundsCheck(r,c,Matrix::rows,Matrix::cols)==1){
		throw "Error: invalid row index";
	}
	throw "Error: invalid column index";
}
Vector Matrix::operator[](const unsigned r) const{
	if(boundsCheck(r,1,Matrix::rows,Matrix::cols)==1){
		throw "Error: invalid row index";
	}
	Vector obj(Matrix::getCols());
	for(int c = 0;c<Matrix::getCols();c++){
		obj[c] = Matrix::matrix[r][c];
	}
	return obj;
}

// Getters and setters:
unsigned Matrix::getRows() const{
	return rows;
}
unsigned Matrix::getCols() const{
	return cols;
}

// transpose
Matrix Matrix::operator~(){
	const int mat_rows = Matrix::getRows();
	const int mat_cols = Matrix::getCols();
	Matrix obj(mat_cols, mat_rows);
	for(int r=0;r<mat_rows;r++){
		for(int c=0;c<mat_cols;c++){
			obj.matrix[c][r]=Matrix::matrix[r][c];
		}
	}
	return obj;
}

// Linear equations:
Matrix Matrix::operator|(const Matrix& rhs_matrix){
	Matrix obj(rhs_matrix);
	if(Matrix::getCols() != Matrix::getRows()){
		throw "Error: non-square matrix provided";
	}
	else if(rhs_matrix.getCols() != 1){
		throw "Error: incorrect augmentation";
	}
	else if(rhs_matrix.getRows() != Matrix::getRows()){
		throw "Error: incorrect augmentation";
	}
	else{
		const int mat_rows = Matrix::getRows();
		const int mat_cols = Matrix::getCols();
		const int mat_rows2 = rhs_matrix.getRows();
		const int mat_cols2 = rhs_matrix.getCols();
		bool echelon = true;
		Matrix mr(*this), mr_2(rhs_matrix), mat_t(*this), mr_22(rhs_matrix);
		echelon = true;
		mat_t|=mr_22;
		for(int r=0;r<mat_rows2;r++){
			for(int c=0;c<mat_cols2;c++){
				if(mr_2.matrix[r][c] != mr_22.matrix[r][c]){
					echelon = false;
					break;
				}
			}
		}
		if(echelon == true){
			for(int r=0;r<mat_rows;r++){
				for(int c=0;c<mat_cols;c++){
					if(mr.matrix[r][c] != mat_t.matrix[r][c]){
						echelon = false;
						break;
					}
				}
			}
		}
		if(echelon == false){
			mr|=mr_2;
		}

		for(int r=mat_rows2-1;r>=0;r--){
			for(int c=r+1;c<mat_rows2;c++){
				mr_2.matrix[r][0] = mr_2.matrix[r][0] - mr.matrix[r][c]*mr_2.matrix[c][0];
			}
			if(mr.matrix[r][r] != 0){
				mr_2.matrix[r][0] = mr_2.matrix[r][0] / mr.matrix[r][r];
			}
			else{
				throw "Error: division by zero";
			}
		}
		return mr_2;
	}
	return obj;
}

Matrix& Matrix::operator|=(Matrix& rhs_matrix){
	if(Matrix::getCols() != Matrix::getRows()){
		throw "Error: non-square matrix provided";
	}
	else if(rhs_matrix.getCols() != 1){
		throw "Error: incorrect augmentation";
	}
	else if(rhs_matrix.getRows() != Matrix::getRows()){
		throw "Error: incorrect augmentation";
	}
	else{
		const int mat_rows = Matrix::getRows();
		const int mat_cols = Matrix::getCols();
		double m = 0;
		for(int r=0;r<mat_rows-1;r++){
			for(int c=r+1;c<mat_cols;c++){
				if(Matrix::matrix[r][r] != 0){
					m = Matrix::matrix[c][r]/Matrix::matrix[r][r];
					for(int k=0; k<mat_cols; k++){
						Matrix::matrix[c][k] = Matrix::matrix[c][k] - m*Matrix::matrix[r][k];
					}
					rhs_matrix.matrix[c][0] = rhs_matrix.matrix[c][0] - m*rhs_matrix.matrix[r][0];
				}
				else{
					throw "Error: division by zero";
				}
			}
		}
	}
	return *this;
}