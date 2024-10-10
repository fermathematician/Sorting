projeto: alg.c projeto.c
	gcc -o projeto alg.c projeto.c

run: projeto
	./projeto

clean:
	rm -f teste
