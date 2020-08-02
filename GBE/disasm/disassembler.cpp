#include "disassembler.hpp"

#include <iomanip>
#include <cassert>
#include <sstream>


namespace disasm
{
#define WRITE_BYTE std::setw(2) << std::setfill('0') << std::hex
#define WRITE_WORD std::setw(4) << std::setfill('0') << std::hex
#define WORD_BYTES (bytes[2] << 8 | bytes[1])
#define WRITE_WORD_BYTES WRITE_WORD << WORD_BYTES

	std::string to_string(const std::vector<uint8_t>& bytes)
	{
		assert(bytes.size() > 0 && "Need bytes to disassemble");

		std::ostringstream oss;

		const uint8_t byte = bytes[0];

		switch (byte)
		{
		case 0x00: oss << "NOP"; break;
		case 0x01: oss << "LD BC, $" << WRITE_WORD << WORD_BYTES; break;
		case 0x02: oss << "LD (BC), A"; break;
		case 0x03: oss << "INC BC"; break;
		case 0x04: oss << "INC B"; break;
		case 0x05: oss << "DEC B"; break;
		case 0x06: oss << "LD B, $" << WRITE_BYTE << bytes[1]; break;
		case 0x07: oss << "RCLA"; break;
		case 0x08: oss << "LD ($" << WRITE_WORD << WORD_BYTES << "), SP"; break;
		case 0x09: oss << "ADD HL, BC"; break;
		case 0x0A: oss << "LD A, BC"; break;
		case 0x0B: oss << "DEC BC"; break;
		case 0x0C: oss << "INC C"; break;
		case 0x0D: oss << "DEC C"; break;
		case 0x0E: oss << "LD C, $" << WRITE_BYTE << (uint16_t)bytes[1]; break;
		case 0x0F: oss << "RRCA"; break;

		case 0x10: oss << "STOP"; break;
		case 0x11: oss << "LD DE, $" << WRITE_WORD << WORD_BYTES; break;
		case 0x12: oss << "LD (DE), A"; break;
		case 0x13: oss << "INC DE"; break;
		case 0x14: oss << "INC D"; break;
		case 0x15: oss << "DEC D"; break;
		case 0x16: oss << "LD D, $" << WRITE_BYTE << bytes[1]; break;
		case 0x17: oss << "RLA"; break;
		case 0x18: oss << "JR $" << WRITE_BYTE << (int16_t)bytes[1]; break;
		case 0x19: oss << "ADD HL, DE"; break;
		case 0x1A: oss << "LD A, (DE)"; break;
		case 0x1B: oss << "DEC DE"; break;
		case 0x1C: oss << "INC E"; break;
		case 0x1D: oss << "DEC E"; break;
		case 0x1E: oss << "LD E, $" << WRITE_BYTE << (uint16_t)bytes[1]; break;
		case 0x1F: oss << "RRA"; break;
		}



		return oss.str();
	}

}

