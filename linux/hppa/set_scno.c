static long
arch_set_scno(struct tcb *tcp, int scno)
{
	return upoke(tcp->pid, PT_GR20, &scno) < 0 ? -1 : 0;
}
