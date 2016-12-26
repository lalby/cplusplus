#include<iostream>
#include<string>
#include<vector>
#include "C:\boost_1_57_0\boost_1_57_0\boost\variant.hpp"
#include "C:\boost_1_57_0\boost_1_57_0\boost\optional.hpp"

class trylock
{
	std::string lock;
public:
	trylock(std::string tmp) : lock(tmp){}
	void locktype() { std::cout<< lock; }
};


boost::optional<trylock> getLock(int x)
{
	if(x%2)
		return boost::none;
	else
		return trylock("ReadLock");
}

int main()
{
	int x;
	std::cin>>x;
	boost::optional<trylock> lock=getLock(x);
	if(lock)
		lock->locktype();
	else
	{
		std::cout<<"try again";
		std::cin>>x;
		boost::optional<trylock> lock=getLock(x);
		if(lock)
		lock->locktype();
	}

}

