static long
set_error(struct tcb *tcp)
{
	if (aarch64_io.iov_len == sizeof(arm_regs))
		arm_regs.ARM_r0 = tcp->u_error;
	else
		aarch64_regs.regs[0] = tcp->u_error;

	return set_regs(tcp->pid);
}
