static long
arch_set_scno(struct tcb *tcp, int scno)
{
	avr32_regs.r8 = scno;
	return set_regs(tcp->pid);
}
