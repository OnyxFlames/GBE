#pragma once

#include <cstdint>

#include "gb_registers.hpp"

class GBCPU
{
private:

public:
	// AF, BC, DE, HL:
	GBRegister mRegisters;

	uint16_t mProgramCounter;
	uint16_t mStackPointer;

};

