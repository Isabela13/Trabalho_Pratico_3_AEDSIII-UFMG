matriz: operacoes.o
	gcc main.c operacoes.o  -o block -g -Wall -Wextra -Werror -std=c99 -pedantic -O2

operacoes.o: operacoes.c
	gcc -c operacoes.c -g

clean:  
	rm *.o
