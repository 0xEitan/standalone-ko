// vermagic, struct sizes, and field offsets are built for
// Ubuntu 18.04.4 LTS with kernel release 5.3.0-46-generic.
// For different kernels, adjust accordingly.

#define NAME "standalone"
#define VERMAGIC "5.3.0-46-generic SMP mod_unload "

__attribute__((section(".modinfo")))
char modinfo_strings[] =
"name=" NAME "\0"
"vermagic=" VERMAGIC;

int my_init(void) { return 0; }
void my_exit(void) { }

__attribute__((section(".gnu.linkonce.this_module")))
struct module {
    char __pad0[0x18];
    char name[sizeof(NAME)];
    char __pad1[0x178 - 0x18 - sizeof(NAME)];
    void *init;
    char __pad2[0x330 - 0x178 - sizeof(void*)];
    void *exit;
    char __pad3[0x380 - 0x330 - sizeof(void*)];
} __attribute__((packed))
__this_module = {
    .name = NAME,
    .init = my_init,
    .exit = my_exit,
};
