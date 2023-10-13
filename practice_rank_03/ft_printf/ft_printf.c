
#include<unistd.h>
#include<stdarg.h>

int	put_str(char *str) {
	if (!str) str = "(null)";
	int i = 0;
	while (str[i]) {
		write(1, &str[i], 1);
		i++;
	}
	return i;
}

int put_num(long long num, long long base) {
	char *hex = "0123456789abcdef";
	int len = 1;

	if (num < 0) {
		num = -num;
		write(1, "-", 1);
		len++;
	}

	if (num >= base) {
		len += put_num(num / base, base);
	}
	write(1, &hex[num % base], 1);
	return len;
}

int ft_printf(const char *format, ... )
{
	int len = 0;

	va_list p;
	va_start(p, format);

	while (*format) {
		if (*format == '%' && ((*(format+1) == 's') || (*(format+1) == 'd') || (*(format+1) == 'x'))) {
			format++;
			if (*format == 's') len += put_str(va_arg(p, char *));
			else if (*format == 'd') len += put_num((long long) va_arg(p, int), 10);
			else len += put_num((long long) va_arg(p, unsigned int), 16);
		} else {
			len += write(1, format, 1);
		}
		format++;
	}
	return len;
}

//int main(void) {
//	ft_printf("%s\n", "toto");
//	ft_printf("Magic %s is %d", "number\n", 42);
//	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
//
//	ft_printf("Magic %s is %d", "numero\n", -2147483648);
//}

