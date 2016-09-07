static long
arch_set_scno(struct tcb *tcp, int scno)
{
	nios2_regs.regs[2] = scno;
	return set_regs(tcp->pid);
}
