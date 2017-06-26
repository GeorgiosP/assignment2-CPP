#include <iostream>
#include <math.h>


using namespace std;
 
void _welcomeMenu(); 
double get_rate_drop_factor();
double fig_drop_min(double rateMgKg, double dropFactor);
double by_weight(float rateOfMeasure, int weightKg, int concentrationMg);
int get_problem();
int fig_ml_hr(int hours);
int get_kg_rate_conc();
int get_unit_conc();
int by_units(int unitPerHour, int consUnit);



int main(){
   
    bool keepGoing = true;

    _welcomeMenu(); 
    do{
        int menuSelection = get_problem();
        switch(menuSelection){
            case 1:{
                double calculation = get_rate_drop_factor();
            
                cout << "The drop rate per minute is:" << ceil(calculation) << endl;
                break;
                }
            case 2:{
                int hours, litersPerHour;

                cout << "Enter number of hours: ";
                cin >> hours;
                litersPerHour = fig_ml_hr(hours);
                cout << "The rate in millilitres per hour is:" << litersPerHour << endl;
                break;
            }
            case 3:{
                double rateOfMeasure = get_kg_rate_conc();

                cout << "The rate in millilitres per hour is: " << rateOfMeasure << endl;
                break;
            }
            case 4:{
                int unitTotal = get_unit_conc();

                cout << "The rate in millilitres per hour is: " << unitTotal << endl;
                break;
            }
            case 5:{
                cout << "Exiting program..." << endl;
                keepGoing = false;
            }
        }       
      
    }while(keepGoing == true);
}



void _welcomeMenu(){
    cout << "               Intravenous Rate Assistant" << endl;
}


int get_problem(){
    int choice;
    cout << R"(     Given a medical order in:		        Calculate Rate in:
    (1) ml/hr & tubing drop factor                  drops / min
    (2) 1 L for n hr                                ml / hr
    (3) mg/kg/hr & concentration in mg/ml	        ml / hr
    (4) units/hr & concentration in units/ml        ml/hr
    (5) Exit)" << endl;
    cout << "\nEnter the number of the programmme you wish to solve: ";
    cin >> choice;
    if(choice > 5 || choice < 1){
        cout << "ERROR Input Must be between 1 & 5" << endl;
        cout << "\n>> ";
        cin >> choice;
    }
    return choice;

}

double get_rate_drop_factor(){
    double rate, dropRate, dropPerMin;

    cout << "Enter rate in ml/hr: ";
    cin >> rate; 
    cout << "Enter tubing’s drop factor (drops/ml): ";
    cin >> dropRate;
    
    dropPerMin = fig_drop_min(rate, dropRate);

    return dropPerMin;
}

double fig_drop_min(double rateMgKg, double dropFactor){
    double calculatedValue; 

    calculatedValue = (rateMgKg * dropFactor) / 60; 

    return calculatedValue;
}

int fig_ml_hr(int hours){
    int perHour = 1000 / hours; 
    return perHour;
}

int get_kg_rate_conc(){
    float rateMg; 
    int concentrationMg, weight; 
    double totalMl;

    cout << "Enter rate in mg/kg/hr: ";
    cin >> rateMg; 
    cout << "Enter patient weight in kg: "; 
    cin >> weight;
    cout << "Enter concentration in mg/ml: ";
    cin >> concentrationMg;

    totalMl = by_weight(rateMg, weight, concentrationMg);
    return totalMl; 
}
int get_unit_conc(){
    int unitPerHour, consUnit, calculatedUnit;
    cout << "Enter rate in units/hr: ";
    cin >> unitPerHour;
    cout << "Enter concentration in units/ml: ";
    cin >> consUnit;

    calculatedUnit = by_units(unitPerHour, consUnit);
    return calculatedUnit;
}
double by_weight(float rateOfMeasure, int weightKg, int concentrationMg){
    double mlPerHour = (rateOfMeasure * weightKg) / concentrationMg;
    return mlPerHour;
}
int by_units(int unitPerHour, int consUnit){
    int mlByUnit; 

    mlByUnit = unitPerHour / consUnit; 
    return mlByUnit; 
}