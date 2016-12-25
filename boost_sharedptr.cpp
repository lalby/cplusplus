#include<iostream>
#include<string>
#include<vector>
#include "C:\boost_1_57_0\boost_1_57_0\boost\shared_ptr.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\make_shared.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\shared_array.hpp"

class Myclass
{
	std::string name;
	int age;

public:
	Myclass( const std::string &fref , int fage): name(fref),age(fage) {}
	Myclass(){};
	~Myclass() { std::cout<<"Destructor called";}
	void Display() { std::cout<<name ; std::cout<<age; }
};

void testrawpointer()
{
	Myclass *ptr1= new Myclass("ram",32);
	ptr1->Display();
}

void testsharedpointer()
{
	boost::shared_ptr<Myclass> shptr1 = boost::make_shared<Myclass> ("tinu",45);
	std::vector<boost::shared_ptr<Myclass>> vMyclass;
	for(int i=0; i<=5;i++)
	{
		vMyclass.push_back(boost::make_shared<Myclass> ("abc",2));
	}
	shptr1->Display();
	//shptr1.reset();
	
	boost::shared_ptr<Myclass> shptr2= shptr1;
	shptr1->Display();
}


void main()
{
	testrawpointer();
	testsharedpointer();
	int x;
	std::cin>>x;

}