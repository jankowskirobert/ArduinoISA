#if !defined (_ISA_LIQUID_CRYSTAL_H_)
#define _ISA_LIQUID_CRYSTAL_H_

#include <LiquidCrystal.h>

class ISALiquidCrystal : public LiquidCrystal {
public:	
	ISALiquidCrystal(void)
		: LiquidCrystal(26, 28, 29, 30, 31, 32)
	{
	}
	
	void begin(void)
	{
		LiquidCrystal::begin(16, 2);
	}
	
	//using 
};



#endif // _ISA_LIQUID_CRYSTAL_H_

