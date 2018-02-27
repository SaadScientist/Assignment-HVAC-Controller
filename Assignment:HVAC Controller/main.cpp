//  Assignment:HVAC Controller

#include <iostream>
using namespace std;


int main() {
     enum HvacStatus {HVAC_OFF, AC_ON, FURNACE_ON};
    
    HvacStatus status = HVAC_OFF;

    int zone1Temp = 75, zone1Thermo = 75, zone2Temp = 80, zone2Thermo = 80;
    bool zone1DamperOpen = false, zone2DamperOpen = false;
  
    
    int input = -1;
    while (input != 0)
     {
         //Print Status and Menu
         
         cout << "Status: " << endl;
         
         if (status == 0) {
             cout << "HVAC OFF" << endl;
         }
         else if(status == 1){
             cout << "AC ON" << endl;
         }
         else if (status == 2){
             cout << "FURNACE ON";
             cout << endl;
         }
         
         //Diplaying True and false in CLOSED and OPEN
         if (zone1DamperOpen == 0 && zone2DamperOpen == 0) {
             cout << "Zone 1 damper is CLOSED" << endl;
             cout << "Zone 2 damper is CLOSED" << endl;
         }else if(zone1DamperOpen ==1 && zone2DamperOpen ==1){
             cout << "Zone 1 damper is OPEN" << endl;
             cout << "Zone 2 damper is OPEN" << endl;
         }else if (zone1DamperOpen == 0 && zone2DamperOpen == 1){
             cout << "Zone 1 damper is CLOSED" << endl;
             cout << "Zone 2 damper is OPEN" << endl;
         }else if (zone1DamperOpen == 1 && zone2DamperOpen == 0){
             cout << "Zone 1 damper is OPEN" << endl;
             cout << "Zone 2 damper is CLOSED" << endl;
         }
         cout << "Zone 1 temperature: " << zone1Temp << endl;
         cout << "Zone 2 temperature: " << zone2Temp << endl;
         cout << "Enter a menu choice: " << endl;
         cout << "0)  Quit " << endl;
         cout << "1)  Set thermostats " << endl;
         cout << "2)  Wait 1 turn " << endl;
         cout << "3)  Wait 10 turns " << endl;
        cin >> input;
        switch(input)
        {
            case 0:
                //quit the program
                break;
                
            case 1:
                
                cout << "Set the thermostat for zone 1: " << endl;
                cin >> zone1Thermo;
                cout << "Set the thermostat for zone 2: " << endl;
                cin >> zone2Thermo;
                break;
                
            case 2:
                
                if (zone1DamperOpen == true) {
                    if (status == AC_ON) {
                        --zone1Temp;
            
                    }if (status == FURNACE_ON) {
                        ++zone1Temp;
                        
                    }
                }
                  if (zone2DamperOpen == true) {
                    if (status == AC_ON) {
                        --zone2Temp;
                    }if (status == FURNACE_ON) {
                        ++zone2Temp;
                    }
                }
                break;
                
            case 3:
                
                for (int i = 0; i < 10; i++) {
                    if (zone1DamperOpen && zone1Temp != zone1Thermo) {
                        if (status == AC_ON) {
                            --zone1Temp;
                        }if (status == FURNACE_ON) {
                            ++zone1Temp;
                        }
                    }
                      if (zone2DamperOpen && zone2Temp != zone2Thermo) {
                        if (status == AC_ON) {
                            --zone2Temp;
                        }if (status == FURNACE_ON) {
                            ++zone2Temp;
                        }
                    }
                }
                
                break;

        }
        
        //Setting the dampers
         if ((zone1Thermo < zone1Temp) || (zone2Thermo < zone2Temp)) {
             status = AC_ON;
             zone1DamperOpen = true;
             zone2DamperOpen = true;
           
             if (zone1Thermo == zone1Temp) {
                 zone1DamperOpen = false;
                 
             }if (zone2Thermo == zone2Temp) {
                 zone2DamperOpen = false;
              
             }
         }
         else if ((zone1Thermo > zone1Temp) || (zone2Thermo > zone2Temp)){
             status = FURNACE_ON;
             zone1DamperOpen = true;
             zone2DamperOpen = true;
            
             if (zone1Thermo == zone1Temp) {
                 zone1DamperOpen = false;
                 
             }
             if (zone2Thermo == zone2Temp) {
                 zone2DamperOpen = false;
                 
             }
             
         }
          else {
             status = HVAC_OFF;
             zone1DamperOpen = false;
             zone2DamperOpen = false;
         }

         
    }   //end while loop

    return 0;
}

 
    
   








