CXX = g++

CXXFLAGS = -lpthread -Werror

SOURCES = thread2.cpp \
	thread3.cpp \
	thread4.cpp \
	thread5.cpp \
	thread6.cpp \
	thread7.cpp \
	thread8.cpp \
	thread9.cpp \
	threads.cpp

OUTPUTS = $(SOURCES:.cpp=)

all: $(OUTPUTS)

%: %.cpp
	$(CXX) $^ -o bin/$@ $(CXXFLAGS)

clean:
	cd bin && rm -f $(OUTPUTS)
