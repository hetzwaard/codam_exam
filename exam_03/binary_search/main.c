#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>

int		size_binary_tree(t_btree *root);

t_btree	*new_node(int val)
{
	t_btree	*n;

	n = malloc(sizeof(t_btree));
	if (!n)
		return (NULL);
	n->value = val;
	n->left = NULL;
	n->right = NULL;
	return (n);
}

void	free_tree(t_btree *root)
{
	if (!root)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int	main(void)
{
	t_btree	*root;
	t_btree	*unbal;

	root = NULL;
	/* empty tree */
	printf("size(NULL) = %d (expected 0)\n", size_binary_tree(root));
	/* single node */
	root = new_node(10);
	printf("size(single) = %d (expected 1)\n", size_binary_tree(root));
	/* build a small tree: 10 with 5 (left), 15 (right), and 3 as left-left */
	root->left = new_node(5);
	root->right = new_node(15);
	root->left->left = new_node(3);
	printf("size(4 nodes) = %d (expected 4)\n", size_binary_tree(root));
	/* unbalanced tree */
	unbal = new_node(1);
	unbal->right = new_node(2);
	unbal->right->right = new_node(3);
	printf("size(unbalanced 3) = %d (expected 3)\n", size_binary_tree(unbal));
	free_tree(root);
	free_tree(unbal);
	return (0);
}
