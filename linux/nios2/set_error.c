static long
set_error(struct tcb *tcp)
{
	nios2_regs.regs[7] = 1; /* r7=1 indicates an error, see get_error() */
	nios2_regs.regs[2] = tcp->u_error;
	return set_regs(tcp->pid);
}
