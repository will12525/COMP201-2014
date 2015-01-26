#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int variable, char* args[])
{

	ifstream ifs;
	ifs.open(args[1]);

	if(ifs.fail())
	{
		cout<<"FAILED, Please provide a text document";
		ifs.close();
		exit(1);
	}

	vector<int> numbers;
	string number="";
	while(ifs>>number)
	{
		if(number=="+")
		{
			if(numbers.size()<2)
			{
				cout<<"Not enough in string"<<endl;
				return 0;
			}
			int x1 =numbers.back();
			numbers.pop_back();
			int x2 = numbers.back();
			numbers.pop_back();
		
			int num=x2+x1;
			
			//cout<<num<<endl;
	
			numbers.push_back(num);
		}
		else if(number=="-")
		{
			if(numbers.size()<2)
			{
				cout<<"Not enough in string"<<endl;
				return 0;
			}
			int x1 =numbers.back();
			numbers.pop_back();
			int x2 = numbers.back();
			numbers.pop_back();
		
			int num=x2-x1;
			
			//cout<<num<<endl;
	
			numbers.push_back(num);
		}
		else if(number=="*")
		{
			if(numbers.size()<2)
			{
				cout<<"Not enough in string"<<endl;
				return 0;
			}
			int x1 =numbers.back();
			numbers.pop_back();
			int x2 = numbers.back();
			numbers.pop_back();
		
			int num=x2*x1;
			
			//cout<<num<<endl;
	
			numbers.push_back(num);
		}
		else if(number=="/")
		{
			if(numbers.size()<2)
			{
				cout<<"Not enough in string"<<endl;
				return 0;
			}
			int x1 =numbers.back();
			numbers.pop_back();
			int x2 = numbers.back();
			numbers.pop_back();
		
			int num=x2/x1;
			
			//cout<<num<<endl;
	
			numbers.push_back(num);
		}
		else
		{
			char *end;
			int newNumber = strtol(number.c_str(), &end, 10);
			numbers.push_back(newNumber);	
		}
	}
	
	
		cout<<numbers.at(0);
	

}