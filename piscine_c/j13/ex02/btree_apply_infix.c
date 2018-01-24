/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 09:54:24 by jballang          #+#    #+#             */
/*   Updated: 2016/09/16 09:57:18 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	t_btree	*tree;

	tree = root;
	if (tree)
	{
		if (tree->left)
			btree_apply_infix(tree->left, applyf);
		applyf(tree);
		if (tree->right)
			btree_apply_infix(tree->right, applyf);
	}
}
