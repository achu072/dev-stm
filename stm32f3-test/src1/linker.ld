/* Highest address of the user mode stack */
_estack = 0x2000A000;    /* end of 40K RAM */

/* Specify the memory areas */
MEMORY
{
  FLASH (rx)      : ORIGIN = 0x8000000, LENGTH = 256K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 40K
  MEMORY_B1 (rx)  : ORIGIN = 0x60000000, LENGTH = 0K
}