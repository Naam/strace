static long
arch_set_scno(struct tcb *tcp, int scno)
{
	i386_regs.orig_eax = scno;
	return set_regs(tcp->pid);
}
