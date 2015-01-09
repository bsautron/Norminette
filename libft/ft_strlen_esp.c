#include "libft.h"

size_t			ft_strlen_esp(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] > ' ')
		i++;
	return (i);
}
