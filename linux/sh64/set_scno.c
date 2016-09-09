static long
arch_set_scno(struct tcb *tcp, int scno)
{
	return upoke(tcp->pid, REG_SYSCALL, &scno) < 0 ? -1 : 0;
}
