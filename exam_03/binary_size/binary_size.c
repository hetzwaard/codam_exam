#include "binary_size.h"

int	binary_size(t_btree *root)
{
	int	left_size;
	int	right_size;

	if (!root)
		return (0);
	left_size = binary_size(root->left);
	right_size = binary_size(root->right);
	return (1 + left_size + right_size);
}
