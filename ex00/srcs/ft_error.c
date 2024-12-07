#include "rush02.h"

void	ft_error(void)
{
	write (2, "Error", 5);
	write (1, "\n", 1);
}

void	ft_error_dict(void)
{
	write (2, "Dict Error", 10);
	write (1, "\n", 1);	
}
