#include <linux/blkdev.h>
#include <linux/syscalls.h>

struct req_trace_tbl req_trace = {.count=0};
bool req_trace_enabled = false;

SYSCALL_DEFINE1(get_reqtrace, struct req_trace_tbl __user *, arg)
{
	return copy_to_user(arg, &req_trace, sizeof(req_trace));
}

SYSCALL_DEFINE1(conf_reqtrace, bool, arg)
{
	pr_info("conf_reqtrace: %d. count was %d\n", arg, req_trace.count);
	req_trace_enabled = arg;
	req_trace.count = 0;
	return 0;
}
