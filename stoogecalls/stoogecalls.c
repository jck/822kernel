#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/printk.h>

SYSCALL_DEFINE0(deepsleep)
{
  pr_info("syscall deep sleep\n");
  return 0;
}
