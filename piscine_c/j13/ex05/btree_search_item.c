/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 10:28:50 by jballang          #+#    #+#             */
/*   Updated: 2016/09/16 11:42:38 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_search_item(t_btree *root, void *data_ref,\
		int (*cmpf)(void *, void*))
{
	t_btree	*tree;

	tree = root;
	if (tree)
	{
		if (tree->left)
			btree_search_item(tree->left, data_ref, cmpf);
		if (cmpf(tree, data_ref) == 0)
			return (tree);
		if (tree->right)
			btree_search_item(tree->right, data_ref, cmpf);
	}
	return (0);
}
