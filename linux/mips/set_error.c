static long
set_error(struct tcb *tcp)
{
	return upoke(tcp->pid, REG_V0, tcp->u_error);
}
