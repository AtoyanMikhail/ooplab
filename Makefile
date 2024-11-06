CC := g++
CXXFLAGS := -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wconversion -Weffc++ -Wfloat-equal -fstack-protector-strong -fPIE -pie -O2 -g -fsanitize=address -fsanitize=undefined -fno-strict-aliasing -DDEBUG -fvisibility=hidden
LIBS := 
SRC_DIR := source
INCDIR := include
OBJDIR := obj

SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')

OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

EXECUTABLE := sea_battle

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $^ -o $@ $(LIBS)


$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR) $(EXECUTABLE)

.PHONY: all clean docs
