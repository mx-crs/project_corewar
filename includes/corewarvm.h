/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewarVM.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 19:15:11 by iyerin            #+#    #+#             */
/*   Updated: 2018/12/25 19:15:15 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWARVM_H
# define COREWARVM_H
# include "op.h"
# include "../src/libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <ncurses.h>
# include <time.h>

# define Y_1 196
# define Y_2 57
# define X_1 67

struct s_vm;

typedef struct			s_player
{
	int					last_live;
	int					lives;
	int					idx;
	int					n;
	int					size;
	char				*name;
	char				*comment;
	char				*instructions;
	struct s_player		*next;
	struct s_vm			*vm;
}						t_player;

typedef	struct			s_process
{
	char				carry;
	unsigned int		*reg;
	int					pc;
	int					delay;
	int					live;
	int					l_size;
	int					n;
	unsigned char		inst;
	struct s_process	*next;
	struct s_vm			*vm;
	struct s_player		*player;
}						t_process;

typedef struct			s_codage
{
	int					*type;
	int					*value;
	int					*raw_value;
	int					valid;
	int					to_skip;
}						t_codage;

typedef struct			s_map_cell
{
	unsigned char		value;
	t_player			*player;
	int					last_update;
}						t_map_cell;

typedef	struct			s_vm
{
	int					cycle;
	int					cycle_;
	int					cycle_to_die;
	int					checks;
	int					game_on;
	int					log;
	int					paused;
	int					c_per_sec;
	int					lives;
	int					p_n;
	char				visual_mode;
	int					nbr_cycles;
	int					fps;
	t_player			*players[MAX_PLAYERS];
	clock_t				next_cycle_time;
	t_player			*winner;
	t_map_cell			**mem;
	t_process			*process;
	t_player			*player;
	t_codage			*codage;
}						t_vm;

void					die(char *s);
void					create_vm(t_vm **vm);
int						hex_len(unsigned int hex);
void					validate_file(char *file);
int						hex_to_int(char c);
void					create_player(t_vm *vm, char *filename, int *idx);
void					create_player2(t_vm *vm, char *filename, int idx);
int						player_index(int i, int argc, char **argv);
void					read_dump(t_vm *vm, int i, int argc, char **argv);
void					print_usage();
int						int_from_hex(char c);
void					dump(t_vm *vm);
void					add_process(t_vm *vm, int pc, t_player *player);
int						next_pc(int pc, int offset);
void					tik_process(t_process **pr);
int						read_bytes(t_vm *vm, int pc, unsigned int n_bytes);
void					copy_process(t_vm *vm, t_process *ref);
t_codage				*read_codage(t_vm *vm, t_process *process, int nf);
void					dump_to_mem(t_process *pr, int len, int val, int idx);
t_codage				*init_codage(void);
int						print_players(t_player *pl);
int						process_count(t_vm *vm);
unsigned long			bot_length(char *file);
void					print_usage(void);
int						count_players(t_vm *vm);
void					sort_players(t_vm *vm);
void					remove_dead_p(t_vm *vm);
void					decrease_cycle_to_die(t_vm *vm);
void					die_if_p_index_sucks(t_vm *vm);
char					*hex_string(unsigned char c);
void					add_player(t_vm *vm, char *file, int idx);
char					*string_from_binary(char *binary, int start, \
						int length);
t_player				*candidate(t_vm *vm, int i);
void					ex_live(t_process *pr);
void					ex_lfork(t_process *pr);
void					ex_zjmp(t_process *pr);
void					ex_fork(t_process *pr);
void					ex_load(t_process *pr);
void					ex_st(t_process *pr);
void					ex_add(t_process *pr);
void					ex_sub(t_process *pr);
void					ex_and(t_process *pr);
void					ex_or(t_process *pr);
void					ex_xor(t_process *pr);
void					ex_ldi(t_process *pr);
void					ex_sti(t_process *pr);
void					ex_lld(t_process *pr);
void					ex_lldi(t_process *pr);
void					ex_aff(t_process *pr);
void					ex_lfork(t_process *pr);
void					print_intro(t_vm *vm);
void					print_command(t_process *pr, int l);
void					announce_winner(t_vm *vm, int j);
void					read_key(t_vm *vm);
void					initiate_visualization(void);
void					visualization(t_vm *vm);
t_player				*print_victory(t_vm *vm, int print);

#endif
