#ifndef _ASM_RISCV_CSR_H
#define _ASM_RISCV_CSR_H

#include "../common.h"

/* Status register flags */
#define SR_SIE	_AC(0x00000002, UL) /* Supervisor Interrupt Enable */
#define SR_SPIE	_AC(0x00000020, UL) /* Previous Supervisor IE */
#define SR_SPP	_AC(0x00000100, UL) /* Previously Supervisor */
#define SR_SUM	_AC(0x00040000, UL) /* Supervisor may access User Memory */

/* SATP flags */
#if __riscv_xlen == 32
#define SATP_PPN     _AC(0x003FFFFF, UL)
#define SATP_MODE_32 _AC(0x80000000, UL)
#define SATP_MODE    SATP_MODE_32
#else
#define SATP_PPN     _AC(0x00000FFFFFFFFFFF, UL)
#define SATP_MODE_39 _AC(0x8000000000000000, UL)
#define SATP_MODE    SATP_MODE_39
#endif

/* Interrupt Enable and Interrupt Pending flags */
#define SIE_SSIE _AC(0x00000002, UL) /* Software Interrupt Enable */
#define SIE_STIE _AC(0x00000020, UL) /* Timer Interrupt Enable */

#ifndef __ASSEMBLY__

#define csr_read(csr)						\
({								\
	register unsigned long __v;				\
	__asm__ __volatile__ ("csrr %0, " #csr			\
			      : "=r" (__v) :			\
			      : "memory");			\
	__v;							\
})

#define csr_write(csr, val)					\
({								\
	unsigned long __v = (unsigned long)(val);		\
	__asm__ __volatile__ ("csrw " #csr ", %0"		\
			      : : "rK" (__v)			\
			      : "memory");			\
})

#define csr_set(csr, val)					\
({								\
	unsigned long __v = (unsigned long)(val);		\
	__asm__ __volatile__ ("csrs " #csr ", %0"		\
			      : : "rK" (__v)			\
			      : "memory");			\
})

#endif /* __ASSEMBLY__ */

#endif /* _ASM_RISCV_CSR_H */
