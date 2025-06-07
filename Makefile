build-mac:
	clang++ *.cpp -std=c++17 -o ./bin/output

run-mac:
	./bin/output

build-and-run-mac: build-mac run-mac

debug-mac:
	clang++ -g *.cpp -std=c++17 -o ./debug/output
	lldb ./debug/output

build-linux: 
	g++ -I . *.cpp -std=c++17 -o ./bin/output

run-linux:
	./bin/output

build-and-run-linux: build-linux run-linux

debug-linux:
	g++ -g -I . *.cpp -std=c++17 -o ./debug/output