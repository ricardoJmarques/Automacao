// Access from ARM Running Linux

#define BCM2708_PERI_BASE        0x20000000
#define GPIO_BASE                (BCM2708_PERI_BASE + 0x200000) /* GPIO controller */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define PAGE_SIZE (4*1024)
#define BLOCK_SIZE (4*1024)

int  mem_fd;
unsigned char *gpio_mem, *gpio_map;
char *spi0_mem, *spi0_map;

// I/O access
volatile unsigned *gpio;

// GPIO setup macros. Always use INP_GPIO(x) before using OUT_GPIO(x) or SET_GPIO_ALT(x,y)
#define INP_GPIO(g) *(gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio+((g)/10)) |=  (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(gpio+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))

#define GPIO_SET *(gpio+7)  // sets   bits which are 1 ignores bits which are 0
#define GPIO_CLR *(gpio+10) // clears bits which are 1 ignores bits which are 0


//
// Set up a memory regions to access GPIO
//
void setup_io()
{
	/* open /dev/mem */
	if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) 
	{
		printf("Can't open /dev/mem \n");
		exit (-1);
	}

	/* mmap GPIO */
	// Allocate MAP block
	if ((gpio_mem = (unsigned char*)malloc(BLOCK_SIZE + (PAGE_SIZE-1))) == NULL) 
	{
		printf("Allocation error \n");
		exit (-1);
	}

	// Make sure pointer is on 4K boundary
	if ((unsigned long)gpio_mem % PAGE_SIZE)
	{
		gpio_mem += PAGE_SIZE - ((unsigned long)gpio_mem % PAGE_SIZE);
	}

	// Now map it
	gpio_map = (unsigned char *)mmap(
		(caddr_t)gpio_mem,
		BLOCK_SIZE,
		PROT_READ|PROT_WRITE,
		MAP_SHARED|MAP_FIXED,
		mem_fd,
		GPIO_BASE
		);

	if ((long)gpio_map < 0)
	{
		printf("mmap error %d\n", (int)gpio_map);
		exit (-1);
	}

	// Always use volatile pointer!
	gpio = (volatile unsigned *)gpio_map;
} // setup_io


// Function to set gpio as output mode
void setgpio()
{
        // Set up gpi pointer for direct register access
        setup_io();

        // Switch GPIO 7 to output mode
        INP_GPIO(7); // must use INP_GPIO before we can use OUT_GPIO
        OUT_GPIO(7);
}
// setgpio


// Function to send the output code to the RF transmitter connected to GPIO 7.
void SendCode(char* szCode)
{
	timespec sleeptime;
	timespec remtime;

	for (int iSend = 0 ; iSend < 10 ; iSend++) // number of code transmitions
	{
		sleeptime.tv_sec = 0;
		sleeptime.tv_nsec = 300000; // 3ms value obtained by trial and error to match transmitter

		for (int i = 0 ; i < strlen(szCode) ; i++)
		{
			if (szCode[i] == '1')
			{
				GPIO_SET = 1<<7; // gpio set high
			}
			else
			{
				GPIO_CLR = 1<<7; // gpio set low
			}
			nanosleep(&sleeptime,&remtime); // wait 3ms before signal changes
		}
		sleeptime.tv_nsec = 900000; // wait 9ms before next code
		nanosleep(&sleeptime,&remtime); // 3 ms to complete lenght of wait for next signal
	}
}


void SendCodePortao(char* szCode)
{
	timespec sleeptime;
	timespec remtime;

	for (int iSend = 0 ; iSend < 20 ; iSend++) // number of code transmitions
	{
		sleeptime.tv_sec = 0;
		sleeptime.tv_nsec = 300000; // 3ms value obtained by trial and error to match transmitter

		for (int i = 0 ; i < strlen(szCode) ; i++)
		{
			if (szCode[i] == '1')
			{
				GPIO_SET = 1<<7; // gpio set high
			}
			else
			{
				GPIO_CLR = 1<<7; // gpio set low
			}
			nanosleep(&sleeptime,&remtime); // wait 3ms before signal changes
		}
		sleeptime.tv_nsec = 900000; // wait 9ms before next code
		nanosleep(&sleeptime,&remtime); // 3 ms to complete lenght of wait for next signal
	}
}


void SendCodeAudi(char* szCode)
{
	timespec sleeptime;
	timespec remtime;

	for (int iSend = 0 ; iSend < 15 ; iSend++) // number of code transmitions
	{
		sleeptime.tv_sec = 0;
		sleeptime.tv_nsec = 300000; // 3ms value obtained by trial and error to match transmitter

		for (int i = 0 ; i < strlen(szCode) ; i++)
		{
			if (szCode[i] == '1')
			{
				GPIO_SET = 1<<7; // gpio set high
			}
			else
			{
				GPIO_CLR = 1<<7; // gpio set low
			}
			nanosleep(&sleeptime,&remtime); // wait 3ms before signal changes
		}
//		sleeptime.tv_nsec = 9000000; // wait 9ms before next code
//		nanosleep(&sleeptime,&remtime); // 3 ms to complete lenght of wait for next signal
	}
}
