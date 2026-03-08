#pragma once
#include <cstdint>
#include <memory>

#include "olcPixelGameEngine.h"

#include "Cartridge.h"

class olc2C02
{
public:
	olc2C02();
	~olc2C02();

private:
	uint8_t nameTable[2][1024];
	uint8_t	tblPalette[32];
	uint8_t tblPattern[2][4096]; //no use for general working of the emu




public:
	uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);
	void cpuWrite(uint16_t addr, uint8_t data);


	uint8_t ppuRead(uint16_t addr, bool bReadOnly = false);
	void ppuWrite(uint16_t addr, uint8_t data);

private:
	std::shared_ptr<Cartridge> cart;

public:
	void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void clock();

private:
	olc::Pixel  palScreen[0x40];
	olc::Sprite* sprScreen;
	olc::Sprite* sprNameTable[2];
	olc::Sprite* sprPatternTable[2];

public:
	// Debugging Utilities
	olc::Sprite& GetScreen();
	olc::Sprite& GetNameTable(uint8_t i);
	olc::Sprite& GetPatternTable(uint8_t i, uint8_t palette);
	olc::Pixel& GetColourFromPaletteRam(uint8_t palette, uint8_t pixel);
	bool frame_complete = false;

private:
	int16_t scanline = 0; //row
	int16_t cycle = 0; //col

};

