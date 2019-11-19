/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solotest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:54:18 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 12:12:47 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	printf("\n%d\n", ft_printf("%.sps%5%w|%-7.d|**%*X|%*x|%*.5i~\n", "test", -87268, -7, -87452, 10, 1112111, -13, UINT_MAX + 789));
	printf("\n");
	printf("\n%d\n", printf("%.sps%5%w|%-7.d|**%*X|%*x|%*.5i~\n", "test", -87268, -7, -87452, 10, 1112111, -13, UINT_MAX + 789));
	return(1);
}