#ifndef _CLOCK_H_
#define _CLOCK_H_

class Clock {

private:

	unsigned int TS;
  unsigned short H;
  unsigned short M;
  unsigned short S;
  unsigned short Overflow;

public:
	Clock();
	Clock(short, short, short);

  void tick();

  unsigned short getHours();
  unsigned short getMinutes();
  unsigned short getSeconds();
  unsigned int getUpTime();
  unsigned short getOverflow();
};

#endif
