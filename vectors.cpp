#include<vectors>
#include<iostream>
#include <math.h>
using namespace std;

int main(int argc, char* argv[])
{
	//vector<type> vector_name(size)
	vector<long long> numbers(50);
	
	//cout<<sizeof(long long)<<endl;
	
	for(int x=0;x<50;x++)
	{
	cout<<"size: "<<numbers.size()<<" capacity "<<numbers.capcaity()<<endl;
	numbers.push_back(pow(2,x));
	//numbers[x]=42;
	}
	
	for(int x=0;x<numbers.size();x++)
	{
		cout<<numbers[x]<<endl;
	}








	return 0;
}

/*
int main(int argc, char* argv[])
{
	int numbers[50];
	for(int x=0;x<50;x++)
	{
		numbers[x]=x;
	}
		
	

}



*/