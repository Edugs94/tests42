/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:01:39 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 19:01:39 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

//This test need to be compiled with libftprintf.a or the library created by the Makefile
//Use cc -Wall -Wextra -Werror to follow the norm and avoid errors

int main(void)
{
    // --- Test variables ---
    char            c = 'A';
    char            *normal_str = "Hello, world!";
    char            *null_str = NULL;
    int             num = 42;
    void            *valid_ptr = &num;
    void            *null_ptr = NULL;
    int             pos_d = 12345;
    int             neg_d = -6789;
    int             max_d = INT_MAX;
    int             min_d = INT_MIN;
    unsigned int    max_u = UINT_MAX;
    int             test_num = 1; // Counter for tests

    // --- Tests for %c ---
    printf("\n--- Tests for: %%c (Character) ---\n");
    printf("%d. System: [%c]\n", test_num, c);
    ft_printf("%d. Mine:   [%c]\n", test_num++, c);
    printf("%d. System: [%c]\n", test_num, '0');
    ft_printf("%d. Mine:   [%c]\n", test_num++, '0');

    // --- Tests for %s ---
    printf("\n--- Tests for: %%s (String) ---\n");
    printf("%d. System: [%s]\n", test_num, normal_str);
    ft_printf("%d. Mine:   [%s]\n", test_num++, normal_str);
    printf("%d. System: [%s]\n", test_num, "");
    ft_printf("%d. Mine:   [%s]\n", test_num++, "");
    printf("%d. System: [%s]\n", test_num, null_str);
    ft_printf("%d. Mine:   [%s]\n", test_num++, null_str);

    // --- Tests for %p ---
    printf("\n--- Tests for: %%p (Pointer) ---\n");
    printf("%d. System: [%p]\n", test_num, valid_ptr);
    ft_printf("%d. Mine:   [%p]\n", test_num++, valid_ptr);
    printf("%d. System: [%p]\n", test_num, null_ptr);
    ft_printf("%d. Mine:   [%p]\n", test_num++, null_ptr);
    printf("%d. System: [%p]\n", test_num, (void *)ULONG_MAX);
    ft_printf("%d. Mine:   [%p]\n", test_num++, (void *)ULONG_MAX);

    // --- Tests for %d and %i ---
    printf("\n--- Tests for: %%d and %%i (Integer) ---\n");
    printf("%d. System: [%d]\n", test_num, pos_d);
    ft_printf("%d. Mine:   [%d]\n", test_num++, pos_d);
    printf("%d. System: [%i]\n", test_num, neg_d);
    ft_printf("%d. Mine:   [%i]\n", test_num++, neg_d);
    printf("%d. System: [%d]\n", test_num, 0);
    ft_printf("%d. Mine:   [%d]\n", test_num++, 0);
    printf("%d. System: [%d]\n", test_num, max_d);
    ft_printf("%d. Mine:   [%d]\n", test_num++, max_d);
    printf("%d. System: [%d]\n", test_num, min_d);
    ft_printf("%d. Mine:   [%d]\n", test_num++, min_d);

    // --- Tests for %u ---
    printf("\n--- Tests for: %%u (Unsigned integer) ---\n");
    printf("%d. System: [%u]\n", test_num, 12345U);
    ft_printf("%d. Mine:   [%u]\n", test_num++, 12345U);
    printf("%d. System: [%u]\n", test_num, 0U);
    ft_printf("%d. Mine:   [%u]\n", test_num++, 0U);
    printf("%d. System: [%u]\n", test_num, max_u);
    ft_printf("%d. Mine:   [%u]\n", test_num++, max_u);
    printf("%d. System: [%u]\n", test_num, (unsigned int)-1);
    ft_printf("%d. Mine:   [%u]\n", test_num++, (unsigned int)-1);

    // --- Tests for %x ---
    printf("\n--- Tests for: %%x (Lowercase hexadecimal) ---\n");
    printf("%d. System: [%x]\n", test_num, 255);
    ft_printf("%d. Mine:   [%x]\n", test_num++, 255);
    printf("%d. System: [%x]\n", test_num, -1);
    ft_printf("%d. Mine:   [%x]\n", test_num++, -1);
    printf("%d. System: [%x]\n", test_num, min_d);
    ft_printf("%d. Mine:   [%x]\n", test_num++, min_d);

    // --- Tests for %X ---
    printf("\n--- Tests for: %%X (Uppercase hexadecimal) ---\n");
    printf("%d. System: [%X]\n", test_num, 255);
    ft_printf("%d. Mine:   [%X]\n", test_num++, 255);
    printf("%d. System: [%X]\n", test_num, -1);
    ft_printf("%d. Mine:   [%X]\n", test_num++, -1);
    printf("%d. System: [%X]\n", test_num, min_d);
    ft_printf("%d. Mine:   [%X]\n", test_num++, min_d);

    // --- Tests for %% and wrong format specifiers ---
    printf("\n--- Tests for: %% (Percentage symbol and wrong format specifiers) ---\n");
    printf("%d. System: [%%%%%%]\n", test_num);
    ft_printf("%d. Mine:   [%%%%%%]\n", test_num++);
    printf("%d. System: [%% %% %%]\n", test_num);
    ft_printf("%d. Mine:   [%% %% %%]\n", test_num++);
    printf("%d. System: [%%s: %s, %%d: %d, %%]\n", test_num, normal_str, neg_d);
    ft_printf("%d. Mine:   [%%s: %s, %%d: %d, %%]\n", test_num++, normal_str, neg_d);
    printf("%d. System: [%%Start and end%%]\n", test_num);
    ft_printf("%d. Mine:   [%%Start and end%%]\n", test_num++);
    printf("%d. System: [Invalid specifier %%y]\n", test_num);
    ft_printf("%d. Mine:   [Invalid specifier %%y]\n", test_num++);
    printf("%d. System: [Another one %% followed by space]\n", test_num);
    ft_printf("%d. Mine:   [Another one %% followed by space]\n", test_num++);
    printf("%d. System: [Single percent at the end%%]\n", test_num);
    ft_printf("%d. Mine:   [Single percent at the end%%]\n", test_num++);

    return (0);
}