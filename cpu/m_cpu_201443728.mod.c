#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7377b0b2, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xf290f33a, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x560967ba, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x26fa4497, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x37c49ac8, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xf0b77561, __VMLINUX_SYMBOL_STR(seq_put_decimal_ull) },
	{ 0xd2555f19, __VMLINUX_SYMBOL_STR(jiffies_64_to_clock_t) },
	{ 0x9584ca05, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xcbee20b2, __VMLINUX_SYMBOL_STR(get_cpu_iowait_time_us) },
	{ 0x7ee6d93a, __VMLINUX_SYMBOL_STR(nsecs_to_jiffies64) },
	{ 0x53614269, __VMLINUX_SYMBOL_STR(get_cpu_idle_time_us) },
	{ 0xfe7c4287, __VMLINUX_SYMBOL_STR(nr_cpu_ids) },
	{ 0xc0a3d105, __VMLINUX_SYMBOL_STR(find_next_bit) },
	{ 0xb152d87d, __VMLINUX_SYMBOL_STR(cpu_possible_mask) },
	{ 0x5ecfeec6, __VMLINUX_SYMBOL_STR(__per_cpu_offset) },
	{ 0xc4f331c6, __VMLINUX_SYMBOL_STR(cpu_online_mask) },
	{ 0x1ebac2bd, __VMLINUX_SYMBOL_STR(getboottime64) },
	{ 0x5567c227, __VMLINUX_SYMBOL_STR(kernel_cpustat) },
	{ 0xb7f969ab, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "F4C9F438B60F0412504D3E6");
