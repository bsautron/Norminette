#include "norminette.h"

int		ft_strlen_scope(char *str)
{
	int		i;

	i = 0;
	if (ft_strnequ(&str[i], "static", 6))
		i += 7;
	if (ft_strnequ(&str[i], "unsigned", 8))
		i += 9;
	while (str[i] && str[i] >= ' ')
		i++;
	return (i);
}
