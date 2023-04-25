
bintree: compil.cpp bintree.h
	g++ -o compil compil.cpp

balance : testbalance.cpp bintree.h
	g++ -o testbalance testbalance.cpp
	
testbalance : balance
	./testbalance

all: bintree tests

myrunner.cpp: mytest.h bintree.h
	python3 ../cxxtest-4.4/bin/cxxtestgen --error-printer -o myrunner.cpp mytest.h

mytest_runner: myrunner.cpp 
	g++ -o mytest_runner myrunner.cpp -I../cxxtest-4.4 

tests: mytest_runner
	./mytest_runner

clean:
	rm -f mytest_runner myrunner.cpp
# do make git "" add parameter String to the end of the command line
git:
	git add .
	git commit -m "$(input)"
	git push