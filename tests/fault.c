/*
 * This file is part of fault injection tests.
 *
 * Copyright (c) 2016 Nahim El Atmani <nahim+dev@naam.me>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "tests.h"
#include <sys/syscall.h>

#ifdef __NR_kill

# include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
# include <unistd.h>

static void
handler(int sig)
{
}

static void
occ_at(int raw)
{
	pid_t pid = getpid();
	syscall(__NR_kill, pid, SIGALRM);
	syscall(__NR_kill, pid, SIGALRM);
	if (!raw)
		printf("kill(%d, SIGALRM) = 0\n"
		       "kill(%d, SIGALRM) = -1 EINVAL (Invalid argument)(DISCARDED)\n"
		       "+++ exited with 0 +++\n", pid, pid);
	else
		printf("kill(%d, 0xe) = 0\n"
		       "kill(%d, 0xe) = -1 (errno 22)(DISCARDED)\n"
		       "+++ exited with 0 +++\n", pid, pid);
}

static void
occ_every(void)
{
	pid_t pid = getpid();
	syscall(__NR_kill, pid, SIGALRM);
	syscall(__NR_kill, pid, SIGALRM);
	syscall(__NR_kill, pid, SIGALRM);
	syscall(__NR_kill, pid, SIGALRM);
	syscall(__NR_kill, pid, SIGALRM);
	syscall(__NR_kill, pid, SIGALRM);
	printf("kill(%d, SIGALRM) = 0\n"
	       "kill(%d, SIGALRM) = -1 EINVAL (Invalid argument)(DISCARDED)\n"
	       "kill(%d, SIGALRM) = 0\n"
	       "kill(%d, SIGALRM) = -1 EINVAL (Invalid argument)(DISCARDED)\n"
	       "kill(%d, SIGALRM) = 0\n"
	       "kill(%d, SIGALRM) = -1 EINVAL (Invalid argument)(DISCARDED)\n"
	       "+++ exited with 0 +++\n", pid, pid, pid, pid, pid, pid);
}

int
main(int argc, char *argv[])
{
	if (argc != 2)
		return -EINVAL;

	sigset_t mask;
	const struct sigaction act = { .sa_handler = handler };
	if (sigaction(SIGALRM, &act, NULL))
		perror_msg_and_fail("sigaction");
	sigemptyset(&mask);
	sigaddset(&mask, SIGALRM);
	if (sigprocmask(SIG_UNBLOCK, &mask, NULL))
		perror_msg_and_fail("sigprocmask");

	if (!strcmp("at", argv[1]))
		occ_at(0);
	else if (!strcmp("every", argv[1]))
		occ_every();
	else if (!strcmp("raw", argv[1]))
		occ_at(1);
	else
		return -EINVAL;

	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_kill")

#endif
