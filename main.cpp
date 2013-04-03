#include "common.hpp"
#include <iostream>


int main()
{
	Common<double>* id=new Common<double>(3,3);
	id->setValue(0,0,1);
	id->setValue(1,1,1);
	id->setValue(2,2,1);
	
	Matrix<double> *n=id->scale(10);
	
	n->printAll();
		
	std::cout<<"test message"<<std::endl;
	return 0;
}
