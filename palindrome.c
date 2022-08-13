/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palindrome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:17:14 by josgarci          #+#    #+#             */
/*   Updated: 2022/08/13 13:35:34 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				val;
	struct ListNode	*next;
};

int	count_list(struct ListNode *head)
{
	int				i;
	struct ListNode	*aux;

	i = 0;
	aux = head;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

int	*list_to_array(struct ListNode *head, int *len)
{
	int	*array;

	array = malloc(sizeof(int) * count_list(head));
	while (head)
	{
		array[*len] = head->val;
		(*len)++;
		head = head->next;
	}
	return (array);
}

bool	isPalindrome(struct ListNode *head)
{
	int	*nums;
	int	len;
	int	i;

	i = 0;
	len = 0;
	nums = list_to_array(head, &len);
	printf("longitud array: %d\n", len);
	while (i < len / 2)
	{
		if (nums[i] != nums[len - i - 1])
			return (false);
		i++;
	}
	return (true);
}

/* 
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
		// printf("%d\n", head[i]);
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
	int len = 23;
	int head[] = {1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,1,1};
	list = create_list(head, len);
	isPalindrome(list);

	return (0);
}
 */