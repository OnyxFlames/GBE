#pragma once

#include <cstdint>

class MemoryDevice
{
public:
	virtual uint8_t read(uint16_t address) = 0;
	virtual void write(uint16_t address, uint8_t byte) = 0;

	virtual ~MemoryDevice() { }
};

