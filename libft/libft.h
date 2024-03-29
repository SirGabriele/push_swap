/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:16:54 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/20 20:14:59 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_listgnl
{
	int					fd;
	char				*line;
	char				*leftovers;
	int					i;
	int					j;
	ssize_t				hmb_read;
	ssize_t				nb_of_read;
	struct s_listgnl	*next;
}		t_listgnl;

// CHAR
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

char		*ft_strupcase(char *str);
char		*ft_strlowcase(char *str);
char		*ft_strcapitalize(char *str);

//STR
size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
int			ft_extension(const char *s1, const char *s2);

//MEMORY
void		*ft_memset(void *ptr, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

//OUTPUT
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr(char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int nb);

//OTHER
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);

//LL
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//FT_PRINTF
int			ft_printf(const char *format, ...);
void		ft_specifier_requested(const char **fmt, int *i, va_list param);
void		ft_flag_requested(const char **fmt, int *i, va_list param);
void		ft_putcharprintf(unsigned const char c, int *i);
void		ft_putstrprintf(char *str, int *i);
void		ft_putnbrbaseprintf(unsigned int nbr, char *base, int *i);
void		ft_putnbrprintf(long long int nbr, int *i);
void		ft_print_memory(unsigned long long int arg, int *i);
void		ft_putmemory(unsigned long long int nbr, char *base, int *i);
int			ft_is_a_specifier(const char c);

//FT_PRINTF_ERROR
int			ft_printf_error(const char *format, ...);
void		ft_specifier_asked_error(const char **fmt, int *i, va_list param);
void		ft_flag_asked_error(const char **fmt, int *i, va_list param);
void		ft_putcharprintf_error(unsigned const char c, int *i);
void		ft_putstrprintf_error(char *str, int *i);
void		ft_putnbrbaseprintf_error(unsigned int nbr, char *base, int *i);
void		ft_putnbrprintf_error(long long int nbr, int *i);
void		ft_print_memory_error(unsigned long long int arg, int *i);
size_t		ft_strlen(const char *str);
void		ft_putmemory_error(unsigned long long int nbr, char *base, int *i);
int			ft_is_a_specifier_error(const char c);

//GNL_TDL
t_listgnl	*ft_lstnewgnl(int entry_fd);
void		ft_lstadd_backgnl(t_listgnl **first_elem, t_listgnl *new);
t_listgnl	*ft_go_to_linkgnl(t_listgnl **first_elem, int fd);
char		*ft_erase_linkgnl(t_listgnl **first_elem, t_listgnl *temp);
char		*get_next_line(int fd);
void		ft_read_file_and_fill_buf(t_listgnl *temp);
void		ft_fill_line_and_sort_leftovers(t_listgnl *temp);
void		ft_manage_buf(t_listgnl *temp);
void		ft_sort_leftovers(t_listgnl *temp);
int			check_string(t_listgnl *temp);
char		*ft_increase_string_size(t_listgnl *temp, char *string);
void		*ft_callocgnl(int size);

#endif
