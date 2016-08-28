static long
arch_set_scno(struct tcb *tcp, int scno)
{
	if (aarch64_io.iov_len == sizeof(arm_regs))
		arm_regs.ARM_r7 = scno;
	else
		aarch64_regs.regs[8] = scno;

	return set_regs(tcp->pid);
}
