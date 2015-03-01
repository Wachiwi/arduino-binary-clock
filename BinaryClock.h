#ifndef _BINARY_CLOCK_H_
#define _BINARY_CLOCK_H_

#include "Clock.h"
#include "List.h"

class BinaryClock : public Clock {

private:

  Clock* timer;
  void toBinary(short, List*);

public:

	BinaryClock();
	BinaryClock(Clock*);

	List* getHours();
  List* getMinutes();
  List* getSeconds();

  unsigned int getUpTime();
  //unsigned int* getOverflow();

  //List* getHours(Clock*);
  //List* getMinutes(Clock*);
  //unsigned short* getSeconds(Clock&);
  //unsigned long* getUpTime(Clock&);
  //unsigned int* getOverflow(Clock*);

	void tick();
	char* toString();
};

#endif
