# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

int	ft_printf(const char *s, ... );
int 	main(void)
{
	int ret_my;
	int ret_pf;

//s
	ret_my = ft_printf("%10.2s\n", "toto");
	ret_pf = printf("%10.2s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%2.2s\n", "toto");
	ret_pf = printf("%2.2s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%2.20s\n", "toto");
	ret_pf = printf("%2.20s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%20.20s\n", "toto");
	ret_pf = printf("%20.20s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%.s\n", "toto");
	ret_pf = printf("%.s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%.4s\n", "toto");
	ret_pf = printf("%.4s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%12s\n", "toto");
	ret_pf = printf("%12s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%2s\n", "toto");
	ret_pf = printf("%2s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%s\n", "toto");
	ret_pf = printf("%s\n", "toto");
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%s\n", NULL);
	ret_pf = printf("%s\n", NULL);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%.s\n", NULL);
	ret_pf = printf("%.s\n", NULL);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%10.3s\n", NULL);
	ret_pf = printf("%10.3s\n", NULL);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("%10.s\n", NULL);
	ret_pf = printf("%10.s\n", NULL);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

//d
	ret_my = ft_printf("Magic %s is %15d\n", "number", 42);
	ret_pf = printf("Magic %s is %15d\n", "number", 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %1d\n", "number", 42);
	ret_pf = printf("Magic %s is %1d\n", "number", 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %15.2d\n", "number", -42);
	ret_pf = printf("Magic %s is %15.2d\n", "number", -42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %15.20d\n", "number", 42);
	ret_pf = printf("Magic %s is %15.20d\n", "number", 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %15.20d\n", "number", -2147483648);
	ret_pf = printf("Magic %s is %15.20d\n", "number", -2147483648);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %.20d\n", "number", 42);
	ret_pf = printf("Magic %s is %.20d\n", "number", 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %.2d\n", "number", 42);
	ret_pf = printf("Magic %s is %.2d\n", "number", 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %d\n", "number", 42);
	ret_pf = printf("Magic %s is %d\n", "number", 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

//x
	ret_my = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %d is %20x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %20x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %d is %1x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %1x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %d is %1.1x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %1.1x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %d is %10.1x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %10.1x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	 ret_my = ft_printf("Hexadecimal for %d is %.1x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %.1x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %d is %.10x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %.10x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %d is %10.10x\n", 42, 42);
	ret_pf = printf("Hexadecimal for %d is %10.10x\n", 42, 42);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %.d is %.x\n", 0, 0);
	ret_pf = printf("Hexadecimal for %.d is %.x\n", 0, 0);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Hexadecimal for %d is %x?\n", 0, 0);
	ret_pf = printf("Hexadecimal for %d is %x?\n", 0, 0);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ret_my = ft_printf("Magic %s is %15.20x\n", "number", 4294967295);
	ret_pf = printf("Magic %s is %15.20x\n", "number", 4294967295);
	if (ret_my != ret_pf)
		printf("pf: %d\nmy: %d\n\n", ret_pf, ret_my);

	ft_printf("no segfault pls %.m!", 0);
}
