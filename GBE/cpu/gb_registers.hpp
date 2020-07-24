#pragma once

#include <cstdint>
/*
	--------------------------------------------------
	TODO: Check if endianess matters for register banks
	--------------------------------------------------
*/
#define GB_LITTLE_ENDIAN
// #define GB_BIG_ENDIAN

struct FlagRegister
{
	union
	{
		uint8_t F;

		bool Z : 1;
		bool N : 1;
		bool H : 1;
		bool C : 1;
		bool unused : 4;
	};
	FlagRegister& operator=(const uint8_t val)
	{
		this->F = val;
		return *this;
	}
};

struct GBRegister
{
	GBRegister()
		: AF(0)
		, BC(0)
		, DE(0)
		, HL(0)
	{

	}
	union
	{
		struct
		{
#if defined(GB_LITTLE_ENDIAN)
			FlagRegister F;
			uint8_t A;
#else
			uint8_t A;
			uint8_t F;
#endif
		};
		uint16_t AF;
	};
	union
	{
		struct
		{
#if defined(GB_LITTLE_ENDIAN)
			uint8_t C;
			uint8_t B;
#else
			uint8_t B;
			uint8_t C;
#endif
		};
		uint16_t BC;
	};
	union
	{
		struct
		{
#if defined(GB_LITTLE_ENDIAN)
			uint8_t E;
			uint8_t D;
#else
			uint8_t D;
			uint8_t E;
#endif
		};
		uint16_t DE;
	};
	union
	{
		struct
		{
#if defined(GB_LITTLE_ENDIAN)
			uint8_t L;
			uint8_t H;
#else
			uint8_t H;
			uint8_t L;
#endif
		};
		uint16_t HL;
	};
};