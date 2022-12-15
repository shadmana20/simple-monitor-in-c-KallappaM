
/*Macro to check the minimum and maximum value of given input*/
#define RangeCheck(Input,MinValue,MaxValue) ((Input<=MinValue || Input>=MaxValue)?0:1)

/*Minimum and Maximum Ranges*/
#define TEMPMIN	0u
#define TEMPMAX 45
#define SOCMIN 20
#define SOCMAX 80
#define CHARGERATEMAX 0.8u

/*Function Delceration for BMS*/
int Check_Temperature(float temperature);
int Check_SOC(float soc);
int Check_ChargeRate(float chargeRate);