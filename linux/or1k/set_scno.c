static long
arch_set_scno(struct tcb *tcp, int scno)
{
	or1k_regs.gpr[11] = scno;

	return set_regs(tcp->pid);
}
