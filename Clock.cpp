#include "Clock.h"

Clock::Clock() {
	this->TS = 0;
	this->H = 0;
	this->M = 0;
	this->S = 0;
	this->Overflow = 0;
}

unsigned short Clock::getHours() {
	return this->H;
}

unsigned short Clock::getMinutes() {
	return this->M;
}

unsigned short Clock::getSeconds() {
	return this->S;
}

unsigned int Clock::getUpTime() {
	return this->TS;
}

unsigned short Clock::getOverflow() {
	return this->Overflow;
}

void Clock::tick() {
	if (this->TS == 3600)
		this->TS = 0;
	this->TS++;
	this->S = this->TS % 60;
	
	
	if(this->S % 60 == 0) {
		this->M++;
		this->S = 0;
		
		if(this->M % 60 == 0) {
			this->H++;
			this->M = 0;
			
			if (this->H % 24 == 0) {
				this->Overflow++;
				this->H = 0;
			}
		}
	}
}
