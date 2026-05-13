all: katamino katamino2 katamino3

katamino: forme.o tableau.o main.o
	g++ $^ -o $@ ./lib/linux/libraylib.a

katamino2: forme.o tableau.o main2.o
	g++ $^ -o $@ ./lib/linux/libraylib.a

katamino3: forme.o tableau.o main3.o
	g++ $^ -o $@ ./lib/linux/libraylib.a

main.o: main.cpp forme.h tableau.h
	g++ -c main.cpp -Wall -O2 -static-libgcc -static-libstdc++

main2.o: main2.cpp forme.h tableau.h
	g++ -c main2.cpp -Wall -O2 -static-libgcc -static-libstdc++

main3.o: main3.cpp forme.h tableau.h
	g++ -c main3.cpp -Wall -O2 -static-libgcc -static-libstdc++

tableau.o: tableau.h tableau.cpp forme.h
	g++ -c tableau.cpp -Wall -O2 -static-libgcc -static-libstdc++

forme.o: forme.cpp forme.h
	g++ -c forme.cpp -Wall -O2 -static-libgcc -static-libstdc++


win:
	make -f MakeFileWin

clean:
	rm -f *.o

clear:
	rm -f *.o *.out *.exe
