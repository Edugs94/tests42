/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:16:31 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/22 23:16:31 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

// --- Define colors ---
#define RESET   "\033[0m"
#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"

static void check_test(int test_num, int res1, int res2)
{
	printf("Ret: %d | %d\n", res1, res2);
	if (res1 == res2)
		printf(GREEN "Test %d: OK\n" RESET, test_num);
	else
		printf(RED "Test %d: KO\n" RESET, test_num);
	printf("--------------------------------\n\n");
}

int main(void)
{
	int res1, res2;
	int test_num = 1;

	printf("--- STARTING EDGE CASE TESTS ---\n\n");

	printf("--- Test %d: Percent and space ---\n", test_num);
	res1 = printf("Hola % t");
	printf("\n");
	res2 = ft_printf("Hola % t");
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: Invalid specifier %%z ---\n", test_num);
	res1 = printf("Hola %) world");
	printf("\n");
	res2 = ft_printf("Hola %) world");
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: String ends with %% ---\n", test_num);
	res1 = printf("Hello %");
	printf("\n");
	res2 = ft_printf("Hello %");
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: Just %% ---\n", test_num);
	res1 = printf("%");
	printf("\n");
	res2 = ft_printf("%");
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: NULL format string ---\n", test_num);
	printf("(Skipping real printf(NULL) - causes SEGFAULT)\n");
	res1 = -1;
	res2 = ft_printf(NULL);
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: Complex percent combinations ---\n", test_num);
	res1 = printf("A %%d B %%%d C %d%% D", 123, 456);
	printf("\n");
	res2 = ft_printf("A %%d B %%%d C %d%% D", 123, 456);
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: Double percent ---\n", test_num);
	res1 = printf("Testing 100%% complete %%");
	printf("\n");
	res2 = ft_printf("Testing 100%% complete %%");
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: Extra arguments ---\n", test_num);
	res1 = printf("Hello", 123, "world", (void *)0);
	printf("\n");
	res2 = ft_printf("Hello", 123, "world", (void *)0);
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: NULL string (%%s) ---\n", test_num);
	res1 = printf("String: %s (end)", (char *)NULL);
	printf("\n");
	res2 = ft_printf("String: %s (end)", (char *)NULL);
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: NULL pointer (%%p) ---\n", test_num);
	res1 = printf("Pointer: %p (end)", (void *)NULL);
	printf("\n");
	res2 = ft_printf("Pointer: %p (end)", (void *)NULL);
	printf("\n");
	check_test(test_num++, res1, res2);

	printf("--- Test %d: Printing zero (d, u, x, X) ---\n", test_num);
	res1 = printf("Zeroes: %d %u %x %X", 0, 0, 0, 0);
	printf("\n");
	res2 = ft_printf("Zeroes: %d %u %x %X", 0, 0, 0, 0);
	printf("\n");
	check_test(test_num++, res1, res2);


	printf("--- END OF EDGE CASE TESTS ---\n");

	return (0);
}
