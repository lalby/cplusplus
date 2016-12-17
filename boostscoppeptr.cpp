#include<iostream>
#include "C:\boost_1_57_0\boost_1_57_0\boost\scoped_ptr.hpp"

class Animals
{
	int type;
	char name[20];
public:
	Animals(){ std::cout<<"constructor called"<<std::endl;}
	void setname(){ std::cout<<"name";}
	void getname(){std::cout<<"lion";}
	void sound(){ std::cout<<" grrr"; } 
	~ Animals() { std::cout<<"destructor called "<<std::endl;}
};

void testsound(Animals *temp)
{
	temp->sound();
}


void foo()
{
	boost::scoped_ptr<Animals> smartptrAnimal;
	smartptrAnimal.reset(new Animals);
	Animals *ptr=smartptrAnimal.get();
	testsound(ptr);
	smartptrAnimal->getname();
}




void main()
{
	foo();
	int x;
	std::cin>>x;
}
