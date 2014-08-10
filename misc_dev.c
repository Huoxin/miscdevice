#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

#define DEVICE_NAME "my_misc_dev"

static int misc_open(struct inode *nd, struct file *filp)
{
	int major = MAJOR(nd->i_rdev);
	int minor = MINOR(nd->i_rdev);
	printk("misc_open,major=%d,minor=%d\n",major,minor);
	return 0;
}

static ssize_t misc_read(struct file *f, char __user *u, size_t sz, loff_t *off)
{
	printk("In the misc_read() function!\n");
	return 0;
}

struct file_operations misc_ops = 
{
	.owner = THIS_MODULE,
	.open = misc_open,
	.read = misc_read,
};

struct miscdevice misc = 
{
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &misc_ops,
};

static int demo_init(void)
{
	int ret;
	ret = misc_register(&misc);
	printk(DEVICE_NAME "\t initialized %s!\n", (0==ret)?"successed":"failed");

	return ret;
}

static void demo_exit(void)
{
	misc_deregister(&misc);
}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Huoxin");
MODULE_DESCRIPTION("An misc device driver as an example");
