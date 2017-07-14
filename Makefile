BIN_DIR := bin/
OBJ_DIR := obj/
SRC_DIR := 
INC_DIR := ./
APP_SRCS_C := $(wildcard $(SRC_DIR)*.c)
APP_SRCS_CXX := $(wildcard $(SRC_DIR)*.cpp)
APP_OBJS := $(addprefix $(OBJ_DIR), $(APP_SRCS_C:%.c=%.c.o) \
			$(APP_SRCS_CXX:%.cpp=%.cpp.o))
APP_EXE := $(BIN_DIR)Chess.exe

CPPFLAGS := -MMD -MP -std=c++11 -g
LFLAGS := 
IFLAGS := -I $(INC_DIR)

default: $(APP_EXE)

$(APP_EXE): $(APP_OBJS)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CFLAGS) $(IFLAGS) $(APP_OBJS) -o $@ $(LFLAGS)

# assembly
$(OBJ_DIR)%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(OBJ_DIR)%.c.o: %.c	
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(OBJ_DIR)%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BIN_DIR) $(OBJ_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p