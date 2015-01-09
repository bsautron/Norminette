#ifndef NORMINETTE_H
# define NORMINETTE_H

# include <stdio.h>
# include "libft.h"

typedef struct		s_func
{
	char			*name;
	int				nb_param;
	int				scope;
	int				regu_brak;
	int				nb_line;
	struct s_func	*next;
}					t_func;

void	ft_getinfo(char *, t_func **, int);
int		ft_istype(char *);
int		ft_iskeyword(char *);
int		ft_iscondition(char *);
int		ft_isfunction(char *);
char	*ft_getname_of_func(char *line);
t_func	*ft_creat_elem(char *name);
void	ft_add_elem(t_func **begin, t_func *new);
void	ft_analyse(t_func *lst);

#endif
