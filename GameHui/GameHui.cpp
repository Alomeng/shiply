#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <malloc.h>
#include <ctime>
#include <string.h>
using namespace std;

	

int mobs( int **p, int n, int &mobs_x, int &mobs_y) {
	srand(time(NULL));
	int gul = n - 1;
	mobs_x = rand() % gul + 1;
	mobs_y = rand() % gul + 1;
	p[mobs_x][mobs_y] = 3;
	return **p, mobs_x, mobs_y;	
}

void player_move(int play, int **p, int n) {
	int x, y;
	mobs(p, n, x, y);	
	int temp = 0;
	int x1=0,y1=0;	
	char kum='	';
	do {
		cin >> kum;
		switch (kum) {
		case('w'):
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (p[i][j] == play) {						
						y1--;
						if (y1 < 0) {
							break;
						}
						temp = p[i][j];
						p[i][j] = p[y1][j];
						p[y1][j] = temp;
						break;
					}
				}
			}break;
		case('s'):
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (p[i][j] == play) {
						y1++;
						if (y1 == n) {
							goto link1;
						}
						temp = p[i][j];
						p[i][j] = p[y1][j];
						p[y1][j] = temp;
						goto link;
					}
				}
			}link:link1:break;
		case('a'):
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (p[i][j] == play) {
						x1--;
						if (x1 < 0) {
							break;
						}
						temp = p[i][j];
						p[i][j] = p[i][x1];
						p[i][x1] = temp;
						break;
					}
				}
			}break;
		case('d'):
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (p[i][j] == play) {
						x1++;
						if (x1 == n) {
							break;
						}
						temp = p[i][j];
						p[i][j] = p[i][x1];
						p[i][x1] = temp;
						break;
					}
				}
			}break;
		}

		if (x1<0 || y1<0 || y1==n || x1==n) {
			play = 0;
			continue;
		}
		if (play == p[x][y]) {
			play = 0;
			continue;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << "" << p[i][j] << " ";
			}
			cout << endl;
		}		
	} while (play == 1);
	x1 = 0, y1 = 0;
	delete[] *p;
	cout << "Ты проиграл..." << endl;
}

int main() {	
	setlocale(LC_ALL, "Russian");
	int play=1;
	char str, s = 'y';
	int **p;
	int n,y=8;		
	while(y == 8){
		cout << "Укажите размер карты: ";
		cin >> n;

		p = new int*[n];
		for (int i = 0; i < n; i++) {
			p[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				p[i][j] = 0;
			}
		}

		p[0][0] = play;

		for (int i = 0; i < n; i++) { 
			for (int j = 0; j < n; j++) {
				cout << "" << p[i][j] << " ";
			}
			cout << endl;
		}

		player_move(play, p, n);
		cout << "Продолжишь играть? y/n\n" << endl;
		cin >> str;
		if (str == s) {
			continue;
		}
		else {
			y = 2375;
		}
	
	}
}