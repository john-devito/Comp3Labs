//
//  main.cpp
//  lab3
//Create a project called lab3 (if using Visual Studio), and a source file called lab3.cpp.
/*Create a Mass class that internally stores a mass in drams1. Create mutator member functions named
setMassAvoirdupoisPounds, setMassTroyPounds, and setMassMetricGrams that take
an input mass in the specified mass system, convert the mass to drams, and store that mass in the class
member variable. Also, create three accessor functions that return the stored mass in each of the three
systems. Write a main function to test your class. Your program should perform error checks on all
inputs.
Use the following equations to convert between the three mass systems:
• 1 dram = 1.7718451953125 grams
• 1 dram = 1/256 Avoirdupois pound2
• 1 dram = 1/96 Troy (apothecaries) pound3
The output of your program should look something like the following:*/
//  Created by John DeVito on 9/23/24.
//

//lab3
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
const double dramToGram = 1.7718451953125;
const double dramToAoirupoisPound = 1.0 / 256;
const double dramToTroyPound = 1.0 / 96;

class Mass
{
private:
double massInDram;

public:
void setMassAvoirdupoisPounds(double pound)
{
  if(pound >= 0)
  {
    massInDram = pound / dramToAoirupoisPound;
  }else
  {
     cout << "Error. It must be non negative." << endl;
  }

}
void setMassTroyPounds(double pound)
{
  if(pound >= 0)
  {
    massInDram = pound / dramToTroyPound;
  }else{
    cout << "Error. It must be non negative." << endl;
  }
}
void setMassMetricGrams(double gram)
{
  if(gram >= 0)
  {
    massInDram = gram / dramToGram;
  }else{
    cout << "Error. It must be non negative." << endl;
  }
}

double getMassAvoirdupoisPounds()
    {
        return massInDram * dramToAoirupoisPound ;
    }

    double getMassTroyPounds()
    {
        return massInDram * dramToTroyPound;
    }

    double getMassMetricGrams()
    {
        return massInDram * dramToGram ;
    }


};

int main()
{
    int choice;
    double mass;
    Mass cMass;
    
    do {
        do {
            cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
            cin >> choice;
            if (cin.fail() || choice < 0 || choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (choice < 0 || choice > 3);
        
        if (choice == 0) {
            cout << "Thanks for using the mass conversion program!";
            exit(0);
        }

        if (choice == 1) {
            do {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a mass in Avoirdupois pounds: ";
                cin >> mass;
            } while (cin.fail());
            
            cMass.setMassAvoirdupoisPounds(mass);  //set only Avoirdupois pounds
        }
        
        if (choice == 2) {
            do {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a mass in Troy pounds: ";
                cin >> mass;
            } while (cin.fail());
            
            cMass.setMassTroyPounds(mass);  //set only Troy pounds
        }
        
        if (choice == 3) {
            do {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a mass in grams: ";
                cin >> mass;
            } while (cin.fail());
            
            cMass.setMassMetricGrams(mass);  //set only Metric Grams
        }
                
        cout << "Mass in Avoirdupois pounds is " << cMass.getMassAvoirdupoisPounds() << endl;
        cout << "Mass in Troy pounds is " << cMass.getMassTroyPounds() << endl;
        cout << "Mass in grams is " << cMass.getMassMetricGrams() << endl;
    
    } while (choice != 0);
}
