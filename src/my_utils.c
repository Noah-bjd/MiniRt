/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:37:12 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/26 18:35:51 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static bool is_delimiter(char c)
{
    return ft_isspace(c);
}

static int count_words(char *str)
{
    int count = 0;
    bool in_word = false;

    while (*str)
    {
        if (is_delimiter(*str))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            in_word = true;
            count++;
        }
        str++;
    }

    return count;
}

static char *extract_word(char *str)
{
    int word_len = 0;

    while (*str && !is_delimiter(*str))
    {
        word_len++;
        str++;
    }

    char *word = malloc((word_len + 1) * sizeof(char));
    strncpy(word, str - word_len, word_len);//implement
    word[word_len] = '\0';

    return word;
}

char **ft_split2(char *str)
{
    int num_words = count_words(str);
    char **words = malloc((num_words + 1) * sizeof(char *));

    if (!words)
        return NULL;

    int word_index = 0;
    bool in_word = false;

    while (*str)
    {
        if (is_delimiter(*str))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            in_word = true;
            words[word_index++] = extract_word(str);
        }

        str++;
    }
    words[word_index] = NULL;
    return words;
}

void    *ft_realloc(void* ptr, size_t new_size) 
{
    size_t  *old_size_ptr;
    size_t  old_size;
    size_t  copy_size;
    void    *new_ptr;
    
    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) 
        return malloc(new_size);
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;  
    old_size_ptr = (size_t*)ptr - 1;
    old_size = *old_size_ptr;
    if (new_size < old_size)
        copy_size = new_size;
    else
        copy_size = old_size;
    ft_memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return (new_ptr);
}

int ft_checkWords(char **array)
{
    int numWords;
    char    **words;
    int i;
    int j;

    i = 0;
    while(array[i] != NULL)
    {
        words = ft_split2(array[i]);
        numWords = mtx_len(words);
        if (numWords != 4)
        {
            j = -1;
            while(words[j++])
                free(words[j]);
            free(words);
            return(0);
        }
        j = -1;
        while(words[j++])
            free(words[j]);
        free(words);
        i++;
    }
    return (1);
}