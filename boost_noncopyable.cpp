#include<iostream>
#include "C:\boost_1_57_0\boost_1_57_0\boost\scoped_ptr.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\noncopyable.hpp"


class Animals : private boost::noncopyable
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

class DerivedAnimals: public Animals
{
public:
	void fly(){ std::cout<<"i can fly";}
	void operator= (DerivedAnimals &tmp)
	{
		std::cout<<"I can copy";
	}
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
	// if derived class override the = and copy construct then will be copyable
	DerivedAnimals b,a;
	a=b;
	int x;
	std::cin>>x;


}

