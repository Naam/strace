static long
set_error(struct tcb *tcp)
{
	return upoke(tcp->pid, PT_GR28, &tcp->u_error) < 0 ? -1 : 0;
}
