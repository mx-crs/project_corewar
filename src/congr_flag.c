/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congr_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:35:09 by myarovoy          #+#    #+#             */
/*   Updated: 2018/12/29 16:35:10 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_cong(void)
{
	ft_printf(".      .           \\|/ .        ");
	ft_printf("           .                    .        .\n");
	ft_printf("  .      .    .   - * -   .        .  ");
	ft_printf("          .          .                .\n");
	ft_printf(" .  .      .    .  /|\\        .       ");
	ft_printf("  .           .            .     .\n");
	ft_printf("   .     .    .     .        .   .   ");
	ft_printf("      .             .         .  .     .\n");
	ft_printf("   .  .     . ^    . Vv   Vv   Vv  ");
	ft_printf(" Vv       .         .     .       .  .    .\n");
	ft_printf(".   .      x  O      o,   o,   o, ");
	ft_printf("  o,       .      .    .      .         .  \n");
	ft_printf(".        /(_){-}+--===--===--===--");
	ft_printf("===    .        .          .      .  ~~~~\n");
	ft_printf("  .      \\=====/   > >  > >  > >  ");
	ft_printf("> >      .           .  .    .     .  ~~~\n");
	ft_printf(".     .     .       .         .   ");
	ft_printf("              .           .     .     . ~~ .\n");
	ft_printf("    .    .       .        .          ");
	ft_printf(".   .           .         .     .     ~~~\n");
	ft_print_cong1();
}

void	ft_print_cong1(void)
{
	ft_printf(".          .   .       .        .      ");
	ft_printf("  .        .          .      .   /\\  ~~\n");
	ft_printf(" .     .           .    ^    .    . ");
	ft_printf("  ^       .         .      .     . /  \\ ||\n");
	ft_printf("                       /|\\          ");
	ft_printf(" /|\\                              / [] \\||\n");
	ft_printf("#### ^ ############ ## /|\\ ##  #####");
	ft_printf(" /|\\ #####################       /      ||\n");
	ft_printf("##  /|\\ ########## ^  #####   ^  ");
	ft_printf("  ################################ / []  []  \\\n");
	ft_printf("#   /|\\ ######### /|\\####### /|\\ ##");
	ft_printf("##   #### ^ ####  #############  |         |\n");
	ft_printf("## #### ## ^   #  /|\\ ###### /|\\ ###");
	ft_printf("# ^ ### /|\\ #  ^  ##########    |  _   _  |\n");
	ft_printf("########  /|\\ ###################### ");
	ft_printf("/|\\ ## /|\\ # /|\\ ##        +===| [_] [_] |\n");
	ft_printf("#######   /|\\  ####################  /|\\");
	ft_printf(" #######  /|\\           +---|         |\n");
	ft_printf("####################################");
	ft_printf("###########################################\n");
}

void	ft_is_flag(t_asm *file, char **av, int ac)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 2 && !ft_strcmp(av[i], "-h"))
		{
			file->flag = 1;
			break ;
		}
		i++;
	}
}
