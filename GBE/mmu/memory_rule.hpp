#pragma once

#include <cstdint>

class MemoryDevice;

/*
	Dictates what memory region reads utilize a given device

	Used in a list of rules, iterating through while a given address isnt in range, when in range, return device to read from/write to
*/

class MemoryRule
{
private:
	MemoryDevice* const mDevice;
	const uint16_t mRangeStart;
	const uint16_t mRangeEnd;
	const uint16_t mOffset;

public:
	MemoryRule(const uint16_t start, const uint16_t end, const uint16_t offset, MemoryDevice* device);

	uint16_t getStart() const;
	uint16_t getEnd() const;
	uint16_t getOffset() const;
	MemoryDevice* getDevice() const;

	bool inRange(const uint16_t value) const;
};

