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

   . = ALIGN(0x1000);

  .embed : {
    /* 4 bytes magic number !emb */
    BYTE(33)
    BYTE(101)
    BYTE(109)
    BYTE(98)

    PROVIDE(embed_data = .);
    . += 300;
  }
  . = ALIGN(0x1000);
  .bss :
  {
    PROVIDE(bss_start = .);
    *(.bss)
    PROVIDE(bss_end = .);
  }
  . = ALIGN(0x1000);

  .kernel_stack : {
    . += 0x8000;
    PROVIDE(kernel_stack_end = .);
  }
  _end = .;
}
