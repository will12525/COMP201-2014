#include <iostream>
using namespace std;

int main()
{
	for(int x=0;x<=100;x++)
	{

		if(x%3==0&&x%5==0)
		{
			cout<<"FizzBuzz";
		}
		else if(x%3==0)
		{
			cout<<"Fizz";
		}
		else if(x%5==0)
		{
			cout<<"Buzz";
		}
		else
		{
			cout<<x;
		}

	}
	return 0;
}