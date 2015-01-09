#include "norminette.h"

int		ft_iscondition(char *line)
{
	if (ft_strnequ(line, "if", 2) && ft_isesp(line[2]))
		return (1);
	if (ft_strnequ(line, "else if", 7) && ft_isesp(line[7]))
		return (1);
	if (ft_strnequ(line, "else", 4) && ft_isesp(line[4]))
		return (1);
	if (ft_strnequ(line, "while", 5) && ft_isesp(line[5]))
		return (1);
	if (ft_strnequ(line, "for", 3) && ft_isesp(line[3]))
	{
		ft_putendl("FOR is forbidden");
		return (1);
	}
	return (0);
}
