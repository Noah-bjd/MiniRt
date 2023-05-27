/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:25:13 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/26 21:29:27 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
// void ft_rgb_pl(char *rgb_string, t_plane *pl)
// {
//     int R;
//     int G;
//     int B;
//     char **rgb_values;

//     R = 0;
//     G = 0;
//     B = 0;
   
//     if (rgb_values != NULL && mtx_len(rgb_values) == 3) 
//     {
//         if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3 && ft_strlen(rgb_values[2]) <= 3)
//         {
//             R = M_ft_atoi(rgb_values[0]);
//             G = M_ft_atoi(rgb_values[1]);
//             B = M_ft_atoi(rgb_values[2]);
//              if (R >= 0 && R <= 255 && G >= 0 && G <= 255 && B >= 0 && B <= 255)
//             {
//                 pl->clr.r = R;
//                 pl->clr.g = G;
//                 pl->clr.b = B;
//             }
//             else
//             {
//                 ft_printf("Error: Invalid RGB values in plane\n", 2);
//                 exit(EXIT_FAILURE);
//             }
//         }
//         else
//         {
//             ft_printf("Error: Problem with the RGB length\n", 2);
//             exit(EXIT_FAILURE);
//         }
//         deallocate(rgb_values);
//     }
//     else
//     {
//         ft_printf("Error: RGB problem in camera\n", 2);
//         exit(EXIT_FAILURE);
//     }
// }
// void ft_rgb_pl(char *rgb_string, t_plane *pl)
// {
//     int R;
//     int G;
//     int B;
//     char **rgb_values;

//     R = 0;
//     G = 0;
//     B = 0;

//     rgb_values = ft_split(rgb_string, ','); // Split the RGB values

//     if (rgb_values != NULL && mtx_len(rgb_values) == 3) 
//     {
//         if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3 && ft_strlen(rgb_values[2]) <= 3)
//         {
//             R = M_ft_atoi(rgb_values[0]);
//             G = M_ft_atoi(rgb_values[1]);
//             B = M_ft_atoi(rgb_values[2]);
//              if (R >= 0 && R <= 255 && G >= 0 && G <= 255 && B >= 0 && B <= 255)
//             {
//                 pl->clr.r = R;
//                 pl->clr.g = G;
//                 pl->clr.b = B;
//             }
//             else
//             {
//                 ft_printf("Error: Invalid RGB values in plane\n", 2);
//                 exit(EXIT_FAILURE);
//             }
//         }
//         else
//         {
//             ft_printf("Error: Problem with the RGB length\n", 2);
//             exit(EXIT_FAILURE);
//         }
//         deallocate(rgb_values);
//     }
//     else
//     {
//         ft_printf("Error: RGB problem in camera\n", 2);
//         exit(EXIT_FAILURE);
//     }
//     // printf_tab(rt);
// }
// void get_pl(char **array, t_rt *rt)
// {
//     t_plane *plane;
//     char **pl_valu;
//     int i = 0;

//     while (array[i])
//     {
//         pl_valu = ft_split2(array[i]);
//         plane = malloc(sizeof(t_plane)); // Allocate memory for plane
//         if (!plane)
//         {
//             ft_printf("Error: Failed to allocate memory for plane\n", 1);
//             exit(EXIT_FAILURE);
//         }
//         if (pl_valu != NULL && mtx_len(pl_valu) == 4)
//         {
//             ft_pl_Cordination(pl_valu[1], plane);
//             ft_rgb_pl(pl_valu[3], plane);
//             add_Obj(rt, plane, PLANE);
//             deallocate(pl_valu);
//         }
//         else
//         {
//             ft_printf("Error: Invalid PL values\n", 2);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }
// }
// void print_objects(t_rt *rt)
// {
//     if (rt == NULL || rt->object == NULL)
//     {
//         printf("No objects allocated.\n");
//         return;
//     }

//     for (t_object *obj = rt->object; obj != NULL; obj = obj->next)
//     {
//         if (obj->type == PLANE)
//         {
//             t_plane *plane = (t_plane *)obj->objct;
//             printf("Object Type: Plane\n");
//             printf("Plane Color: RGB(%d, %d, %d)\n", plane->clr.r, plane->clr.g, plane->clr.b);
//             printf("Plane Coordinates: (%f, %f, %f)\n", plane->crd.x, plane->crd.y, plane->crd.z);
//             printf("\n");
//         }
//         else
//             printf("nah");
//     }
// }

// void ft_pl(t_rt *rt, int count)
// {
//     char *pl_elem;
//     char **array;

//     pl_elem = extractElements(rt->fl, "pl ", count);
//     array = ft_split(pl_elem, '\n');
//     if (array != NULL && ft_checkWords(array))
//         get_pl(array, rt);
//     else 
//     {
//         ft_printf("Error: Invalid array or words\n", 2);
//        exit(1);
//     }
//     print_objects(rt);
//     // return(0);
// }
// void ft_rgb_pl(char *rgb_string, t_plane *pl)
// {
//     int R;
//     int G;
//     int B;
//     char **rgb_values;

//     R = 0;
//     G = 0;
//     B = 0;

//     rgb_values = ft_split(rgb_string, ','); // Split the RGB values

//     if (rgb_values != NULL && mtx_len(rgb_values) == 3)
//     {
//         if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3 && ft_strlen(rgb_values[2]) <= 3)
//         {
//             R = M_ft_atoi(rgb_values[0]);
//             G = M_ft_atoi(rgb_values[1]);
//             B = M_ft_atoi(rgb_values[2]);
//             if (R >= 0 && R <= 255 && G >= 0 && G <= 255 && B >= 0 && B <= 255)
//             {
//                 pl->clr.r = R;
//                 pl->clr.g = G;
//                 pl->clr.b = B;
//             }
//             else
//             {
//                 ft_printf("Error: Invalid RGB values in plane\n", 2);
//                 exit(EXIT_FAILURE);
//             }
//         }
//         else
//         {
//             ft_printf("Error: Problem with the RGB length\n", 2);
//             exit(EXIT_FAILURE);
//         }
//         deallocate(rgb_values);
//     }
//     else
//     {
//         ft_printf("Error: RGB problem in camera\n", 2);
//         exit(EXIT_FAILURE);
//     }
// }

// void get_pl(char **array, t_rt *rt)
// {
//     t_plane *plane;
//     char **pl_valu;
//     int i = 0;

//     while (array[i])
//     {
//         pl_valu = ft_split2(array[i]);
//         plane = malloc(sizeof(t_plane)); // Allocate memory for plane
//         if (!plane)
//         {
//             ft_printf("Error: Failed to allocate memory for plane\n", 1);
//             exit(EXIT_FAILURE);
//         }
//         if (pl_valu != NULL && mtx_len(pl_valu) == 4)
//         {
//             ft_pl_Cordination(pl_valu[1], plane);
//             ft_rgb_pl(pl_valu[3], plane);
//             add_Obj(rt, plane, PLANE);
//             deallocate(pl_valu);
//         }
//         else
//         {
//             ft_printf("Error: Invalid PL values\n", 2);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }
// }

// void print_objects(t_rt *rt)
// {
//     if (rt == NULL || rt->object == NULL)
//     {
//         printf("No objects allocated.\n");
//         return;
//     }

//     for (t_object *obj = rt->object; obj != NULL; obj = obj->next)
//     {
//         if (obj->type == PLANE)
//         {
//             t_plane *plane = (t_plane *)obj->objct;
//             printf("Object Type: Plane\n");
//             printf("Plane Color: RGB(%d, %d, %d)\n", plane->clr.r, plane->clr.g, plane->clr.b);
//             printf("Plane Coordinates: (%f, %f, %f)\n", plane->crd.x, plane->crd.y, plane->crd.z);
//             printf("\n");
//         }
//         else
//         {
//             printf("Unknown object type\n");
//         }
//     }
// }

// void ft_pl(t_rt *rt, int count)
// {
//     char *pl_elem;
//     char **array;

//     pl_elem = extractElements(rt->fl, "pl ", count);
//     array = ft_split(pl_elem, '\n');
//     if (array != NULL && ft_checkWords(array))
//         get_pl(array, rt);
//     else
//     {
//         ft_printf("Error: Invalid array or words\n", 2);
//         exit(1);
//     }
//     print_objects(rt);
// }