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

void	ft_getinfo(char *line, t_func **lst, int l)
{
	size_t	i;
	size_t	len;
	char	bre;
	char	bre2;

	i = 0;
	if (ft_isfunction(line))
	{
		ft_add_elem(lst, ft_creat_elem(ft_getname_of_func(line)));
		(*lst)->nb_param--;
		bre = 0;
		bre2 = 0;
		while (line[i])
		{
			(*lst)->nb_param += ft_istype(&line[i]);
			if (!bre) 
			{
				while (ft_isprint(line[i]))
				{
					(*lst)->scope += 1;
					i++;
				}
				while (line[i] == '\t')
				{
					if (!bre2)
					{
						if (ft_strlen_esp(line) == 4)
							(*lst)->scope += 4;
						(*lst)->scope += 4 - (int)ft_strlen_esp(line);
						bre2 = 1;
					}
					else
						(*lst)->scope += 4;
					i++;
				}
				bre = 1;
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
		if (*lst)
		{
			if ((*lst)->regu_brak > 0)
				(*lst)->nb_line++;
		}
		if (len > 80)
			dprintf(1, "error %d: line have %zu caracter\n", l, len);
	}
}
