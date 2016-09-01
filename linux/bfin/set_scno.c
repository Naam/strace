static long
arch_set_scno(struct tcb *tcp, int scno)
{
	return upoke(tcp->pid, PT_ORIG_P0, &tcp->scno);
}
