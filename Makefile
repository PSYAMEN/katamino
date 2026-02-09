all: katamino clean win

katamino: forme.o tableau.o main.o
	g++ $^ -o $@ /home/PSYAMEN/PeiP2/InfoS4/server-tests/ServerSide/lib/linux/libraylib.a --static

main.o: main.cpp forme.h tableau.h
	g++ -c main.cpp -Wall -O2 -static-libgcc -static-libstdc++

tableau.o: tableau.h forme.h
	g++ -c tableau.cpp -Wall -O2 

forme.o: forme.cpp forme.h
	g++ -c forme.cpp -Wall -O2 


win:
	make -f MakeFileWin

clean:
	rm -f *.o

clear:
	rm -f *.o *.out *.exe
