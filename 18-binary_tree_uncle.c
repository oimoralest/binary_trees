#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *aux = NULL;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	aux = node->parent->parent;
	if (aux->left && aux->right)
	{
		if (aux->left->n == node->parent->n)
			aux = aux->right;
		else
			aux = aux->left;
		return (aux);
	}
	else
		return (NULL);
}
