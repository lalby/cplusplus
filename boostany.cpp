#include<iostream>
#include "C:\boost_1_57_0\boost_1_57_0\boost\any.hpp"
#include <vector>


bool isInt(const boost::any &oper)
{
	try{
		 boost::any_cast<int>(oper);
		  return true;
	}
	catch(boost::bad_any_cast &tmp)
	{
		return false;
	}

}



void main()
{
	int ax=10;
	std::cout<<ax;
	std::vector<boost::any >anyContainer;
	anyContainer.push_back(2);
	anyContainer.push_back("name");
	int *p;
	p=&ax;
	anyContainer.push_back(p);

	std::vector<boost::any>::iterator it;
	for(it=anyContainer.begin();it!=anyContainer.end();it++)
	{
		if (isInt(*it))
		{
			int x= boost::any_cast<int> (*it);
			std::cout<<x;
		}
		else
		{
			std::cout<<"not an integer";
		}
	}

	std::cin>>ax;
}
