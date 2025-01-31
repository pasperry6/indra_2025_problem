make:
	g++ -std=c++11 -o out sol.cpp
	./out input.txt

input:
	g++ -std=c++11 -o out_crea input_creator.cpp
	./out_crea input.txt $(NUM)

time:
	g++ -std=c++11 -o out sol.cpp
	time ./out input.txt