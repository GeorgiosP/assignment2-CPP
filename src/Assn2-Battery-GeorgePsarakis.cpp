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
double recharge(battery_t battery);

int main(){
    battery_t battery;
	int timePowered;
	int chargeTime;

    battery.voltage = 12.0;
    battery.maxStorage = 5 * pow(10,6); 
    battery.currentStoredJoules = battery.maxStorage;

    cout << "The battery before subtratction: " << battery.currentStoredJoules << endl;

    battery.currentStoredJoules = power_device(battery, 900); 

    cout << "Powering a 4 amp light for 15 minites, The battery after subtraction: " << battery.currentStoredJoules << endl;

    timePowered = max_time(battery, 8);
    cout << "The 8amp device can be power for " << timePowered << " seconds" << endl;

    battery.currentStoredJoules = recharge(battery);
    
    timePowered = max_time(battery, 8);
    cout << "The 8amp device can be power for " << timePowered << " seconds after the battery is charged" << endl;



    return 0;
}

double recharge(battery_t battery){

    double whatisMax = battery.maxStorage;
    

    return whatisMax;
}
double max_time(battery_t battery, double current){
    int numberOfSeconds = battery.currentStoredJoules / current; 
    return numberOfSeconds;
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

