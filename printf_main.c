/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:30:37 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/22 22:30:37 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int res1, res2;

	printf("--- STARTING EDGE CASE TESTS ---\n\n");

	printf("--- Test 1: Percent and space ---\n");
	res1 = printf("Hola % t");
	printf("\n");
	res2 = ft_printf("Hola % t");
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 2: Invalid specifier %%z ---\n");
	res1 = printf("Hola %) world");
	printf("\n");
	res2 = ft_printf("Hola %) world");
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 3: String ends with %% ---\n");
	res1 = printf("Hello %");
	printf("\n");
	res2 = ft_printf("Hello %");
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 4: Just %% ---\n");
	res1 = printf("%");
	printf("\n");
	res2 = ft_printf("%");
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 5: NULL format string ---\n");
	printf("(Skipping real printf(NULL) - causes SEGFAULT)\n");
	res1 = -1;
	res2 = ft_printf(NULL);
	printf("\n");
	printf("Ret: %d (placeholder) | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 6: Complex percent combinations ---\n");
	res1 = printf("A %%d B %%%d C %d%% D", 123, 456);
	printf("\n");
	res2 = ft_printf("A %%d B %%%d C %d%% D", 123, 456);
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 7: Double percent ---\n");
	res1 = printf("Testing 100%% complete %%");
	printf("\n");
	res2 = ft_printf("Testing 100%% complete %%");
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 8: Extra arguments ---\n");
	res1 = printf("Hello", 123, "world", (void *)0);
	printf("\n");
	res2 = ft_printf("Hello", 123, "world", (void *)0);
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 9: NULL string (%%s) ---\n");
	res1 = printf("String: %s (end)", (char *)NULL);
	printf("\n");
	res2 = ft_printf("String: %s (end)", (char *)NULL);
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 10: NULL pointer (%%p) ---\n");
	res1 = printf("Pointer: %p (end)", (void *)NULL);
	printf("\n");
	res2 = ft_printf("Pointer: %p (end)", (void *)NULL);
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- Test 11: Printing zero (d, u, x, X) ---\n");
	res1 = printf("Zeroes: %d %u %x %X", 0, 0, 0, 0);
	printf("\n");
	res2 = ft_printf("Zeroes: %d %u %x %X", 0, 0, 0, 0);
	printf("\n");
	printf("Ret: %d | %d\n", res1, res2);
	printf("--------------------------------\n\n");

	printf("--- END OF EDGE CASE TESTS ---\n");

	return (0);
}
