#include "norminette.h"

int		ft_isiskeyword(char *line)
{
	if (ft_istype(line))
		return (1);
	if (ft_iscondition(line))
		return (1);
	return (0);
}
