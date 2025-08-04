CC=gcc
CFLAGS=-Wall -Wextra -Iinclude
OBJDIR=build
BINDIR=build
SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=$(OBJDIR)/%.o)
TARGET=$(BINDIR)/user_manager

all: $(TARGET)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
