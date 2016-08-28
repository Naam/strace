static long
arch_set_scno(struct tcb *tcp, int scno)
{
	if (x86_io.iov_len == sizeof(i386_regs))
		i386_regs.orig_eax = scno;
	else
		x86_64_regs.orig_rax = scno;

	return set_regs(tcp->pid);
}
