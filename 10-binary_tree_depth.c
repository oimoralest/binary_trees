#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: the depth of the node or 0 on failure
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t i = 0;
	binary_tree_t *aux = NULL;

	if (!tree)
		return (0);
	aux = (binary_tree_t *)tree;
	while (aux->parent)
	{
		i++;
		aux = aux->parent;
	}

	return (i);
}
