static long
set_error(struct tcb *tcp)
{
	switch (aarch64_io.iov_len) {
		case sizeof(aarch64_regs):
			aarch64_regs.regs[8] = tcp->u_error;
			return set_regs(tcp->pid);
		case sizeof(arm_regs):
			arm_regs.ARM_r7 = tcp->u_error;
			return set_regs(tcp->pid);
	}
	return -1;
}
