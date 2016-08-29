static long
arch_set_scno(struct tcb *tcp, int scno)
{
	ppc_regs.gpr[0] = scno;
	return set_regs(tcp->pid);
}
