static long
set_error(struct tcb *tcp)
{
	if (x86_io.iov_len == sizeof(i386_regs))
		i386_regs.orig_eax = tcp->u_error;
	else
		x86_64_regs.orig_rax = tcp->u_error;

	return set_regs(tcp->pid);
}
