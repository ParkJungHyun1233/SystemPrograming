mathcalc : simplecalc.o sum.o sub.o mul.o div.o
	gcc -o mathcalc simplecalc.o sum.o sub.o mul.o div.o
	
simplecalc.o : simplecalc.c
	gcc -c simplecalc.c
sum.o : sum.c
	gcc -c sum.c
sub.o : sub.c
	gcc -c sub.c
mul.o : mul.c
	gcc -c mul.c
div.o : div.c
	gcc -c div.c

clean : 
	rm -f mathcalc simplecalc.o sum.o sub.o mul.o div.o
