/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 00:03:29 by root              #+#    #+#             */
/*   Updated: 2025-12-02 00:03:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long int get_target(int idx, t_philo *philos)
{
    return (get_last_eat_time(&philos[idx].last_eat_time));
}

static void ft_swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

static void quick_sort_internal(int *arr, t_philo *philos, int left, int right)
{
    int i;
    int j;
    long long int pivot;

    i = left;
    j = right;
    pivot = get_target(arr[(left + right)/ 2], philos);
    while (i <= j)
    {
        while (get_target(arr[i], philos) < pivot)
            i++;
        while (get_target(arr[j], philos) > pivot)
            j--;
        if (i <= j)
        {
            ft_swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (j > left)
        quick_sort_internal(arr, philos, left, j);
    if (i < right)
        quick_sort_internal(arr, philos, i, right);
}

void quick_sort(int *arr, int size, t_philo *philos)
{
    if (size <= 1)
        return ;
    quick_sort_internal(arr, philos, 0, size - 1);
}