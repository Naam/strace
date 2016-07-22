static long
set_error(struct tcb *tcp)
{
	x86_64_regs.orig_rax = tcp->u_error;
	return set_regs(tcp->pid);
}
