/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:15:43 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/22 16:57:27 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** sti : Opcode 11. Prend un registre, et deux index (potentiellement des
** registres). Additionne les deux derniers, utilise cette somme comme une
** adresse ou sera copiée la valeur du premier paramètre.
*/

static void		dbg(t_process *proc, int32_t val1, int32_t val2, int32_t val3)
{
	ft_putstr("P\t");
	ft_putstr("\033[1;");
	ft_putnbr((31 + (proc->idlive % 7)));
	ft_putstr(";40m");
	ft_putnbr(proc->id);
	ft_putstr(" | sti ");
	ft_putnbr(val1);
	ft_putstr(" ");
	ft_putnbr(val2);
	ft_putstr(" ");
	ft_putnbr(val3);
	ft_putendl("");
	ft_putstr(C_NONE);
}

static void		norme(t_process *process)
{
	process->nb_cycle -= 25;
	process->pc %= MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
}

void			apply_sti(t_process *proc, t_env *env)
{
	t_args		args[3];
	int32_t		val;
	int32_t		val1;
	int32_t		addr;
	int32_t		reg;

	decode(args, env->memory[proc->pc], env->memory[proc->pc + 1]);
	addr = proc->pc + BYPASS_ARG_ENCODE;
	reg = get_args(env->memory, addr, args[0].length);
	addr += args[0].length;
	val = get_args(env->memory, addr, args[1].length);
	val = return_value(proc, env->memory, args[1], val);
	addr += args[1].length;
	val1 = get_args(env->memory, addr, args[2].length);
	val1 = return_value(proc, env->memory, args[2], val1);
	if (reg > 0 && reg <= 16)
	{
		write_memory(env->memory, proc->pc + ((val1 + val) % IDX_MOD),
				proc->reg[reg - 1]);
		protocol_mem(*env, *proc, proc->pc + ((val1 + val) % IDX_MOD));
	}
	proc->pc += BYPASS(args, BYPASS_ARG_ENCODE);
	norme(proc);
	if (env->dbg)
		dbg(proc, reg, val, val1);
}
