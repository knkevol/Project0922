#include <iostream>

using namespace std;

int main()
{
	int NumArray[10] = { 0, };

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < j; ++i)
		{
			cout << " ";
			
		}
		for (int k = 0; k < 5-j; ++k)
		{
			cout << "*";
		}
		
		cout << "\n";
	}
	

	return 0;
}