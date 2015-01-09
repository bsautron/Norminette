#include "norminette.h"

int		ft_istype(char *line)
{
	if (ft_strnequ(line, "void", 4) && ft_isesp(line[4]))
		return (1);
	if (ft_strnequ(line, "char", 4) && ft_isesp(line[4]))
		return (1);
	if (ft_strnequ(line, "int", 3) && ft_isesp(line[3]))
		return (1);
	return (0);
}
