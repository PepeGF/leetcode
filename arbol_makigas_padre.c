#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int valor;
	struct nodo *left;
	struct nodo *right;
	struct nodo *padre;
} nodo;

typedef nodo Arbol;

nodo *crearnodo(int valor, nodo *padre)
{
	nodo *nuevonodo;

	nuevonodo = malloc(sizeof(nodo));
	nuevonodo->valor = valor;
	nuevonodo->left = NULL;
	nuevonodo->right = NULL;
	nuevonodo->padre = padre;
	return (nuevonodo);
}

void destruirnodo(nodo *nodo)
{
	nodo->left = NULL;
	nodo->right = NULL;
	free(nodo);
}

static void insertarconpadre(nodo **arbol, nodo *padre, int valor)
{
	int valorraiz;

	if (*arbol == NULL)
		*arbol = crearnodo(valor, padre);
	else
	{
		valorraiz = (*arbol)->valor;
		if (valor < valorraiz)
			insertarconpadre(&(*arbol)->left, *arbol, valor);
		else
			insertarconpadre(&(*arbol)->right, *arbol, valor);
	}
}

void insertar(nodo **arbol, int valor)
{
	insertarconpadre(arbol, NULL, valor);
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

nodo *obtener(nodo *arbol, int valor)
{
	if (arbol == NULL)
		return (NULL);
	if (arbol->valor == valor)
		return (arbol);
	if (valor < arbol->valor)
		return (obtener(arbol->left, valor));
	else
		return (obtener(arbol->right, valor));
}

static void reemplazar (nodo *arbol, nodo *nuevonodo)
{
	if (arbol->padre)
	{
		if (arbol->valor == arbol->padre->left->valor)
			arbol->padre->left = nuevonodo;
		else if (arbol->valor == arbol->padre->right->valor)
			arbol->padre->right = nuevonodo;
	}
	if (nuevonodo != NULL)
		nuevonodo->padre = arbol->padre;
}

static nodo *minimo(nodo *arbol)
{
	if (arbol == NULL)
		return (NULL);
	if (arbol->left == NULL)
		return (arbol);
	else
		return (minimo(arbol->left));
}

static void eliminarnodo(nodo *nodoeliminar)
{
	nodo *nodominimo;
	if (nodoeliminar->left && nodoeliminar->right)
	{
		nodominimo = minimo(nodoeliminar->right);
		nodoeliminar->valor = nodominimo->valor;
		eliminarnodo(nodominimo);
	}
	else if (nodoeliminar->left)
	{
		reemplazar(nodoeliminar, nodoeliminar->left);
		destruirnodo(nodoeliminar);
	}
	else if (nodoeliminar->right)
	{
		reemplazar(nodoeliminar, nodoeliminar->right);
		destruirnodo(nodoeliminar);
	}
	else
	{
		reemplazar(nodoeliminar, NULL);
		destruirnodo(nodoeliminar);
	}
}

void eliminar(nodo *arbol, int valor)
{
	if (arbol == NULL)
		return ;
	if (valor < arbol->valor)
		eliminar (arbol->left, valor);
	else if (valor > arbol->valor)
		eliminar (arbol->right, valor);
	else
		eliminarnodo(arbol);
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
		if (arbol->padre == NULL)
		{
			printf(" %d {//}", arbol->valor);
		}
		else
			printf(" %d (%d) ", arbol->valor, arbol->padre->valor);
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
	inorden(arbol);
	printf("\n");
	insertar(&arbol, 10);
	inorden(arbol);
	printf("\n");
	insertar(&arbol, 4);
	inorden(arbol);
	printf("\n");
	insertar(&arbol, 9);
	inorden(arbol);
	printf("\n");
	insertar(&arbol, 20);
	inorden(arbol);
	printf("\n");
	insertar(&arbol, 2);
	inorden(arbol);
	printf("\n");
	insertar(&arbol, 15);
	inorden(arbol);
	printf("\n");
	printf("\n");
	printf("\n");
	eliminar(arbol, 5);
	inorden(arbol);
	printf("\n");

	// printexist(arbol, 10);
	// printexist(arbol, 3);
	// printexist(arbol, 9);

	return 0;
}
