/************************************************
* SE UTILIZÓ CODIGO DE REFERENCIA DE GITHUB
* https://github.com/01org/KVMGT-kernel/blob/master/fs/proc/meminfo.c
* AUTOR: @paulgortmaker
* 
*************************************************/
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/hugetlb.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int meminfo_proc_show(struct seq_file *m, void *v)
{
    struct sysinfo i;
    unsigned long pages[NR_LRU_LISTS];
    int lru;
#define K(x) ((x) << (PAGE_SHIFT - 10))
    si_meminfo(&i);
    for (lru = LRU_BASE; lru < NR_LRU_LISTS; lru++)
        pages[lru] = global_page_state(NR_LRU_BASE + lru);        
        //CREAR EL JSON, LA FUNCION K() devuelve el equivalente en kb,
        //se divide por 1024 para obtener los megas
    seq_printf(m, "{");
    seq_printf(m, "\"ram\": %8lu,",K(i.totalram)/1024);
    seq_printf(m, "\"used\": %8lu,",(K(i.totalram)-K(i.freeram))/1024);
    seq_printf(m, "\"free\": %8lu,",K(i.freeram)/1024);
    seq_printf(m, "\"average\": %8lu",(((K(i.totalram)-K(i.freeram))/1024)*100 )/ (K(i.totalram)/1024));
    seq_printf(m, "}");
#undef K
    return 0;
}

static void __exit final(void) //Salida de modulo
{
    printk(KERN_INFO "Cleaning Up.\n");
}

static int meminfo_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, meminfo_proc_show, NULL);
}

static const struct file_operations meminfo_proc_fops = {
    .open = meminfo_proc_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};
static int __init inicio(void) //Escribe archivo en /proc
{
    proc_create("m_ram_201443728", 0, NULL, &meminfo_proc_fops);
    return 0;
}
module_init(inicio);
module_exit(final);

MODULE_LICENSE("GPL");

