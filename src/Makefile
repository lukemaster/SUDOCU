all:functions.o main.o
	@echo Creating "sudocu"...
	@gcc main.o functions.o -o sudocu
	@echo Done successfuly.

debug:main.c functions.c
	@echo Creating "sudocu" in debug mode...
	@gcc -g3 main.c functions.c -o sudocu.debug
	@echo Done successfuly.

functions.o:functions.c
	@echo Creating "functions.o"...
	@gcc -O3 -c functions.c -o functions.o
	
main.o:main.c
	@echo Creating "main.o"...
	@gcc -O3 -c main.c -o main.o

clean:functions.o main.o sudocu
	@echo Cleaning objects...
	@rm main.o functions.o sudocu

clean-debug:sudocu.debug
	@echo Cleaning debug objects...
	@rm -rf sudocu.debug*