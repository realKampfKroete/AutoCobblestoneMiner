#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <math.h>
#include <cmath>

#define SCROLLUP 120
#define SCROLLDOWN -120
using namespace std;



//global var
int Timer = 1000; //Timer
double TimerEquation; //ist wert von Timer in Sekunden oder Minuten
int Slot = 0; //var used to switch through "SLOTS" in Minecraft inventory and cases in code
int exSeconds; // extra seconds
string ON_OFF = "waiting"; // used to start, end or edit application
string MinSec;// "Seconds" or " Minutes" depending on how long timer is
string optAnd; // optional "and" depending how long the timer is
string optSeconds; // optional "seconds" depending on how long the timer is
string exSecondsString; // variable into string
string optAndString; // variable into string
string optSecondsString; // variable into string
string optZusammenString; // compilation of short strings

string pickaxe; // material of pickaxe
bool pickON_OFF = false; // used in while loop to keep asking pickaxe material
float pickSpeed = 0; // var used to determine -> mined blocks per second
float pickDur = 0; // pickaxe durability, used to determnine -> how long until pickaxe breaks
float efficiency = 9; // efficiency enchantment, used to determnine -> blocks per seconds
double damage = 0; // speedMultiplier; used how long a block takes to brake -> nlocks per second
int pickID = 0;

bool Edit = true; // to allow edit

int slotStart; // the slot with first pickaxe
int slotEnd; // the slot with the last pickaxe
bool slotWahl = false; // to detect if slots did get an var

int TimerTimes2 = Timer * 2;
float TimerMultiplier;

int old_clock; // 10% from Timer

int efficiencyINT;

void TimerCalc() { //function to decide wheter secconds or minutes
    if (efficiency == 0) {
        TimerMultiplier = 1.85;
    }
    else if (efficiency >= 1) {
        TimerMultiplier = 1.5;
    }

    switch (pickID)
    {
    case 1: //wood
        switch (efficiencyINT)
        {
        case 0:
            TimerMultiplier = TimerMultiplier * 1.1008;
            break;
        case 1:
            TimerMultiplier = TimerMultiplier * 1.32;
            break;
        case 2:
            TimerMultiplier = TimerMultiplier * 1.175;
            break;

        case 3:
            TimerMultiplier = TimerMultiplier * 1.59;
            break;

        case 4:
            TimerMultiplier = TimerMultiplier * 1.725;
            break;

        case 5:
            TimerMultiplier = TimerMultiplier * 2.15;
            break;

        }
        break;

    case 2: //stone
        switch (efficiencyINT)
        {
        case 0: TimerMultiplier = TimerMultiplier * 1.06;
            break;

        case 1:
            TimerMultiplier = TimerMultiplier * 1.06;
            break;

        case 2:
            TimerMultiplier = TimerMultiplier * 1.419;
            break;

        case 3:
            TimerMultiplier = TimerMultiplier * 1.592;
            break;

        case 4:
            TimerMultiplier = TimerMultiplier * 2.17;
            break;

        case 5:
            TimerMultiplier = TimerMultiplier * 1.8;
            break;
        }

    case 3: //iron
        switch (efficiencyINT)
        {
        case 0:
            TimerMultiplier = TimerMultiplier * 1.0587;
            break;

        case 1:
            TimerMultiplier = TimerMultiplier * 1.253;
            break;

        case 2:
            TimerMultiplier = TimerMultiplier * 1.245;
            break;

        case 3:
            TimerMultiplier = TimerMultiplier * 1.66;
            break;

        case 4:
            TimerMultiplier = TimerMultiplier * 2.21;
            break;

        case 5:
            TimerMultiplier = TimerMultiplier * 1.814;
            break;
        }

    case 4: //diamond
        switch (efficiencyINT)
        {
        case 0:
            TimerMultiplier = TimerMultiplier * 0.902; //0.873327
            break;

        case 1:
            TimerMultiplier = TimerMultiplier * 1.08150359;//1.0860359 //1.07710359 ///1.07710359 //1.07697859 //1.07649526 //1.07749526; 
            break;

        case 2:
            TimerMultiplier = TimerMultiplier * 0.9628;
            break;

        case 3:
            TimerMultiplier = TimerMultiplier * 0.8304;
            break;

        case 4:
            TimerMultiplier = TimerMultiplier * 1.104;
            break;

        case 5:
            TimerMultiplier = TimerMultiplier * 0.7386;
            break;
        }
    
    case 5: //netherite
        switch (efficiencyINT)
        {
        case 0:
            TimerMultiplier = TimerMultiplier * 1.10; //0.873327
            break;

        case 1:
            TimerMultiplier = TimerMultiplier * 1.40495467;
            break;

        case 2:
            TimerMultiplier = TimerMultiplier * 0.98;
            break;

        case 3:
            TimerMultiplier = TimerMultiplier * 0.8304;
            break;

        case 4:
            TimerMultiplier = TimerMultiplier * 1.104;
            break;
        case 5:
            TimerMultiplier = TimerMultiplier * 1.1079;
            break;
        }

    case 6: //gold
        switch (efficiencyINT)
        {
        case 0:
            TimerMultiplier = TimerMultiplier * 1.10;
            break;

        case 1:
            TimerMultiplier = TimerMultiplier * 1.5;
            break;

        case 2:
            TimerMultiplier = TimerMultiplier * 1.627;
            break;

        case 3:
            TimerMultiplier = TimerMultiplier * 1.97;
            break;

        case 4:
            TimerMultiplier = TimerMultiplier * 1.97;
            break;

        case 5:
            TimerMultiplier = TimerMultiplier * 2.5;
            break;
        }

    default:
        break;
    }


    TimerTimes2 = Timer * TimerMultiplier;


    if (TimerTimes2 >= 60000) {
        (TimerEquation = TimerTimes2 / 60000);
    }
    else {
        TimerEquation = (TimerTimes2 / 1000.00);
    }
}

void fMinSec() { //function to print out seconds or Minutes

    if (TimerTimes2 >= 60000) {
        MinSec = " Minutes";
    }
    else {
        MinSec = " Seconds";
    }
}

void optSecondsf() { // makes string based on TimerCalc and fMinSec

    if (exSeconds > 0 && TimerTimes2 > 60000) {
        ostringstream optSecondsString1;
        optSecondsString1 << " seconds.";
        optSecondsString = optSecondsString1.str();
    }
    else {
        ostringstream optSecondsString1;
        optSecondsString1 << "";
        optSecondsString = optSecondsString1.str();
    }
}

void optAndF() { // makes string based on TimerCalc and fMinSec
    if (exSeconds > 0 && TimerTimes2 > 60000) {
        ostringstream optAndString1;
        optAndString1 << " and ";
        optAndString = optAndString1.str();
    }
    else {
        ostringstream optAndString1;
        optAndString1 << ".";
        optAndString = optAndString1.str();
    }
}

void optExSecondsf() { // makes string based on TimerCalc and fMinSec
    exSeconds = (TimerTimes2 % 60000) / 1000;
    if (exSeconds > 0 && TimerTimes2 > 60000) {
        exSeconds = (TimerTimes2 % 60000) / 1000;
        ostringstream exSecondsString1; //
        exSecondsString1 << exSeconds; // SO MACHT MAN VARIABLE IN EINEN STRING
        exSecondsString = exSecondsString1.str(); //
    }
    else {
        ostringstream exSecondsString1;
        exSecondsString1 << "";
        exSecondsString = exSecondsString1.str();
    }
}

void optZusammenf() { // makes string based on TimerCalc and fMinSec

    optExSecondsf();
    optAndF();
    optSecondsf();
    ostringstream optZusammenString1;
    optZusammenString1 << optAndString << exSecondsString << optSecondsString << endl;
    optZusammenString = optZusammenString1.str();
}

void Counter() { // counts how many blocks have been broken, how much the process is finished and how often it will repeat;
    // Clicker

    old_clock = ((Timer / 10));
    int clock1;

    for (clock1 = 0; clock1 < Timer; clock1 = clock1 + old_clock)
    {
        cout << "Now on Slot: " << Slot << " for " << TimerEquation << MinSec << optZusammenString;
        cout << "\n" << ceil(((clock1 * 100) / Timer)) << "% finished.\n";
        cout << floor((clock1 / ((ceil(1 / damage) / 20) * 1000))) << "-" << floor((clock1 / ((ceil(1 / damage) / 20) * 1000)) * 2) << " blocks mined.\n";
        cout << "\n\nExit: WindowsKey > Cobblestone Miner Application > double click on the X to exit\n";


        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        Sleep((old_clock * TimerMultiplier));
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);



        system("cls");
    }

    cout << "Now on Slot: " << Slot << " for " << TimerEquation << MinSec << optZusammenString << endl;
    cout << "100% finished.\n" << floor((clock1 / ((ceil(1 / damage) / 20) * 1000))) << "-" << floor((clock1 / ((ceil(1 / damage) / 20) * 1000)) * 2) << " blocks mined.\n\n";


    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    cout << "eating...\n";
    Sleep(2500);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
    cout << "eating done\n";

    Sleep(500);
    //keybd_event(0x31, 0, 0, 0);
    //keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0);
    mouse_event(MOUSEEVENTF_WHEEL, 0, 0, SCROLLDOWN, 0);
    Sleep(500);


    system("cls");

}


int main()
{
    cout << "-----------------------\n";
    cout << "---COBBLESTONE MINER---\n";
    cout << "--- by KampfKroete ----\n\n";

    while (Edit == true) {

        ON_OFF = "waiting";

        cout << "Enter your pickaxe\n\n";
        cout << " - wood\n - stone\n - iron\n - gold\n - diamond\n - netherite\n\n";
        cout << "(answer in lowercase)\n\n";

        pickON_OFF = false;
        pickSpeed = 0;
        pickDur = 0;
        efficiency = 9;
        damage = 0;

        while (pickON_OFF == false)
        {
            cin >> pickaxe;
            if (pickaxe == "wood") {
                Timer = 82500;
                pickSpeed = 2;
                pickDur = 59 - 5;
                pickID = 1;
                pickON_OFF = true;

            }
            else if (pickaxe == "stone") {
                Timer = 94500;
                pickSpeed = 4;
                pickDur = 131 - 5;
                pickID = 2;
                pickON_OFF = true;
            }
            else if (pickaxe == "iron") {
                Timer = 122500;
                pickSpeed = 6;
                pickDur = 250 - 5;
                pickID = 3;
                pickON_OFF = true;
            }
            else if (pickaxe == "diamond") {
                Timer = 622400;
                pickSpeed = 8;
                pickDur = 1564 - 5;
                pickID = 4;
                pickON_OFF = true;
            }
            else if (pickaxe == "netherite") {
                Timer = 709100;
                pickSpeed = 9;
                pickDur = 2031 - 5;
                pickID = 5;
                pickON_OFF = true;
            }
            else if (pickaxe == "gold") {
                Timer = 7500;
                pickSpeed = 12;
                pickDur = 30 - 2;
                pickID = 6;
                pickON_OFF = true;
            }
            else if (pickaxe == "Code:405") {
                pickON_OFF = false;
            }
            else {
                cout << "Invalid: Enter again\n\n";
                pickON_OFF = false;
                pickDur = 1;
                pickSpeed = 1;
            }

        }

        cout << "\nEnter efficiency level\n";
        cout << "(if it has none: Enter 0)\n\n";


        while (efficiency == 9) {
            cin >> efficiency;
            floor(efficiency);
            efficiencyINT = efficiency;

            if (efficiency > 5 || efficiency < 0) {
                efficiency = 9;
                cout << "enter again\n";
            }
            else if (efficiency == 0) {
                Edit = false;
                damage = (pickSpeed / 60);
                Timer = pickDur * ((ceil(1 / damage) / 20) * 1000) + 1000;
            }
            else if (efficiency > 0 && efficiency < 6) {

                Edit = false;
                damage = (pickSpeed + ((efficiency * efficiency) + 1)) / 60;
                Timer = ((pickDur * ((ceil(1 / damage) / 20) * 1000)));
            }
            else {
                efficiency = 9;
                cout << "enter again\n";
            }

        }





        while (slotWahl == false) {
            cout << "\nEnter the Slot Number (1 - 9) where your FIRST pickaxe is\n";
            cin >> slotStart;
            if (slotStart < 1 || slotStart > 9) {
                cout << "Invalid slot: Enter again\n";
                slotWahl = false;
            }
            else if (slotStart >= 1 && slotStart <= 8) {
                slotStart = slotStart;
                cout << "\nEnter the Slot Number where your LAST pickaxe is\n";
                cin >> slotEnd;
                if (slotEnd >= slotStart && slotEnd <= 9) {
                    slotEnd = slotEnd;
                    cout << "\npreparing...";
                    Sleep(2500);
                    slotWahl = true;
                }
                else if (slotEnd < slotStart) {
                    cout << "your last pickaxe can't be in a slot before your first\n";
                    slotWahl = false;
                }

            }
            else if (slotStart == 9) {
                slotStart = 9;
                cout << "Pickaxe is on last slot usable slot\n";
                slotEnd = 9;
                cout << "preparing...\n";
                Sleep(2500);
                slotWahl = true;

            }
            else {
                cout << "Invalid slot: Enter again";
                slotWahl = false;
            }
        }


        system("cls");
        cout << "Pickaxe: " << pickaxe << endl;
        cout << "Efficiency: " << efficiency << endl;
        cout << "First Pickaxe on slot: " << slotStart << endl;
        cout << "Last Pickaxe on slot: " << slotEnd << endl;


        cout << "\nType START to begin mining\n";
        cout << "Type EDIT to rechose your tool\n";
        cout << "Type END to exit the application\n\n";

        while (ON_OFF == "waiting")
        {
            cin >> ON_OFF;
            if (ON_OFF == "start" || ON_OFF == "START" || ON_OFF == "Start")
            {
                Edit = false;
                system("cls");
                ON_OFF = "start";
                cout << "starting...\n\n";
                cout << " - select the first pickaxe in your hotbar\n";
                cout << " - the cobblestone miner will automatically eat, to prevent you from starving.\n";
                cout << "   put food in your offhand\n\n\n";

                for (int tMinus20 = 20; tMinus20 >= 10; tMinus20--) { //Starting counter/timer
                    cout << "\rStarting in " << tMinus20;
                    Sleep(1000);
                }

                cout << "\rStarting in "; //Starting counter/timer

                for (int tMinus10 = 9; tMinus10 >= 0; tMinus10--) { //Starting counter/timer
                    cout << "\rStarting in " << tMinus10 << " ";
                    Sleep(1000);
                }

                Sleep(100);
                system("cls");
            }
            else if (ON_OFF == "edit" || ON_OFF == "EDIT" || ON_OFF == "Edit") {

                Edit = true;
                pickaxe = "Code:405";
                pickON_OFF = false;
                pickSpeed = 0;
                pickDur = 0;
                efficiency = 9;
                damage = 0;
                slotStart = 0;
                slotEnd = 0;
                slotWahl = false;
                system("cls");
            }
            else if (ON_OFF == "end" || ON_OFF == "END" || ON_OFF == "End") {
                Edit = false;
                exit(0);
            }

            else {
                cout << "\rEnter again: ";
                ON_OFF = "waiting";
            };

        }; //StartUp: Ende

    }

    Slot = slotStart;


    for (Slot = slotStart; Slot <= slotEnd; Slot++) { //MINER: Start

        switch (Slot) {
        case 1:

            keybd_event(0x31, 0, 0, 0);
            keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        case 2:

            keybd_event(0x32, 0, 0, 0);
            keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        case 3:

            keybd_event(0x33, 0, 0, 0);
            keybd_event(0x33, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        case 4:

            keybd_event(0x34, 0, 0, 0);
            keybd_event(0x34, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        case 5:

            keybd_event(0x35, 0, 0, 0);
            keybd_event(0x35, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        case 6:

            keybd_event(0x36, 0, 0, 0);
            keybd_event(0x36, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        case 7:

            keybd_event(0x37, 0, 0, 0);
            keybd_event(0x37, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        case 8:

            keybd_event(0x38, 0, 0, 0);
            keybd_event(0x38, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;
        case 9:

            keybd_event(0x39, 0, 0, 0);
            keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0);

            TimerCalc();
            fMinSec();
            optZusammenf();

            Counter();
            break;

        } // MINER: END
    }

    system("color a");

    cout << "------------------------\n";
    cout << "------- FINISHED -------\n";
    cout << "------------------------\n\n";
    cout << "*under perfect conditions you mined " << floor(((Timer / ((ceil(1 / damage) / 20) * 1000)) * ((slotEnd - slotStart) + 1))) << " blocks* \n";



    system("color b");
    Sleep(500);
    system("color c");
    Sleep(500);
    system("color a");
    Sleep(500);
    system("color b");
    Sleep(500);
    system("color c");
    Sleep(500);
    system("color a");
    Sleep(500);system("color b");
    Sleep(500);
    system("color c");
    Sleep(500);
    system("color a");

    system("pause>0");
}


