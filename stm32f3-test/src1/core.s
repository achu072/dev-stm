/* Define assembly instructions */

.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

/* Global memory locations */

.global vtable
.global reset_handler

/* Vector table */

.type vtable, %object
vtable:
    .word _estack
    .word reset_handler
.size vtable, .-vtable

/* Reset handler - called on reset */

.type reset_handler, %function
reset_handler:
  /* Set the stack pointer to the end of the stack */
  LDR  r0, =_estack
  MOV  sp, r0

  /* Set test value */
  LDR  r7, =0x01234567
  MOVS r0, #0
  main_loop:
    /* Add 1 to register 'r0' */
    ADDS r0, r0, #1
    /* Loop back */
    B    main_loop
.size reset_handler, .-reset_handler