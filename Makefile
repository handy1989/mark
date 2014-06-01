OBJECT=mark
all:$(OBJECT)

mark:main.cpp handlers.cpp io.cpp
	g++ -o $@ $^

clean:
rm -f $(OBJECT) *.o
