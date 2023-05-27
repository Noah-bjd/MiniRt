/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_ut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:34:45 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/26 21:36:48 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char* extractElements(char** str, const char* elementPrefix, int h_m_elements) {
    int count ;

    // Allocate memory for the extracted elements
    char** extractedElements = malloc((h_m_elements + 1) * sizeof(char*));
    if (extractedElements == NULL) 
    {
       ft_printf("Error: Allocation problem from extractElements\n", 1);
        return NULL;
    }
    // Extract the matching elements
    count = 0;
    for (int i = 0; str[i] != NULL; i++) {
        if (!ft_strncmp(str[i], elementPrefix, strlen(elementPrefix)))
        {
            extractedElements[count] = ft_strdup(str[i]);
            count++;
        }
    }
    extractedElements[count] = NULL;  // Null-terminate the array
    // Concatenate the extracted elements into a single string
    size_t extractedSize = 0;
    for (int i = 0; i < count; i++) {
        extractedSize += ft_strlen(extractedElements[i]) + 1;  // Account for newline character
    } // 
    char* extractedString = malloc(extractedSize);
    if (extractedString == NULL) {
        // Error handling for memory allocation failure
        free(extractedElements);
        return NULL;
    }
    extractedString[0] = '\0';  // Initialize the string as empty
    for (int i = 0; i < count; i++) {
        strcat(extractedString, extractedElements[i]);
        strcat(extractedString, "\n");
    }

    // Free the memory allocated for the array of pointers
    for (int i = 0; i < count; i++) {
        free(extractedElements[i]);
    }
    free(extractedElements);

    return extractedString;
}

void ft_pl_cordCheck(char **ptr, t_plane *rt)
{
    if (ptr != NULL && mtx_len(ptr) == 3)
    {
        rt->crd.x = ft_atof(ptr[0]);
        rt->crd.y = ft_atof(ptr[1]);
        rt->crd.z = ft_atof(ptr[2]);
    }
    else
    {
        ft_printf("Error: Invalid light coordinates\n", 1);
        exit(EXIT_FAILURE);
    }
}

void ft_pl_Cordination(char *string, t_plane *rt)
{
    char **ptr;

    ptr = ft_split(string, ',');
    if (ptr != NULL && mtx_len(ptr) == 3)
    {
        ft_pl_cordCheck(ptr, rt);
        deallocate(ptr);
    }
    else
    {
        ft_printf("Error: Invalid light coordinates\n", 1);
        exit(EXIT_FAILURE);
    }
    printf("x: %f\n", rt->crd.x);
    printf("y: %f\n", rt->crd.y);
    printf("z: %f\n", rt->crd.z);
}