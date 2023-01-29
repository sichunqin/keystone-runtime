OUTPUT_ARCH( "riscv" )

SECTIONS
{
  . = 0xffffffffc0000000;
  PROVIDE(rt_base = .);
  .text : {
    *(.text._start)
    *(.text.encl_trap_handler)
    *(.text)
  }
  . = ALIGN(0x1000);
  .rodata :
  {
    *(.rdata)
    *(.rodata)
  }
  .data : { *(.data) }
  .bss :
  {
    PROVIDE(bss_start = .);
    *(.bss)
    PROVIDE(bss_end = .);
  }

  .kernel_stack : {
    . += 0x8000;
    PROVIDE(kernel_stack_end = .);
  }
  _end = .;
}
