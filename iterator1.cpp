#include <iostream>

template<typename T>
inline T const & max(T a,T b){ return (a>b ? a:b);}

int main()
{
	cout<<max(4,2);
	cout<<max(4,2.3);
}
