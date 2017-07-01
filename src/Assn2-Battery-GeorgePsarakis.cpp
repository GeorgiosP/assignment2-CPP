#include <iostream>
#include <math.h>

using namespace std;

struct battery_t {
    double voltage; 
    double maxStorage;
    double currentStoredJoules;
};

double amps = 3.5; 
double lightAmp = 4.0;

double power_device(battery_t battery, int seconds);
double max_time(battery_t, double); 
double recharge(battery_t battery, int seconds);

int main(){
    battery_t battery;
	int timePowered;
	int chargeTime;

    battery.voltage = 12.0;
    battery.maxStorage = 5000; 
    battery.currentStoredJoules = battery.maxStorage;

    cout << "The battery before subtratction: " << battery.currentStoredJoules << endl;

    battery.currentStoredJoules = power_device(battery, 900); 

    cout << "The battery after subtraction: " << battery.currentStoredJoules << endl;

    return 0;
}   
double power_device(battery_t battery, int seconds){
    
    double calc;

    if(battery.currentStoredJoules - (lightAmp * seconds) <= 0.00){
        cout << "Battery is dead... please recharge it." << endl;
        
    }
    else{
        cout << "Battery can power it removing energy from the battery" << endl;
        calc = battery.currentStoredJoules - (lightAmp * seconds);
        return calc;
    }

}

double max_time(battery_t battery){

}