#include<iostream>
#include<string>
#include<vector>
#include "C:\boost_1_57_0\boost_1_57_0\boost\shared_ptr.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\make_shared.hpp"
#include<iostream>
#include<string>
#include<vector>
#include "C:\boost_1_57_0\boost_1_57_0\boost\shared_ptr.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\make_shared.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\shared_array.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\weak_ptr.hpp"

class B;
class A
{
public:
	int x;
	//boost::shared_ptr<B> shpB;   cyclic -so non of the object not deleted
	//solution is weak ptr
	boost::weak_ptr<B> wshpB;
	A(int y): x(y) {}
	void print(){ std::cout<<x;}
	~A(){ std::cout<<"destructor A";}
};

class B
{
public:
	int y;
	boost::shared_ptr<A> shpA;
	B(int x):y(x) {}
	void print (){ std::cout<<y;}
	~B(){ std::cout<<"destructor B"; }
};

void testcyclic()
{
	boost::shared_ptr<A> shpa=boost::make_shared<A> (1);
	boost::shared_ptr<B> shpb=boost::make_shared<B> (2);
	shpa->wshpB=shpb;
	shpb->shpA=shpa;
}


void main()
{
	int *ptr = new int(10);
	int *ref=ptr; 
	delete ptr;
	//ref will undefined data

	boost::shared_ptr<int> sptr;
	sptr.reset(new int);
	*sptr=10;

	//get pointer without taking ownership
	boost::weak_ptr<int> weak1=sptr;

	sptr.reset(new int);
	*sptr=5;

	boost::weak_ptr<int> weak2=sptr;

	if(boost::shared_ptr<int> sp3=weak1.lock())
		std::cout<<*sp3;
	else
		std::cout<<"not exists weak1";


	if(boost::shared_ptr<int> sp4=weak2.lock())
		std::cout<<*sp4;
	else
		std::cout<<"not exists weak2";


	//example 2
	//cyclic reference
	testcyclic();


	int x;
	std::cin>>x;

}