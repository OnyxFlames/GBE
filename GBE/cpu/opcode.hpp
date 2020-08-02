#pragma once

// https://pastraiser.com/cpu/gameboy/gameboy_opcodes.html


#include <cstdint>

// forward def

class GBState;

namespace op
{

	uint8_t nop(GBState& state);					/* 0x00 */
	uint8_t ld_bc_word(GBState& state);				/* 0x01 - BC = word */
	uint8_t ld_addr_bc_a(GBState& state);			/* 0x02 - [BC] = A */
	uint8_t inc_bc(GBState& state);					/* 0x03 - BC += 1 */
	uint8_t inc_b(GBState& state);					/* 0x04 - B += 1 */
	uint8_t dec_b(GBState& state);					/* 0x05 - B -= 1 */
	uint8_t ld_b_byte(GBState& state);				/* 0x06 - B = byte */
	uint8_t rlca(GBState& state);					/* 0x07 - Carry = (A & 0x80) >> 7, A <<= 1 */
	uint8_t ld_addr_word_sp(GBState& state);		/* 0x08 - [word] = sp */
	uint8_t add_hl_bc(GBState& state);				/* 0x09 - HL += BC */
	uint8_t ld_a_addr_bc(GBState& state);			/* 0x0A - A = [bc] */
	uint8_t dec_bc(GBState& state);					/* 0x0B - BC -= 1 */
	uint8_t inc_c(GBState& state);					/* 0x0C - C += 1 */
	uint8_t dec_c(GBState& state);					/* 0x0D - C -= 1 */
	uint8_t ld_c_byte(GBState& state);				/* 0x0E - C = byte */
	uint8_t rrca(GBState& state);					/* 0x0F - Carry = A & 0x01, A >>= 1 */
}