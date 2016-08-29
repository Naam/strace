static long
set_error(struct tcb *tcp)
{
	ppc_regs.gpr[0] = -1;
	ppc_regs.gpr[3] = tcp->u_error;
	return set_regs(tcp->pid);
}
