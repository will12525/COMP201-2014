#include <string>
#include <vector>
#include <iostream>
#include <ifstream>

using namespace std;

int main()
{
	vector<string> words;
	string word;
	//reads in words until done
	while(cin>>word)
	{
	
		if(word=="done")
		{
		break;
		}
		words.push_back(word);


	}
	
	//prints out words in reverse
	while(words.size()>0)
	{
		cout<<words.back()<<endl;
		words.pop_back();
	
	
	}

	return 0;
}