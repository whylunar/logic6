#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <queue>
#include <locale.h>
using namespace std;




void rand_Zap(int** Matrix, int n) {
	srand(time(NULL));
	printf("G\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i][j] = 0;
			}
			if (i < j) {
				Matrix[i][j] = rand() % 2;
				Matrix[j][i] = Matrix[i][j];
			}
		}
}
void print_G(int** Matrix, int n) {
	printf("  ");
	for (int i = 0; i < n; i++)
		printf("%3d", i + 1);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++) {

			printf("%3d", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}
void BFSD(int v, int* dist, int** G, int N)
{
	queue <int> Q;
	Q.push(v);
	dist[v] = 0;
	while (Q.empty() == false) {
		v = Q.front();
		Q.pop();
		printf("%d ", v + 1);
		for (int i = 0; i < N; i++) {
			if ((G[v][i] == 1) && dist[i] == -1) {
				Q.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int N = 1;
	scanf("%d", &N);

	int** G = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) 
	{
		G[i] = (int*)malloc(N * sizeof(int));
	}

	int* dist;
	dist = (int*)malloc(N * sizeof(int));


	int i = 0, j = 0;

	for (i = 0; i < 5; i++)
		dist[i] = -1;

	rand_Zap(G, N);
	print_G(G, N);

	/*for (j = 0; j < N; j++)*/
	{
		for (i = 0; i < N; i++)
			dist[i] = -1;

		/*printf("От вершины %d\n", j + 1);*/

		int p = 0, l = 0;
		printf("Введите вершины\n");
		scanf("%d %d", &p, &l);

		printf("От вершины %d\n", p);

		p -= 1;
		l -= 1;

		BFSD(p, dist, G, N);
		printf("%d ", dist[l]);

		/*for (i = 0; i < N; i++)
		{
			if (dist[i] != -1)
				printf("%d \t", dist[i]);
			else
				printf("Нет прохода \t");
		}*/
		printf("\n");
	}
	getchar();
	getchar();
}

