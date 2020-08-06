#pragma once

/*
	State representing an instance of a running Gameboy (color)
	Contains the CPU, the MMU, the PPU, and the APU -  is utilized by the application class
*/

#include "cpu/gb_cpu.hpp"
// #include "mmu/gb_mmu.hpp"
// #include "ppu/gb_ppu.hpp"

class GBMMU; // memory
class GBPPU; // picture
class GBAPU; // audio

class GBState
{
private:
	GBCPU& mCPU;
	GBMMU& mMMU;
	GBPPU& mPPU;
	GBAPU& mAPU;

public:

};

