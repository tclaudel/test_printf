/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solotest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:54:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 08:40:36 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	dprintf(1, "\ntesting\t: %s\n", "\"%3i\", -1");
	if ((printf("|%*.10x|\n", -45, 200)) == (ft_printf("|%*.10x|\n", -45, 200)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%01i|\", -1");
	if ((printf("|%01i|\n", -1)) == (ft_printf("|%01i\n|", -1)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");

	dprintf(1, "\ntesting\t: %s\n", "\"|%2.2i|\", -1");
	if ((printf("|%2.2i|\n", -1)) == (ft_printf("|%2.2i|\n", -1)))
		puts("SUCCEED\n");
	else
		puts("ERROR\n");


}