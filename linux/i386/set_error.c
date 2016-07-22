static long
set_error(struct tcb *tcp)
{
	i386_regs.orig_eax = tcp->u_error;
	return set_regs(tcp->pid);
}
