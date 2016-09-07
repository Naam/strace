static long
arch_set_scno(struct tcb *tcp, int scno)
{
#if !defined(__ARM_EABI__) || ENABLE_ARM_OABI
	/* We can deal with thumb mode... */
	if (arm_regs.ARM_cpsr & 0x20) {
		goto eabi;
	} /* ...however using PTRACE_POKETEXT feels wrong */
	return -1;
#else
eabi:
	arm_regs.ARM_r7 = scno;
	return set_regs(tcp->pid);
#endif
}
