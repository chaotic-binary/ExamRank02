#include <unistd.h>

int main(int ac, char **av)
{
	int tab[256];
	int i, j;

	if (ac == 3)
	{
		i = 0;
		while (i < 256)
			tab[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (av[i][j])
			{
				if (i == 2 && tab[(unsigned char)av[i][j]] == 0)
				{
					tab[(unsigned char)av[i][j]] = 1;
				}
				if (i == 1 && tab[(unsigned char)av[i][j]] == 1)
				{
					tab[(unsigned char)av[i][j]] = 2;
					write(1, &av[i][j], 1);
				}
				++j;
			}
			--i;
		}
	}
	write(1, "\n", 1);
	return 0;
}