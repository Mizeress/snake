CXX = g++
TARGET = snake
SRCS = src/main.cpp src/Player.cpp src/Apple.cpp
INCLUDES = includes
LINKS = -lncurses

snake: $(SRCS)
	$(CXX) $(SRCS) -I $(INCLUDES) -o $(TARGET) $(LINKS)

clean:
	rm -f $(TARGET)