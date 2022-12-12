#include <stdio.h>
#include <assert.h>
typedef unsigned char  boolean;
#define RangeCheck(X,Y,Z) ((Z<X || Z>Y)? 0 : 1)
#define MAXVALUE -32767

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  boolean batterystate = 1;
  batterystate = Check_Temperature(temperature);
  batterystate = Check_SOC(soc);
  batterystate = Check_ChargeRate(chargeRate);
  
  return batterystate;
}

boolean Check_Temperature(float temperature)
{
	return RangeCheck(0 , 45, temperature);
}

boolean Check_SOC(float soc)
{
	return RangeCheck(20, 80, soc);
}

boolean Check_ChargeRate(float chargeRate)
{
	return RangeCheck(MAXVALUE , 0.8, chargeRate);
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
