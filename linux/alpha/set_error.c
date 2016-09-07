static long
set_error(struct tcb *tcp)
{
	int error = -1;

	if (upoke(tcp->pid, REG_A3, &error) < 0)
		return -1;
	if (upoke(tcp->pid, REG_R0, &tcp->u_error) < 0)
		return -1;

	return 0;
}
