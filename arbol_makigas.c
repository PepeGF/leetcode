#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int valor;
	struct nodo *left;
	struct nodo *right;
} nodo;

typedef nodo Arbol;

nodo *crearnodo(int valor)
{
	nodo *nuevonodo;

	nuevonodo = malloc(sizeof(nodo));
	nuevonodo->valor = valor;
	nuevonodo->left = NULL;
	nuevonodo->right = NULL;
	return (nuevonodo);
}

void destruirnodo(nodo *nodo)
{
	nodo->left = NULL;
	nodo->right = NULL;
	free(nodo);
}

void insertar(nodo **arbol, int valor)
{
	int valorraiz;

	if (*arbol == NULL)
		*arbol = crearnodo(valor);
	else
	{
		valorraiz = (*arbol)->valor;
		if (valor < valorraiz)
			insertar(&(*arbol)->left, valor);
		else
			insertar(&(*arbol)->right, valor);
	}
}

int existe(nodo *arbol, int valor)
{
	if (arbol == NULL)
		return (0);
	else if (valor == arbol->valor)
		return (1);
	else if (valor < arbol->valor)
		return (existe(arbol->left, valor));
	else
		return (existe(arbol->right, valor));
}

void printexist(nodo *arbol, int valor)
{
	if (existe(arbol, valor))
		printf("El nodo %d existe en el árbol\n", valor);
	else
		printf("El nodo %d NO existe en el árbol\n", valor);
}

void preorden(nodo *arbol)
{
	if (arbol == NULL)
		printf(" - ");
	else
		{
			printf("( %d ", arbol->valor);
			preorden(arbol->left);
			preorden(arbol->right);
			printf(" )");
		}
}

void inorden(nodo *arbol)
{
	if (arbol == NULL)
		printf (" - ");
	else
	{
		printf("( ");
		inorden(arbol->left);
		printf(" %d ", arbol->valor);
		inorden(arbol->right);
		printf(" )");
	}
}

void postorden(nodo *arbol)
{
	if (arbol == NULL)
		printf (" - ");
	else
	{
		printf("( ");
		postorden(arbol->left);
		postorden(arbol->right);
		printf(" %d )", arbol->valor);
	}
}

int main(void)
{
	nodo *arbol = NULL;

	insertar(&arbol, 5);
	postorden(arbol);
	printf("\n");
	insertar(&arbol, 10);
	postorden(arbol);
	printf("\n");
	insertar(&arbol, 4);
	postorden(arbol);
	printf("\n");
	insertar(&arbol, 9);
	postorden(arbol);
	printf("\n");
	insertar(&arbol, 15);
	postorden(arbol);
	printf("\n");

	// printexist(arbol, 10);
	// printexist(arbol, 3);
	// printexist(arbol, 9);

	return 0;
}
