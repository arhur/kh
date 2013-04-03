#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

template <class T>
class Matrix 
{
	private:
		int width,height;
	public:
		Matrix(int w,int h) : width(w),height(h) {}
		int getWidth()
		{
			return width;
		}
		int getHeight()
		{
			return height;
		}	
		virtual Matrix<T>* mul(Matrix<T>* matr)=0;
		virtual Matrix<T>* add(Matrix<T>* matr)=0;
		virtual Matrix<T>* scale(T coef)=0;
		virtual T getValue(int i,int j)=0;
		void printAll();
};


template<class T>
void Matrix<T>::printAll()
{
		for (int i=0;i<height;++i) {
			for (int j=0;j<width;++j)
				std::cout<<getValue(i,j)<<" ";
			std::cout<<std::endl;
		}
}
#endif
