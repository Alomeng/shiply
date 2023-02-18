#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <malloc.h>

void move(int play, int **p, int n) {	
	int temp = 0;
	int x1=0,y1=0;	
	char kum='	';
	do {

		scanf_s(" %c", &kum, sizeof(kum));
		switch (kum) {
		case('w'):
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (p[i][j] == play) {
						y1--;
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
						temp = p[i][j];
						p[i][j] = p[y1][j];
						p[y1][j] = temp;
						goto link;
					}
				}
			}link:break;
		case('a'):
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (p[i][j] == play) {
						x1--;
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
						temp = p[i][j];
						p[i][j] = p[i][x1];
						p[i][x1] = temp;
						break;
					}
				}
			}break;
		}		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%2d", p[i][j]);
			}
			printf("\n");
		}
		
	} while (play == 1);
	
}

int main() {	
	int play=1;
	setlocale(LC_ALL, "Russian");
	int **p;
	int n;	
	printf("Укажите размер карты: ");
	scanf_s("%d", &n);
	p = (int**)malloc(n*n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			p[i][j] = 0;
		}
	}
	p[0][0] = play;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d", p[i][j]);
		}
		printf("\n");
	}
	move(play, p, n);	
}