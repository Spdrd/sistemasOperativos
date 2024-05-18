GCC = gcc
CFLAGS = -lpthread
PROGRS = principal
clean:
	$(RM) $(PROGS) *.o
principal: 
	$(GCC) $(CFLAGS) modulo.c -c
	$(GCC) $(CFLAGS) $@.c -c
	$(GCC) $(CFLAGS) $@.o modulo.o -o $@