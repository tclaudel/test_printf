/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:15:11 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 11:27:18 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

#include <stdio.h>
#include <limits.h>
#include <time.h>

void	print_error (size_t *i)
{
	dprintf(1, "\033[1;31m");
	dprintf(1, "\n>============================================<\n\n");
	dprintf(1, "                       KO                     \n\n");
	dprintf(1, ">============================================<\n\n");
	dprintf(1, "\033[0m");
	*i += 1;
}

void	print_ok (size_t *i)
{
	dprintf(1, "\033[0;32m");
	dprintf(1, "return : OK\n\n");
	dprintf(1, "\033[0m");
	*i += 1;
}

void	print_undef ()
{
	dprintf(1, "\033[3;32m");
	dprintf(1, "undefined\n\n");
	dprintf(1, "\033[0m");
}

void	print_testing (char *str)
{
	dprintf(1, "\033[3;90m");
	dprintf(1, "testing \t%s\n", str);
	dprintf(1, "\033[0m");
}

void	print_result(size_t tested, size_t ok, size_t ko)
{
	size_t pourcentok;

	pourcentok = ok * 100 / tested;
	dprintf(1, ">------------------ RESULT ------------------<\n\n");

	dprintf(1, "\033[1;90m");
	dprintf(1, "\tTESTED : %zu\n", tested);
	dprintf(1, "\033[0m");
	if (pourcentok == 100)
	{
		dprintf(1, "\033[1;32m");
		dprintf(1, "\t%zu TEST FULL PASSED\n", ok);
		dprintf(1, "\033[0m");
	}
	else 
	{
		dprintf(1, "\033[1;31m");
		dprintf(1, "\t%zu%% failed\n", 100 -pourcentok);
		dprintf(1, "\t%zu errors found\n", ko);
		dprintf(1, "\033[0m");
	}
	
	dprintf(1, "\n>--------------------------------------------<\n");

}

int		ft_uatoi(const char *nptr)
{
	int		i;
	unsigned int		nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - '0';
		i++;
	}
	if (sign == 1)
		return (-nb);
	return (nb);
}

int		ft_c_in_str(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}


char	*ft_random_str(size_t length)
{
	static char		charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char			*randstr;
	size_t			i;
	size_t			key;

	key = 0;
	i = 0;
	randstr = malloc(sizeof(char) * (length +1));
	while(i < length)
	{
		key = rand() % sizeof(charset) -1;
		randstr[i] = charset[key];
		i++;
	}
	randstr[length] = '\0';
	return (randstr);
}

int		ft_random_nb(size_t length)
{
	static char		charset[] = "0123456789";
	char			*randstr;
	size_t			i;
	size_t			key;
	int				nb;

	key = 0;
	i = 0;
	randstr = malloc(sizeof(char) * (length +1));
	key = rand() % sizeof(charset) -1;
	if(key % 2 == 1)
	{
		randstr[i] = '-';
		i++;
	}
	while(i < length)
	{
		key = rand() % sizeof(charset) -1;
		randstr[i] = charset[key];
		i++;
	}
	randstr[length] = '\0';
	nb = ft_atoi(randstr);
	free(randstr);
	return (nb);
}

unsigned int	ft_random_unb(size_t length)
{
	static char		charset[] = "0123456789";
	char			*randstr;
	size_t			i;
	size_t			key;
	int				nb;

	key = 0;
	i = 0;
	randstr = malloc(sizeof(char) * (length +1));
	while(i < length)
	{
		key = rand() % sizeof(charset) -1;
		randstr[i] = charset[key];
		i++;
	}
	randstr[length] = '\0';
	nb = ft_uatoi(randstr);
	free(randstr);
	return (nb);
}

int		main(int ac, char **av)
{
	size_t	tested = 0;
	size_t	testok = 0;
	size_t	testko = 0;
	int		i;

	fflush(stdout);

	srand (time (NULL));
	
	char	*str[20] = {"", NULL, "0", ft_random_str(10), ft_random_str(10), ft_random_str(10), ft_random_str(10), ft_random_str(12), ft_random_str(18), ft_random_str(3), ft_random_str(53), ft_random_str(16), ft_random_str(17), ft_random_str(1), ft_random_str(20), ft_random_str(10), ft_random_str(54), ft_random_str(0), ft_random_str(100), ft_random_str(50)};
	unsigned int	unb[20] = {0, UINT_MAX, ft_random_unb(1), ft_random_unb(1),ft_random_unb(1),ft_random_unb(1), ft_random_unb(2), ft_random_unb(3), ft_random_unb(4), ft_random_unb(5), ft_random_unb(6), ft_random_unb(7), ft_random_unb(8), ft_random_unb(9), ft_random_unb(10), ft_random_unb(11), ft_random_unb(12), ft_random_unb(13), ft_random_unb(14), ft_random_unb(15)};
	int		nb[20] = {0, INT_MIN, INT_MAX, -1, ft_random_nb(2), ft_random_nb(3), ft_random_nb(3),ft_random_nb(3),ft_random_nb(3),ft_random_nb(3),ft_random_nb(4), ft_random_nb(5), ft_random_nb(6), ft_random_nb(7), ft_random_nb(8), ft_random_nb(9), ft_random_nb(10), ft_random_nb(11), ft_random_nb(12)};

	if(ac == 1 || ft_c_in_str('a', av[1]))
	{dprintf(1, ">--------------- CLASSIC TEST ---------------<\n\n");
	
	tested++;
	print_testing("bonjour");
	if (printf("printf    :\tbonjour\n") == ft_printf("ft_printf :\tbonjour\n"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("");
	if (printf("") == ft_printf(""))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ D TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.d\\n|\", 0");
	if (printf("printf    :\t|%.d|\n", 0) == ft_printf("ft_printf :\t|%.d|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%--d\\n|\", 45");
	if (printf("printf    :\t|%--d|\n", 45) == ft_printf("ft_printf :\t|%--d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%00d\\n|\", 45");
	if (printf("printf    :\t|%00d|\n", 45) == ft_printf("ft_printf :\t|%00d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45d\\n|\", 0");
	if (printf("printf    :\t|%.45d|\n", 0) == ft_printf("ft_printf :\t|%.45d|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%45d\\n|\", -87");
	if (printf("printf    :\t|%45d|\n", -87) == ft_printf("ft_printf :\t|%45d|\n", -87))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*d\\n|\", -9, -87");
	if (printf("printf    :\t|%*d|\n", -9, -87) == ft_printf("ft_printf :\t|%*d|\n", -9, -87))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-*d\\n|\", -9, -87");
	if (printf("printf    :\t|%-*d|\n", -9, -87) == ft_printf("ft_printf :\t|%-*d|\n", -9, -87))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"%.*d|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*d|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*d|\\n\", 0, 45");
	if (printf("printf    :\t|%.*d|\n", 0, 45) == ft_printf("ft_printf :\t|%.*d|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*d|\\n\", 45, 0");
	if (printf("printf    :\t|%.*d|\n", 45, 0) == ft_printf("ft_printf :\t|%.*d|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", 45");
	if (printf("printf    :\t|%d|\n", 45) == ft_printf("ft_printf :\t|%d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%--d|\\n\", 45");
	if (printf("printf    :\t|%--d|\n", 45) == ft_printf("ft_printf :\t|%--d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.046d|\\n\", 45");
	if (printf("printf    :\t|%.046d|\n", 45) == ft_printf("ft_printf :\t|%.046d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046d|\\n\", 45");
	if (printf("printf    :\t|%046d|\n", 45) == ft_printf("ft_printf :\t|%046d|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-*046d|\\n\", 15, 45");
	if (printf("printf    :\t|%-*d|\n", 15, 45) == ft_printf("ft_printf :\t|%-*d|\n", 15, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	ft_printf("ft_printf :\t|%**46d|\n", 15, 10, 45);
		print_undef();

	tested++;
	print_testing("\"|%*d|\\n\", -9, 45");
	if (printf("printf    :\t|%*d|\n", -9, 45) == ft_printf("ft_printf :\t|%*d|\n", -9, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-*d|\\n\", -9, 45");
	if (printf("printf    :\t|%-*d|\n", -9, 45) == ft_printf("ft_printf :\t|%-*d|\n", -9, 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%046d|\\n\", INT_MIN");
	if (printf("printf    :\t|%046d|\n", INT_MIN) == ft_printf("ft_printf :\t|%046d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046d|\\n\", INT_MAX");
	if (printf("printf    :\t|%046d|\n", INT_MAX) == ft_printf("ft_printf :\t|%046d|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", INT_MIN");
	if (printf("printf    :\t|%d|\n", INT_MIN) == ft_printf("ft_printf :\t|%d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-55d|\\n\", INT_MIN");
	if (printf("printf    :\t|%-55d|\n", INT_MIN) == ft_printf("ft_printf :\t|%-55d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", INT_MAX");
	if (printf("printf    :\t|%d|\n", INT_MAX) == ft_printf("ft_printf :\t|%d|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54d|\\n\", INT_MIN");
	if (printf("printf    :\t|%-54d|\n", INT_MIN) == ft_printf("ft_printf :\t|%-54d|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%d|\\n\", INT_MAX");
	if (printf("printf    :\t|%-54d|\n", INT_MAX) == ft_printf("ft_printf :\t|%-54d|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

dprintf(1, ">------------------ I TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.i\\n|\", 0");
	if (printf("printf    :\t|%.i|\n", 0) == ft_printf("ft_printf :\t|%.i|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%45i\\n|\", -16");
	if (printf("printf    :\t|%45i|\n", -16) == ft_printf("ft_printf :\t|%45i|\n", -16))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"%.*i|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*i|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*i|\\n\", 0, 45");
	if (printf("printf    :\t|%.*i|\n", 0, 45) == ft_printf("ft_printf :\t|%.*i|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*i|\\n\", 45, 0");
	if (printf("printf    :\t|%.*i|\n", 45, 0) == ft_printf("ft_printf :\t|%.*i|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", 45");
	if (printf("printf    :\t|%i|\n", 45) == ft_printf("ft_printf :\t|%i|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46i|\\n\", 45");
	if (printf("printf    :\t|%.46i|\n", 45) == ft_printf("ft_printf :\t|%.46i|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%046i|\\n\", -2147483648");
	if (printf("printf    :\t|%046i|\n", -2147483647) == ft_printf("ft_printf :\t|%046i|\n", -2147483647))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046i|\\n\", INT_MIN");
	if (printf("printf    :\t|%046i|\n", INT_MIN) == ft_printf("ft_printf :\t|%046i|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046i|\\n\", INT_MAX");
	if (printf("printf    :\t|%046i|\n", INT_MAX) == ft_printf("ft_printf :\t|%046i|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MIN");
	if (printf("printf    :\t|%i|\n", INT_MIN) == ft_printf("ft_printf :\t|%i|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MAX");
	if (printf("printf    :\t|%i|\n", INT_MAX) == ft_printf("ft_printf :\t|%i|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MIN - 1");
	if (printf("printf    :\t|%i|\n", INT_MIN - 1) == ft_printf("ft_printf :\t|%i|\n", INT_MIN - 1))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MAX + 1");
	if (printf("printf    :\t|%i|\n", INT_MAX + 1) == ft_printf("ft_printf :\t|%i|\n", INT_MAX + 1))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54i|\\n\", INT_MIN");
	if (printf("printf    :\t|%-54i|\n", INT_MIN) == ft_printf("ft_printf :\t|%-54i|\n", INT_MIN))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%i|\\n\", INT_MAX");
	if (printf("printf    :\t|%-54i|\n", INT_MAX) == ft_printf("ft_printf :\t|%-54i|\n", INT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

dprintf(1, ">------------------ U TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.u\\n|\", 0");
	if (printf("printf    :\t|%.u|\n", 0) == ft_printf("ft_printf :\t|%.u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45u\\n|\", 0");
	if (printf("printf    :\t|%.45u|\n", 0) == ft_printf("ft_printf :\t|%.45u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"%.*u|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*u|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*u|\\n\", 0, 45");
	if (printf("printf    :\t|%.*u|\n", 0, 45) == ft_printf("ft_printf :\t|%.*u|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*u|\\n\", 45, 0");
	if (printf("printf    :\t|%.*u|\n", 45, 0) == ft_printf("ft_printf :\t|%.*u|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", 45");
	if (printf("printf    :\t|%u|\n", 45) == ft_printf("ft_printf :\t|%u|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46u|\\n\", 45");
	if (printf("printf    :\t|%.46u|\n", 45) == ft_printf("ft_printf :\t|%.46u|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%046u|\\n\", -2147483648");
	if (printf("printf    :\t|%046u|\n", -2147483647) == ft_printf("ft_printf :\t|%046u|\n", -2147483647))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046u|\\n\", 0");
	if (printf("printf    :\t|%046u|\n", 0) == ft_printf("ft_printf :\t|%046u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046u|\\n\", UINT_MAX");
	if (printf("printf    :\t|%046u|\n", UINT_MAX) == ft_printf("ft_printf :\t|%046u|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", 0");
	if (printf("printf    :\t|%u|\n", 0) == ft_printf("ft_printf :\t|%u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", UINT_MAX");
	if (printf("printf    :\t|%u|\n", UINT_MAX) == ft_printf("ft_printf :\t|%u|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54u|\\n\", 0");
	if (printf("printf    :\t|%-54u|\n", 0) == ft_printf("ft_printf :\t|%-54u|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%u|\\n\", UINT_MAX");
	if (printf("printf    :\t|%-54u|\n", UINT_MAX) == ft_printf("ft_printf :\t|%-54u|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ x TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.x\\n|\", 0");
	if (printf("printf    :\t|%.x|\n", 0) == ft_printf("ft_printf :\t|%.x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45x\\n|\", 0");
	if (printf("printf    :\t|%.45x|\n", 0) == ft_printf("ft_printf :\t|%.45x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);


	print_testing("\"%.*x|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*x|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*x|\\n\", 0, 45");
	if (printf("printf    :\t|%.*x|\n", 0, 45) == ft_printf("ft_printf :\t|%.*x|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*x|\\n\", 45, 0");
	if (printf("printf    :\t|%.*x|\n", 45, 0) == ft_printf("ft_printf :\t|%.*x|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%x|\\n\", 45");
	if (printf("printf    :\t|%x|\n", 45) == ft_printf("ft_printf :\t|%x|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46x|\\n\", 45");
	if (printf("printf    :\t|%.46x|\n", 45) == ft_printf("ft_printf :\t|%.46x|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046x|\\n\", 0");
	if (printf("printf    :\t|%046x|\n", 0) == ft_printf("ft_printf :\t|%046x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046x|\\n\", UINT_MAX");
	if (printf("printf    :\t|%046x|\n", UINT_MAX) == ft_printf("ft_printf :\t|%046x|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%x|\\n\", 0");
	if (printf("printf    :\t|%x|\n", 0) == ft_printf("ft_printf :\t|%x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%x|\\n\", UINT_MAX");
	if (printf("printf    :\t|%x|\n", UINT_MAX) == ft_printf("ft_printf :\t|%x|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54x|\\n\", 0");
	if (printf("printf    :\t|%-54x|\n", 0) == ft_printf("ft_printf :\t|%-54x|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54x|\\n\", UINT_MAX");
	if (printf("printf    :\t|%-54x|\n", UINT_MAX) == ft_printf("ft_printf :\t|%-54x|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);
	
	dprintf(1, ">------------------ X TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%.X\\n|\", 0");
	if (printf("printf    :\t|%.X|\n", 0) == ft_printf("ft_printf :\t|%.X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.45X\\n|\", 0");
	if (printf("printf    :\t|%.45X|\n", 0) == ft_printf("ft_printf :\t|%.45X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);


	print_testing("\"%.*X|\\n\", 45");
	if (ft_printf("ft_printf :\t|%.*X|\n", 45))
		print_undef();

	tested++;
	print_testing("\"|%.*X|\\n\", 0, 45");
	if (printf("printf    :\t|%.*X|\n", 0, 45) == ft_printf("ft_printf :\t|%.*X|\n", 0, 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*X|\\n\", 45, 0");
	if (printf("printf    :\t|%.*X|\n", 45, 0) == ft_printf("ft_printf :\t|%.*X|\n", 45, 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", 45");
	if (printf("printf    :\t|%X|\n", 45) == ft_printf("ft_printf :\t|%X|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", 20");
	if (printf("printf    :\t|%X|\n", 20) == ft_printf("ft_printf :\t|%X|\n", 20))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.46X|\\n\", 45");
	if (printf("printf    :\t|%.46X|\n", 45) == ft_printf("ft_printf :\t|%.46X|\n", 45))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046X|\\n\", 0");
	if (printf("printf    :\t|%046X|\n", 0) == ft_printf("ft_printf :\t|%046X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%046X|\\n\", UINT_MAX");
	if (printf("printf    :\t|%046X|\n", UINT_MAX) == ft_printf("ft_printf :\t|%046X|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", 0");
	if (printf("printf    :\t|%X|\n", 0) == ft_printf("ft_printf :\t|%X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", UINT_MAX");
	if (printf("printf    :\t|%X|\n", UINT_MAX) == ft_printf("ft_printf :\t|%X|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54X|\\n\", 0");
	if (printf("printf    :\t|%-54X|\n", 0) == ft_printf("ft_printf :\t|%-54X|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%X|\\n\", UINT_MAX");
	if (printf("printf    :\t|%-54X|\n", UINT_MAX) == ft_printf("ft_printf :\t|%-54X|\n", UINT_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ S TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%s|\\n\", bonjour");
	if (printf("printf    :\t|%s|\n", "bonjour") == ft_printf("ft_printf :\t|%s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%s.|\\n\", bonjour");
	if (printf("printf    :\t|%s.|\n", "bonjour") == ft_printf("ft_printf :\t|%s.|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%s|\\n\", \"\"");
	if (printf("printf    :\t|%s|\n", "") == ft_printf("ft_printf :\t|%s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.15s|\\n\", bonjour");
	if (printf("printf    :\t|%.15s|\n", "bonjour") == ft_printf("ft_printf :\t|%.15s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.015s|\\n\", bonjour");
	if (printf("printf    :\t|%.015s|\n", "bonjour") == ft_printf("ft_printf :\t|%.015s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.*15s|\\n\", -15, bonjour");
	if (printf("printf    :\t|%.*s|\n", -15, "bonjour") == ft_printf("ft_printf :\t|%.*s|\n", -15, "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%5s|\\n\", bonjour");
	if (printf("printf    :\t|%5s|\n", "bonjour") == ft_printf("ft_printf :\t|%5s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.5s|\\n\", bonjour");
	if (printf("printf    :\t|%.5s|\n", "bonjour") == ft_printf("ft_printf :\t|%.5s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*5s|\\n\",  5,bonjour");
	if (printf("printf    :\t|%*s|\n", 5, "bonjour") == ft_printf("ft_printf :\t|%*s|\n", 5,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*s|\\n\",  -50, bonjour");
	if (printf("printf    :\t|%*s|\n", -50, "bonjour") == ft_printf("ft_printf :\t|%*s|\n", -50,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%16s|\\n\", bonjour");
	if (printf("printf    :\t|%16s|\n", "bonjour") == ft_printf("ft_printf :\t|%16s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%.16s|\\n\", bonjour");
	if (printf("printf    :\t|%.16s|\n", "bonjour") == ft_printf("ft_printf :\t|%.16s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%*16s|\\n\",  16,bonjour");
	if (printf("printf    :\t|%*s|\n", 16, "bonjour") == ft_printf("ft_printf :\t|%*s|\n", 16,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);


	print_testing("\"|%.*5s|\\n\", 16, bonjour");
	ft_printf("ft_printf :\t|%.*5s|\n", 16, "bonjour");
	print_undef();
	
	tested++;
	print_testing("\"|%-50s|\\n\", \"bonjour");
	if (printf("printf    :\t|%-50s|\n", "bonjour") == ft_printf("ft_printf :\t|%-50s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"|%-050s|\\n\", \"bonjour");
	ft_printf("ft_printf :\t|%-050s|\n", "bonjour");
	print_undef();

	tested++;
	print_testing("\"|%*s|\\n\", 15, NULL");
	if (printf("printf    :\t|%*s|\n", 15, NULL) == ft_printf("ft_printf :\t|%*s|\n", 15,  NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-46s|\\n\", NULL");
	if (printf("printf    :\t|%-46s|\n", NULL) == ft_printf("ft_printf :\t|%-46s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.46s|\\n\", NULL");
	if (printf("printf    :\t|%.46s|\n", NULL) == ft_printf("ft_printf :\t|%.46s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.46s|\\n\", \"\"");
	if (printf("printf    :\t|%.46s|\n", "") == ft_printf("ft_printf :\t|%.46s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);
	
	tested++;
	print_testing("\"|%46s|\\n\", \"\"");
	if (printf("printf    :\t|%46s|\n", "") == ft_printf("ft_printf :\t|%46s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%46.0s|\\n\", \"\"");
	if (printf("printf    :\t|%46.0s|\n", "") == ft_printf("ft_printf :\t|%46.0s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"|%0.46s|\\n\", \"\"");
	ft_printf("ft_printf :\t|%046s|\n", "");
		print_undef();
	
	tested++;
	print_testing("\"|%s|\\n\", bonj\\200our");
	if (printf("printf    :\t|%s|\n", "bonj\200our") == ft_printf("ft_printf :\t|%s|\n", "bonj\200our"))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ C TEST ------------------<\n\n");

	tested++;
	print_testing("\"|%46c|\\n\", 'c'");
	if (printf("printf    :\t|%46c|\n", 'c') == ft_printf("ft_printf :\t|%46c|\n", 'c'))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-46c|\\n\", 0");
	if (printf("printf    :\t|%-46c|\n", 0) == ft_printf("ft_printf :\t|%-46c|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%c|\\n\", 'c'");
	if (printf("printf    :\t|%c|\n", 'c') == ft_printf("ft_printf :\t|%c|\n", 'c'))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%c%c|\\n\", 'c', 0");
	if (printf("printf    :\t|%c%c|\n", 'c', 0) == ft_printf("ft_printf :\t|%c%c|\n", 'c', 0))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%c*8%c|\\n\", 'c', 0");
	if (printf("printf    :\t|%c*8%c|\n", 'c', 0) == ft_printf("ft_printf :\t|%c*8%c|\n", 'c', 0))
		print_ok(&testok);
	else
		print_error(&testko);

	ft_printf("ft_printf :\t|%.0c|\n", 'c');
		print_undef();

	dprintf(1, ">------------------ P TEST ------------------<\n\n");

	char *s = ft_strdup("bonjour");

	print_testing("\"|%p|\\n\", 0");
	ft_printf("ft_printf :\t|%p|\n", 0);
	print_undef();

	tested++;
	print_testing("\"|%p|\\n\", NULL");
	if (printf("printf    :\t|%p|\n", NULL) == ft_printf("ft_printf :\t|%p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", &str + 100000");
	if (printf("printf    :\t|%p|\n", s + 100000) == ft_printf("ft_printf :\t|%p|\n", s + 100000))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", &tested");
	if (printf("printf    :\t|%p|\n", &tested) == ft_printf("ft_printf :\t|%p|\n", &tested))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", &str");
	if (printf("printf    :\t|%p|\n", s) == ft_printf("ft_printf :\t|%p|\n", s))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%54p|\\n\", NULL");
	if (printf("printf    :\t|%54p|\n", NULL) == ft_printf("ft_printf :\t|%54p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54p|\\n\", NULL");
	if (printf("printf    :\t|%-54p|\n", NULL) == ft_printf("ft_printf :\t|%-54p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	print_testing("\"|%054p|\\n\", NULL");
	ft_printf("ft_printf :\t|%0.54p|\n", NULL);
		print_undef();

	tested++;
	print_testing("\"|%p|\\n\", NULL");
	if (printf("printf    :\t|%p|\n", NULL) == ft_printf("ft_printf :\t|%p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", \"\"");
	if (printf("printf    :\t|%p|\n", "") == ft_printf("ft_printf :\t|%p|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	free(s);

	dprintf(1, ">-------------- Pourcent TEST ---------------<\n\n");

	tested++;
	print_testing("\"|%54%|\\n\"");
	if (printf("printf    :\t|%54%|\n") == ft_printf("ft_printf :\t|%54%|\n"))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">---------------- MORGAN TEST ---------------<\n\n");

	tested++;
	print_testing("\"|%.3s|\\n\", NULL");
	if (printf("printf    :\t|%.3s|\n", NULL) == ft_printf("ft_printf :\t|%.3s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%3s|\\n\", NULL");
	if (printf("printf    :\t|%3s|\n", NULL) == ft_printf("ft_printf :\t|%3s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);


	tested++;
	print_testing("\"|%c|\\n\", 'c'");
	if (printf("printf    :\t|%c|\n", 0) == ft_printf("ft_printf :\t|%c|\n", 0))
		print_ok(&testok);
	else
		print_error(&testko);

	char *tmp;

	tmp = NULL;
	tested++;
	print_testing("\"|%p|\\n\", 0");
	if (printf("printf    :\t|%p|\n", tmp) == ft_printf("ft_printf :\t|%p|\n", tmp))
		print_ok(&testok);
	else
		print_error(&testko);

	tmp = NULL;
	tested++;
	print_testing("\"|%.p|\\n\", \"bonjour\"");
	if (printf("printf    :\t|%.p|\n", "bonjour") == ft_printf("ft_printf :\t|%.p|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%15p|\\n\", \"bonjour\"");
	if (printf("printf    :\t|%15p|\n", "bonjour") == ft_printf("ft_printf :\t|%15p|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%15p|\\n\", NULL");
	if (printf("printf    :\t|%15p|\n", NULL) == ft_printf("ft_printf :\t|%15p|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%15s.-*0|\\n\", \"bon-jour\"");
	if (printf("printf    :\t|%15s.-*0|\n", "bon-jour") == ft_printf("ft_printf :\t|%15s.-*0|\n", "bon-jour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%150p|\\n\", \"bonjour\"");
	if (printf("printf    :\t|%150p|\n", "bonjour") == ft_printf("ft_printf :\t|%150p|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", \"bonjour\"");
	if (printf("printf    :\t|%p|\n", "bonjour") == ft_printf("ft_printf :\t|%p|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", (void *)-1");
	if (printf("printf    :\t|%p|\n", (void *)-1) == ft_printf("ft_printf :\t|%p|\n", (void *)-1))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", (void*)ULONG_MAX)");
	if (printf("printf    :\t|%p|\n", (void*)ULONG_MAX) == ft_printf("ft_printf :\t|%p|\n", (void*)ULONG_MAX))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%p|\\n\", 0");
	if (printf("printf    :\t|%p|\n", "monais monaie mauney") == ft_printf("ft_printf :\t|%p|\n", "monais monaie mauney"))
		print_ok(&testok);
	else
		print_error(&testko);


	tested++;
	print_testing("\"|%.*s|\\n\",  -50, bonjour");
	if (printf("printf    :\t|%.*s|\n", -50, "bonjour") == ft_printf("ft_printf :\t|%.*s|\n", -50,"bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	dprintf(1, ">------------------ MIX TEST ----------------<\n\n");

	tested++;
	print_testing("\"|%s %d %p %x %X %i %u %c|\n\", \"bonjour\", 50, \"bonjour\", 168, -168, 54, 87, \'c\'");
	if (printf("printf    :\t|%s %d %p %x %X %i %u %c|\n", "bonjour", 50, "bonjour", 168, -168, 54, 87, 'c') == ft_printf("ft_printf :\t|%s %d %p %x %X %i %u %c|\n", "bonjour", 50, "bonjour", 168, -168, 54, 87, 'c'))
		print_ok(&testok);
	else
		print_error(&testko);}

	if(ac != 1)
	{
	if(ft_c_in_str('s', av[1])|| ft_c_in_str('a', av[1]))
	{
		dprintf(1, ">----------------- NEW S TEST ---------------<\n\n");

	tested++;
	print_testing("\"|%s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%s|\n", "bonjour") == ft_printf("ft_printf :\t|%s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%s|\\n\",  NULL");
	if (printf("printf    :\t|%s|\n", NULL) == ft_printf("ft_printf :\t|%s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%s|\\n\",  \"\"");
	if (printf("printf    :\t|%s|\n", "") == ft_printf("ft_printf :\t|%s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.54s|\\n\",  \"0\"");
	if (printf("printf    :\t|%.54s|\n", "0") == ft_printf("ft_printf :\t|%.54s|\n", "0"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%.s|\n", "bonjour") == ft_printf("ft_printf :\t|%.s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.s|\\n\",  NULL");
	if (printf("printf    :\t|%.s|\n", NULL) == ft_printf("ft_printf :\t|%.s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.s|\\n\",  \"\"");
	if (printf("printf    :\t|%.s|\n", "") == ft_printf("ft_printf :\t|%.s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%-54s|\n", "bonjour") == ft_printf("ft_printf :\t|%-54s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54s|\\n\",  NULL");
	if (printf("printf    :\t|%-54s|\n", NULL) == ft_printf("ft_printf :\t|%-54s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-54s|\\n\",  \"\"");
	if (printf("printf    :\t|%-54s|\n", "") == ft_printf("ft_printf :\t|%-54s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%54s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%54s|\n", "bonjour") == ft_printf("ft_printf :\t|%54s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%54s|\\n\",  NULL");
	if (printf("printf    :\t|%54s|\n", NULL) == ft_printf("ft_printf :\t|%54s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%54s|\\n\",  \"\"");
	if (printf("printf    :\t|%54s|\n", "") == ft_printf("ft_printf :\t|%54s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.54s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%.54s|\n", "bonjour") == ft_printf("ft_printf :\t|%.54s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.54s|\\n\",  NULL");
	if (printf("printf    :\t|%.54s|\n", NULL) == ft_printf("ft_printf :\t|%.54s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.54s|\\n\",  \"\"");
	if (printf("printf    :\t|%.54s|\n", "") == ft_printf("ft_printf :\t|%.54s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.2s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%.2s|\n", "bonjour") == ft_printf("ft_printf :\t|%.2s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.2s|\\n\",  NULL");
	if (printf("printf    :\t|%.2s|\n", NULL) == ft_printf("ft_printf :\t|%.2s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%.2s|\\n\",  \"\"");
	if (printf("printf    :\t|%.2s|\n", "") == ft_printf("ft_printf :\t|%.2s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-2s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%-2s|\n", "bonjour") == ft_printf("ft_printf :\t|%-2s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-2s|\\n\",  NULL");
	if (printf("printf    :\t|%-2s|\n", NULL) == ft_printf("ft_printf :\t|%-2s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-2s|\\n\",  \"\"");
	if (printf("printf    :\t|%-2s|\n", "") == ft_printf("ft_printf :\t|%-2s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-20s|\\n\",  \"bonjour\"");
	if (printf("printf    :\t|%-20s|\n", "bonjour") == ft_printf("ft_printf :\t|%-20s|\n", "bonjour"))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-20s|\\n\",  NULL");
	if (printf("printf    :\t|%-20s|\n", NULL) == ft_printf("ft_printf :\t|%-20s|\n", NULL))
		print_ok(&testok);
	else
		print_error(&testko);

	tested++;
	print_testing("\"|%-20s|\\n\",  \"\"");
	if (printf("printf    :\t|%-20s|\n", "") == ft_printf("ft_printf :\t|%-20s|\n", ""))
		print_ok(&testok);
	else
		print_error(&testko);

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%s|\\n\",  random");
		if (printf("printf    :\t|%s|\n", str[i]) == ft_printf("ft_printf :\t|%s|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.s|\\n\",  random");
		if (printf("printf    :\t|%.s|\n", str[i]) == ft_printf("ft_printf :\t|%.s|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"%s\",  random");
		if (printf("%s", str[i]) == ft_printf("%s", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.54s|\\n\",  random");
		if (printf("printf    :\t|%.54s|\n", str[i]) == ft_printf("ft_printf :\t|%.54s|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.0s|\\n\",  random");
		if (printf("printf    :\t|%.0s|\n", str[i]) == ft_printf("ft_printf :\t|%.0s|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%20s|\\n\",  random");
		if (printf("printf    :\t|%20s|\n", str[i]) == ft_printf("ft_printf :\t|%20s|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|str :\\t%s\\naddr :\\t%p\\n|\",  random");
		if (printf("printf    :\tstr :\t|%s|\n\t\taddr :\t|%p|\n", str[i], str[i]) == ft_printf("ft_printf :\tstr :\t|%s|\n\t\taddr :\t|%p|\n", str[i], str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.2s|\\n\",  random");
		if (printf("printf    :\t|%.2s|\n", str[i]) == ft_printf("ft_printf :\t|%.2s|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%54.0s|\\n\", random");
		if (printf("printf    :\t|%54.0s|\n", str[i]) == ft_printf("ft_printf :\t|%54.0s|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}}

	if(ft_c_in_str('p', av[1])|| ft_c_in_str('a', av[1]))
	{
	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%p|\\n\",  random");
		if (printf("printf    :\t|%p|\n", str[i]) == ft_printf("ft_printf :\t|%p|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}
	
		i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.p|\\n\",  random");
		if (printf("printf    :\t|%.p|\n", str[i]) == ft_printf("ft_printf :\t|%.p|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%54p|\\n\",  random");
		if (printf("printf    :\t|%54p|\n", str[i]) == ft_printf("ft_printf :\t|%54p|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%54p|\\n\",  random");
		if (printf("printf    :\t|%54p|\n", str[i]) == ft_printf("ft_printf :\t|%54p|\n", str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}}

	
	if(ft_c_in_str('d', av[1])|| ft_c_in_str('a', av[1]))
	{i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%d|\\n\",  random");
		if (printf("printf    :\t|%d|\n", nb[i]) == ft_printf("ft_printf :\t|%d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.d|\\n\",  random");
		if (printf("printf    :\t|%.d|\n", nb[i]) == ft_printf("ft_printf :\t|%.d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54d|\\n\",  random");
		if (printf("printf    :\t|%-54d|\n", nb[i]) == ft_printf("ft_printf :\t|%-54d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54d|\\n\",  random");
		if (printf("printf    :\t|%0.54d|\n", nb[i]) == ft_printf("ft_printf :\t|%0.54d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-2d|\\n\",  random");
		if (printf("printf    :\t|%-2d|\n", nb[i]) == ft_printf("ft_printf :\t|%-2d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54d|\\n\",  random");
		if (printf("printf    :\t|%-54d|\n", nb[i]) == ft_printf("ft_printf :\t|%-54d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%--45d|\\n\",  random");
		if (printf("printf    :\t|%--45d|\n", nb[i]) == ft_printf("ft_printf :\t|%--45d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-*d|\\n\", 45, random");
		if (printf("printf    :\t|%-*d|\n", 45, nb[i]) == ft_printf("ft_printf :\t|%-*d|\n", 45,nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*d|\\n\", -45, random");
		if (printf("printf    :\t|%*d|\n", -45, nb[i]) == ft_printf("ft_printf :\t|%*d|\n", -45,nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*d|\\n\", -45, random");
		if (printf("printf    :\t|%*d|\n", -45, nb[i]) == ft_printf("ft_printf :\t|%*d|\n", -45,nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"line :\\t|%*d|\\nstr :\\t%s\\n\", -45, random, random");
		if (printf("printf    :\tline :\t|%*d|\n\t\tstr :\t|%s|\n", -45, nb[i], str[i]) == ft_printf("ft_printf :\tline :\t|%*d|\n\t\tstr :\t|%s|\n", -45, nb[i], str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.*d|\\n\", -45, random");
		if (printf("printf    :\t|%0.*d|\n", -45, nb[i]) == ft_printf("ft_printf :\t|%0.*d|\n", -45,nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0d|\\n\", 10, random");
		if (printf("printf    :\t|%0.*d|\n", 10, nb[i]) == ft_printf("ft_printf :\t|%0.*d|\n", 10,nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.54d|\\n\", random");
		if (printf("printf    :\t|%.54d|\n", nb[i]) == ft_printf("ft_printf :\t|%.54d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%010.0d|\\n\", random");
		if (printf("|%010.0d|\n", nb[i]) == ft_printf("|%010.0d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%54.0d|\\n\", random");
		if (printf("printf    :\t|%54.0d|\n", nb[i]) == ft_printf("ft_printf :\t|%54.0d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54d|\\n\",random");
		if (printf("printf    :\t|%0.54d|\n", nb[i]) == ft_printf("ft_printf :\t|%0.54d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}
	
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.0d|\\n\", random");
		if (printf("printf    :\t|%0.0d|\n", nb[i]) == ft_printf("ft_printf :\t|%0.0d|\n", nb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}}

	if(ft_c_in_str('i', av[1])|| ft_c_in_str('a', av[1]))
	{
		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("\"%3i\", random");
			if ((printf("|%-3i|\n", nb[i])) == (ft_printf("|%-3i|\n", nb[i])))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("\"%01i\", random");
			if ((printf("|%01i|\n", nb[i])) == (ft_printf("|%01i\n|", nb[i])))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("\"%01i\", random");
			if ((printf("|%01i|\n", nb[i])) == (ft_printf("|%01i\n|", nb[i])))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("\"%10.1i\", random");
			if ((printf("|%2.1i|\n", nb[i])) == (ft_printf("|%2.1i\n|", nb[i])))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("\"%1.10i\", random");
			if ((printf("|%1.10i|\n", nb[i])) == (ft_printf("|%1.10i|\n", nb[i])))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("\"%1.10i\", random");
			if ((printf("|%1.10i|\n", nb[i])) == (ft_printf("|%1.10i\n|", nb[i])))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}
	}

	if(ft_c_in_str('u', av[1])|| ft_c_in_str('a', av[1]))
{
	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%u|\\n\",  random");
		if (printf("printf    :\t|%u|\n", unb[i]) == ft_printf("ft_printf :\t|%u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.u|\\n\",  random");
		if (printf("printf    :\t|%.u|\n", unb[i]) == ft_printf("ft_printf :\t|%.u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54u|\\n\",  random");
		if (printf("printf    :\t|%-54u|\n", unb[i]) == ft_printf("ft_printf :\t|%-54u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54u|\\n\",  random");
		if (printf("printf    :\t|%0.54u|\n", unb[i]) == ft_printf("ft_printf :\t|%0.54u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-2u|\\n\",  random");
		if (printf("printf    :\t|%-2u|\n", unb[i]) == ft_printf("ft_printf :\t|%-2u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54u|\\n\",  random");
		if (printf("printf    :\t|%-54u|\n", unb[i]) == ft_printf("ft_printf :\t|%-54u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%--45u|\\n\",  random");
		if (printf("printf    :\t|%--45u|\n", unb[i]) == ft_printf("ft_printf :\t|%--45u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-*u|\\n\", 45, random");
		if (printf("printf    :\t|%-*u|\n", 45, unb[i]) == ft_printf("ft_printf :\t|%-*u|\n", 45, unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*u|\\n\", -45, random");
		if (printf("printf    :\t|%*u|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%*u|\n", -45,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*u|\\n\", -45, random");
		if (printf("printf    :\t|%*u|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%*u|\n", -45, unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"line :\\t|%*u|\\nstr :\\t%s\\n\", -45, random, random");
		if (printf("printf    :\tline :\t|%*u|\n\t\tstr :\t|%s|\n", -45, unb[i], str[i]) == ft_printf("ft_printf :\tline :\t|%*u|\n\t\tstr :\t|%s|\n", -45, unb[i], str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0u|\\n\", -45, random");
		if (printf("printf    :\t|%0.*u|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%0.*u|\n", -45,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0u|\\n\", 10, random");
		if (printf("printf    :\t|%0.*u|\n", 10, unb[i]) == ft_printf("ft_printf :\t|%0.*u|\n", 10,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%54.0u|\\n\", random");
		if (printf("printf    :\t|%54.0u|\n", unb[i]) == ft_printf("ft_printf :\t|%54.0u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54u|\\n\",random");
		if (printf("printf    :\t|%0.54u|\n", unb[i]) == ft_printf("ft_printf :\t|%0.54u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.0u|\\n\", random");
		if (printf("printf    :\t|%0.0u|\n", unb[i]) == ft_printf("ft_printf :\t|%0.0u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.0u|\\n\", random");
		if (printf("printf    :\t|%0.0u|\n", unb[i]) == ft_printf("ft_printf :\t|%0.0u|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}}
if(ft_c_in_str('c', av[1])|| ft_c_in_str('a', av[1]))
	{dprintf(1, ">---------------- ASCII TEST ---------------<\n\n");

	print_testing("all ascii char");
	unsigned int u;

	u = 0;
	while (u < 255)
	{
		tested++;
		if (printf("printf    :\t|%c|\n", u) == ft_printf("ft_printf :\t|%c|\n", u))
			testok++;
		else
		{
			testko++;
			print_error(&testko);
		}
		u++;
	}

	print_testing("all ascii char");

	u = 0;
	while (u < 255)
	{
		tested++;
		if (printf("printf    :\t|%54c|\n", u) == ft_printf("ft_printf :\t|%54c|\n", u))
			testok++;
		else
		{
			testko++;
			print_error(&testko);
		}
		u++;
	}

	print_testing("all ascii char");

	u = 0;
	while (u < 255)
	{
		tested++;
		if (printf("printf    :\t|%-5c|\n", u) == ft_printf("ft_printf :\t|%-5c|\n", u))
			testok++;
		else
		{
			tested++;
			print_error(&testko);
		}
		u++;
	}}

	if(ft_c_in_str('x', av[1])|| ft_c_in_str('a', av[1]))
	{i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%x|\\n\",  random");
		if (printf("printf    :\t|%x|\n", unb[i]) == ft_printf("ft_printf :\t|%x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.x|\\n\",  random");
		if (printf("printf    :\t|%.x|\n", unb[i]) == ft_printf("ft_printf :\t|%.x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54x|\\n\",  random");
		if (printf("printf    :\t|%-54x|\n", unb[i]) == ft_printf("ft_printf :\t|%-54x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54x|\\n\",  random");
		if (printf("printf    :\t|%0.54x|\n", unb[i]) == ft_printf("ft_printf :\t|%0.54x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-2x|\\n\",  random");
		if (printf("printf    :\t|%-2x|\n", unb[i]) == ft_printf("ft_printf :\t|%-2x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54x|\\n\",  random");
		if (printf("printf    :\t|%-54x|\n", unb[i]) == ft_printf("ft_printf :\t|%-54x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%--45x|\\n\",  random");
		if (printf("printf    :\t|%--45x|\n", unb[i]) == ft_printf("ft_printf :\t|%--45x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-*x|\\n\", 45, random");
		if (printf("printf    :\t|%-*x|\n", 45, unb[i]) == ft_printf("ft_printf :\t|%-*x|\n", 45, unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*x|\\n\", -45, random");
		if (printf("printf    :\t|%*x|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%*x|\n", -45,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*x|\\n\", -45, random");
		if (printf("printf    :\t|%*x|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%*x|\n", -45, unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"line :\\t|%*x|\\nstr :\\t%s\\n\", -45, random, random");
		if (printf("printf    :\tline :\t|%*x|\n\t\tstr :\t|%s|\n", -45, unb[i], str[i]) == ft_printf("ft_printf :\tline :\t|%*x|\n\t\tstr :\t|%s|\n", -45, unb[i], str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0x|\\n\", -45, random");
		if (printf("printf    :\t|%0.*x|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%0.*x|\n", -45,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0x|\\n\", 10, random");
		if (printf("printf    :\t|%0.*x|\n", 10, unb[i]) == ft_printf("ft_printf :\t|%0.*x|\n", 10,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%54.0x|\\n\", random");
		if (printf("printf    :\t|%54.0x|\n", unb[i]) == ft_printf("ft_printf :\t|%54.0x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54x|\\n\",random");
		if (printf("printf    :\t|%0.54x|\n", unb[i]) == ft_printf("ft_printf :\t|%0.54x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.0x|\\n\", random");
		if (printf("printf    :\t|%0.0x|\n", unb[i]) == ft_printf("ft_printf :\t|%0.0x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.0x|\\n\", random");
		if (printf("printf    :\t|%0.0x|\n", unb[i]) == ft_printf("ft_printf :\t|%0.0x|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}}

	if(ft_c_in_str('X', av[1])|| ft_c_in_str('a', av[1]))
	{i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%X|\\n\",  random");
		if (printf("printf    :\t|%X|\n", unb[i]) == ft_printf("ft_printf :\t|%X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.X|\\n\",  random");
		if (printf("printf    :\t|%.X|\n", unb[i]) == ft_printf("ft_printf :\t|%.X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54X|\\n\",  random");
		if (printf("printf    :\t|%-54X|\n", unb[i]) == ft_printf("ft_printf :\t|%-54X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54X|\\n\",  random");
		if (printf("printf    :\t|%0.54X|\n", unb[i]) == ft_printf("ft_printf :\t|%0.54X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-2X|\\n\",  random");
		if (printf("printf    :\t|%-2X|\n", unb[i]) == ft_printf("ft_printf :\t|%-2X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54X|\\n\",  random");
		if (printf("printf    :\t|%-54X|\n", unb[i]) == ft_printf("ft_printf :\t|%-54X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%--45X|\\n\",  random");
		if (printf("printf    :\t|%--45X|\n", unb[i]) == ft_printf("ft_printf :\t|%--45X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-*X|\\n\", 45, random");
		if (printf("printf    :\t|%-*X|\n", 45, unb[i]) == ft_printf("ft_printf :\t|%-*X|\n", 45, unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*X|\\n\", -45, random");
		if (printf("printf    :\t|%*X|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%*X|\n", -45,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*X|\\n\", -45, random");
		if (printf("printf    :\t|%*X|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%*X|\n", -45, unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"line :\\t|%*X|\\nstr :\\t%s\\n\", -45, random, random");
		if (printf("printf    :\tline :\t|%*X|\n\t\tstr :\t|%s|\n", -45, unb[i], str[i]) == ft_printf("ft_printf :\tline :\t|%*X|\n\t\tstr :\t|%s|\n", -45, unb[i], str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0X|\\n\", -45, random");
		if (printf("printf    :\t|%0.*X|\n", -45, unb[i]) == ft_printf("ft_printf :\t|%0.*X|\n", -45,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0X|\\n\", 10, random");
		if (printf("printf    :\t|%0.*X|\n", 10, unb[i]) == ft_printf("ft_printf :\t|%0.*X|\n", 10,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%54.0X|\\n\", random");
		if (printf("printf    :\t|%54.0X|\n", unb[i]) == ft_printf("ft_printf :\t|%54.0X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54X|\\n\",random");
		if (printf("printf    :\t|%0.54X|\n", unb[i]) == ft_printf("ft_printf :\t|%0.54X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.0X|\\n\", random");
		if (printf("printf    :\t|%0.0X|\n", unb[i]) == ft_printf("ft_printf :\t|%0.0X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.0X|\\n\", random");
		if (printf("printf    :\t|%0.0X|\n", unb[i]) == ft_printf("ft_printf :\t|%0.0X|\n", unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}}

	if(ft_c_in_str('o', av[1])|| ft_c_in_str('a', av[1]))
	{i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%%|\\n\",  random");
		if (printf("printf    :\t|%%|\n") == ft_printf("ft_printf :\t|%%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%.%|\\n\",  random");
		if (printf("printf    :\t|%.%|\n") == ft_printf("ft_printf :\t|%.%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54%|\\n\",  random");
		if (printf("printf    :\t|%-54%|\n") == ft_printf("ft_printf :\t|%-54%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%0.54%|\\n\",  random");
		if (printf("printf    :\t|%0.54%|\n") == ft_printf("ft_printf :\t|%0.54%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-2%|\\n\",  random");
		if (printf("printf    :\t|%-2%|\n") == ft_printf("ft_printf :\t|%-2%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-54%|\\n\",  random");
		if (printf("printf    :\t|%-54%|\n") == ft_printf("ft_printf :\t|%-54%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%--45%|\\n\",  random");
		if (printf("printf    :\t|%--45%|\n") == ft_printf("ft_printf :\t|%--45%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%-*%|\\n\", 45, random");
		if (printf("printf    :\t|%-*%|\n", 45) == ft_printf("ft_printf :\t|%-*%|\n", 45))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*%|\\n\", -45, random");
		if (printf("printf    :\t|%*%|\n", -45) == ft_printf("ft_printf :\t|%*%|\n", -45,unb[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*%|\\n\", -45, random");
		if (printf("printf    :\t|%*%|\n", -45) == ft_printf("ft_printf :\t|%*%|\n", -45))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"line :\\t|%*%|\\nstr :\\t%s\\n\", -45, random, random");
		if (printf("printf    :\tline :\t|%*%|\n\t\tstr :\t|%s|\n", -45, str[i]) == ft_printf("ft_printf :\tline :\t|%*%|\n\t\tstr :\t|%s|\n", -45, str[i]))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0%|\\n\", -45, random");
		if (printf("printf    :\t|%0.*%|\n", -45) == ft_printf("ft_printf :\t|%0.*%|\n", -45))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

	i = 0;
	while (i < 20)
	{
		tested++;
		print_testing("\"|%*.0%|\\n\", 10, random");
		if (printf("printf    :\t|%0.*%|\n", 10) == ft_printf("ft_printf :\t|%0.*%|\n", 10))
			print_ok(&testok);
		else
			print_error(&testko);
		i++;
	}

		tested++;
		print_testing("\"|%54.0%|\\n\", random");
		if (printf("printf    :\t|%54.0%|\n") == ft_printf("ft_printf :\t|%54.0%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);

		tested++;
		print_testing("\"|%0.54%|\\n\"");
		if (printf("printf    :\t|%0.54%|\n") == ft_printf("ft_printf :\t|%0.54%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);

		tested++;
		print_testing("\"|%-054%|\\n\"");
		if (printf("printf    :\t|%-054%|\n") == ft_printf("ft_printf :\t|%-054%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);

		tested++;
		print_testing("\"|%0.0%|\\n\"");
		if (printf("printf    :\t|%0.0%|\n") == ft_printf("ft_printf :\t|%0.0%|\n"))
			print_ok(&testok);
		else
			print_error(&testko);
	}

	if(ft_c_in_str('m', av[1])|| ft_c_in_str('a', av[1]))
	{
		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("str :\\t%s\\nint :\\t%d\nline :\\t%u\\naddr :\\t%p\", str, int, line, addr");
			if (printf("printf    :\tstr :\t|%s|\n\t\tint :\t|%d|\n\t\tline :\t|%u|\n\t\taddr :\t|%p|\n", str[i], nb[i], unb[i], str[i]) == ft_printf("ft_printf :\tstr :\t|%s|\n\t\tint :\t|%d|\n\t\tline :\t|%u|\n\t\taddr :\t|%p|\n", str[i], nb[i], unb[i], str[i]))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}
		
		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("str :\\t%50s\\nint :\\t%*d\nline :\\t%u\\naddr :\\t%p\", str, 15, int, line, addr");
			if (printf("printf    :\tstr :\t|%50s|\n\t\tint :\t|%*d|\n\t\tline :\t|%u|\n\t\taddr :\t|%p|\n", str[i], 15, nb[i], unb[i], str[i]) == ft_printf("ft_printf :\tstr :\t|%50s|\n\t\tint :\t|%*d|\n\t\tline :\t|%u|\n\t\taddr :\t|%p|\n", str[i], 15, nb[i], unb[i], str[i]))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("str :\\t%50s\\nint :\\t%*d\nline :\\t%u\\naddr :\\t%p\", str, 15, int, line, addr");
			if (printf("printf    :\tstr :\t|%50s|\n\t\tint :\t|%*d|\n\t\tline :\t|%u|\n\t\taddr :\t|%p|\n", str[i], 15, nb[i], unb[i], str[i]) == ft_printf("ft_printf :\tstr :\t|%50s|\n\t\tint :\t|%*d|\n\t\tline :\t|%u|\n\t\taddr :\t|%p|\n", str[i], 15, nb[i], unb[i], str[i]))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing(":\\tint\\t: |%d|\\n\\t\\tuint\\t:|%u|\\n\\t\\txint\\t: |%x|\\n\\t\\tXint\\t: |%X|\\n\", int, uint, uint, uint");
			if (printf("printf    :\tint\t: |%d|\n\t\tuint\t:|%u|\n\t\txint\t: |%x|\n\t\tXint\t: |%X|\n", nb[i], unb[i], unb[i], unb[i]) == ft_printf("ft_printf :\tint\t: |%d|\n\t\tuint\t:|%u|\n\t\txint\t: |%x|\n\t\tXint\t: |%X|\n", nb[i], unb[i], unb[i], unb[i]))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing(":\\tint\\t: |%.54d|\\n\\t\\tuint\\t:|%u|\\n\\t\\txint\\t: |%x|\\n\\t\\tXint\\t: |%X|\\n\", int, uint, uint, uint");
			if (printf("printf    :\tint\t: |%.54d|\n\t\tuint\t:|%u|\n\t\txint\t: |%x|\n\t\tXint\t: |%X|\n", nb[i], unb[i], unb[i], unb[i]) == ft_printf("ft_printf :\tint\t: |%.54d|\n\t\tuint\t:|%u|\n\t\txint\t: |%x|\n\t\tXint\t: |%X|\n", nb[i], unb[i], unb[i], unb[i]))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("str :\\t%50s\\nint :\\t%*d\nline :\\t%u\\naddr :\\t%*p%c\", str, 15, int, line, addr, @");
			if (printf("printf    :\tstr :\t|%50s|\n\t\tint :\t|%*d|\n\t\tline :\t|%u|\n\t\taddr :\t|%*p||%c|\n", str[i], 15, nb[i], unb[i], -9, str[i], '@') == ft_printf("ft_printf :\tstr :\t|%50s|\n\t\tint :\t|%*d|\n\t\tline :\t|%u|\n\t\taddr :\t|%*p||%c|\n", str[i], 15, nb[i], unb[i], -9,str[i], '@'))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}

		i = 0;
		while (i < 20)
		{
			tested++;
			print_testing("str :\\t%.50s\\nint :\\t%.54d\nline :\\t%u\\naddr :\\t%*p\", str, 15, int, unb, addr");
			if (printf("printf    :\tstr :\t|%.50s|\n\t\tint :\t|%.54d|\n\t\tline :\t|%u|\n\t\taddr :\t|%*p|\n", str[i], 15, nb[i], -98, str[i]) == ft_printf("ft_printf :\tstr :\t|%.50s|\n\t\tint :\t|%.54d|\n\t\tline :\t|%u|\n\t\taddr :\t|%*p|\n", str[i], 15, nb[i], -98, str[i]))
				print_ok(&testok);
			else
				print_error(&testko);
			i++;
		}
	}
	}
	int a;

	a = 3;
	while(a < 20)
	{
		free(str[a]);
		a++;
	}
	print_result(tested, testok, testko);
}