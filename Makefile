CC = g++
CFLAGS = -I.
OBJ = Laboratorio_de_metodos_numericos.o

%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o output

