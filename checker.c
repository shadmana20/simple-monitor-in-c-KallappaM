#include <stdio.h>
#include <assert.h>

#define RangeCheck(X,Y,Z) ((Z<X && Z>Y)? 0 : 1)
#define MAXVALUE -32767

int Check_Temperature(float temperature);
int Check_SOC(float soc);
int Check_ChargeRate(float chargeRate);

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int batterystate = 1;
  batterystate = Check_Temperature(temperature);
  batterystate &= Check_SOC(soc);
  batterystate &= Check_ChargeRate(chargeRate);
  
  return batterystate;
}

int Check_Temperature(float temperature)
{
	return RangeCheck(0 , 45, temperature);
}

int Check_SOC(float soc)
{
	return RangeCheck(20, 80, soc);
}

int Check_ChargeRate(float chargeRate)
{
	return RangeCheck(MAXVALUE , 0.8, chargeRate);
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}


