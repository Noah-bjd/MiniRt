/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:59:48 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/27 13:32:24 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void    check_Alpha(char **string)
{
    int i;
    int C_A;
    int C_C;
    int C_L;

    C_A = 0;
    C_C = 0;
    C_L = 0;
    i = 0;
    while(string[i])
    {
        if (string[i][0] == 'A')
            C_A++;
        else if (string[i][0] == 'C')
            C_C++;
        else if(string[i][0] == 'L')
            C_L++;
        i++;
    }
    if ((C_A > 1 || C_L > 1 || C_C > 1))
    {
        printf("Error: Multiple or less occurrences of A, C, or L\n");
        exit(EXIT_FAILURE);
    }
}

void get_Alpha(t_rt *rt)
{
    char    *tmp;
    int     i;
    t_lines lines[] = {
        {"A ", ft_Alight, 3},
        {"C ", ft_Cam, 4},
        {"L ", ft_light, 4}
    };
    i = 0;
    while (i < sizeof(lines) / sizeof(lines[0]))
    {
        tmp = SearchString(rt->fl, lines[i].prefix);
        if (tmp == NULL)
        {
            printf("Error: Unable to find '%s' line\n", lines[i].prefix);
            exit(1);
        }
        if (!(lines[i].count ^ countWords(tmp))) {
            lines[i].function(tmp, rt);
        } 
        else 
        {
            printf("Error: Invalid format for '%s' line\n", lines[i].prefix);
            exit(1);
        }
        i++;
    }
}
void    len_elem(char **string,int *pl, int *sp, int *cy)
{
    int i;

    i = 0;
    while(string[i])
    {
        if (!ft_strncmp(string[i], "pl ", ft_strlen("pl ")))
            (*pl)++;
        else if (!ft_strncmp(string[i], "sp ", ft_strlen("sp ")))
            (*sp)++;
        else if(!ft_strncmp(string[i], "cy ", ft_strlen("cy ")))
            (*cy)++;
        i++;
    }
     if (!(*pl ^ 0 ) || !(*sp ^ 0) || !(*cy ^ 0))
    {
        if (*pl == 0)
            ft_printf("Error: Missing 'pl' elements\n", 1);
        if (*sp == 0)
            ft_printf("Error: Missing 'sp' elements\n", 1);
        if (*cy == 0)
            ft_printf("Error: Missing 'cy' elements\n", 1);
        exit(EXIT_FAILURE);
    }
}
// void    get_elem(t_rt *rt)
// {
//     int pl;
//     int sp;
//     int cy;

//     pl = 0;
//     sp = 0;
//     cy = 0;
    // len_elem(rt->fl, &pl, &sp,&cy);
//     ft_pl(rt, pl);
// }
void init_rt(t_rt *rt)
{
    char    **tok;
    check_Alpha(rt->fl);
    get_Alpha(rt);
    // printf_tab(rt);
    parse_obj(rt);
}