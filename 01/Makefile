all: mytest_runner

myrunner.cpp: mytest.h
	python3 ../cxxtest-4.4/bin/cxxtestgen --error-printer -o myrunner.cpp mytest.h

count_if_followed_by.o: count_if_followed_by.cpp
	g++ -c -o count_if_followed_by.o count_if_followed_by.cpp

mytest_runner: myrunner.cpp count_if_followed_by.o
	g++ -o mytest_runner myrunner.cpp -I../cxxtest-4.4 count_if_followed_by.o

run: mytest_runner
	./mytest_runner

clean:
	rm -f mytest_runner myrunner.cpp count_if_followed_by.o
