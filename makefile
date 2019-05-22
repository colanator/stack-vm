src = $(wildcard *.c)
obj = $(src:.c=.o)

stack-vm: $(obj)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) stack-vm
	rm -f $(obj) stack-test
	rm -f $(obj) instr-mem-test