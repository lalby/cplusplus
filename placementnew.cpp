#include<iostream>
#include<string>
//#include<vector>
//#include "C:\boost_1_57_0\boost_1_57_0\boost\variant.hpp"
//#include "C:\boost_1_57_0\boost_1_57_0\boost\optional.hpp"

//placement new

class Base
{
	int x;
public:
	Base() {std::cout<<" constructor called"<<std::endl; }
	void printData() { std::cout<<x;}
	~Base() { std::cout <<" destutcor called"; }
};


void main()
{
	char *mem = new char [10* sizeof(Base)];
	Base *b1= (Base *) new(&mem[0]) Base();
	
	b1->~Base();
	delete [] mem;
}







