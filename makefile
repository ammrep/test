root_apps_dir := apps
apps_subdirs := echo
root_sys_dir := sys
CFLAGS = -Wall -Wextra
LFLAGS = -s -pipe

relative_apps_dirs := $(addprefix ../$(root_apps_dir)/, $(apps_subdirs))
relative_sys_dirs := $(addprefix ../, $(root_sys_dir)) 
objects_apps_dirs := $(addprefix $(root_apps_dir)/, $(apps_subdirs))
objects_sys_dirs := $(root_sys_dir)
objects_apps := $(patsubst ../%, %, $(wildcard $(addsuffix /*.cpp, $(relative_apps_dirs))))
objects_sys := $(patsubst ../%, %, $(wildcard $(addsuffix /*.cpp, $(relative_sys_dirs))))
objects := $(objects_apps) $(objects_sys)
objects := $(objects:.cpp=.o)

all: $(program_name)

$(program_name): obj_dirs $(objects)
	g++ $(objects) $(LFLAGS) ../main.cpp -o $@

obj_dirs:
	mkdir -p $(objects_apps_dirs)
	mkdir -p $(objects_sys_dirs)

VPATH := ../

%.o: %.cpp
	g++ -c $< $(CFLAGS) -o $@
 
clean:
	rm -r obj/
