.section .text
.global findpeak
# using 16-bit integers (short)
findpeak:
    # rdi=arr pointer, rsi=n
    pushq %rbp # push base pointer
    movq %rsp, %rbp # new stack pointer
    cmpq $1, %rsi # check if n == 1
    je base1
    cmpq $2, %rsi # check if n == 2
    je base2
    
    movq %rsi, %r8 # r8 = n
    shrq $1, %r8 # r8 = n/2 = mid
    movq %r8, %r9 # r9 = mid
    
    movw (%rdi, %r8, 2), %ax # ax = arr[mid]
    
    movq %r8, %r10
    decq %r10
    movw (%rdi, %r10, 2), %cx # cx = arr[mid-1]
    
    movq %r8, %r10
    incq %r10
    movw (%rdi, %r10, 2), %bx # bx = arr[mid+1]
    
    cmpw %ax, %cx # compare arr[mid-1] with arr[mid]
    jge if1
    
    cmpw %ax, %bx # compare arr[mid+1] with arr[mid]
    jge if2
    
    jmp retval # return arr[mid] as peak
    
if1:
    movq %r9, %rsi # rsi = mid
    call findpeak # call findpeak for left half
    jmp end
    
if2:
    leaq (%rdi, %r9, 2), %rdi # rdi = arr + mid*2 (for 16-bit elements)
    subq %r9, %rsi # rsi = n - mid
    call findpeak # call findpeak for right half
    jmp end
    
end:
    popq %rbp # pop base pointer
    ret
    
base1:
    movw (%rdi), %ax # return arr[0]
    popq %rbp # pop base pointer
    ret
    
base2:
    movw (%rdi), %ax # ax = arr[0]
    movw 2(%rdi), %cx # cx = arr[1]
    cmpw %ax, %cx # compare arr[1] with arr[0]
    jle base2_1 # if arr[1] <= arr[0], return arr[0]
    movw %cx, %ax # return arr[1]
    popq %rbp # pop base pointer
    ret
    
base2_1:
    popq %rbp # pop base pointer
    ret
    
retval:
    movw (%rdi, %r9, 2), %ax # return arr[mid]
    popq %rbp # pop base pointer
    ret
    