#include <stdlib.h>
#include "norminette.h"

t_func	*ft_creat_elem(char *name)
{
	t_func	*new;

	new = (t_func *)malloc(sizeof(t_func));
	if (new)
	{
		new->name = ft_strdup(name);
		new->nb_param = 0;
		new->scope = 0;
		new->regu_brak = 0;
		new->nb_line = 0;
		new->nb_var = 0;
		new->after_dec = 0;
		new->after_func = 0;
		new->next = NULL;
	}
	return (new);
}
