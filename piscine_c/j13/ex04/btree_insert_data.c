/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 10:08:40 by jballang          #+#    #+#             */
/*   Updated: 2016/09/16 10:28:23 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,\
		int (*cmpf)(void *, void *))
{
	t_btree	*tree;
	int		side;

	tree = *root;
	while (tree)
	{
		if (cmpf(item, tree) < 0)
		{
			if (tree->left)
				tree = tree->left;
			else
				side = 1;
		}
		else if (cmpf(item, tree) >= 0)
		{
			if (tree->right)
				tree = tree->right;
			else
				side = 2;
		}
	}
	if (side == 1)
		tree->left = item;
	else if (side == 2)
		tree->right = item;
}
