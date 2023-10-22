    .file   "div.c"
    .text
    .globl  div_qr
    .type   div_qr, @function
div_qr:
.LFB0:
    .cfi_startproc
    movl    %edi, %eax
    cltd
    idivl   %esi
    movl    %edx, (%rdx)
    ret
    .cfi_endproc
.LFE0:
    .size   div_qr, .-div_qr
    .ident  "GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
    .section    .note.GNU-stack,"",@progbits
