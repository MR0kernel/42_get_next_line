/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:08 by guilrodr          #+#    #+#             */
/*   Updated: 2023/01/20 16:31:11 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *realloc_buffer(char *buffer, size_t size)
{
    char    *new_buffer;
    size_t     i;

    i = 0;
    if (!buffer)
    {
        new_buffer = (char *)malloc(sizeof(char) * (size + 1));
        if (new_buffer == NULL)
            return (NULL);
        new_buffer[0] = '\0';
        return (new_buffer);
    }
    new_buffer = (char *)malloc(sizeof(char) * (size + 1));
    if (new_buffer == NULL)
        return (NULL);
    while (i < size)
    {
        new_buffer[i] = buffer[i];
        i++;
    }
    new_buffer[i] = '\0';
    free(buffer);
    buffer = NULL;
    return (new_buffer);
}

size_t ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\0')
        i++;
    return (i);
}

size_t find_newline(const char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\0')
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (0);
}

char    *ft_join(char *line, char *buffer)
{
    char    *new_line;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    new_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
    while (line[i])
    {
        new_line[i] = line[i];
        i++;
    }
    while (buffer[j])
    {
        new_line[i] = buffer[j];
        i++;
        j++;
    }
    new_line[i] = '\0';
    return (new_line);
}

char *may_split(char **pending_line)
{
    size_t newline_index;
    char   *line;
    size_t index;
    char *tmp;
    size_t j_index;

    j_index = 0;
    index = 0;
    newline_index = find_newline (*pending_line);
    if (newline_index)
    {
        line = (char *)malloc(sizeof(char) * newline_index + 1);
        while ((*pending_line)[index] != '\n' && (*pending_line)[index] != '\0')
            line[index++] = (*pending_line)[index];
        line[index] = '\0';
        tmp = malloc(sizeof(char) * (ft_strlen(*pending_line) - newline_index + 1));
        if (tmp)
            while ((*pending_line)[index++])
                tmp[j_index++] = (*pending_line)[index];
        free(*pending_line);
        *pending_line = tmp;
        return (line);
    }
    return (NULL);
}
