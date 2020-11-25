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
/**
 * binary_trees_ancestor -  lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return:  pointer to the lowest common ancestor otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *aux = (binary_tree_t *)first, *aux2 = (binary_tree_t *)second;
	size_t depthFirst = 0, depthSecond = 0;

	if (!aux || !aux2)
		return (NULL);
	depthFirst = binary_tree_depth(first);
	depthSecond = binary_tree_depth(second);
	if (depthFirst < depthSecond)
	{
		while (depthFirst != depthSecond)
			aux2 = aux2->parent, depthSecond--;
	}
	else
	{
		while (depthFirst != depthSecond)
			aux = aux->parent, depthFirst--;
	}
	if (aux->n == aux2->n)
		return (NULL);
	while (aux && aux2 && aux->n != aux2->n)
		aux = aux->parent, aux2 = aux2->parent;

	return (aux);
}
