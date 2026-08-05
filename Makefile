# --- Compilers ---

CXX       := clang
CXXFLAGS  := -Wall -Wextra -O2
AR        := ar
ARFLAGS   := rcs

# --- Source Layout ---
LIB_SRC       := src
LIB_SRC_FILES := $(LIB_SRC)/uninstall-me.c
LIB_OBJ       := $(LIB_SRC)/uninstall-me.o
LIB_OUT       := libuninstall-melib.a

# LICENSE := LICENSE

# --- Install paths ---
PREFIX      := /usr/local
LIB_DIR     := $(PREFIX)/lib
INCLUDE_DIR := $(PREFIX)/include

# --- Targets ---
.PHONY: all install uninstall clean

all: $(LIB_OUT) $(TARGET)

# --- Compile library object ---
$(LIB_OBJ): $(LIB_SRC_FILES)
	$(CXX) $(CXXFLAGS) -I$(LIB_SRC) -c $< -o $@

$(LIB_OUT): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^

# --- Install ---
install: all
	install -Dm644 $(LIB_OUT)    $(DESTDIR)$(LIB_DIR)/$(LIB_OUT)

# --- Uninstall ---
uninstall: all
	rm -r $(DESTDIR)$(LIB_DIR)/$(LIB_OUT)

clean:
	rm -r $(LIB_OBJ) $(LIB_OUT)
