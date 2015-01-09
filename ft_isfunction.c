#include "norminette.h"

int		ft_isfunction(char *line)
{
	if (ft_istype(line) && ft_charcheck_in_str('(', line) && ft_charcheck_in_str(')', line))
	{
		return (1);
}
	return (0);
}
