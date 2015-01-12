#include <fcntl.h>
#include "norminette.h"
#include "get_next_line.h"

void	ft_norminette(char **av, char nomain)
{
	char	*line;
	int		i;
	int		l;
	int		fd;
	t_func	*lst;

	i = 1;
	while (av[i])
	{
		while (nomain && av[i] && ft_strstr(av[i], "main"))
			i++;
		if (av[i])
		{
			dprintf(1, "\033[1;37;40mNorme\033[0m: %s\n", av[i]);
			fd = open(av[i], O_RDONLY);
			l = 1;
			lst = NULL;
			while ((get_next_line(fd, &line)) > 0)
			{
				ft_getinfo(line, &lst, l);
				l++;
			}
			ft_analyse(lst);
			close(fd);
			i++;
		}
		else
			break ;
	}
}

int		main(int ac, char **av)
{
	char	nomain;

	nomain = 0;
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "-Nomain"))
		{
			nomain = 1;
			av += 1;
		}
		ft_norminette(av, nomain);
	}
	else
		dprintf(1, "%s\n", "Give me money BITCH!!!");
	return (0);
}
