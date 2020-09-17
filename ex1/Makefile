all:
	gcc -o ex1.exe main.c -lm -Wall

run:
	rm -r results; mkdir results
	./ex1.exe numberGen/10.gen 1000 > results/10.dat
	./ex1.exe numberGen/100.gen 1000 > results/100.dat
	./ex1.exe numberGen/1000.gen 1000 > results/1000.dat
	./ex1.exe numberGen/5000.gen 1000 > results/5000.dat
	./ex1.exe numberGen/10000.gen 1000 > results/10000.dat

	echo "# Array Size	Inverse	Bubble" > results/all.dat
	cat results/10.dat >> results/all.dat
	cat results/100.dat >> results/all.dat
	cat results/1000.dat >> results/all.dat
	cat results/5000.dat >> results/all.dat
	cat results/10000.dat >> results/all.dat

gen:
	gcc -o numberGen.exe numberGen.c -lm -Wall
	rm -r numberGen; mkdir numberGen
	./numberGen.exe 10 > numberGen/10.gen
	./numberGen.exe 100 > numberGen/100.gen
	./numberGen.exe 1000 > numberGen/1000.gen
	./numberGen.exe 5000 > numberGen/5000.gen
	./numberGen.exe 10000 > numberGen/10000.gen
