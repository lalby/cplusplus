#include<iostream>
#include<string>
#include<vector>
#include "C:\boost_1_57_0\boost_1_57_0\boost\variant.hpp"


typedef boost::variant<std::string, int ,char *> myVariant;

bool isInt(myVariant temp)
{
	try{
		int x= boost::get<int> (temp);
		return true;
	}
	catch(boost::bad_get &e)
	{
		return false;
	}
}

int main()
{

	
	std::vector<myVariant> Container;
	Container.push_back(10);
	Container.push_back("hello");
	char *p ="good";

	Container.push_back(20);

	//std::string &sdata=boost::get<std::string> (Container.back());
	int data;
	if(isInt(Container.back()))
	{
		int	data=boost::get<int> (Container.back());
		std::cout<<data;
	}
	int x;
	std::cin>>x;

}