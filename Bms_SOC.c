#include <stdio.h>
#include BMS_Cfg.h

/*Function Delceration*/
int Check_SOC(float soc);
int Check_ChargeRate(float chargeRate);

/*Function returns flase if the SOC is out of range and true if its in range*/
int Check_SOC(float soc)
{
  return RangeCheck(soc,SOCMIN,SOCMAX);

}
 
/*Function returns flase if the chargeRate is out of range and true if its in range*/ 
int Check_ChargeRate(float chargeRate)
{
   if(chargeRate>CHARGERATEMAX)
   return 0;
   else
   return 1;
}
