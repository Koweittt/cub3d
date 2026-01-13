/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trambure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:12:46 by trambure          #+#    #+#             */
/*   Updated: 2025/05/05 08:12:55 by trambure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
char	*gnl_strdup(const char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);

#endif
