#ifndef _LIST_H_
#define _LIST_H_

class List {

private:

  short* list;
  short size;
	short max_index;

  void copy(short*, short*);
  void copy(short*, short*, bool);
  short* grow();
  short* shrink();

public:

  List();

  void push(short);
  short pop();
  short shift();
  void unshift(short);
  char* toString();
  short length();
	void clear();
	List* revert();
};

#endif
