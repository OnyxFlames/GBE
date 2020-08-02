#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace disasm
{
	// core of the disassembler, turn a byte sequence into a readable string
	std::string to_string(const std::vector<uint8_t>& bytes);
}

class Disassembler
{
};

