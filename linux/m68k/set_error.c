static long
set_error(struct tcb *tcp)
{
	return upeek(tcp->pid, 4 * PT_D0, &tcp->u_error) < 0 ? -1 : 0;
}
