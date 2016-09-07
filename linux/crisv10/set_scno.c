static long
arch_set_scno(struct tcb *tcp, int scno)
{
	return upoke(tcp->pid, 4 * PT_R9, &scno) < 0 ? -1 : 0;
}
