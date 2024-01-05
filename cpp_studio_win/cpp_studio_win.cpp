// cpp_studio_win.cpp : Defines the entry point for the application.
//

#include "cpp_studio_win.h"

using namespace std;

/**
* Function shows loops and break and continue
*/
void loops_break_continue()
{
	int j = 0;
	//
	for (int i = 0; i < 10; i++)
	{
		while (j < 10)
		{
			cout << "i = " << i << " j = " << j << endl;
			if (j > 3)
				break;
			j++;
			
			if (j > 5)
				continue;

			cout << "j now -> " << j << endl;
		}

	}

}

int main()
{
	cout << "Hello CMake." << endl;
	//
	//loops_break_continue();
	return 0;
}
