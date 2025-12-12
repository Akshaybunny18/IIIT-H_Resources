.section .text

.global diff

diff:
    #rdi=arr[0],rsi=n
    pushq %rbp #push base pointer
    movq %rsp, %rbp #new stack pointer
    movq (%rdi),%r9 #max=arr[0]
    movq (%rdi),%r8 #min=arr[0]
    movq $0,%rbx #i=0

    loop:
        cmpq %rsi,%rbx #check if i<n
        jge end #end loop if i>=n

        cmpq (%rdi),%r9 #compare arr[i] with max
        jg max #if arr[i]>max
        cmpq (%rdi),%r8 #compare arr[i] with min
        jl min #if arr[i]<min
        
        jmp next #if none of the above conditions satisfy

    max:
        movq (%rdi),%r9 #max=arr[i]
        jmp next

    min:
        movq (%rdi),%r8 #min=arr[i]
        jmp next

    next:
        leaq 8(%rdi),%rdi #i++
        incq %rbx
        jmp loop #goto beginning of loop

    end:
        subq %r9, %r8 #max-min
        movq %r8,%rax #store difference in %rax
        popq %rbp #pop base pointer
    ret #return %rax which has max-min
