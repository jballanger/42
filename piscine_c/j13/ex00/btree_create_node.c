/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:25:39 by jballang          #+#    #+#             */
/*   Updated: 2016/09/16 10:10:34 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*tmp_tree;

	tmp_tree = (t_btree*)malloc(sizeof(t_btree));
	if (tmp_tree == NULL)
		return (0);
	tmp_tree->item = item;
	tmp_tree->left = 0;
	tmp_tree->right = 0;
	return (tmp_tree);
}
