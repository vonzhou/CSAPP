/* $begin elfsymbol */
typedef struct { 
    int name;        /* string table offset */ 
    int value;       /* section offset, or VM address */ 
    int size;        /* object size in bytes */ 
    char type:4,     /* data, func, section, or src file name (4 bits) */ 
	 binding:4;  /* local or global (4 bits) */ 
    char reserved;   /* unused */  
    char section;    /* section header index, ABS, UNDEF, */ 
                     /* or COMMON  */  
} Elf_Symbol; 
/* $end elfsymbol */

/* $begin elfrelo */
typedef struct { 
    int offset;     /* offset of the reference to relocate */ 
    int symbol:24,  /* symbol the reference should point to */ 
	type:8;     /* relocation type */ 
} Elf32_Rel; 
/* $end elfrelo */

