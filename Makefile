LIB_PATH = libft
ASM_PATH = assembler
VM_PATH = vm

all:
	make -C $(LIB_PATH)
	make -C $(ASM_PATH)
	make -C $(VM_PATH)
	@cp $(ASM_PATH)/asm ./
	@cp $(VM_PATH)/corewar ./

clean:
	make clean -C $(LIB_PATH)
	make clean -C $(ASM_PATH)
	make clean -C $(VM_PATH)

fclean:
	make fclean -C $(LIB_PATH)
	make fclean -C $(ASM_PATH)
	make fclean -C $(VM_PATH)
	@[ -f asm ] && rm asm || echo
	@[ -f corewar ] && rm corewar || echo

re: fclean all
