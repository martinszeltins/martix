#include <system.h>
#include <serial.h>


void panic(const char *message, const char *file, uint32_t line)
{
    asm volatile("cli");
    qemu_printf("PANIC(%s) at %s : %u\n", message, file, line);
    for(;;);
}

void print_reg(register_t * reg) {
    qemu_printf("Registers dump:\n");
    qemu_printf("eax 0x%x ebx 0x%x 0x%ecx 0x%x %edx 0x%x\n", reg->eax, reg->ebx, reg->ecx, reg->edx);
    qemu_printf("edi 0x%x esi 0x%x %ebp 0x%x %esp 0x%x\n", reg->edi, reg->esi, reg->ebp, reg->esp);
    qemu_printf("eip 0x%x cs 0x%x ss 0x%x eflags 0x%x useresp 0x%x\n", reg->eip, reg->ss, reg->eflags, reg->useresp);
}
void print_reg16(register16_t * reg) {
    qemu_printf("Registers dump:\n");
    qemu_printf("ax 0x%x bx 0x%x cx 0x%x dx 0x%x\n", reg->ax, reg->bx, reg->cx, reg->dx);
    qemu_printf("di 0x%x si 0x%x bp 0x%x sp 0x%x\n", reg->di, reg->si, reg->bp, reg->sp);
    qemu_printf("ds 0x%x es 0x%x fs 0x%x gs 0x%x ss 0x%x eflags 0x%x\n", reg->ds, reg->es, reg->fs, reg->gs, reg->ss, reg->eflags);
}
