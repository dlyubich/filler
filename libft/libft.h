/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:17:03 by dlyubich          #+#    #+#             */
/*   Updated: 2017/11/01 16:17:03 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 512

# include <wchar.h>
# include <stdarg.h>
# define A(x) ((x) < 0 ? -(x) : (x))

int	g_count;

# define BIT7 127
# define BIT11 2047
# define BIT16 65535
# define BIT21 2097151
# define BIT26 67108863
# define BIT31 2147483647

typedef	struct		s_values
{
	int				minus;
	int				sign;
	int				zero;
	int				resh;
	int				space;

	int				width;
	int				prec;
	int				size;
	char			bukva;

}					t_val;

typedef struct		s_gnl
{
	int				fd;
	char			*str;
}					t_gnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **str);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char	const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
	size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				**ft_strsplit(char const *s, char c);
void				ft_lstpushback(t_list **list, void *content, size_t size);
int					ft_max(int *s, size_t len);
char				*ft_strreverse(const char *s);
void				ft_swap(void *a, void *b);
char				*ft_substr(char const *s, unsigned int start, char c);

int					ft_printf(const char *format, ...);
void				ft_cast(t_val val, va_list args);
char				*ft_itoaint(intmax_t value);
char				*ft_itoa_base(unsigned long long value, int base, int flag);
char				*ft_width(char *str, t_val val);
void				ft_mod(char *str, t_val val, int un);
int					ft_isdigit(int c);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
char				*ft_mod_prec(char *str, t_val val);
void				ft_widestr(wchar_t *d, t_val val);
void				ft_place_char(int size, char c);
int					ft_check_len_wch(char **data);
void				ft_wputstr(char **d);
void				ft_char(t_val val, va_list args);
void				ft_modchar(char *str, t_val val);
char				*ft_mod_resh(char *str, t_val val);
char				*ft_mod_sign(char *str, t_val val);
int					parse_sign(const char *str, int i, t_val *val);
int					parse_dig(const char *str, int i, t_val *val, va_list args);
int					parse_bukva(const char *str, int i, t_val *val);
void				parse_next(t_val val, va_list args);
void				ft_help(t_val val);
int					count_char(const char *str, int i, t_val *val, char c);

#endif
