// The Laast Two To Be Completed Soon

#include <string>
#include <fstream>
#include <stdlib.h>
#include "matrix.h"
#include <iomanip>
#include <iostream>
using namespace std;
Matrix Matrix::operator*(const double &rhs){
	Matrix Mat_Array( this->getRows(), this->getCols() );

        for(int counter=0; counter<this->getRows(); counter++){
		
		for(int Index=0;Index<this->getCols();Index++){
			
			Mat_Array.matrix[ counter][Index]=this->matrix[ counter][Index]*rhs;
		}
        }
        return Mat_Array;
}
Matrix& Matrix:: operator*=(const double &rhs){      
        for(int counter=0; counter<this->getRows(); counter++){
		
		for(int Index=0;Index<this->getCols();Index++){
			
			this->matrix[ counter][Index]=this->matrix[ counter][Index]*rhs;
		}
        }
	return *this;
}
Matrix Matrix:: operator^(int pow){
	if(this->getRows()!=this->getCols()){
		cout<<"Error: non-square matrix provided"<<endl;
		return *this;
        }
	else if(pow<0){
		cout<<"Error: negative power is not supported"<<endl;
		return *this;
        }
	else{
		if(pow==0){
			Matrix Mat_Array(this->getRows(),this->getCols());
			for(int counter=0; counter<this->getRows(); counter++){
		
				for(int Index=0;Index<this->getCols();Index++){
					if(counter==Index){
						Mat_Array.matrix[counter][Index]=1;

					}
					else{
						Mat_Array.matrix[counter][Index]=0;
					}
				}
			}
			return Mat_Array;
		}
		else if(pow==1){
			return *this;
		}
		else if(pow>1){
			Matrix Mat_Array(this->getRows(),this->getCols());
			for(int counter=0; counter<this->getRows(); counter++){
		
				for(int Index=0;Index<this->getCols();Index++){
					
					Mat_Array.matrix[counter][Index]=this->matrix[counter][Index];
					
				}
			}
			Matrix Mat_Two=Mat_Array;
			for(int Index=0;Index<(pow-1);Index++){
				
				Mat_Array=Mat_Array*Mat_Two;
			}
			return Mat_Array;
		}
            
        }

}
Matrix& Matrix:: operator^=(int pow){
    if(this->getRows() != this->getCols()){
		cout<<"Error: non-square matrix provided";
		cout<<endl;
		return *this;
        }
	else if(pow<0){
		cout<<"Error: negative power is not supported";
		cout<<endl;
		return *this;
        }
	else{
		if(pow==0){
			for(int counter=0; counter<this->getRows(); counter++){
		
				for(int Index=0;Index<this->getCols();Index++){
					if(counter==Index){
						this->matrix[counter][Index]=1;

					}
					else{
						this->matrix[counter][Index]=0;
					}
				}
			}
			return *this;
		}
		else if(pow==1){
                
			return *this;
		}
		else if(pow>1){
			Matrix Mat_Array( this->getRows(), this->getCols() );
			
			for(int counter=0; counter<this->getRows(); counter++){
		
				for(int Index=0;Index<this->getCols();Index++){
					
					Mat_Array.matrix[counter][Index]=this->matrix[counter][Index];
					
				}
			}
			Matrix Mat_Two=Mat_Array;
			for(int Index=0;Index<(pow-1);Index++){
				
				Mat_Array=Mat_Array*Mat_Two;
			}
			for(int counter=0; counter<this->getRows(); counter++){
		
				for(int Index=0;Index<this->getCols();Index++){
					
					this->matrix[counter][Index]=Mat_Array.matrix[counter][Index];
					
				}
			}			
			return *this;
		}
        }
}
// Matrix/scalar operations
Matrix Mat
// Matrix/scalar operations
Matrix Matrix::operator*(const Matrix &rhs){
        if( rhs.getRows() != this->getCols() ){
		cout<<"Error: invalid matrix multiplication";
		cout<<endl;
		return *this;
        }
	else
	{
		Matrix Mat_Array( this->getRows(), rhs.getCols() );
		double Variable;
		for (int counter = 0; counter <this->getRows(); counter++){
			
			for(int Index =0;Index<this->getCols();Index++){
				
				Variable=0.0;
				for(int DJ_Tears = 0; DJ_Tears<this->getCols() ;DJ_Tears++){
					
					Variable=this->matrix[counter][DJ_Tears]* rhs.matrix[DJ_Tears][Index];
				}
				Mat_Array.matrix[counter][Index]=Variable;
			}
		}
		return Mat_Array;
        }
}
Matrix& Matrix:: operator*=(const Matrix &rhs){
        if(this->getCols() !=rhs.getRows()){
		cout<<"Error: invalid matrix multiplication";
		cout<<endl;
		return *this;
        }
	else{
		Matrix Mat_Array(this->getRows(),rhs.getCols());

		double Variable;
		for (int i = 0; i <this->getRows(); i++){
			for(int j =0;j<rhs.getCols();j++){
				Variable=0.0;
				for(int m = 0; m<this->getCols() ;m++){
					Variable=this->matrix[i][m]* rhs.matrix[m][j];
				}
				Mat_Array.matrix[i][j]=Variable;
			}
                    
		}
		for(int i=0;i<this->getRows();i++){
			
			delete [] matrix[i];
		}
		delete [] matrix;
		this->rows=this->getRows();
		this->cols=rhs.getCols();
		
		matrix=new double*[this->getRows()];
		
		for(int Count=0;Count<this->getRows();Count++){
			matrix[Count]=new double[rhs.getCols()];
		}
		for(int Counter=0;Counter<this->getRows();Counter++){
			
			for(int Dj=0;Dj< rhs.getCols();Dj++){
				
				this->matrix[Counter][Dj]=Mat_Array.matrix[Counter][Dj];
			}
                }
		return *this;
        }
}
Matrix Matrix::operator/(const double &rhs){
	this->denominator=rhs;
	
	if(this->denominator==0){
		
		cout<<"Error: division by zero";
		cout<<endl;
		return *this;
	}
	else{
		
		Matrix Mat_Array( this->getRows(), this->getCols() );

		for(int Dj=0;Dj<this->getRows();Dj++){
			
			for(int Counter=0;Counter<this->getCols();Counter++){
				
				Mat_Array.matrix[Dj][Counter]=this->matrix[Dj][Counter]/this->denominator;
				
			}
		}
		return Mat_Array;
	}
}
// Access the individual elements
double &Matrix::operator()(const unsigned r, const unsigned c){
	for(int g=0;g<rows;g++){
		for(int v=0;v<cols;v++){
			if(g==r&&c==v){
				
				return matrix[g][v];
			}
		}
	}
}
const double &Matrix::operator()(const unsigned r, const unsigned c) const{	
	for(int g=0;g<rows;g++){
		for(int v=0;v<cols;v++){
			if(g==r&&c==v){
				
				return matrix[g][v];
			}
		}
	}
}
Matrix Matrix::operator[](const unsigned r) const{
	Matrix mat(1, this->getCols());
	for(int Cols =0;Cols<this->getCols();Cols++)
	{
		mat.matrix[0][Cols]=this->matrix[r][Cols];
	}
	return mat;
}
// Getters and setters:
unsigned Matrix::getRows() const{
	return rows;
}
unsigned Matrix::getCols() const{
	return cols;
}
double *Matrix::operator|(Matrix &rhs){
	if(rows == cols && rhs.col==1 && rhs.rows=rows){
		if(row==2 && cols==2){
			linearDeterminants = new double[2];
			linearDeterminants[0]=((rhs.matrix[0][0]*matrix[1][1])-(matrix[0][1]*rhs.matrix[1][0]));
			linearDeterminants[1]=((matrix[0][0]*rhs.matrix[1][1])-(rhs.matrix[0][1]*matrix[1][0]));
		
			return linearDeterminants;
		}
		else{
			int F,G,H;
			linearDeterminants = new double[3];
			F=((rhs.matrix[0][0])*((matrix[1][1]* matrix[2][2])-(matrix[1][2] * matrix[2][1])))-1*(matrix[0][1]*c07777
			G=
			H=
			
		}
	
	
}
													       // Linear equations:
/*Task 3 starts here*/
double Matrix::operator~(){}
Matrix Matrix::operator|=(Matrix &rhs){}
