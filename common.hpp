#ifndef COMMON_HPP
#define COMMON_HPP

#include <stdlib.h>
#include "matrix.hpp"

template <class T>
class Common:public Matrix<T>
{
	private:
		T** M;	
	public:
		Common(int w,int h,T defValue=0);
		T getValue(int i,int j);
		void setValue(int i,int j,T value);
		Matrix<T>* mul(Matrix<T>* matr);
		Matrix<T>* add(Matrix<T>* matr);
		Matrix<T>* scale(T coef);
};
		
template <class T>
Matrix<T>* Common<T>::mul(Matrix<T>* matr)
{
	int m1,n1,m2,n2;
	m1=this->getHeight();
	n1=this->getWidth();
	m2=matr->getHeight();
	n2=matr->getWidth();
	if (n1!=m2) 
		exit(EXIT_FAILURE);
	
	Common<T>* res=new Common<T>(m1,n2,0);
	
	for (int i=0;i<m1;++i)
	{
		for (int j=0;j<n2;++j)
		{
			T sum=0;
			for (int k=0;k<n1;++k)
				sum+=this->getValue(i,k)*matr->getValue(k,j);
			res->M[i][j]=sum;
		}
	}	
	return res;
}

template <class T> 
Common<T>::Common(int w,int h,T defValue):Matrix<T>(w,h)
{
			M=new T*[h];
			for (int i=0;i<h;++i) {
				M[i]=new T[w];
				for (int j=0;j<w;++j)
					M[i][j]=defValue;
			}	
}

template <class T> 
T Common<T>::getValue(int i,int j)
{
	if ((i< this->getHeight()) && (j<this->getWidth())) 
		return M[i][j];
	else 
		exit(EXIT_FAILURE);

}

template <class T>
void Common<T>::setValue(int i,int j,T value)
{
	if ((i< this->getHeight()) && (j< this->getWidth())) 
		M[i][j]=value;
	else
		exit(EXIT_FAILURE);
}

 
template <class T>
Matrix<T>* Common<T>::add(Matrix<T>* matr)
{
	int m1,n1,m2,n2;
	m1=this->getHeight();
	n1=this->getWidth();
	m2=matr->getHeight();
	n2=matr->getWidth();
	if (n1!=n2 ||  m1!=m2)
		exit(EXIT_FAILURE);
	Common<T>* res=new Common<T>(m1,n1,0);
	for (int i=0;i<m1;++i)
		for (int j=0;j<n1;++j)
			res->M[i][j]=M[i][j]+matr->getValue(i,j);
	return res;
}

template <class T>
Matrix<T>* Common<T>::scale(T coef)
{
	
	int m,n;
	m=this->getHeight();
	n=this->getWidth();
	
	Common<T>* res=new Common<T>(m,n,0);

	for (int i=0;i<m;++i)
		for (int j=0;j<n;++j)
			res->M[i][j]=M[i][j]*coef;

	return res;

}
#endif

