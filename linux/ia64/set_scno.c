static long
arch_set_scno(struct tcb *tcp, int scno)
{
	if (ia64_ia32mode)
		ia64_regs.gr[0] = scno;
	else
		ia64_regs.gr[15] = scno;

	return set_regs(tcp->pid);
}