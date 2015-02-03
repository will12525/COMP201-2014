#include <iostream>
using namespace std;

void age_a_year(int & age)
{
	age++;
}

//C-style version
void age_a_year_old_C_way()
{

}
int main()
{
	int jack = 50;
	age_a_year(jack);
	cout<<jack<<endl;

}