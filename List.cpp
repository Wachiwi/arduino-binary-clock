#include "List.h"

List::List(){
	this->list = new short[0];
	this->size = 0;
	this->max_index = -1;
}

// Add element 'value' at the end of the list
void List::push(short value) {
	short* new_array = this->grow(); // Creating array with new size
	if (this->length() > 1) { // Copy only if necessary
		this->copy(this->list,new_array);
	}
	delete this->list; // free memory of old list
	this->list = new_array; // assign new list
	this->list[this->max_index] = value; //assign value
}

// Get and remove the last element of the list
short List::pop() {
	if (this->length() == 0) {
		return 0;
	}
	
	short tmp = this->list[this->max_index];
	short* new_array = this->shrink();
	this->copy(this->list,new_array);
	
	delete this->list;
	this->list = new_array;
	return tmp;
}

// Add element 'value' at the front of the list
void List::unshift(short value) {
	short* new_array = this->grow();
	if (this->length() > 1) {
		this->copy(this->list,new_array,true);
	}
	
	delete this->list;
	this->list = new_array;
	this->list[0] = value;
}

// TODO: Shift not working, wrong way of copying
short List::shift() {
	if (this->length() == 0) {
		return 0;
	}
	
	short tmp = this->list[0];
	short* new_array = this->shrink();
	this->copy(this->list, new_array, true);
	
	delete this->list;
	this->list = new_array;
	return tmp;
}

List* List::revert() {
	short* tmp = new short[this->length()];
	for(short i = (this->max_index); i >= 0; i--) {
		tmp[this->max_index - i] = this->list[i];
	}
	delete this->list;
	this->list = tmp;
	return this;
}

/*
 * Method to reset the List to "null"
 */
void List::clear() {
	delete this->list;
	this->size = 0;
	this->max_index = -1;
	this->list = new short[0];
}

short List::length() {
	return this->size;
}

void List::copy(short* source, short* target) {
	for(short el = 0; el < this->length(); el++) {
		target[el] = source[el];
	}
}

void List::copy(short* source, short* target, bool offset) {
	for(short el = 1; el < this->length(); el++) {
		target[el] = source[el-1];
	}
}

/*
 * Method to create and return a new array of an incremented size.
 */
short* List::grow() {
	(this->size)++;
	(this->max_index)++;
	return new short[this->size];
	
}

short* List::shrink() {
	(this->size)--;
	(this->max_index)--;
	return new short[this->size];
}

/*
char* List::toString() {
 char* log = "[";
	for (short i = 0; i < this->length(); i++) {
		char* tmp;
		sprshortf(tmp, "%d", this->list[i]);
		if (i == (this->length()-1)){
			log += "\"" + tmp + "\"";
		} else {
			log += "\"" + tmp + "\",";
		}
 }
 log += "]";
 return log;
}*/
