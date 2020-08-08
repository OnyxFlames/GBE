#include "memory_rule.hpp"

#include <cassert>

MemoryRule::MemoryRule(const uint16_t start, const uint16_t end, const uint16_t offset, MemoryDevice* device)
	:	mRangeStart(start)
	,	mRangeEnd(end)
	,	mOffset(offset)
	,	mDevice(device)
{
	assert(start <= end);
	assert(device != nullptr);
}

uint16_t MemoryRule::getStart() const
{
	return mRangeStart;
}

uint16_t MemoryRule::getEnd() const
{
	return mRangeEnd;
}

uint16_t MemoryRule::getOffset() const
{
	return mOffset;
}

MemoryDevice* MemoryRule::getDevice() const
{
	return mDevice;
}

bool MemoryRule::inRange(const uint16_t value) const
{
	return (value >= mRangeStart && value <= mRangeEnd);
}
