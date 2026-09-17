hepsi: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/AnaProgram.cpp -o ./lib/AnaProgram.o
	g++ -c -I "./include" ./src/Sekil.cpp -o ./lib/Sekil.o
	g++ -c -I "./include" ./src/TekDugum.cpp -o ./lib/TekDugum.o
	g++ -c -I "./include" ./src/Tuval.cpp -o ./lib/Tuval.o
	g++ -c -I "./include" ./src/Dikdortgen.cpp -o ./lib/Dikdortgen.o
	g++ -c -I "./include" ./src/Ucgen.cpp -o ./lib/Ucgen.o
	g++ -c -I "./include" ./src/Yildiz.cpp -o ./lib/Yildiz.o
	g++ -c -I "./include" ./src/SekilListesi.cpp -o ./lib/SekilListesi.o
	g++ -c -I "./include" ./src/CiftDugum.cpp -o ./lib/CiftDugum.o
	g++ -c -I "./include" ./src/CiftListe.cpp -o ./lib/CiftListe.o

bagla:
	g++ ./lib/AnaProgram.o \
	    ./lib/SekilListesi.o \
	    ./lib/CiftDugum.o \
	    ./lib/CiftListe.o \
	    ./lib/Dikdortgen.o \
	    ./lib/Ucgen.o \
	    ./lib/Yildiz.o \
	    ./lib/Sekil.o \
	    ./lib/TekDugum.o \
	    ./lib/Tuval.o \
	    -o ./bin/program.exe

calistir:
	./bin/program.exe

clean:
	del /Q .\lib\*.o
	del /Q .\bin\program.exe