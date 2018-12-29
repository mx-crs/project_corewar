/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:58:28 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/09 14:58:29 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../src/libft/includes/libft.h"

# define T_REG				1
# define T_DIR				2
# define T_IND				4

# define REG_NUMBER			16
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define COMMAND_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD			".name \t"
# define COMMENT_CMD		".comment \t"
# define PREFIX_PRG			(16 + PROG_NAME_LENGTH + COMMENT_LENGTH)
# define BOT_MAX_SIZE		(1024)
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3
# define CNT_CMD			16

typedef struct				s_label_in
{
	struct s_label_in		*next;
	char					*l_name;
	int						l_reserved;
	int						l_size;
	int						l_pos;
	int						l_pos_sub;
}							t_label_in;

typedef struct				s_label_out
{
	struct s_label_out		*next;
	char					*l_name;
	int						l_pos;
}							t_label_out;

typedef struct				s_header
{
	unsigned int			magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	unsigned int			prog_size;
	char					comment[COMMENT_LENGTH + 1];
}							t_header;

typedef struct				s_asm
{
	char					*file_name;
	char					file[PREFIX_PRG + BOT_MAX_SIZE];
	int						flag;
	int						f_size;
	char					*in_file;
	char					**in_file_n;
	t_label_in				*label_in;
	t_label_out				*label_out;
	t_header				header;
}							t_asm;

typedef struct				s_op
{
	char					name[6];
	int						n_args;
	int						args[3];
	int						n_cmd;
	int						cycles;
	int						codage;
	int						l_size;
}							t_op;

extern t_op					g_op_tab[CNT_CMD];

void						ft_usage(void);

int							ft_take_cmd_n(char *op);
int							ft_fill_core(t_asm *file);
int							ft_fill_core_with_cmd(t_asm *file);
int							ft_get_num(t_asm *file, char *cmd,
													int l_pos_sub, int cmd_n);
int							ft_take_cmd(int cmd_n, char *c_line, t_asm *file,
													int l_pos_sub);

void						ft_fill_in_label(t_asm *file, t_label_in *l_in,
														t_label_out	*l_out);
int							ft_fill_labels(t_asm *file);
int							ft_cmd_is_label(char *cmd, t_asm *file);
int							ft_take_label_in(t_asm *file, char *cmd,
											int l_pos_sub, int cmd_n);

void						ft_add_new_label_in(t_asm *file, char *l_name,
											int l_pos_sub, int l_size);
void						ft_add_new_label_out(t_asm *file, char *l_name);

void						ft_free_mem(char **tmp);
int							ft_clear_data(t_asm *file);
int							ft_take_num(char *cmd);
int							ft_get_task(t_asm *file, int fd);
int							ft_fill_input_file(t_asm *file, char **av, int ac);

int							ft_get_name(t_asm *file);
int							ft_get_comment(t_asm *file);
void						ft_fill_header(t_asm *file);
short int					ft_reverse_endian_two(short int num);
int							ft_reverse_endian(int num);

char						*ft_clear_spaces(char *line);
void						ft_fill_tmp(char *tmp, char **tmp_n, char **tmp_ws);
int							ft_is_string(t_asm *file, int i);
int							ft_filled_line(char *str);
int							ft_shift_header(char *str);

void						ft_bit_offset(char **cmd, int *num);
void						ft_write_to_position(t_asm *file, void *src,
												size_t pos, size_t b_size);
int							ft_write_to_cor_file(t_asm *file);
int							ft_write_to_buffer(t_asm *file, void *src,
															size_t size);
int							ft_fill_codage(t_op op, char *c_line, t_asm *file);

int							ft_detect_arg_whitespace(char *tmp);
int							ft_detect_arg(char *arg);
int							ft_compare_args(int arg_set, int arg);
int							ft_valid_arg(char **argv, int argc, int cmd_n);
int							ft_detect_cmd_free_return(char **cmd, int ret);

int							ft_get_argc(char **argv);
int							ft_detect_arg_mode(char chr);
int							ft_detect_arg_free_return(char **tmp, int ret);

int							ft_shift_comment(t_asm *file);
int							ft_iter_n_c(int *n_c, char nc);
int							ft_shift_comment_name(int *i, char *in_file);
int							ft_valid_name_comment(t_asm *file);
void						ft_iter_until_pnt(t_asm *file, int *i, char chr);

void						ft_print_cong(void);
void						ft_print_cong1(void);
void						ft_is_flag(t_asm *file, char **av, int ac);

#endif
