
/* mthomas: modified for LPC2138 */

MEMORY
{
  flash (rx) : ORIGIN = 0x00000000, LENGTH = 500k
  ram   (rw) : ORIGIN = 0x40000000, LENGTH = 32k
}

/* __stack_end__ = 0x40000000 + 64K - 4; */

__stack_end__ = ORIGIN(ram) + LENGTH(ram) -4;

SECTIONS 
{
	. = 0;
	startup : { *(.startup)} >flash

	prog : 
	{
		*(.text)
		*(.rodata)
		*(.rodata*)
		*(.glue_7)
		*(.glue_7t)
	} >flash

	__end_of_text__ = .;

	.data : 
	{
		__data_beg__ = .;
		__data_beg_src__ = __end_of_text__;
		*(.data)
		__data_end__ = .;
	} >ram AT>flash

	.bss : 
	{
		__bss_beg__ = .;
		*(.bss)
	} >ram

	/* Align here to ensure that the .bss section occupies space up to
	_end.  Align after .bss to ensure correct alignment even if the
	.bss section disappears because there are no input sections.  */
	. = ALIGN(32 / 8);
}
	. = ALIGN(32 / 8);
	_end = .;
	_bss_end__ = . ; __bss_end__ = . ; __end__ = . ;
	PROVIDE (end = .);


