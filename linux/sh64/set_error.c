static long
set_error(struct tcb *tcp)
{
	return upeek(tcp->pid, REG_GENERAL(9), &tcp->u_error) < 0 ? -1 : 0;
}
