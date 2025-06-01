build-mac:
	clang++ *.cpp -o ./bin/output

run-mac:
	./bin/output

build-and-run-mac: build-mac run-mac

debug-mac:
	clang++ -g *.cpp -o ./bin/debug
	lldb ./debug/output