#include <iostream> // cpp standard
#include <conio.h> // c standard
#include <vector>
#include <algorithm>
#include <string>

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

bool Predict(int NewX, int NewY)
{
	if (Map[NewY][NewX] == 0)
	{
		return true;
	}
	
	return false;
}

void Input()
{
	KeyCode = _getch();
}

void Process()
{
		if (KeyCode == 'w')
		{
			if (Map[PlayerY - 1][PlayerX] == 1)
			{
				return;
			}
			PlayerY--;

		}
		else if (KeyCode == 's')
		{
			if (Map[PlayerY + 1][PlayerX] == 1)
			{
				return;
			}
			PlayerY++;
		}
		else if (KeyCode == 'a')
		{
			if (Map[PlayerY][PlayerX - 1] == 1)
			{
				return;
			}
			PlayerX--;
		}
		else if (KeyCode == 'd')
		{
			if (Map[PlayerY][PlayerX + 1] == 1)
			{
				return;
			}
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
