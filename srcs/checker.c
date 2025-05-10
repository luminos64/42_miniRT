#include "miniRT.h"

bool	check_argument(char **split_line, int limit)
{
	int	count;

	count = 0;
	if (!split_line)
		return (0);
	while (split_line[count])
		count++;
	if (count > limit)
		return (false);
	return (true);
}
