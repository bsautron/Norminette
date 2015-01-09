#include <stdlib.h>
#include "norminette.h"

void	ft_add_elem(t_func **begin, t_func *new)
{
	if (begin && new)
	{
		new->next = *begin;
		*begin = new;
	}
	else if (!new && begin)
		new = *begin;
}
