#include <iostream> // cpp standard
#include <conio.h> // c standard

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

bool Predict(int NewY, int NewX)
{
	if (NewY >= 0 && NewY < 10 && NewX >= 0 && NewX < 10)
	{
		if (Map[NewY][NewX] == 0)
		{
			return true;
		}
	}

	return false;
}

void Input()
{
	KeyCode = _getch();
}

void Process()
{
	int nextX = PlayerX;
	int nextY = PlayerY;

	if (KeyCode == 'w')
	{
		nextY--;
	}
	else if (KeyCode == 's')
	{
		nextY++;
	}
	else if (KeyCode == 'a')
	{
		nextX--;
	}
	else if (KeyCode == 'd')
	{
		nextX++;
	}
	else if (KeyCode == 'q')
	{
		bIsPlaying = false;
		return;
	}

	if (Predict(nextY, nextX))
	{
		PlayerX = nextX;
		PlayerY = nextY;
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
