static long
arch_set_scno(struct tcb *tcp, int scno)
{
	arc_regs.scratch.r8 = scno;
	return set_regs(tcp->pid);
}
