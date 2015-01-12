#include <unistd.h>
#include "norminette.h"


void	ft_univer(char *line, int l)
{
	int		i;
	int		len;

	len = ft_strlen(line) - 1;
	i = len;
	while (i >= 0 && line[i] && line[i] <= ' ')
		i--;
	if (i != len)
		dprintf(1, "error %d: white space in endding the line\n", l);
}

int		ft_scope(char *line, t_func *lst)
{
	int		i;
	int		len;
	char	bre;

	i = 0;
	len = 0;
	bre = 0;
	while (line[i] && line[i] != '*')
	{
		if (ft_strnequ(&line[i], lst->name, ft_strlen(lst->name)))
			break ;
		if (line[i] == '\t')
			len += 4 - len % 4;
		len++;
		i++;
	}
	return (len);
}

void	ft_getinfo(char *line, t_func **lst, int l)
{
	int		bre;
	static int	status;
	int		regu_par;
	size_t	i;
	size_t	len;

	i = 0;
	regu_par = 0;
	if (ft_isfunction(line))
	{
		status = 1;
		ft_add_elem(lst, ft_creat_elem(ft_getname_of_func(line)));
		(*lst)->scope = ft_scope(line, *lst);
		while (line[i])
		{
			if (line[i] == '(')
				regu_par++;
			if (line[i] == ')')
				regu_par--;
			if (ft_strnequ(&line[i], (*lst)->name, ft_strlen((*lst)->name)))
				i+= ft_strlen((*lst)->name) - 1;
			while (ft_istype(&line[i]))
			{
				if (regu_par > 0)
					(*lst)->nb_param += 1;
				i += ft_strlen_esp(&line[i]);
			}
			i++;
		}
		if ((*lst)->nb_param > 4)
			dprintf(1, "error %d: function %s give %d arguments\n", l, (*lst)->name, (*lst)->nb_param);
	}
	else
	{
		bre = 0;
		len = 0;
		if (*lst && ft_onlyesp(line))
		{
			if ((*lst)->regu_brak == 0)
				(*lst)->after_func++;
			if ((*lst)->after_dec >= 0 && status == 2)
			{
				dprintf(1, "error %d: declaration must be following by a single empty line\n", l);
			}
			else if ((*lst)->after_dec < -1 && (*lst)->regu_brak)
				dprintf(1, "error %d: empty line\n", l);
		}
		if (*lst && ft_isdeclar(line))
		{
			status = 2;
			(*lst)->after_dec = -1;
			(*lst)->nb_var++;
		}
		else
		{
			if (*lst && ft_onlyesp(line) && status == 2)
				(*lst)->after_dec += 1;
			else if (*lst)
			{
				status = 0;
				(*lst)->after_dec = -2;
			}
			while (line[i])
			{
				if (ft_strnequ(&line[i], "//", 2))
					dprintf(1, "error %d: bad comment\n", l);
				if (*lst)
				{
					if (line[i] == '{')
						(*lst)->regu_brak++;
					else if (line[i] == '}')
						(*lst)->regu_brak--;
				}
				if (!bre)
				{
					ft_univer(line, l);
					bre = 1;
				}
				if (line[i] == '\t')
					len += 3;
				len++;
				i++;
			}
		}
		if (*lst)
		{
			if ((*lst)->regu_brak > 0)
				(*lst)->nb_line++;
		}
		if (len > 80)
			dprintf(1, "error %d: line have %zu caracter\n", l, len);
	}
}
