hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/BuzdeviGezegen.o -c ./src/BuzdeviGezegen.c
	gcc -I ./include/ -o ./lib/CuceGezegen.o -c ./src/CuceGezegen.c
	gcc -I ./include/ -o ./lib/DosyaOkuma.o -c ./src/DosyaOkuma.c
	gcc -I ./include/ -o ./lib/GazdeviGezegen.o -c ./src/GazdeviGezegen.c
	gcc -I ./include/ -o ./lib/Gezegenler.o -c ./src/Gezegenler.c
	gcc -I ./include/ -o ./lib/KayacGezegen.o -c ./src/KayacGezegen.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/Liste.o -c ./src/Liste.c
	gcc -I ./include/ -o ./lib/Simulasyon.o -c ./src/Simulasyon.c
	gcc -I ./include/ -o ./lib/Tarih.o -c ./src/Tarih.c
	gcc -I ./include/ -o ./lib/UzayAraci.o -c ./src/UzayAraci.c
	gcc -I ./include/ -o ./lib/Zaman.o -c ./src/Zaman.c
	gcc -I ./include/ -o ./bin/Test ./lib/BuzdeviGezegen.o ./lib/Tarih.o ./lib/CuceGezegen.o ./lib/DosyaOkuma.o ./lib/GazdeviGezegen.o ./lib/Gezegenler.o ./lib/KayacGezegen.o ./lib/Kisi.o ./lib/Liste.o ./lib/Simulasyon.o ./lib/UzayAraci.o ./lib/Zaman.o ./src/Test.c

calistir:
	./bin/Test
