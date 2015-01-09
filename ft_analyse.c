#include "norminette.h"

void	ft_gscope(t_func *lst)
{
	int		scope;

	scope = lst->scope;
	lst = lst->next;
	while (lst && lst->scope == scope)
		lst = lst->next;
	if (lst)
		dprintf(1, "%s\n", "error: bad global scope");
}

void	ft_nbline(t_func *lst)
{
	while (lst)
	{
		if (lst->nb_line > 25)
			dprintf(1, "error: function %s have %d lines\n", lst->name, lst->nb_line);
		lst = lst->next;
	}
}

void	ft_nbfunc(t_func *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	if (i > 5)
		dprintf(1, "error: file have %d functions\n", i);
}

void	ft_analyse(t_func *lst)
{
	if (lst)
	{
		ft_nbfunc(lst);
		ft_gscope(lst);
		ft_nbline(lst);
	}
}
