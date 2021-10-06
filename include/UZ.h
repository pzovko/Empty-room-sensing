#define UZ_pin_trig   3
#define UZ_pin_echo  2

#define GETDIST(time) (time*0.017)

void InitUZ();
void UZ_interrupt();
void UZ_disable();
unsigned long UZ_measure();