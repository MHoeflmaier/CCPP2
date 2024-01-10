CXXFLAGS=-MMD -MP -g -Wall -fsanitize=address
CC=$(CXX)

PROGRAMS=programm
OBJECTS=connection.o type.o gate.o fanout.o

ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

programm: $(OBJECTS)

clean:
	-rm -f $(ALLOBJECTS) $(ALLOBJECTS:%.o=%.d) $(PROGRAMS)

-include $(ALLOBJECTS:%.o=%.d)
