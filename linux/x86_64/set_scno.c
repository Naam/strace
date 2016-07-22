static long
arch_set_scno(struct tcb *tcp, int scno)
{
	x86_64_regs.orig_rax = scno;
	return set_regs(tcp->pid);
}
