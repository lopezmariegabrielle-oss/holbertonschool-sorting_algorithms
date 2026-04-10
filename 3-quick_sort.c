#include "sort.h"
#include <complex.h>

/**
 * swap_items - Échange deux éléments dans le tableau
 * @array: Le tableau
 * @size: La taille totale (pour l'affichage)
 * @a: Pointeur vers le premier élément
 * @b: Pointeur vers le second élément
 */
void swap_items(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Schéma de partition de Lomuto
 * @array: Le tableau d'entiers
 * @size: Taille complète du tableau
 * @low: Indice de début
 * @high: Indice de fin (pivot)
 *
 * Return: La position finale du pivot
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low;
	int j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			swap_items(array, size, &array[i], &array[j]);
			i++;
		}
		j++;
	}
	swap_items(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_recursion - Gère les appels récursifs du tri
 * @array: Le tableau d'entiers
 * @size: Taille complète
 * @low: Indice de début
 * @high: Indice de fin
 */
void quick_recursion(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, size, low, high);

		/* Tri de la partie gauche avant le pivot */
		quick_recursion(array, size, low, pivot_idx - 1);
		/* Tri de la partie droite après le pivot */
		quick_recursion(array, size, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - Trie un tableau avec l'algorithme Quick Sort
 * @array: Le tableau d'entiers
 * @size: Taille du tableau
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_recursion(array, size, 0, (int)size - 1);
}
