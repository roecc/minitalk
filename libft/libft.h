/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:42:33 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 21:48:01 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

extern int		ft_atoi(const char *str);
extern void		ft_bzero(void *s, size_t n);
extern void		*ft_calloc(size_t count, size_t size);
extern int		ft_isalnum(int c);
extern int		ft_isalpha(int c);
extern int		ft_isascii(int c);
extern int		ft_isdigit(int c);
extern int		ft_isprint(int c);
extern char		*ft_itoa(int n);
extern void		*ft_memchr(void *s, int c, size_t n);
extern int		ft_memcmp(const void *s1, const void *s2, size_t n);
extern void		*ft_memcpy(void *dest, const void *src, size_t n);
extern void		*ft_memmove(void *dest, const void *src, size_t n);
extern void		*ft_memset(void *s, int c, size_t n);
extern void		ft_putchar_fd(char c, int fd);
extern void		ft_putendl_fd(char *s, int fd);
extern void		ft_putnbr_fd(int n, int fd);
extern void		ft_putstr_fd(char *s, int fd);
extern char		**ft_split(char const *s, char c);
extern char		*ft_strchr(char *s, int c);
extern char		*ft_strdup(const char *s1);
extern void		ft_striteri(char *s, void (*f)(unsigned int, char*));
extern char		*ft_strjoin(char const *s1, char const *s2);
extern size_t	ft_strlcat(char *dst, const char *src, size_t size);
extern size_t	ft_strlcpy(char *dst, const char *src, size_t size);
extern long int	ft_strlen(char *s);
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern char		*ft_strnstr(const char *big, const char *little, size_t len);
extern char		*ft_strrchr(char *s, int c);
extern char		*ft_strtrim(char const *s1, char const *set);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern int		ft_tolower(int c);
extern int		ft_toupper(int c);
extern void		ft_lstadd_back(t_list **lst, t_list *new);
extern void		ft_lstadd_front(t_list **lst, t_list *new);
extern void		ft_lstclear(t_list **lst, void (*del)(void*));
extern void		ft_lstdelone(t_list *lst, void (*del)(void *));
extern void		ft_lstiter(t_list *lst, void (*f)(void *));
extern t_list	*ft_lstlast(t_list *lst);
extern t_list	*ft_lstmap(t_list *lst, void *(*f)\
(void *), void (*del)(void *));
extern t_list	*ft_lstnew(void *content);
extern int		ft_lstsize(t_list *lst);

#endif