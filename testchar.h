#ifndef TESTCHAR_H
#define TESTCHAR_H


#include <linux/init.h>           // macro  __init __exit
#include <linux/module.h>       
#include <linux/device.h>        
#include <linux/errno.h>
#include <linux/kernel.h>        
#include <linux/fs.h>             // file system in Linux
#include <asm/uaccess.h>  
#include <linux/mutex.h>       
#define  DEVICE_NAME "testchar"    
#define  CLASS_NAME  "testing" 

MODULE_LICENSE("GPL");            
MODULE_AUTHOR("Ivette Prieto Castro");    
MODULE_DESCRIPTION("Linux device driver for the B^3");  
MODULE_VERSION("0.1");  


static int major = 0;                 
static char message[256] = {0};
static short sizeMssg = 0;            
static struct class*  testcharClass  = NULL; 
static struct device* testcharDevice = NULL; 
static DEFINE_MUTEX(testcharMutex);  //mutex unlocked by default
 
static int dev_open(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);
static int dev_release(struct inode *, struct file *);

#endif