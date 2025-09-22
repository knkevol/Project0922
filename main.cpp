#include <iostream> // cpp standard
#include <conio.h> // c standard
#include <vector>
#include <algorithm>

using namespace std;

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

int KeyCode = 0;

void Input()
{
	KeyCode = _getch();
}
void Process()
{
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

}
void Render()
{
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

int main()
{
	

	//frame
	while (bIsPlaying)
	{
		Input();
		Process();
		Render();
	}

	return 0;
}
