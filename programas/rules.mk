CXX = g++

all: $(addprefix bin/,$(SOURCES:.cpp=))

clean:
	-@rm -rf bin

bin/%: %.cpp bin 
	$(CXX) $< -o $@ $(CXXFLAGS)

bin:
	-@mkdir bin
