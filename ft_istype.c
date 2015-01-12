#include "norminette.h"

int		ft_istype(char *line)
{
	if (ft_strnequ(line, "t_", 2))
		return (1);
	if (ft_strnequ(line, "int", 3))
		return (1);
	if (ft_strnequ(line, "char", 4))
		return (1);
	if (ft_strnequ(line, "void", 4))
		return (1);
	if (ft_strnequ(line, "long", 4))
		return (1);
	if (ft_strnequ(line, "float", 5))
		return (1);
	if (ft_strnequ(line, "short", 5))
		return (1);
	if (ft_strnequ(line, "signed", 6))
		return (1);
	if (ft_strnequ(line, "double", 6))
		return (1);
	if (ft_strnequ(line, "size_t", 6))
		return (1);
	if (ft_strnequ(line, "static", 6))
		return (1);
	if (ft_strnequ(line, "struct", 6))
		return (1);
	if (ft_strnequ(line, "unsigned", 8))
		return (1);
	return (0);
}
