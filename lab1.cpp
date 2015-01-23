#include <fstream>
#include <iostream>
using namespace std;


int main(int variable, char* args[])
{

	ifstream ifs;
	ifs.open(args[1]);

	if(ifs.fail())
	{
		cout<<"FAILED";
		ifs.close();
		exit(1);
	}

	cout<<"x x^2 Current sum\n= === ===========\n";

	int sum=0;
	int number=0;
	while(ifs>>number)
	{
		sum=sum+number;
		cout<<number<<" "<<number*number<<" "<<sum<<endl;
	}

return 0;
}