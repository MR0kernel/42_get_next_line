/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:31 by guilrodr          #+#    #+#             */
/*   Updated: 2023/01/20 16:31:33 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FR_GETNEXTLINE_FT_GNL_H
#define FR_GETNEXTLINE_FT_GNL_H

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


char    *read_buffer_and_stock(int fd);
char    *realloc_buffer(char *buffer, size_t size);
char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
size_t  find_newline(const char *str);
char    *may_split(char **pending_line);
char    *collapser(char *buffer);
char    *ft_join(char *line, char *buffer);


#endif
