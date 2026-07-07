# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

# Shared core engine files (everything except the main files)
CORE_SRCS = camera.cpp ray.cpp render.cpp shape.cpp vectorOps.cpp
CORE_OBJS = $(CORE_SRCS:.cpp=.o)

# Executables
EXEC1 = demo_animation
EXEC2 = demo_stereo

# Default target builds both executables
all: $(EXEC1) $(EXEC2)

# Link the first executable
$(EXEC1): demo_animation.o $(CORE_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link the second executable
$(EXEC2): demo_stereo.o $(CORE_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic rule to compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f *.o $(EXEC1) $(EXEC2)

.PHONY: all clean
