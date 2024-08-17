#include<iostream>
#include<string>
#include<fstream>
#include <conio.h>
int countroom = 0;
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define N 10
#define M 10
class Recursive
{
	class node
	{
	public:
		friend class Recursive;
		int x;
		int y;
		node* next;
	};

public:
	node* top;
	Recursive() { top = nullptr; }
	void push(int a, int b)
	{
		if (top == nullptr)
		{
			node* temp = new node;
			temp->x = a;
			temp->y = b;
			top = temp;
			temp->next = nullptr;
		}
		else
		{
			node* temp = new node;
			temp->x = a;
			temp->y = b;
			temp->next = top;
			top = temp;
		}
	}
	void printnode()
	{
		node* c = top;
		while (c != nullptr)
		{
			cout << c->x << c->y << " ";
			c = c->next;
		}
		cout << endl;
	}

};

void Print(int r, int c, char map[10][10])
{
	system("cls");
	char X = '#', S = ' ';

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (i == r && j == c) cout << "*" << "  ";
			else cout << map[i][j] << "  ";
		cout << endl;
	}
}

void filehandeling(char map[10][10], string a);

bool ROOM1(int x, int y, char map[10][10], Recursive& path);

bool ROOM2(int x, int y, char map[10][10], Recursive& path);

bool ROOM2(int x, int y, char map[10][10], Recursive& path)
{
	string roomname = "room2.txt";
	filehandeling(map, roomname);
	int c;
	while (1)
	{
		c = 0;
		switch ((c = _getch()))
		{
		case KEY_UP:
			if (x > 1 && map[x - 1][y] != 'X') x = x - 1;
			Print(x, y, map);
			break;
		case KEY_DOWN:
			if (x < N - 2 && map[x + 1][y] != 'X') x = x + 1;
			Print(x, y, map);
			break;
		case KEY_LEFT:
			if (y > 1 && map[x][y - 1] != 'X') y = y - 1;
			Print(x, y, map);
			break;
		case KEY_RIGHT:
			if (y < M - 2 && map[x][y + 1] != 'X') y = y + 1;
			Print(x, y, map);
			break;
		default:
			break;
		}
		if (map[x][y] == 'D')
		{
			return false;
		}
		else if (map[x][y] == 'G')
		{
			//
		}

		else if (map[x][y] == 'P')
		{

			int random = rand() % 2;
			if (random == 0)
			{
				return ROOM1(6, 1, map, path);
			}
			else
			{
				int random1 = rand() % 2;
				if (random1 == 0)
				{
					return ROOM1(6, 1, map, path);
				}
				else { return ROOM2(6, 1, map, path); }
			}
		}

		else if (map[x][y] == 'T')
		{
			return true;
		}
		path.push(x, y);
	}
}

bool ROOM1(int x, int y, char map[10][10], Recursive& path)
{
	string roomname = "room1.txt";
	int c;
	filehandeling(map, roomname);
	while (1)
	{
		c = 0;
		switch ((c = _getch()))
		{
		case KEY_UP:
			if (x > 1 && map[x - 1][y] != 'X') x = x - 1;
			Print(x, y, map);
			break;
		case KEY_DOWN:
			if (x < N - 2 && map[x + 1][y] != 'X') x = x + 1;
			Print(x, y, map);
			break;
		case KEY_LEFT:
			if (y > 1 && map[x][y - 1] != 'X') y = y - 1;
			Print(x, y, map);
			break;
		case KEY_RIGHT:
			if (y < M - 2 && map[x][y + 1] != 'X') y = y + 1;
			Print(x, y, map);
			break;
		default:
			break;
		}
		if (map[x][y] == 'D')
		{
			return false;
		}

		else if (map[x][y] == 'G')
		{
			//
		}

		else if (map[x][y] == 'P')
		{
			int random = rand() % 2;
			if (random == 0)
			{
				if (countroom == 0)
				{
					return false;
				}
				else
				{
					countroom = 1;
					return ROOM2(6, 1, map, path);
				}
			}
			else
			{
				countroom = 1;
				int random1 = rand() % 2;
				if (random1 == 0)
				{
					return ROOM2(6, 1, map, path);
				}
				else { return ROOM1(6, 1, map, path); }
			}
		}

		else if (map[x][y] == 'T')
		{
			return true;
		}
		path.push(x, y);
	}

}

void filehandeling(char map[10][10], string a)
{
	string str;
	fstream file; char data;
	file.open(a);
	if (!file)
	{
		cout << "No file found!" << endl;
	}
	else
	{
		char d;
		int i = 0;
		while (!file.eof())
		{
			getline(file, str);
			for (int j = 0, k = 0; j < 10; j++, k = k + 2)
			{
				d = str[k];
				map[i][j] = d;
			}
			i++;
		}
		file.close();
	}


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Recursive path;

	int x = 2, y = 4;
	char map[10][10];
	if (ROOM1(x, y, map, path))
	{
		cout << "-----Congratulations!----" << endl;
		path.printnode();
	}
	else
	{
		cout << "----Game over!-----" << endl;
		path.printnode();
	}
	system("Pause");
	return 0;
}