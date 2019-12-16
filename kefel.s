.section .text
.globl   kefel
kefel:  movl %edi,%eax
shl $8,%eax
movl %edi,%ecx
shl $10,%ecx
subl %ecx,%eax
movl %edi,%ecx
shl $7,%ecx
movl %edi,%edx
shl $5,%edx
subl %edx,%ecx
subl %ecx,%eax
movl %edi,%ecx
shl $4,%ecx
subl %edi,%ecx
subl %ecx,%eax
ret
