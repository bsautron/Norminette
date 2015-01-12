#include "norminette.h"

int		ft_isdeclar(char *line)
{
	if (line[0] == '\t' && ft_istype(&line[1]))
		return (1);
	return (0);
}
