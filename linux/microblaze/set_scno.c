static long
arch_set_scno(struct tcb *tcp, int scno)
{
	return upoke(tcp->pid, 0, &scno) < 0 ? -1 : 0;
}
