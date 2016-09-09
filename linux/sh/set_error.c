static long
set_error(struct tcb *tcp)
{
	return upoke(tcp->pid, 4 * REG_REG0, &tcp->u_error) < 0 ? -1 : 0;
}
