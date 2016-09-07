static long
set_error(struct tcb *tcp)
{
	if (ia64_ia32mode)
		ia64_regs.gr[8] = tcp->u_error;
	else
		ia64_regs.gr[10] = tcp->u_error;

	return set_regs(tcp->pid);
}
