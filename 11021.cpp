#include <iostream>
using namespace std;

int num, num1;
int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> num >> num1;

		cout << "Case #" << i + 1 << ": " << num + num1 << endl;
	}
}