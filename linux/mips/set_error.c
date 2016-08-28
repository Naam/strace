static long
set_error(struct tcb *tcp)
{
	if (mips_REG_A3) {
		mips_REG_A3 = -1;
		mips_REG_V0 = tcp->u_error;
	} else {
#ifdef LINUX_MIPSN32
		mips_REG_V0 = tcp->u_lrval;
#else
		mips_REG_V0 = tcp->u_rval;
#endif
	}

	return set_regs(tcp->pid);
}
