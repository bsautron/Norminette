#include <stdlib.h>
#include "norminette.h"

char		*ft_getname_of_func(char *line)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] >= ' ')
		i++;
	while (ft_isesp(line[i]))
		i++;
	while (line[i] == '*')
		i++;
	while (line[i] != '(')
	{
		i++;
		j++;
	}
	dst = (char *)malloc(sizeof(char) * (j + 1));
	i -= j;
	j = 0;
	while (line[i] != '(')
	{
		dst[j] = line[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
