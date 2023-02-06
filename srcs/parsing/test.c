#include <stdlib.h>
#include <stdio.h>

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

void	test(t_vector *vec)
{
	vec->x = 10;
	vec->y = 25;
	vec->z = 30;
}

int	main(int argc, char **argv)
{
	int			i;
	t_vector	vec;
	int			*tab;

	tab = malloc(atoi(argv[1]));
	i = 0;
	vec.x = 25;
	test(&vec);
	printf("%d\n", vec.x);
}