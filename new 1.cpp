#include <iostream>
using namespace std;

int main()
{
	int number,product;
	cout<<"How many ints?"
	cin >>number;
	product = 1;
	
	int * array = new int[number];
	for(int i=0;i<number;i++)
	{
		cout<<"number: ";
		cin>>array[i];
	}
	for(int i=0;i<number;i++)
	{
		product *= array[i];
	}
	delete array;
	cout<<product<<endl;
	return 0;

}