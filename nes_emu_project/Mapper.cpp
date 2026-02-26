#include "Mapper.h"

//abstract class for all other types of mappers
Mapper::Mapper(uint8_t prgBanks, uint8_t chrBanks)
{
	nPRGBanks = prgBanks;
	nCHRBanks = chrBanks;
}


Mapper::~Mapper()
{
}