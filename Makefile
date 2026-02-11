CXX = g++
TARGET = snake
SRCS = src/main.cpp src/Player.cpp src/Apple.cpp
INCLUDES = includes

LIBS = -lncurses -lpthread -lm -ldl 

snake: $(SRCS)
	$(CXX) $(SRCS) -I $(INCLUDES) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)