/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:39:20 by ael-korc          #+#    #+#             */
/*   Updated: 2022/03/13 14:13:42 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(char *error_message, t_data *data)
{
	ft_printf("\033[1;31m");
	(void)data;
	if (error_message)
		exit(printf("Error\n%s\n", error_message));
	if (!error_message)
	{
		ft_printf("\033[0;36m");
		ft_printf("\n░▒▓█►─═  ＧＡＭＥ ＣＬＯＳＥＤ ＳＵＣＣＥＳＦＵＬＬＹ ═─◄█▓▒░\n");
		exit(0);
	}
}
