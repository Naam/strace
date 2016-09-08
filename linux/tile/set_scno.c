static long
arch_set_scno(struct tcb *tcp, int scno)
{
	tile_regs.regs[10] = scno;
	return set_regs(tcp->pid);
}
