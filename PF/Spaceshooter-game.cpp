#include<iostream>
#include<conio.h>
#include"graphics.h"
#include<Windows.h>
#include<fstream>
#include<thread>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void aliens(int xr, int yr, int xr1, int yr1, int xr2, int yr2, int level)
{
	setcolor(RED);
	rectangle(xr, yr, xr + 20, yr + 10);
	setfillstyle(SOLID_FILL, RED);
	floodfill(xr + 5, yr + 5, RED);
	setcolor(YELLOW);
	rectangle(xr1, yr1, xr1 + 20, yr1 + 10);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(xr1 + 5, yr1 + 5, YELLOW);
	if (level >= 3) {
		setcolor(BLUE);
		rectangle(xr2, yr2, xr2 + 20, yr2 + 10);
		setfillstyle(SOLID_FILL, BLUE);
		floodfill(xr2 + 5, yr2 + 5, BLUE);
	}
}

void spaceship(int& m, int& d, int& e, int c, int b, int& s1, int f)
{
	m = c + 10;
	if (f == 0) {
		e = s1 - 10, d = s1 - 20;
	}
	setcolor(WHITE);
	rectangle(c, s1 - 20, b, s1);
	line(m, d, m, e);

}
void main_design()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\tI  N  S  T  R  U  C  T  I  O  N  S\n";
	cout << endl;
	cout << endl;
	cout << "\t\t1. USE A OR D TO MOVE\n";
	cout << endl;
	cout << "\t\t2. PRESS SPACE TO FIRE BULLETS\n";
	cout << endl;
	cout << "\t\t3. AVOID HITTING SPACE DEBRIS\n";
	cout << endl;
	cout << "\t\t4. DIFFERENT COLOURED SPACE DEBRIS WILL GIVE DIFFERENT SCORE\n";
	cout << endl;
	cout << "\t\t5. PRESS ESC TO RESTART GAME\n";
	cout << endl;
}
void design()
{

	rectangle(18, 12, 470, 470);
	rectangle(12, 7, 475, 475);
	rectangle(12, 7, 678, 475);
	rectangle(480, 12, 673, 151);
	rectangle(480, 155, 673, 271);
	rectangle(480, 276, 673, 470);
	settextstyle(6, 0, 1.5);
	outtextxy(520, 40, "S P A C E");
	outtextxy(500, 80, "S H O O T E R");
	outtextxy(510, 390, "LIVES : ");
	outtextxy(510, 200, "LEVEL : ");
	outtextxy(510, 320, "SCORE : ");

}
int levels(int xr, int xr1, int xr2, int& yr2, int& yr, int& yr1, int score, int& flag, int& m, int& e, int& d, int& cnt, int& count, int s1, int level, int& s, int& lives, int& chk, int& ct)
{

	if ((xr < 440 && xr>20) && (xr1 < 440 && xr1>20) && (xr2 < 440 && xr2>20))
	{
		aliens(xr, yr, xr1, yr1, xr2, yr2, level);
		cnt = 1;
		count = 1;
		ct = 1;
		if (flag == 1)
		{
			if (m >= xr && m <= xr + 20)
			{
				if (e >= yr && e <= yr + 10 && e < s1 - 10)
				{
					yr = 600;
					d = 430, e = 440;
					cnt = 0;
					flag = 0;
					score += 5;
				}
			}
			if (m >= xr1 && m <= xr1 + 20)
			{
				if (e >= yr1 && e <= yr1 + 10 && e < s1 - 10)
				{
					yr1 = 600;
					d = 430, e = 440;
					count = 0;
					flag = 0;
					score++;
				}
			}
			if (m >= xr2 && m <= xr2 + 20)
			{
				if (e >= yr2 && e <= yr2 + 10 && e < s1 - 10)
				{
					yr2 = 600;
					d = 430, e = 440;
					ct = 0;
					flag = 0;
					score += 10;
				}
			}
			if (yr < 440)
			{
				yr += level;
			}
			else if (yr >= 440 && yr != 600)
			{
				yr = 600;
				lives--;
				if (lives == 0)
				{
					chk = 1;
				}
			}
			else if (yr == 600)
			{
				cnt = 0;
			}

			if (yr1 < 440)
			{
				yr1 += level;
			}
			else if (yr1 >= 440 && yr1 != 600)
			{
				yr1 = 600;
				lives--;
				if (lives == 0)
				{
					chk = 1;
				}
			}
			else if (yr1 == 600)
			{
				count = 0;
			}
			if (yr2 < 440)
			{
				yr2 += level;
			}
			else if (yr2 >= 440 && yr2 != 600)
			{
				yr2 = 600;
				lives--;
				if (lives == 0)
				{
					chk = 1;
				}
			}
			else if (yr2 == 600)
			{
				ct = 0;
			}
		}
	}
	return score;
}

void main()
{
	main_design();
	char t[10];
	cout << "Enter your name" << endl;
	cin >> t;
	int ct = 0;
	char a = 0; int s1 = 450;
	int lives = 3, level = 1, l = 0, s = 10;
	int score = 0;
	int pf = 0;
	char scoreboard[10] = { 0 };
	char livesboard[10] = { 0 }, levelboard[10] = { 0 };
	int c = 222, b = 242, d = 430, e = 440, k = 0, m, flag = 0;
	int y = 50, x = 50, x1 = 120, y1 = 50;
	srand((unsigned)time(0));
	int xr, xr2, yr2;
	int yr;
	int xr1;
	int yr1;
	int cnt = 0, chk = 0;
	int count = 0;
	initwindow(700, 500);
	while (1)
	{


		cleardevice();
		spaceship(m, d, e, c, b, s1, flag);
		itoa(score, scoreboard, 10);
		outtextxy(620, 320, scoreboard);
		design();
		itoa(lives, livesboard, 10);
		outtextxy(620, 390, livesboard);
		itoa(level, levelboard, 10);
		outtextxy(620, 200, levelboard);
		if (cnt == 0)
		{
			xr = 10 + rand() % 470;
			yr = 10 + rand() % 20;
		}
		if (count == 0)
		{
			xr1 = 10 + rand() % 470;
			yr1 = 10 + rand() % 20;
		}
		if (ct == 0)
		{
			xr2 = 20 + rand() % 470;
			yr2 = 10 + rand() % 20;
		}


		if (c >= xr && c <= xr + 20 || b >= xr && b <= xr + 20)
		{
			if (s1 >= yr && s1 <= yr + 10)
			{
				lives--;
				yr = 600;
				if (lives == 0)
				{
					initwindow(700, 500);
					settextstyle(6, 0, 1);
					outtextxy(180, 150, "YOU HAVE LOST THE GAME");
					outtextxy(150, 220, "PRESS ESC TO QUIT THE GAME");
					a = getch();
					if (a == 27) {
						break;
					}
				}
			}
		}
		if (c >= xr1 && c <= xr1 + 20 || b >= xr1 && b <= xr1 + 20)
		{
			if (s1 >= yr1 && s1 <= yr1 + 10)
			{
				lives--;
				yr1 = 600;
				if (lives == 0)
				{
					initwindow(700, 500);
					settextstyle(6, 0, 1);
					outtextxy(180, 150, "YOU HAVE LOST THE GAME");
					outtextxy(150, 220, "PRESS ESC TO QUIT THE GAME");
					a = getch();
					if (a == 27) {
						break;
					}
				}
			}
		}
		if (c >= xr2 && c <= xr2 + 20 || b >= xr2 && b <= xr2 + 20)
		{
			if (s1 >= yr2 && s1 <= yr2 + 10)
			{
				lives--;
				yr2 = 600;
				if (lives == 0)
				{
					initwindow(700, 500);
					settextstyle(6, 0, 1);
					outtextxy(180, 150, "YOU HAVE LOST THE GAME");
					outtextxy(150, 220, "PRESS ESC TO QUIT THE GAME");
					a = getch();
					if (a == 27) {
						break;
					}
				}
			}
		}
		if (score >= s)
		{
			level++;
			s += (level * 10);
			if (level > 5) {
				initwindow(700, 500);
				settextstyle(6, 0, 1);
				outtextxy(180, 150, "YOU HAVE WON THE GAME");
				outtextxy(150, 220, "PRESS ESC TO QUIT THE GAME");
				a = getch();
				if (a == 27) {
					break;
				}
			}
		}
		score = levels(xr, xr1, xr2, yr2, yr, yr1, score, flag, m, e, d, cnt, count, s1, level, s, lives, chk, ct);
		if (chk == 1) {
			initwindow(700, 500);
			settextstyle(6, 0, 1);
			outtextxy(180, 150, "YOU HAVE LOST THE GAME");
			outtextxy(150, 220, "PRESS ESC TO QUIT THE GAME");
			a = getch();
			if (a == 27) {
				break;
			}
		}
		if (d < s1 - 20)
		{
			d -= 5;
			e -= 5;

			if (d < 30)
			{
				d = s1 - 20;
				e = s1 - 10;
			}
		}

		delay(5);
		if (kbhit())
		{
			a = getch();

			if (a == 'd')
			{
				if (b < 460)
				{
					b += 10;
					c += 10;
				}
			}
			else if (a == 'a')
			{
				if (c > 28)
				{
					b -= 10;
					c -= 10;
				}
			}
			else if (a == ' ')
			{
				d -= 5;
				e -= 5;
				flag = 1;
			}
			else if (a == 27)
			{
				break;
			}

		}
	}
	fstream file("score.txt", ios::app);
	file << t << ":" << score << endl;
	file.close();
}