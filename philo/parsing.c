#include "philo.h"

int	parse_input(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			printf("No negative values admited\n");
			return (1);
		}
		if (argv[i][j] == '+' && argv[i][j + 1] == '0')
		{
			printf("+0...Is not a valid format\n");
			return (1);
		}
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
		       j++;
		if (argv[i][j])
		{
			printf("Non numeric value inside the argvs\n");
			return (1);
		}
	i++;
	}
	return (0);	
}
