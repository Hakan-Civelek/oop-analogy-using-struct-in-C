hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./lib/File.o -c ./src/File.c
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -I ./include/ -o ./bin/Test ./lib/Bitki.o ./lib/Canli.o ./lib/File.o ./lib/Habitat.o ./src/Test.c

calistir:
	./bin/Test