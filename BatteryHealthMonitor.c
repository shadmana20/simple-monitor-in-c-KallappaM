#include "BatteryManagmentSystem.h"

#define TOLERENCEVALUE 5

struct 
{
	int DrainRange;
	int PeakRange;
}descharge_range;

WarningRanges ReturnSocBreach(int soc);
WarningRanges ReturnSocWarning(int soc);

int SocRangeCheck(int soc, int MinRange, int MaxRange)
{
	if(soc <= MinRange)
	{
		return 1;
	}
	else if(soc>=MaxRange)
	{
		return 0;
	}
	
}

void CalculateDrianPeakThreshold(int MinThreshold , int MaxThreshold)
{
    int Value = (int)((TOLERENCEVALUE*MaxThreshold)/100);
    
     descharge_range.DrainRange = MinThreshold + Value;
     descharge_range.PeakRange  = MaxThreshold - Value;
}

WarningWithTolerance PreWarningIndicatorMessage(int input, int MinThreshold , int MaxThreshold )
{   

    CalculateDrianPeakThreshold(MinThreshold , MaxThreshold);
	
    if(input <= descharge_range.DrainRange)	    
    {
        return Approaching_Discharge;
    }
 
    if( input>= descharge_range.PeakRange)
    {
        return Approaching_Peak;
    }
}

WarningRanges BatteryHelathMonitor(int soc)
{  
    switch(soc)
    {
    case 0 ... 20:  
    case 81 ... 100:	
    return ReturnSocBreach(soc);
    break;
    case 21 ...24:
    case 25 ... 75:        
    case 76 ... 80:        
    return ReturnSocWarning(soc);
    break;
    default:
    return SOC_UNDEFINED;
    break;
            
    }
}

WarningRanges ReturnSocBreach(int soc)
{
	 
	if(SocRangeCheck(soc, 20, 81) == 1)
	{
		return LOW_SOC_BREACH;
	}
	else
	{
		return HIGH_SOC_BREACH;
	}
	
}

WarningRanges ReturnSocWarning(int soc)
{
	
	WarningRanges Returnstaus = SOC_NORMAL;
	
	if(SocRangeCheck(soc, 24, 76) == 1)
	{
		Returnstaus = LOW_SOC_WARNING;
	}
	else
	{
		Returnstaus = HIGH_SOC_WARNING;
	}
	
	return Returnstaus;
	
}
