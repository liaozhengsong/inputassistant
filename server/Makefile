CFLAGS = -g 
DIRS := ./src/
DIRO := ./bin/
source:= $(wildcard $(DIRS)*.cc)
obj:= $(patsubst $(DIRS)%.cc, $(DIRO)%.o,$(source))
main: $(obj)
	g++ -o $@ $^ $(CFLAGS)
$(obj): $(source)
	@$(foreach i,$(source),\
		gcc -o $(patsubst $(DIRS)%.cc,$(DIRO)%.o,$(i)) -c $(i) $(CFLAGS);\
	)
.PHONY:clean
clean:
	rm -rf $(obj) main
