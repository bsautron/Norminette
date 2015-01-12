#include "norminette.h"

char	*ft_gettype_of_func(char *line)
{
	int		i;

	i = 0;
	if (ft_strnequ(&line[i], "static", 6))
		i += 7;
	if (ft_strnequ(&line[i], "unsigned", 8))
		i += 9;
	return (ft_strndup(&line[i], ft_strlen_esp(&line[i])));
}
