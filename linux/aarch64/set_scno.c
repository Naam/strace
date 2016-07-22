static long
arch_set_scno(struct tcb *tcp, int scno)
{
	switch (aarch64_io.iov_len) {
		case sizeof(aarch64_regs):
			aarch64_regs.regs[8] = scno;
			return set_regs(tcp->pid);
		case sizeof(arm_regs):
			arm_regs.ARM_r7 = scno;
			return set_regs(tcp->pid);
	}
	return -1;
}
