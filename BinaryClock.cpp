#include "BinaryClock.h"

BinaryClock::BinaryClock() {
	this->timer = new Clock();
}

BinaryClock::BinaryClock(Clock* timer) {
	this->timer = timer;
}

List* BinaryClock::getHours(){
	List* hrs = new List();
	toBinary(this->timer->getHours(), hrs);
	return hrs->revert(); // use ->revert() only with push() in toBinary()
}

List* BinaryClock::getMinutes(){
	List* min = new List();
	toBinary(this->timer->getMinutes(), min);
	return min->revert(); // use ->revert() only with push() in toBinary()
}

List* BinaryClock::getSeconds(){
	List* sec = new List();
	toBinary(this->timer->getSeconds(), sec);
	return sec->revert(); // use ->revert() only with push() in toBinary()
}

unsigned int BinaryClock::getUpTime() {
	return this->timer->getUpTime();
}

void BinaryClock::toBinary(short number, List* list){
	if (number != 0) {
		list->push(number % 2); // normally use unsihft
		this->toBinary(number / 2, list);
	}
}

void BinaryClock::tick() {
	this->timer->tick();
}

/*
char* BinaryClock::toString() {
	char* out = "Time:\n==========" +
 "\nHours:\t" + this->getHours()->toString() +
 "\nMinutes:\t" + this->getMinutes()->toString() +
 "\nSeconds:\t" + this->getSeconds()->toString();
	return out;
}*/
