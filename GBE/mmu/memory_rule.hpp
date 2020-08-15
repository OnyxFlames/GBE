#pragma once

#include <cstdint>

class MemoryDevice;

/*
	Dictates what memory region reads utilize a given device

	Used in a list of rules, iterating through while a given address isnt in range, when in range, return device to read from/write to

	TODO: Add predicate list, a list of functions that test the address value more indepth than just inRange, eg. address & 0xC000 != 0
		this will allow for more intricate memory mappers, where predicates are tested in a given rule before moving on to the next rule
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

