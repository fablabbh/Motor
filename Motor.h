/*
	Motor - a small library for Arduino to handle motor control using L298 HBridge
	
	MIT licensed.
*/

#ifndef Motor_h
#define Motor_h
#include "Arduino.h"

class Motor {

private:

	// This Is The Control, Enable Pins
	uint8_t _ena_pin    = 0;
	uint8_t _in1_pin    = 0;
	uint8_t _in2_pin    = 0;

	// Set Speed Data
	uint8_t _speed      = 0;
	uint8_t _min_speed  = 0;
	uint8_t _max_speed  = 255;

	// Invert The Direction
	bool    _invert     = false;

public:

	// Constructor With Parameter
	Motor(uint8_t enable, uint8_t in1, uint8_t in2);

	// Set The Starting Parameters
	void begin();

	// Set Minimum Speed
	void setMin(uint8_t value);

	// Set Maximum Speed
	void setMax(uint8_t value);

	// Invert Motor Direction
	void invert();

	// Move Forword
	void forward();

	// Move Backword
	void backward();

	// Motor Speed
	void goMin();

	// Motor Speed
	void goMax();

	// Motor Speed
	void goSpeed(uint8_t speed);

	// Press Break
	void stop();

	// Command By Serial
	unsigned int command(Stream &serial);

};

#endif
