all: mytest_runner

myrunner.cpp: mytest.h complex.cpp 	
	python3 ../cxxtest-4.4/bin/cxxtestgen --error-printer -o myrunner.cpp mytest.h

mytest_runner: myrunner.cpp 
	g++ -o mytest_runner myrunner.cpp -I../cxxtest-4.4 

run: mytest_runner
	./mytest_runner

clean:
	rm -f mytest_runner myrunner.cpp
# do make git "" add parameter String to the end of the command line
git:
	git add .
	git commit -m "$(input)"
	git push