#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

short id = 0;
short nextid = 0;
short rot = 0;
short X = 0;
short Y = 0;

unsigned int Time = 0;
float worktime = 0;
float controlTime = 0;
float gTime = 1;
int score = 0;
bool pause = false;
bool gameover = false;
float gameovertime = 0;
int level = 1;
bool controlType = 0;
short sens = 1;

bool buff[20][14]{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setSymbol(int cx, int cy, char symbol) {
	COORD Cur;
	Cur.X = cx;
	Cur.Y = cy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	cout << symbol;
}

void setCursor(int cx, int cy) {
	COORD Cur;
	Cur.X = cx;
	Cur.Y = cy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void update() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 14; j++) {
			if (buff[i][j]) setSymbol(j+1, i+1, '#');
			else setSymbol(j+1, i+1, ' ');
		}
}

void deletef() {
	switch (id) {
	case 1:
		if (rot == 0) {
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
			buff[Y + 1][X] = false;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = false;
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
		}
		else if (rot == 2) {
			buff[Y - 1][X] = false;
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
		}
		else if (rot == 3) {
			buff[Y - 1][X] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
			buff[Y + 1][X] = false;
		}
		break;
	case 2:
		if (rot == 0) {
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
			buff[Y + 1][X + 1] = false;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
			buff[Y + 1][X - 1] = false;
		}
		else if (rot == 2) {
			buff[Y - 1][X - 1] = false;
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
		}
		else if (rot == 3) {
			buff[Y - 1][X] = false;
			buff[Y - 1][X + 1] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
		}
		break;
	case 3:
		if (rot == 0) {
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
			buff[Y + 1][X + 1] = false;
		}
		else if (rot == 1) {
			buff[Y - 1][X + 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
			buff[Y + 1][X] = false;
		}
		break;
	case 4:
		buff[Y][X] = false;
		buff[Y][X + 1] = false;
		buff[Y + 1][X] = false;
		buff[Y + 1][X + 1] = false;
		break;
	case 5:
		if (rot == 0) {
			buff[Y + 1][X - 1] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
			buff[Y][X + 1] = false;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
			buff[Y + 1][X + 1] = false;
		}
		break;
	case 6:
		if (rot == 0) {
			buff[Y][X - 1] = false;
			buff[Y + 1][X - 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
		}
		else if (rot == 1) {
			buff[Y - 1][X - 1] = false;
			buff[Y - 1][X] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
		}
		else if (rot == 2) {
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
			buff[Y - 1][X + 1] = false;
		}
		else if (rot == 3) {
			buff[Y - 1][X] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
			buff[Y + 1][X + 1] = false;
		}
		break;
	case 7:
		if (rot == 0) {
			buff[Y][X - 1] = false;
			buff[Y][X] = false;
			buff[Y][X + 1] = false;
			buff[Y][X + 2] = false;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = false;
			buff[Y][X] = false;
			buff[Y + 1][X] = false;
			buff[Y + 2][X] = false;
		}
		break;
	}
}

void drawf() {
	switch (id) {
	case 1:
		if (rot == 0) {
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
			buff[Y + 1][X] = true;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = true;
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
		}
		else if (rot == 2) {
			buff[Y - 1][X] = true;
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
		}
		else if (rot == 3) {
			buff[Y - 1][X] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
			buff[Y + 1][X] = true;
		}
		break;
	case 2:
		if (rot == 0) {
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
			buff[Y + 1][X + 1] = true;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
			buff[Y + 1][X - 1] = true;
		}
		else if (rot == 2) {
			buff[Y - 1][X - 1] = true;
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
		}
		else if (rot == 3) {
			buff[Y - 1][X] = true;
			buff[Y - 1][X + 1] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
		}
		break;
	case 3:
		if (rot == 0) {
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
			buff[Y + 1][X + 1] = true;
		}
		else if (rot == 1) {
			buff[Y - 1][X + 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
			buff[Y + 1][X] = true;
		}
		break;
	case 4:
		buff[Y][X] = true;
		buff[Y][X + 1] = true;
		buff[Y + 1][X] = true;
		buff[Y + 1][X + 1] = true;
		break;
	case 5:
		if (rot == 0) {
			buff[Y + 1][X - 1] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
			buff[Y][X + 1] = true;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
			buff[Y + 1][X + 1] = true;
		}
		break;
	case 6:
		if (rot == 0) {
			buff[Y][X - 1] = true;
			buff[Y + 1][X - 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
		}
		else if (rot == 1) {
			buff[Y - 1][X - 1] = true;
			buff[Y - 1][X] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
		}
		else if (rot == 2) {
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
			buff[Y - 1][X + 1] = true;
		}
		else if (rot == 3) {
			buff[Y - 1][X] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
			buff[Y + 1][X + 1] = true;
		}
		break;
	case 7:
		if (rot == 0) {
			buff[Y][X - 1] = true;
			buff[Y][X] = true;
			buff[Y][X + 1] = true;
			buff[Y][X + 2] = true;
		}
		else if (rot == 1) {
			buff[Y - 1][X] = true;
			buff[Y][X] = true;
			buff[Y + 1][X] = true;
			buff[Y + 2][X] = true;
		}
		break;
	}
}

void checklines() {
	setCursor(18, 0);
	cout << "Очки: " << score;
	setCursor(18, 1);
	cout << "Уровень: " << level;
	short linesdestroyed = 0;
	short lineempty = -1;
	bool block;
	for (int i = 0; i < 20; i++) {//проверка готовых линий
		block = true;
		for (int j = 0; j < 14; j++) {
			if (!buff[i][j]) block = false;
		}
		if (block) {
			linesdestroyed++;
			for (int j = 0; j < 14; j++) {
				buff[i][j] = false;
			}
		}
	}
	if (linesdestroyed > 0) {//сдвиг
		for (int i = 19; i >= 0; i--) {//i - проверяемая строчка
			block = false;
			for (int j = 0; j < 14; j++) {
				if (buff[i][j]) block = true;
			}

			if (lineempty > -1) {//если на линии есть блок и известна пустая линия, то сдвинуть вниз
				if (block) {
					for (int j = i; j >= 0; j--) {//цикл копирования линий
						for (int l = 0; l < 14; l++) {//цикл копирования блоков слева на право
							buff[lineempty - (i - j)][l] = buff[j][l];//копирование линии на место пустой
							buff[j][l] = false;//очистка перемещаемой линии
						}
					}
					i = lineempty;//возвращение проверяемой линии на место бывшей пустой линии
					lineempty = -1;//пустая линия неизвестна
				}
			}
			else if(!block) {//если линия пуста, то линия известна
				lineempty = i;
			}
		}
	}
	
	if (linesdestroyed == 1) {
		score += 100;
	}
	else if (linesdestroyed == 2) {
		score += 300;
	}
	else if (linesdestroyed == 3) {
		score += 700;
	}
	else if (linesdestroyed == 4) {
		score += 1500;
	}
}

void drawNextf() {
	setCursor(28, 2);
	cout << "    ";
	setCursor(28, 3);
	cout << "   ";
	switch (nextid) {
	case 1:
		setCursor(28, 2);
		cout << "###";
		setCursor(29, 3);
		cout << "#";
		break;
	case 2:
		setCursor(28, 2);
		cout << "###";
		setCursor(30, 3);
		cout << "#";
		break;
	case 3:
		setCursor(28, 2);
		cout << "##";
		setCursor(29, 3);
		cout << "##";
		break;
	case 4:
		setCursor(28, 2);
		cout << "##";
		setCursor(28, 3);
		cout << "##";
		break;
	case 5:
		setCursor(29, 2);
		cout << "##";
		setCursor(28, 3);
		cout << "##";
		break;
	case 6:
		setCursor(28, 2);
		cout << "###";
		setCursor(28, 3);
		cout << "#";
		break;
	case 7:
		setCursor(28, 2);
		cout << "####";
		break;
	}
}

void generate() {
	checklines();
	if (buff[0][6]) {
		gameover = true;
	}
	X = 6;
	Y = 0;
	rot = 0;
	if (!nextid) {
		id = rand() % 7 + 1;
		nextid = rand() % 7 + 1;
	}
	else {
		id = nextid;
		nextid = rand() % 7 + 1;
	}
	drawf();
	update();
	drawNextf();
}

void restart() {
	gameover = false;
	gameovertime = 0;
	worktime = 0;
	rot = 0;
	score = 0;
	setCursor(18, 0);
	cout << "          ";
	setCursor(18, 1);
	cout << "          ";
	setCursor(18, 2);
	cout << "Седующая: ";
	setCursor(18, 0);
	cout << "Очки: " << score;
	setCursor(18, 1);
	cout << "Уровень: " << level;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 14; j++) {
			buff[i][j] = false;
			setSymbol(j + 1, i + 1, ' ');
		}
	generate();
}

void draw() {
	cout << "=====ТЕТРИС=====" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "=              =" << endl;
	cout << "================" << endl;

	setCursor(18, 2);
	cout << "Седующая: ";
	setCursor(18, 0);
	cout << "Очки: " << score;
	setCursor(18, 1);
	cout << "Уровень: " << level;
	setCursor(18, 5);
	cout << "Управление: ";
	setCursor(18, 6);
	cout << "Влево/Вправо - Управление фигурой";
	setCursor(18, 7);
	cout << "Вверх - Поворот фигуры";
	setCursor(18, 8);
	cout << "Вниз - Быстрый спуск фигуры";
	setCursor(18, 9);
	cout << "Пробел - Пауза";
	setCursor(18, 10);
	cout << "F1 - Настройки";
}

void rotatef() {
	deletef();
	switch (id) {
	case 1:
		if (rot == 0) {
			if (!buff[Y - 1][X]) {
				rot = 1;
			}
		}
		else if (rot == 1) {
			if (!buff[Y][X + 1]) {
				if(X < 13)
					rot = 2;
			}
		}
		else if (rot == 2) {
			if (!buff[Y + 1][X]) {
				if(Y < 19)
					rot = 3;
			}
		}
		else if (rot == 3) {
			if (!buff[Y][X - 1]) {
				if(X > 0)
					rot = 0;
			}
		}
		break;
	case 2:
		if (rot == 0) {
			if (!buff[Y + 1][X - 1] && !buff[Y + 1][X] && !buff[Y - 1][X]) {
				rot = 1;
			}
		}
		else if (rot == 1) {
			if (!buff[Y - 1][X - 1] && !buff[Y][X - 1] && !buff[Y][X + 1]) {
				if(X < 13)
					rot = 2;
			}
		}
		else if (rot == 2) {
			if (!buff[Y - 1][X] && !buff[Y - 1][X + 1] && !buff[Y + 1][X]) {
				if(Y < 19)
					rot = 3;
			}
		}
		else if (rot == 3) {
			if (!buff[Y][X - 1] && !buff[Y][X + 1] && !buff[Y + 1][X + 1]) {
				if(X > 0)
					rot = 0;
			}
		}
		break;
	case 3:
		if (rot == 0) {
			if (!buff[Y][X + 1] && !buff[Y - 1][X + 1]) {
				rot = 1;
			}
		}
		else if (rot == 1) {
			if (!buff[Y][X - 1] && !buff[Y + 1][X + 1]) {
				if(X > 0)
					rot = 0;
			}
		}
		break;
	case 4:

		break;
	case 5:
		if (rot == 0) {
			if (!buff[Y - 1][X] && !buff[Y + 1][X + 1]) {
				rot = 1;
			}
		}
		else if (rot == 1) {
			if (!buff[Y + 1][X - 1] && !buff[Y + 1][X]) {
				if (X > 0)
					rot = 0;
			}
		}
		break;
	case 6:
		if (rot == 0) {
			if (!buff[Y - 1][X - 1] && !buff[Y - 1][X] && !buff[Y + 1][X])
				rot = 1;
		}
		else if (rot == 1) {
			if (X < 13)
				if (!buff[Y - 1][X + 1] && !buff[Y][X + 1] && !buff[Y][X - 1])
					rot = 2;
		}
		else if (rot == 2) {
			if (Y < 19)
				if (!buff[Y - 1][X] && !buff[Y + 1][X] && !buff[Y + 1][X + 1])
					rot = 3;
		}
		else if (rot == 3) {
			if (X > 1)
				if (!buff[Y][X - 1] && !buff[Y + 1][X - 1] && !buff[Y][X + 1])
					rot = 0;
		}
		break;
	case 7:
		if (rot == 0) {
			if(Y < 18)
				if (!buff[Y - 1][X] && !buff[Y + 1][X] && !buff[Y + 2][X]) {
					rot = 1;
				}
		}
		else if (rot == 1) {
			if((X > 0) && (X < 12))
				if (!buff[Y][X - 1] && !buff[Y][X + 1] && !buff[Y][X + 2]) {
					rot = 0;
				}
		}
		break;
	}
	drawf();
	update();
}

void movef(short dir) {
	/*
	2<  >0
	  \/
	  1
	*/
	switch (id) {
	case 1:
		if (dir == 0) {
			if (rot == 0) {
				if(X < 12)
					if (!buff[Y][X + 2] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
			else if (rot == 1) {
				if (X < 13)
					if (!buff[Y - 1][X + 1] && !buff[Y][X + 1] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
			else if (rot == 2) {
				if (X < 12)
					if (!buff[Y - 1][X + 1] && !buff[Y][X + 2]) {
						deletef();
						X++;
					}
			}
			else if (rot == 3) {
				if (X < 12)
					if (!buff[Y - 1][X + 1] && !buff[Y][X + 2] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
		}
		else if (dir == 1) {
			if (rot == 0) {
				if(Y < 18)
					if (!buff[Y + 1][X - 1] && !buff[Y + 2][X] && !buff[Y + 1][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 1) {
				if(Y < 18)
					if (!buff[Y + 1][X - 1] && !buff[Y + 2][X]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 2) {
				if (Y < 19)
					if (!buff[Y + 1][X - 1] && !buff[Y + 1][X] && !buff[Y + 1][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 3) {
				if (Y < 18)
					if (!buff[Y + 1][X + 1] && !buff[Y + 2][X]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
		}
		else if (dir == 2) {
			if (rot == 0) {
				if (X > 1)
					if (!buff[Y][X - 2] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
			else if (rot == 1) {
				if (X > 1)
					if (!buff[Y][X - 2] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
			else if (rot == 2) {
				if (X > 1)
					if (!buff[Y - 1][X - 1] && !buff[Y][X - 2]) {
						deletef();
						X--;
					}
			}
			else if (rot == 3) {
				if (X > 0)
					if (!buff[Y - 1][X - 1] && !buff[Y][X - 1] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
		}
		break;
	case 2:
		if (dir == 0) {
			if (rot == 0) {
				if (X < 12)
					if (!buff[Y][X + 2] && !buff[Y + 1][X + 2]) {
						deletef();
						X++;
					}
			}
			else if (rot == 1) {
				if (X < 13)
					if (!buff[Y - 1][X + 1] && !buff[Y][X + 1] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
			else if (rot == 2) {
				if(X < 12)
					if (!buff[Y][X + 2] && !buff[Y - 1][X]) {
						deletef();
						X++;
					}
			}
			else if (rot == 3) {
				if(X < 12)
					if (!buff[Y - 1][X + 2] && !buff[Y][X + 1] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
		}
		else if (dir == 1) {
			if (rot == 0) {
				if(Y < 18)
					if (!buff[Y + 1][X - 1] && !buff[Y + 1][X] && !buff[Y + 2][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 1) {
				if(Y < 18)
					if (!buff[Y + 2][X - 1] && !buff[Y + 2][X]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 2) {
				if (Y < 19)
					if (!buff[Y + 1][X - 1] && !buff[Y + 1][X] && !buff[Y + 1][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 3) {
				if(Y < 18)
					if (!buff[Y + 2][X] && !buff[Y][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
		}
		else if (dir == 2) {
			if (rot == 0) {
				if (X > 1)
					if (!buff[Y][X - 2] && !buff[Y + 1][X]) {
						deletef();
						X--;
					}
			}
			else if (rot == 1) {
				if (X > 1)
					if (!buff[Y - 1][X - 1] && !buff[Y][X - 1] && !buff[Y + 1][X - 2]) {
						deletef();
						X--;
					}
			}
			else if (rot == 2) {
				if(X > 1)
					if (!buff[Y - 1][X - 2] && !buff[Y][X - 2]) {
						deletef();
						X--;
					}
			}
			else if (rot == 3) {
				if(X > 0)
					if (!buff[Y - 1][X - 1] && !buff[Y][X - 1] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
		}
		break;
	case 3:
		if (dir == 0) {
			if (rot == 0) {
				if (X < 12)
					if (!buff[Y][X + 1] && !buff[Y + 1][X + 2]) {
						deletef();
						X++;
					}
			}
			else if (rot == 1) {
				if(X < 12)
					if (!buff[Y - 1][X + 2] && !buff[Y][X + 2] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
		}
		else if (dir == 1) {
			if (rot == 0) {
				if(Y < 18)
					if (!buff[Y + 1][X - 1] && !buff[Y + 2][X] && !buff[Y + 2][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 1) {
				if(Y < 18)
					if (!buff[Y + 2][X] && !buff[Y + 1][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
		}
		else if (dir == 2) {
			if (rot == 0) {
				if(X > 1)
					if (!buff[Y][X - 2] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
			else if (rot == 1) {
				if(X > 0)
					if (!buff[Y - 1][X] && !buff[Y][X - 1] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
		}
		break;
	case 4:
		if (dir == 0) {
			if (X < 12)
				if (!buff[Y][X + 2] && !buff[Y + 1][X + 2]) {
					deletef();
					X++;
				}
		}
		else if (dir == 1) {
			if(Y < 18)
				if (!buff[Y + 2][X] && !buff[Y + 2][X + 1]) {
					deletef();
					Y++;
				}
				else id = 0;
			else id = 0;
		}
		else if (dir == 2) {
			if(X>0)
				if (!buff[Y][X - 1] && !buff[Y + 1][X - 1]) {
					deletef();
					X--;
				}
		}
		break;
	case 5:
		if (dir == 0) {
			if (rot == 0) {
				if(X < 12)
					if (!buff[Y][X + 2] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
			else if (rot == 1) {
				if(X < 12)
					if (!buff[Y - 1][X + 1] && !buff[Y][X + 2] && !buff[Y + 1][X + 2]) {
						deletef();
						X++;
					}
			}
		}
		else if (dir == 1) {
			if (rot == 0) {
				if(Y < 18)
					if (!buff[Y + 2][X - 1] && !buff[Y + 2][X] && !buff[Y + 1][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 1) {
				if(Y < 18)
					if (!buff[Y + 1][X] && !buff[Y + 2][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
		}
		else if (dir == 2) {
			if (rot == 0) {
				if (X > 1)
					if (!buff[Y][X - 1] && !buff[Y + 1][X - 2]) {
						deletef();
						X--;
					}
			}
			else if (rot == 1) {
				if(X > 0)
					if (!buff[Y - 1][X - 1] && !buff[Y][X - 1] && !buff[Y + 1][X]) {
						deletef();
						X--;
					}
			}
		}
		break;
	case 6:
		if (dir == 0) {
			if (rot == 0) {
				if(X < 12)
					if (!buff[Y][X + 2] && !buff[Y + 1][X]) {
						deletef();
						X++;
					}
			}
			else if (rot == 1) {
				if(X < 13)
					if (!buff[Y - 1][X + 1] && !buff[Y][X + 1] && !buff[Y + 1][X + 1]) {
						deletef();
						X++;
					}
			}
			else if (rot == 2) {
				if(X < 12)
					if (!buff[Y - 1][X + 2] && !buff[Y][X + 2]) {
						deletef();
						X++;
					}
			}
			else if (rot == 3) {
				if(X < 12)
					if (!buff[Y - 1][X + 1] && !buff[Y][X + 1] && !buff[Y + 1][X + 2]) {
						deletef();
						X++;
					}
			}
		}
		else if (dir == 1) {
			if (rot == 0) {
				if(Y < 18)
					if (!buff[Y + 2][X - 1] && !buff[Y + 1][X] && !buff[Y + 1][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 1) {
				if(Y < 18)
					if (!buff[Y][X - 1] && !buff[Y + 2][X]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 2) {
				if(Y < 19)
					if(!buff[Y + 1][X - 1] && !buff[Y + 1][X] && !buff[Y + 1][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 3) {
				if(Y < 18)
					if (!buff[Y + 2][X] && !buff[Y + 2][X + 1]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
		}
		else if (dir == 2) {
			if (rot == 0) {
				if(X > 1)
					if (!buff[Y][X - 2] && !buff[Y + 1][X - 2]) {
						deletef();
						X--;
					}
			}
			else if (rot == 1) {
				if(X > 1)
					if (!buff[Y - 1][X - 2] && !buff[Y][X - 1] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
			else if (rot == 2) {
				if(X > 1)
					if (!buff[Y - 1][X] && !buff[Y][X - 2]) {
						deletef();
						X--;
					}
			}
			else if (rot == 3) {
				if(X > 0)
					if (!buff[Y - 1][X - 1] && !buff[Y][X - 1] && !buff[Y + 1][X - 1]) {
						deletef();
						X--;
					}
			}
		}
		break;
	case 7:
		if (dir == 0) {
			if (rot == 0) {
				if(X < 11)
					if (!buff[Y][X + 3]) {
						deletef();
						X++;
					}
			}
			else if (rot == 1) {
				if(X < 13)
					if (!buff[Y][X + 1]) {
						deletef();
						X++;
					}
			}
		}
		else if (dir == 1) {
			if (rot == 0) {
				if(Y < 19)
					if (!buff[Y + 1][X - 1] && !buff[Y + 1][X] && !buff[Y + 1][X + 1] && !buff[Y + 1][X + 2]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
			else if (rot == 1) {
				if(Y < 17)
					if (!buff[Y + 3][X]) {
						deletef();
						Y++;
					}
					else id = 0;
				else id = 0;
			}
		}
		else if (dir == 2) {
			if (rot == 0) {
				if(X > 1)
					if (!buff[Y][X - 2]) {
						deletef();
						X--;
					}
			}
			else if (rot == 1) {
				if(X > 0)
					if (!buff[Y - 1][X - 1] && !buff[Y][X - 1] && !buff[Y + 1][X - 1] && !buff[Y + 2][X - 1]) {
						deletef();
						X--;
					}
			}
		}
		break;
	}
	drawf();
	update();
}

float getElapsedTime() {
	unsigned int end = clock();
	unsigned int enda = Time;
	Time = end;
	return (float(end) - float(enda)) / 1000.0;
}

void settings() {
	short selectedStr = 0;
	int nkey = 0;
	pause = true;
	selectedStr = 0;
	system("cls");
	cout << "Настройки:" << endl << ">Тип управления: ";
	if (controlType) {
		cout << "Спортивный" << endl;
	}
	else {
		cout << "Обычный" << endl;
	}
	cout << " Чувствительнсть управления: " << sens;
	while (nkey != 27) {
		nkey = _getch();
		if ((nkey == 72) || (nkey == 80)) {
			setCursor(0, 1);
			cout << " " << endl << " ";
			if (selectedStr) {
				selectedStr = 0;
				setCursor(0, 1);
				cout << ">";
			}
			else {
				selectedStr = 1;
				setCursor(0, 2);
				cout << ">";
			}
		}
		if (selectedStr) {
			if (nkey == 75) {
				if (sens <= 1) {
					sens = 1;
				}
				else {
					sens--;
				}
				setCursor(29, 2);
				cout << "    ";
				setCursor(29, 2);
				cout << sens;
			}
			else if (nkey == 77) {
				if (sens >= 1000) {
					sens = 1000;
				}
				else {
					sens++;
				}
				setCursor(29, 2);
				cout << "    ";
				setCursor(29, 2);
				cout << sens;
			}
		}
		else {
			if ((nkey == 75) || (nkey == 77)) {
				setCursor(17, 1);
				cout << "          ";
				if (!controlType) {
					controlType = 1;
					setCursor(17, 1);
					cout << "Спортивный" << endl;
				}
				else {
					controlType = 0;
					setCursor(17, 1);
					cout << "Обычный" << endl;
				}
			}
		}
	}
	nkey = 0;
	pause = false;
	system("cls");
	draw();
	drawNextf();
}

int main() {
	setlocale(0, "");
	int key = 0;
	srand(time(0));
	draw();
	generate();
	while (key != 27) {
		if (!gameover) {
			gTime = getElapsedTime();
			if (!pause){worktime += gTime; controlTime += gTime;}
			if (worktime >= 1.0 / float(level)) {
				level = (score / 1000) + 1;
				if (id == 0) {
					rot = 0;
					generate();
				}
				else {
					movef(1);
				}
				worktime = 0;
			}
			if (!controlType) {
				if (_kbhit()) {
					key = _getch();
					switch (key) {
					case 72://вверх
						if (!pause)rotatef();
						break;
					case 75://влево
						if (!pause)movef(2);
						break;
					case 77://вправо
						if (!pause)movef(0);
						break;
					case 80://вниз
						if (!pause)movef(1);
						break;
					case 59:
						settings();
						break;
					case 32:
						if (pause) { pause = false; setCursor(18, 3); cout << "     "; }
						else { pause = true; setCursor(18, 3); cout << "Pause"; }
						break;
					}
				}
			}
			else {
				if (controlTime >= 1 / sens) {
					if (GetAsyncKeyState(VK_UP)) {
						if (!pause)rotatef();
					}
					else if (GetAsyncKeyState(VK_LEFT)) {
						if (!pause)movef(2);
					}
					else if (GetAsyncKeyState(VK_DOWN)) {
						if (!pause)movef(1);
					}
					else if (GetAsyncKeyState(VK_RIGHT)) {
						if (!pause)movef(0);
					}
					else {
						if (_kbhit()) {
							key = _getch();
							switch (key) {
							case 59:
								settings();
								break;
							case 32:
								if (pause) { pause = false; setCursor(18, 3); cout << "     "; }
								else { pause = true; setCursor(18, 3); cout << "Pause"; }
								break;
							}
						}
					}
					controlTime = 0;
				}
			}
		}
		else {
			setCursor(4, 11);
			cout << "GAME OVER";
			while (gameovertime < 3) {
				gameovertime += getElapsedTime();
			}
			restart();
		}
	}
	return 0;
}