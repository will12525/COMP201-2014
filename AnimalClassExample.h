#include <iostream>
#include <string>

using namespace std;

class Animal{
	public:
	//constructor
		Animal(string word)
		{
			greeting = word;
		}
		void speak()
		{
			cout<<greeting<<endl;
		}
	private:
		string greeting;
};

int main()
{
//these animals live on the stack
//on a stack exiting a function cleans up the mess
	Animal lion("roar");
	Animal dog("woof");
	
	lion.speak();
	dog.speak();
	
	//these live on the heap
	//doesnt clean up junk, need to delete stuff seperatly
	Animal * tiger = new Animal("Roar");
	Animal * liger = new Animal("lol");
	Animal * person;
	person = new Animal("Don't eat me");

	(*tiger).speak(); //this or line below
	tiger->speak();
	
	//need to delete
	delete tiger;
	delete liger;
	delete person;
	
	
	return 0;
}