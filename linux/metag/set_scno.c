static long
arch_set_scno(struct tcb *tcp, int scno)
{
	metag_regs.dx[0][1] = scno;  /* syscall number in D1Re0 (D1.0) */
	return set_regs(tcp->pid);
}
