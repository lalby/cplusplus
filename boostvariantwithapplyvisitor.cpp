#include<iostream>
#include<string>
#include<vector>
#include "C:\boost_1_57_0\boost_1_57_0\boost\variant.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\foreach.hpp"

class NewOrder
{
	double ordsize;
	std::string ric;
	double price;
public:
	NewOrder(const double size,const std::string &tric, const double fprice): ordsize(size),ric(tric),price(fprice){}
};
class AmendOrder
{
	double ordsize;
	std::string ric;
	double price;
public:
	AmendOrder(const double size,const std::string &tric, const double fprice): ordsize(size),ric(tric),price(fprice){}
};

typedef boost::variant<NewOrder,AmendOrder> myCont;
typedef std::vector<myCont> myVect;

class Order:public boost::static_visitor<>
{
public:
	void operator()(NewOrder &t)
	{
		std::cout<<"New order ";
	}
	void operator()(AmendOrder &t)
	{
		std::cout<<"AmendOrder ";
	}

};

myVect OrderStore;

class publishOrder
{
	Order ord;
	public:
	
		void operator()()
		{
			BOOST_FOREACH(myCont &v, OrderStore)
			{
					boost::apply_visitor(ord,v);
			}	
		}
};

int main()
{
	NewOrder NO(23,"12.HK",34);
	AmendOrder AM(23,"12.HK",38);
	publishOrder PO;
	
	OrderStore.push_back(NO);
	OrderStore.push_back(AM);
	PO();

	int x;
	std::cin>>x;

}