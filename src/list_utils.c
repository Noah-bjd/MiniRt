/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:30 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/27 14:00:53 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void add_Obj(t_object **lst, void* object, int type)
{
    t_object    *currentNode;
    t_object    *n_obj;
    
    n_obj = malloc(sizeof(t_object));
    if (!n_obj)
    {
        ft_printf("Error: allocation error for object\n", 2);
        exit(EXIT_FAILURE);
    }
    n_obj->objct = object;
    n_obj->type = type;
    n_obj->next = NULL;
    if (lst || *lst) 
        *lst = n_obj;
    else 
    {
        currentNode = *lst;
        // printf("in addobj : %p\n", currentNode->next);
        printf("hello\n");
        while (currentNode->next)
            currentNode = currentNode->next;
        currentNode->next = n_obj;
    }
}
