/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:23 by guilrodr          #+#    #+#             */
/*   Updated: 2023/01/20 16:49:46 by guilrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 199
#define TESTNUMBER 73
//--------------------------------------------3---------------------------------
// si ligne contiens split la ligne en deux et retourne la premiere partie
char	*get_next_line(int fd)
{
    char	*buffer;
    buffer = read_buffer_and_stock(fd);
    if (buffer == NULL)
        return (NULL);

    buffer = collapser(buffer);
    return (buffer);
}
//--------------------------------------------2---------------------------------
// rauni la ligne stockee dans pending line et celle de la derniere lecture du fichier
char    *collapser(char *buffer)
{
    char        *line;
    static char *pending_line;
    size_t      newline_index;

    if (pending_line)
    {
        pending_line = ft_join(pending_line, buffer);
        if (find_newline(pending_line))
        {
            line = may_split (&pending_line);
            if (line)
                return (line);
        }
    }
    newline_index = find_newline(buffer);
    line = NULL;
    if (newline_index && !(pending_line))
    {
        pending_line = ft_join("", buffer + newline_index + 1);
        buffer = realloc_buffer(buffer, newline_index);
        return (buffer);
    }

    return (buffer);
}



//--------------------------------------------1---------------------------------
// si fichier valide, lis BUFFER_SIZE octets dans le fichier et retune le resultat dans une chaine de caracteres finissant par un '\0'

char    *read_buffer_and_stock(int fd)
{
    char        *buffer;
    ssize_t     read_size;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buffer == NULL)
        return (NULL);
    read_size = read(fd, buffer, BUFFER_SIZE);
    if (read_size == -1)
    {
        free(buffer);
        return (NULL);
    }
    if (read_size == 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[read_size + 1] = '\0';
    buffer = realloc_buffer(buffer, read_size);
    return (buffer);
}
















int main (void)
{
	int fd;
	char *line;

	line = NULL;
	fd = open("./lorem.txt",O_RDONLY);
    int i = 0;
	while (i++ < TESTNUMBER)
	{
		line = get_next_line(fd);
        printf("\n______out main Start _____\n");
        printf("line : %d\n" , i);
		printf("%s", line);
		printf("\n______out main End ______\n");
     //   free(line);
	}

	//free(line);
	close(fd);

    return (0);
}