#ifndef _ASM_M68K_MODULE_H
#define _ASM_M68K_MODULE_H

#ifdef CONFIG_MMU

struct mod_arch_specific {
	struct m68k_fixup_info *fixup_start, *fixup_end;
};

#define MODULE_ARCH_INIT {				\
	.fixup_start		= __start_fixup,	\
	.fixup_end		= __stop_fixup,		\
}


enum m68k_fixup_type {
	m68k_fixup_memoffset,
	m68k_fixup_vnode_shift,
};

struct m68k_fixup_info {
	enum m68k_fixup_type type;
	void *addr;
};

#define m68k_fixup(type, addr)			\
	"	.section \".m68k_fixup\",\"aw\"\n"	\
	"	.long " #type "," #addr "\n"	\
	"	.previous\n"

extern struct m68k_fixup_info __start_fixup[], __stop_fixup[];

struct module;
extern void module_fixup(struct module *mod, struct m68k_fixup_info *start,
			 struct m68k_fixup_info *end);

#else

struct mod_arch_specific {
};

#endif /* CONFIG_MMU */

#define MODULES_ARE_ELF32
#define Elf_Shdr Elf32_Shdr
#define Elf_Sym Elf32_Sym
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Rel		Elf32_Rel
#define Elf_Rela	Elf32_Rela
#define ELF_R_TYPE(X)	ELF32_R_TYPE(X)
#define ELF_R_SYM(X)	ELF32_R_SYM(X)

#endif /* _ASM_M68K_MODULE_H */
