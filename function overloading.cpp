#include <iostream>

using namespace std;

class Animals
{
	public:
	void sound()
	{
	cout << "This is parent class" << endl;
	}
};

class Dogs : public Animals
{
	public:
	void sound()
	{
	cout << "Dogs bark" << endl;
	}
};

int main()
{
           Dogs d;
	d.sound();
	return 0;
}
