/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 10:04:42 by jballang          #+#    #+#             */
/*   Updated: 2016/09/16 10:07:43 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	t_btree	*tree;

	tree = root;
	if (tree)
	{
		if (tree->left)
			btree_apply_suffix(tree->left, applyf);
		if (tree->right)
			btree_apply_suffix(tree->right, applyf);
		applyf(tree);
	}
}
