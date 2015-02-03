#include <iostream>
using namespace std;


//g++ -g PointerIntro.cpp -o PointerIntro.exe
//-g allows to run in debugger
//gdb PointerIntro.exe

int main(int argc, char* argv[])
{
	//declaring a variable allocates space in memory for that variable
	//That memory is in the stack
	int variable;
	variable = 500;
	//Declaring a pointer also declares a variable
	//that memory is also on the stack
	int* pointer;
	//initialize the pointer to where variable happens to be
	pointer = &variable;
	//*pointer de-references the pointer(we get what its pointing at)
	cout<<*pointer<<endl;
	return 0;
}

//set breakpoints tells the debugger where to stop.
//break main //set a breakpoint on main
//run [cmdline arguments] // run program with command line