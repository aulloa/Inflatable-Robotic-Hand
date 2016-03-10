
#define RightMotor 5 //The chosen pin must have PWM
#define LeftMotor 6 //The chosen pin must have PWM
#define dir 4 // Motor Direction 

#define Valve1 53//up channel
#define Valve2 52//right channel
#define Valve3 51//down channel
#define Valve4 50//left channel
#define Valve5 49//3_way valve
#define Valve6 48
#define Valve7 47

/* Define the rotational speed of the motor. MUST be between 0 and 255. */
int pulse     = 0;//Duty Cycle of motors based on position of triggers
int forward   = 0;//Boolean to determine previos direction moved
int brake_on  = 0;//Boolean to see if brake is on
int i         = 0; //Iterator
int Lpwm      = 0;//Duty Cycle for steering left
int Rpwm      = 0;// duty cycle for steering right
int SSpwm     = 0;//steady state duty cycle for all valves
int Adir      = 1;//channel selection variable based on the d pad

char  d[2] = "n";//direction string for prints
char  s[2] = "s";//direction string for prints
