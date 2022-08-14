// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// root = [6,2,8,0,4,7,9,null,null,3,5]
/*

	  6
   2      8
0   4   7   9
   3 5
 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *new_node(int value)
{
	struct TreeNode *nodo;

	nodo = malloc(sizeof(struct TreeNode));
	nodo->left = NULL;
	nodo->right = NULL;
	nodo->val = value;
	return (nodo);
}

void create_tree(struct TreeNode **tree, int value)
{
	struct TreeNode *node;

	node = new_node(value);
	if (*tree == NULL)
		*tree = node;
	else if (value < (*tree)->val)
		create_tree(&(*tree)->left, value);
	else
		create_tree(&(*tree)->right, value);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	if (p->val < root->val && q->val < root->val)
		return(lowestCommonAncestor(root->left, p, q));
	if (p->val > root->val && q->val > root->val)
		return(lowestCommonAncestor(root->right, p, q));
	return (root);	
}


void inorden(struct TreeNode *arbol)
{
	if (arbol == NULL)
		printf (" - ");
	else
	{
		printf("( ");
		inorden(arbol->left);
		printf(" %d ", arbol->val);
		inorden(arbol->right);
		printf(" )");
	}
}

void printtabs(int numtabs)
{
	int i;

	i = 0;
	while (i < numtabs)
	{
		printf("\t");
		i++;
	}
}

void	printtree_rec(struct TreeNode *root, int level)
{
	if (root == NULL)
	{
		printtabs(level);
		printf("---<empty>---\n");
		return ;
	}
	printtabs(level);
	printf("value = %d\n", root->val);
	printtabs(level);
	printf("left\n");

	printtree_rec(root->left, level + 1);
	printtabs(level);
	printf("right\n");
	
	printtree_rec(root->right, level + 1);

	// printtabs(level);
	// printf("DONE\n");
}

int main(void)
{
	int i;
	struct TreeNode *tree;
	struct TreeNode *lca;

	tree = NULL;
	int root[] = {6,2,8,0,4,7,9,3,5};
	i = 0;
	while (i < 9)
	{
		create_tree(&tree, root[i]);
		i++;
	}
	lca = lowestCommonAncestor(tree, tree->left->left, tree->right->left);
	printf("%d y %d: %d\n", tree->left->left->val, tree->right->left->val, lca->val);


/* 
	inorden(tree);
	printf("\n");
	printtree_rec(tree, 0);
 */
	return 0;
}
