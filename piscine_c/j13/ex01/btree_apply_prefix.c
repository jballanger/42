/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:41:22 by jballang          #+#    #+#             */
/*   Updated: 2016/09/16 10:04:06 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	t_btree	*tree;

	tree = root;
	if (tree)
	{
		applyf(tree);
		if (tree->left)
			btree_apply_prefix(tree->left, applyf);
		if (tree->right)
			btree_apply_prefix(tree->right, applyf);
	}
}
