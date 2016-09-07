static long
arch_set_scno(struct tcb *tcp, int scno)
{
	return upoke(tcp->pid, REG_R0, &scno);
}
