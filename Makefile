build-mac:
	clang++ *.cpp -std=c++17 -o ./bin/output

run-mac:
	./bin/output

build-and-run-mac: build-mac run-mac

debug-mac:
	clang++ -g *.cpp -std=c++17 -o ./debug/output
	lldb ./debug/output