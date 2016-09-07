static long
set_error(struct tcb *tcp)
{
	return upoke(tcp->pid, 3 * 4, &tcp->u_error) < 0 ? -1 : 0;
}
