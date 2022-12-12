#include <stdio.h>
#include <assert.h>

#define RangeCheck(X,Y,Z) (X<=Y || X>=Z)?0:1

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
    return RangeCheck(temperature,0 , 45);
}

 

 

int Check_SOC(float soc)
{
  return RangeCheck(soc,20, 80);

}

 
int Check_ChargeRate(float chargeRate)
{
   if(chargeRate>0.8)
   return 0;
   else
   return 1;
}

int main()
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));

}
