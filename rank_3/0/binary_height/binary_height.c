#include "binary_height.h"

int	max(int left, int right)
{
	if (left > right)
		return (left);
	return (right);
}

int	max_height(t_btree *root)
{
	int	left_height;
	int	right_height;

	if (!root)
		return (0);
	left_height = max_height(root->left);
	right_height = max_height(root->right);
	return (1 + max(left_height, right_height));
}
