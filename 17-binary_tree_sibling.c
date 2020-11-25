#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *aux = NULL;

	if (!node || !node->parent)
		return (NULL);
	aux = node->parent;
	if (aux->left && aux->right)
	{
		if (aux->left->n == node->n)
			aux = aux->right;
		else
			aux = aux->left;
		return (aux);
	}
	else
		return (NULL);
}
