static long
arch_set_scno(struct tcb *tcp, int scno)
{
	return upoke(tcp->pid, SYSCALL_NR, &scno) < 0 ? -1 : 0;
}
