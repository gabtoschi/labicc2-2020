SRC_DIR := src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

PROGRAM_NAME := ex4.exe

INPUT_CONFIGS := 1 2 3
INPUT_FILES := 14k 29k 58k 116k

execute_time = ./$(PROGRAM_NAME) t <<< "test.txt $(1)"

all:
	gcc -o $(PROGRAM_NAME) $(SRC_FILES) -I./include -lm -Wall

run:
	./$(PROGRAM_NAME) r

time:
	./$(PROGRAM_NAME) t

alltime:
	rm -r results; mkdir results

	for config in $(INPUT_CONFIGS); do \
		for file in $(INPUT_FILES); do \
			echo "$$file.txt $$config" | ./$(PROGRAM_NAME) t >> results/$$config.dat;  \
		done; \
	done
