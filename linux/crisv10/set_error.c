static long
set_error(struct tcb *tcp)
{
	return upoke(tcp->pid, 4 * PT_R10, &tcp->u_error) < 0 ? -1 : 0;
}
