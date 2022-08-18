// https://leetcode.com/problems/middle-of-the-linked-list/

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode 
{
	int val;
	struct ListNode *next;
};

int	ft_lstsize(struct ListNode *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

struct ListNode* middleNode(struct ListNode* head)
{
	int lst_size;
	int i;
	struct ListNode *aux;

	i = 1;
	lst_size = ft_lstsize(head);
	lst_size = lst_size / 2 + 1;
	aux = head;
	while (i < lst_size)
	{
		i++;
		aux = aux->next;
	}
	return (aux);
}

struct ListNode	*ft_lstlast(struct ListNode *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

struct ListNode	*ft_lstnew(int val)
{
	struct ListNode	*new;

	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(struct ListNode **lst, struct ListNode *new)
{
	struct ListNode	*old_last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	old_last = ft_lstlast(*lst);
	old_last->next = new;
}

int main()
{
	int x;
	int i = 1;
	struct ListNode *nodo = NULL;
	struct ListNode *aux;

	x = 11;
	while (i <= x)
	{
		ft_lstadd_back(&nodo, ft_lstnew(i));
		i++;
	}
	i = 0;
	aux = nodo;
	while (aux)
	{
		printf("Nodo %d valor %d\n", i, aux->val);
		aux = aux->next;
		i++;
	}
	aux = middleNode(nodo);
	printf("-------------\nNodo medio: %d\n--------------\n", aux->val);
	return (0);
}
