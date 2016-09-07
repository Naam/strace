static long
set_error(struct tcb *tcp)
{
	metag_regs.dx[0][0] = tcp->u_error; /* result pointer in D0Re0 (D0.0) */
	return set_regs(tcp->pid);
}
