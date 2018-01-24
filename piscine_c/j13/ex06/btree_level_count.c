/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 11:43:06 by jballang          #+#    #+#             */
/*   Updated: 2016/09/16 14:49:51 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	b_tree	*tree;
	int		count;
	int		tmp_count;

	tree = root;
	count = 0;
	tmp_count = 0;
	if (tree)
	{
		if (tree->left)
		{
			btree_level_count(tree->left);
			count++;
		}
		if (tree->right)
		{
			btree_level_count(tree->right);
			tmp_count++;
		}
	}
	if (count < tmp_count)
		count = tmp_count;
	return (count);
}
