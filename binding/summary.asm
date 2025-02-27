.LC0:
        .string "Base::nv_func()\n"
Base::nv_func():
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     esi, OFFSET FLAT:.LC0
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        nop
        leave
        ret
.LC1:
        .string "Derived::show()\n"
Derived::show():
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     esi, OFFSET FLAT:.LC1
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        nop
        leave
        ret
.LC2:
        .string "Derived::show2()\n"
Derived::show2():
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     esi, OFFSET FLAT:.LC2
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     eax, OFFSET FLAT:vtable for Derived+16
        mov     QWORD PTR [rbp-16], rax
        lea     rax, [rbp-16]
        mov     QWORD PTR [rbp-8], rax
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    Base::nv_func()
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax]
        mov     rdx, QWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    rdx
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax]
        add     rax, 8
        mov     rdx, QWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    rdx
        mov     eax, 0
        leave
        ret
vtable for Derived:
        .quad   0
        .quad   typeinfo for Derived
        .quad   Derived::show()
        .quad   Derived::show2()
typeinfo for Derived:
        .quad   vtable for __cxxabiv1::__si_class_type_info+16
        .quad   typeinfo name for Derived
        .quad   typeinfo for Base
typeinfo name for Derived:
        .string "7Derived"
typeinfo for Base:
        .quad   vtable for __cxxabiv1::__class_type_info+16
        .quad   typeinfo name for Base
typeinfo name for Base:
        .string "4Base"