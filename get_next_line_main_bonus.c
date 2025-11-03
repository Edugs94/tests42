/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:58:22 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/03 11:06:45 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_check_args(int argc)
{
    if (argc < 2)
    {   
        write (1, "File name missing.\n", 19);
        return (-1);
    }   
    if (argc > 2)
    {   
        write (1, "Too many arguments.\n", 20);
        return (-1);
    }   
    return (0);
}

int main(int argc, char **argv)
{
    int     fd1; 
    int     fd2; 
    char    *str1;
    char    *str2;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
    str1 = get_next_line(fd1);
    str2 = get_next_line(fd2);
    while (str1 || str2)
    {   
        printf("%s", str1);
        printf("%s", str2);
        free(str1);
        free(str2);
        str1 = get_next_line(fd1);
        str2 = get_next_line(fd2);
    }   
    close(fd1);
    close(fd2);
}

