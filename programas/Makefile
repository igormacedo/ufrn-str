SUBDIRS = alocacao \
		  prioridade \
		  processos \
		  sinais \
		  tempo \
		  thread

all: $(addprefix make_,$(SUBDIRS))

clean: $(addprefix clean_,$(SUBDIRS))

make_%: %
	@cd $* && $(MAKE) all

clean_%: %
	@cd $* && $(MAKE) clean
