
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

int count_list(struct ListNode* head)
{
	int i = 0;
	struct ListNode *aux;
	aux = head;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return i;
}

int get_value_by_index(struct ListNode* head, int index)
{
	int i;
	int value;
	struct ListNode *aux;

	i = 0;
	aux = head;
	while (i != index)
	{
		aux = aux->next;
		i++;
	}
	value = aux->val;
	return (value);
}

bool isPalindrome(struct ListNode* head)
{
	//int list_len = count_list(head);
	int index = 0;
	int val_index;
	struct ListNode* aux;
	aux = head;
	while (aux)
	{
		val_index = get_value_by_index(head, index);
		printf("Indice %d -> valor %d\n", index, val_index);
		index++;
		aux = aux->next;
	}
	return (true);
}

struct ListNode  *ft_lstnew(int val)
{
        struct ListNode  *new;

        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!new)
                return (NULL);
        new->val = val;
        new->next = NULL;
        return (new);
}

struct ListNode  *ft_lstlast(struct ListNode *lst)
{
        if (!lst)
                return (0);
        while (lst->next)
                lst = lst->next;
        return (lst);
}

void    ft_lstadd_back(struct ListNode **lst, struct ListNode *new)
{
        struct ListNode  *old_last;

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

struct ListNode *create_list(int *head, int len)
{
	struct ListNode *list = NULL;
	int i = 0;

	if (!head)
		return (NULL);
	while (i < len)
	{
		printf("%d\n", head[i]);
		ft_lstadd_back(&list, ft_lstnew(head[i]));
		i++;
	}
	return (list);
}

void print_list(struct ListNode *lst)
{
	struct ListNode *aux;

	aux = lst;
	if (!lst)
		return ;
	while (aux)
	{
		printf("%d\n",aux->val);
		aux = aux->next;
	}
}
int main ()
{
	struct ListNode *list;
	int len = 4;
	int head[] = {1,2,2,1};
	list = create_list(head, len);
	isPalindrome(list);

	return (0);
}
