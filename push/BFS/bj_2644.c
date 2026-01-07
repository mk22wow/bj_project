#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

enum VisitMode{Visited = 1, NotVisited = 0};

typedef struct Vertex {
	int name;
	int Visited;
	int distance;
	struct Edge* list;
}Vertex;

typedef struct Edge {
	Vertex* from;
	Vertex* target;
	int direction;
	struct Edge* next;
}Edge;

Vertex* createVertex(int data) {
	Vertex* newV = (Vertex*)malloc(sizeof(Vertex));
	newV->list = NULL;
	newV->name = data;
	newV->distance = 0;
	newV->Visited = NotVisited;

	return newV;
}

void destroyV(Vertex* V) {
	while (V->list != NULL) {
		Edge* E = V->list->next;
		free(V->list);
		V->list = E;
	}

	free(V);
}

Edge* createEdge(Vertex* from, Vertex* target, int direction) {
	Edge* E = (Edge*)malloc(sizeof(Edge));
	E->from = from;
	E->target = target;
	E->direction = direction;
	E->next = NULL;

	return E;
}

void addEdge(Vertex* V, Edge* E) {
	E->next = V->list;
	V->list = E;
}

void BFS(Vertex** G, Vertex* V1, Vertex* V2, int N) {
	Vertex** Q = (Vertex**)malloc(sizeof(Vertex*) * N);
	int front = 0, rear = 0;
	V1->Visited = Visited;
	Q[rear++] = V1;

	while (front < rear) {
		Vertex* V = Q[front++];
		Edge* E = V->list;
		while (E != NULL) {
			if (E->target->Visited == NotVisited) {
				E->target->Visited = Visited;
				E->target->distance = V->distance + 1;
				if (E->target == V2) {
					printf("%d", E->target->distance);
					free(Q);
					return;
				}
				Q[rear++] = E->target;
			}
			E = E->next;
		}
	}
	printf("-1");
	free(Q);
}

int main(void) {
	int N, M;
	int x, y;
	scanf("%d", &N);
	Vertex** G = (Vertex**)malloc(sizeof(Vertex*) * N);
	for (int i = 0; i < N; i++) {
		G[i] = createVertex(i + 1);
	}
	scanf("%d %d", &x, &y);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		Vertex* temp_1 = G[a - 1];
		Vertex* temp_2 = G[b - 1];
		addEdge(temp_1, createEdge(temp_1, temp_2, 1));
		addEdge(temp_2, createEdge(temp_2, temp_1, -1));
	}

	int result = -1;
	Vertex* V1 = G[x - 1];
	Vertex* V2 = G[y - 1];

	BFS(G, V1, V2, N);
	for (int i = 0; i < N; i++) {
		destroyV(G[i]);
	}
	free(G);
	return 0;
}