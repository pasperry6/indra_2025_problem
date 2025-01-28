make:
	g++ -o out sol.cpp
	./out input.txt

input:
	g++ -o out_crea input_creator.cpp
	./out_crea input.txt 100