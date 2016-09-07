static long
arch_set_scno(struct tcb *tcp, int scno)
{
	if (s390_regset.gprs[2])
		s390_regset.gprs[2] = scno;
	else
		s390_regset.gprs[1] = scno;

	return set_regs(tcp->pid);
}
