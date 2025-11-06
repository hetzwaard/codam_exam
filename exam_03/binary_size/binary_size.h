#ifndef BTREE_H
#define BTREE_H

typedef struct	s_btree
{
	int				value;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

#endif