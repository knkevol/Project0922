#include <iostream> // cpp standard
#include <conio.h> // c standard
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//LoadLevel
	int Map[10][10] = 
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int PlayerX = 1;
	int PlayerY = 1;
	char PlayerShape = 'P';
	bool bIsPlaying = true;

	//»ç»ó(Mapping)
	char Sprites[10] = { ' ', '*', };

	//Input
	while (bIsPlaying)
	{
		int KeyCode = _getch();
	
		if (KeyCode == 'w')
		{
			PlayerY--;
		}
		else if (KeyCode == 's')
		{
			PlayerY++;
		}
		else if (KeyCode == 'a')
		{
			PlayerX--;
		}
		else if (KeyCode == 'd')
		{
			PlayerX++;
		}
		else if (KeyCode == 'q')
		{
			bIsPlaying = false;
		}

		//Render();
		system("cls");
		for (int Y = 0; Y < 10; Y++)
		{
			for (int X = 0; X < 10; X++)
			{
				if (PlayerX == X && PlayerY == Y)
				{
					cout << PlayerShape;
				}
				else
				{
					cout << Sprites[Map[Y][X]];
				}
			}
			cout << "\n";
		}
	}

	return 0;
}