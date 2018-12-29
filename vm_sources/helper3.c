/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordiyc <agordiyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 18:12:46 by agordiyc          #+#    #+#             */
/*   Updated: 2018/12/25 18:14:01 by agordiyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewarvm.h"

int		count_players(t_vm *vm)
{
	int			i;
	int			c;

	i = 0;
	c = 0;
	while (i < MAX_PLAYERS)
	{
		c += (vm->players[i++] != NULL);
	}
	return (c);
}

void	set_player_indexes(t_vm *vm)
{
	t_player	*tmp;
	int			i;

	i = -1;
	tmp = vm->player;
	while (tmp != NULL)
	{
		tmp->idx = i;
		tmp->n = -i--;
		tmp = tmp->next;
	}
}

void	sort_players(t_vm *vm)
{
	t_player	*prev;
	t_player	*cand;
	int			i;

	prev = NULL;
	i = 1;
	die_if_p_index_sucks(vm);
	while (i <= count_players(vm))
	{
		cand = candidate(vm, i);
		if (prev == NULL)
			vm->player = cand;
		else
			prev->next = cand;
		prev = cand;
		cand->idx = i++;
	}
	set_player_indexes(vm);
}

void	delete_process(t_process **p, t_process *next, t_process **del)
{
	*p = next;
	free((*del)->reg);
	free(*del);
}

void	remove_dead_p(t_vm *vm)
{
	t_process	*tmp;
	t_process	*prev;

	prev = NULL;
	tmp = vm->process;
	while (tmp)
	{
		if ((tmp->live == 0) && (prev == NULL))
		{
			delete_process(&(vm->process), tmp->next, &tmp);
			tmp = vm->process;
		}
		else if (tmp->live == 0)
		{
			delete_process(&tmp, tmp->next, &(prev->next));
			prev->next = tmp;
		}
		else
		{
			tmp->live = 0;
			prev = tmp;
			tmp = tmp->next;
		}
	}
	vm->game_on = (vm->process != NULL);
}
