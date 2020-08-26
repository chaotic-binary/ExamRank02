# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int p;
int w;

int pf_strlen(char *s)
{
	if (!s)
		return 6;
	char *start = s;
	while (*s)
		++s;
	return (s - start);
}

int ft_min(int x, int y)
{
	return (x < y) ? x : y;
}

int	print_pad(char sym, int pad)
{
	if (pad <= 0)
		return 0;
	int i = pad + 1;
	while (--i)
		write(1, &sym, 1);
	return (pad);
}

int count_digits(size_t n, size_t bs)
{
	int i = 1;

	while (n / bs)
	{
		n /= bs;
		++i;
	}
	return i;
}

int print_num(size_t n, size_t bs, int len)
{
	char res[len];
	char digits[] = "0123456789abcdef";
	int i = len - 1;

	while (i >= 0)
	{
		res[i] = digits[n % bs];
		n /= bs;
		--i;
	}
	return (write(1, res, len));
}

int print_str(char *s, int len)
{
	if (!s)
		return (write(1,"(null)",len));
	else
		return (write(1, s, len));
}

void	atoi_wp(const char **fmt, int *value)
{
	int n = 0;

	while (**fmt >= '0' && **fmt <= '9')
	{
		n = n * 10 + (**fmt - '0');
		++*fmt;
	}
	*value = n;
}

void	print_fmt(const char **fmt, va_list arg, int *ret)
{
	int arglen;
	int sign = 0;
	size_t n;
	char *s;
	char c = **fmt;

	if (!c)
		return;
	else
		++*fmt;
	if (c == 's')
	{
		s = va_arg(arg, char *);
		arglen = pf_strlen(s);
		if (p > -1)
			arglen = ft_min(p, arglen);
		p = 0;
		w = w - arglen;
	}
	else
	{
		if (c == 'x')
		{
			n = (size_t)va_arg(arg, unsigned);
			arglen = count_digits(n, 16);
		}
		if (c == 'd')
		{
			long d = (long)va_arg(arg, int);
			if (d < 0)
			{
				n = (size_t)(-d);
				sign = 1;
			}
			else
				n = (size_t)d;
			arglen = count_digits(n, 10);
		}
		if (n == 0 && p == 0)
			arglen = 0;
		if (p > 0)
			p = p - arglen;
		if (p < 0)
			p = 0;
		w = w - p - arglen - sign;
	}
	*ret += print_pad(' ', w);
	if (sign)
		*ret += write(1, "-", 1);
	*ret += print_pad('0', p);
	if (c == 's')
		*ret += print_str(s, arglen);
	if (c == 'd')
		*ret += print_num(n, 10, arglen);
	if (c == 'x')
		*ret += print_num(n, 16, arglen);
}

int	ft_printf(const char *fmt, ... )
{
	va_list	arg;
	int		ret;

	if (!fmt)
		return (-1);
	ret = 0;
	va_start(arg, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			ret += write(1, fmt++, 1);
		if (*fmt == '%')
		{
			w = 0;
			p = -1;
			++fmt;
			atoi_wp(&fmt, &w);
			if (*fmt == '.')
			{
				++fmt;
				atoi_wp(&fmt, &p);
			}
			print_fmt(&fmt, arg, &ret);
		}
	}
	va_end(arg);
	return ret;
}