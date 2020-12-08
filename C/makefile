
src = $(wildcard src/*.c)
obj = $(src:.c = .o)

CXXFLAGS = -g -Wall

exe: $(obj)
	$gcc -o $@ $^ $(CXXFLAGS)

clean:
	rm -rf *o exe
