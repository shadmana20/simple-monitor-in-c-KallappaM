#include <stdio.h>
#include <assert.h>
#include <BMS_Cfg.h>

/*Function Returns True if the Battery is OK else return false*/
int batteryIsOk(float temperature, float soc, float chargeRate)
{
  int batterystate = 1;
  batterystate = Check_Temperature(temperature);
  batterystate &&= Check_SOC(soc);
  batterystate &&= Check_ChargeRate(chargeRate);

  return batterystate;
}

/*Function returns flase if the Temperature is out of range and true if Temperature is in range*/ 
int Check_Temperature(float temperature)
{
    return RangeCheck(temperature,TEMPMIN,TEMPMAX);
}

int main()
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(batteryIsOk(44, 79, 0.7));
  assert(!batteryIsOk(46, 81, 0.8));
  assert(!batteryIsOk(0, 0, 0.7));

}
