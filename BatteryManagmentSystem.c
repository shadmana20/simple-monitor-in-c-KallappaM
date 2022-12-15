#include <stdio.h>
#include <assert.h>

/*Macro to check the minimum and maximum value of given input*/
#define RangeCheck(Input,MinValue,MaxValue) ((Input<=MinValue || Input>=MaxValue)?0:1)

/*Minimum and Maximum Ranges*/
#define TEMPMIN	0
#define TEMPMAX 45
#define SOCMIN 20
#define SOCMAX 80
#define CHARGERATEMAX 0.8

/*Function Delceration for BMS*/
int Check_Temperature(float temperature);
int Check_SOC(float soc);
int Check_ChargeRate(float chargeRate);

/*Function Returns True if the Battery is OK else return false*/
int batteryIsOk(float temperature, float soc, float chargeRate)
{
  int batterystate = 1;
  batterystate = Check_Temperature(temperature);
  batterystate *= Check_SOC(soc);
  batterystate *= Check_ChargeRate(chargeRate);

  return batterystate;
}

/*Function returns flase if the Temperature is out of range and true if Temperature is in range*/ 
int Check_Temperature(float temperature)
{
    return RangeCheck(temperature,TEMPMIN,TEMPMAX);
}

/*Function returns flase if the SOC is out of range and true if its in range*/
int Check_SOC(float soc)
{
  return RangeCheck(soc,SOCMIN,SOCMAX);

}
 
/*Function returns flase if the chargeRate is out of range and true if its in range*/ 
int Check_ChargeRate(float chargeRate)
{
   if(chargeRate > CHARGERATEMAX)
   return 0;
   else
   return 1;
}

int main()
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(batteryIsOk(44, 79, 0.7));
  assert(!batteryIsOk(46, 81, 0.8));
  assert(!batteryIsOk(0, 0, 0.7));

}
