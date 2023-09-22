#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cctype>
#include <limits>
#include <vector>
#include <unistd.h>
using namespace std;
void display_menu();
const char local_destination[33][20]={"Adana","Ankara","Alanya","Antalya","Balikesir","Bursa",
                                   "Denizli","Diyarbakir","Elazig", "Erzurum","Eskisehir","Gaziantep","Hatay","Isparta"
                                   ,"Istanbul","Izmır","Kars","Kayseri","Kocaeli","Konya","Kutahya","Malatya","Mugla","Nevsehir","Ordu","Samsun"
                                   ,"Sinop","Sivas","Sanliurfa","Tekirdag","Trabzon","Van","Zonguldak"};
const char international_destination[15][20]={"LONDON","BERLIN","DUBAI","RIYADH","BEIJING","PARIS","CANBERRA","TOKYO","WASHINGTON","DELHI","ISLAMABAD","MADRID","BRASILIA",
                                   "OTTAWA", "TURKEY" };


char flight_time[33][6] = {
    "08:00", "08:30", "10:30", "13:15", "15:45", "18:30", "20:00", "22:15", "23:45",
    "09:00", "06:30", "01:30", "15:15", "17:45", "05:30", "20:20", "22:45", "00:45",
    "08:00", "08:30", "10:30", "13:15", "15:45", "18:30", "20:00", "22:15", "23:45",
    "09:00", "06:30", "01:30", "15:15", "17:45", "05:30",
};
const char flight_day[33][20]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday",
                               "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Monday", "Tuesday", "Wednesday",  "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Thursday", "Friday", "Saturday", "Sunday", "Monday"};
const int local_price{8000};
const int international_price{15000};
class Passenger{


     public:
           string first_name;
           string last_name;
           string address;
           string phone_no;
           string birthday;
           string origin;
           string dest;
           int seats;
           int ticket;
         Passenger();

        Passenger(string &first_name, string &last_name, string &address, string &phone_no, string &birthday, string &ori, string &des, int &seat, int &tick){
        }

       void information(string &first_name, string &last_name, string &address, string &phone_no, string &birthday);
       void destination();
       void price(string &ori, string &des, int &seat, int &tick);
       void to_approve();
       bool isAllDigits(const string& str);
       bool isValidDate(const string& date);
       bool isDigit(const int &str);
       void display_information(string &first_name, string &last_name, string &address, string &phone_no, string &birthday, string &ori, string &des, int &seat, int &tick);
       int generateRandomFlightNumber();

};

void Passenger::display_information(string &first_name, string &last_name, string &address, string &phone_no, string &birthday, string &ori, string &des, int &seat, int &tick){
        cout << endl << endl;
        cout << "*****TICKET INFORMATION*****" << endl;
        cout << "First name: " << first_name << endl;
        cout << "Last name: " << last_name << endl;
        cout << "Address: " << address<< endl;
        cout << "Phone Number: " << phone_no << endl;
        cout << "Bithday: " << birthday <<endl;
        cout << "Origin: " << origin << endl;
        cout << "Destination: " << dest << endl;
        cout << "Number of Seats: " << seats << endl;
        cout << "PRICE: " << ticket << " TL" << endl;
        cout << "TICKET NUMBER: " << generateRandomFlightNumber() << endl;

    }

  bool Passenger:: isAllDigits(const string &str) {

    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool Passenger:: isValidDate(const string& date) {
    if (date.size() != 10)
        return false;

    if (date[2] != '/' || date[5] != '/') // Format check
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 2 || i == 5)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;


    if (year < 1900 || year > 2099)
        return false;

    return true;
}

  void Passenger::information(string &first_name, string &last_name, string &address, string &phone_no, string &birthday){
        cout << "Enter Your First Name: ";
        cin >> first_name;
        cout << "Enter Your Last Name: ";
        cin >> last_name;
        cout << "Enter Your Address: ";
        cin >> address;
        cout << "Enter your Phone Number: ";
        cin >> phone_no;
         while (!isAllDigits(phone_no)) {
        cout << "Invalid entry. Please enter numbers only." << endl;
        cout << "Enter your Phone Number: ";
        cin >> phone_no;
        }
        cout << "Enter Your Birthday - [DD/MM/YYYY]: ";
        cin >> birthday;
        while (!isValidDate(birthday)) {
        cout << "Invalid date format. Please enter in DD/MM/YYYY format." << endl;
        cout << "Enter Your Birthday: ";
        cin >> birthday;
        }
        cout << endl;
        destination();
}
  void Passenger::destination(){
     string passport;

     int choice;
     cout << "1. Local Destination: " << endl;
     cout << "2. International Destination: " << endl;
     cin >> choice;

     switch(choice){
         case 1:
         {
             cout << "These are the local destinations where we are flying: " << endl;

             for(int i = 0; i < 33; i++){
			    for(int j = 0; j < 20; j++){
				   cout << local_destination[i][j];
			    }
		      }
         cout<< setw(15);
         price(origin, dest, seats, ticket);

         break;
         }
         case 2:{
              cout << "Enter your passport number: ";
              cin >> passport;
              while (!isAllDigits(passport)) {
                cout << "Invalid entry. Please enter numbers only." << endl;
                cout << "Enter your passport number: ";
                cin >> passport;
        }
              cout << "These are the international destinations where we are flying:" <<endl;
              for(int i = 0; i < 15; i++){
			     for(int j = 0; j < 20; j++)
			     {
				     cout << international_destination[i][j];
			      }
			  cout<< endl;
		     }
               price(origin, dest, seats, ticket);
               break;
            }

        default:
           cout<< "You made an incorrect entry. Please try again." <<endl;
         }
     }

     void Passenger::price(string &ori, string &des, int &seat, int &tick){
         cout << endl << endl;
         while(true){
             cout << "Enter your origin: ";
             cin >> origin;
             char first_letter = origin[0];
              if (isupper(first_letter)) {
                  break;
              } else {
                  cout << "Error: The first letter of the city name MUST be capitalized." << endl;
        }
         }
         while(true){
             cout << "Enter your destination: ";
             cin >> dest;
             char first_let = dest[0];
             if(isupper(first_let)) {
                  break;
              } else {
                  cout << "Error: The first letter of the city name MUST be capitalized." << endl;
            }
         }

        while (true) {
        cout << "Enter the number of seats: ";
        cin >> seats;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "Invalid entry. Please enter an integer." << endl;
            cin.clear(); // Hata bayrağını sıfırla
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear incorrect entry
        } else {
            break; // End the loop when a valid integer is input
        }
    }

         bool foundOrigin = false;
         bool foundDest = false;

    for (int i = 0; i < 33; i++) {
        if (origin == local_destination[i]) {
            foundOrigin = true;
            break;
        }
    }
    for (int i = 0; i < 33; i++) {
        if (dest == local_destination[i]) {
            foundDest = true;
            break;
        }
    }
    if(foundOrigin && foundDest) {
        ticket = local_price * seats;
    }
    else {
        ticket = international_price * seats;
    }
         cout << "Price: " << ticket << " TL" << endl;
     }

void Passenger::to_approve(){
    char approve;
    cout << endl << endl;
    cout << "Do you wish confirm your ticket? [y/n]:";
    cin >> approve;

    if(approve == 'y' || approve == 'Y'){
        cout << "Thank you for choosing SPARKLE airlines." << endl;
        cout << "Press Enter to continue..."<<endl;
    }
    else if(approve == 'n' || approve == 'N'){
        cout << "Ticket reservation confirmation was rejected." << endl;
        cout << "Press Enter to continue..."<<endl;
    }
    else{
        cout <<"You entered an incorrect option. Please try again." << endl;
        to_approve();
    }
}

 int Passenger:: generateRandomFlightNumber() {

    srand(time(0));
    int random_no = rand() % 90000 + 10000;
    return random_no;

 }
class Routes {

    public:
    void print(){
			int i,j;
            cout <<"\nPlease wait..."<< endl;
            sleep(3);
			cout<<"\n\n\n\n\tFollowing are the international flights available"<<endl;
			for(i=0;i<15;i++)
			{
				cout<<endl;
                cout << "\n*******************"<<international_destination[i]<<"******************" << endl;
                cout<<endl;

				for(j=0;j<15;j++)
				{
					if(i==j)
					{
						continue;
					}
					else
					{
						cout<<"Flight from "<<international_destination[i]<<" to "<<international_destination[j] <<" " << flight_time[j] << " and " <<" " <<  flight_day[j] <<endl;
					}
				}
			}
			cout<<"\n\n\n\n\tFollowing are the local flights available"<<endl;
			for(i=0;i<33;i++)
			{
				cout<<endl;
                 cout << "\n******************* "<< local_destination[i] <<" ******************" << endl;
                 cout<<endl;
				for(j=0;j<33;j++)
				{
                    if(i==j)
					{
						continue;
					}else
					{
						cout<<"Flight from "<<local_destination[i]<<" to "<<local_destination[j] <<" " << flight_time[j] << " and " <<" " <<  flight_day[j]<<endl;
					}
				}
			}
            char select;

       cout << "\nDo you want to make a booking? [y/n]: "<<endl;
       cin >> select;

       if(select == 'y' || select == 'Y'){
        cout << "\nI direct you to the main menu. Please wait...";
        sleep(2);
        cout << endl;
        system("cls");
        display_menu();
       }else if(select == 'n' || select == 'N'){
        cout << "OKAY. BYE!" << endl;
        cout << "Press Enter to continue..."<<endl;
          }
    }
};

class Complaint{

    public:
     int complaint;
     string userComplaint;
     void complaint_func();
     string getComplaintText();
};


string Complaint::getComplaintText() {
    string complaint_sentence;
    cout << "Please enter your complaint (press Enter to finish):\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        string line;
        getline(cin, line);

        if (line.empty()) {
            break;
        }
        complaint_sentence += line + "\n";
    }

    cout << "Thank you for your complaint. You wrote:\n";
    cout << complaint_sentence;
    cout << "Please enter to continue... (2 TIMES)" << endl;
    return complaint_sentence;

}
void Complaint::complaint_func(){
   do {
    cout << "1. Airport Handling" << endl;
    cout << "2. Baggage Delivery" << endl;
    cout << "3. Booking and Ticketing" << endl;
    cout << "4. Other" << endl;
    cout << "Please select the complaint subject: ";
    cin >> complaint;

    // Kullanıcının seçeneği geçerli mi kontrol edin
    if (complaint < 1 || complaint > 4) {
        cout << "Invalid option. Please select a valid option (1, 2, 3, or 4)." << endl;
    }
} while (complaint < 1 || complaint > 4);
}
class Exit {
public:
    static void quit(int exitCode) {
        cout << "We wait again. BYE:)" << endl;
        sleep(2);
        exit(exitCode);
    }
};

class About {
public:
    About() {}
    About(const std::string& airlineName, const std::string& mission, const std::string& vision,
          const std::string& services, const std::string& responsibilities, const std::string& contactInfo)
        : airlineName(airlineName), mission(mission), vision(vision),
          services(services), responsibilities(responsibilities), contactInfo(contactInfo) {}

    void display() const {
        cout << "----------------------------------" << endl;
        cout <<endl;
        cout << "AIRLINE NAME: " << airlineName << endl;
        cout <<endl;
        cout << "MISSION: \n" << mission << endl;
        cout <<endl;
        cout << "VISION:\n" << vision << endl;
        cout <<endl;
        cout << "SERVICES: \n" << services << endl;
        cout <<endl;
        cout << "RESPONSIBILITIES:\n" << responsibilities << endl;
        cout <<endl;
        cout << "CONTACT INFORMATION:\n " << contactInfo << endl;
        cout <<endl;
        cout << "----------------------------------" << endl;
    }
     void displayAirlineInfo();

private:
    string airlineName;
    string mission;
    string vision;
    string services;
    string responsibilities;
    string contactInfo;
};

void About:: displayAirlineInfo() {
    About airline(
        "SPARKLE Airline",
        "Our mission is to keep customer satisfaction at the highest level and maintain our leadership in the industry\nby providing a safe and comfortable travel experience.",
        "Our vision is to transform air transportation with innovative solutions and provide hassle-free travel \nto customers around the world.",
        "Wide Flight Network, Comfortable Seats, Delicious Food, Wi-Fi and Entertainment, Loyalty Program",
        "SPARKLE Airline Company recognizes its responsibility for the environment by adopting environmentally\nfriendly practices.",
        "\nAddress: Exp Street No: 123, Ankara, Turkey\n\nPhone Number: +90 123 456 7890\n\nE-mail: info@sparkleairlines.com\n\nWeb Sitesi: www.sparkleairlines.com"
    );

    airline.display();

}
class Manage {
public:
    void rescheduleFlight() {
        string current_time;
        char choice;

        cout << "Enter your current flight time (HH:MM): ";
        cin >> current_time;

        // Mevcut uçuş saati geçerli bir saat mi kontrol etmek için gerekli kodu ekleyebilirsiniz.

        cout << "Would you like to postpone your flight to another time? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            cout << "Recommended new flight times: " << endl;
            for (int i = 0; i < 18; ++i) {
                if (current_time < flight_time[i]) {
                    cout << flight_time[i] << endl;
                }
            }

            string selected_time_index;
            cout << "Please write the flight time you want to postpone (HH:MM): ";
            cin >> selected_time_index;

            if (selected_time_index >= current_time) {
                cout << "Your flight " << selected_time_index << " time was postponed." << endl;
                cout<< "You are directed to the main menu." << endl;
                sleep(3);
                system("cls");
                display_menu();
                // Yeni uçuş saatini kullanarak gerekli işlemleri yapabilirsiniz.
            } else {
                cout << "You entered an invalid option. Your flight will continue at the same time." << endl;
                cout<< "You are directed to the main menu." << endl;
                sleep(3);
                system("cls");
                display_menu();
            }
        } else {
            cout << "Your flight will continue at the same time." << endl;
            cout<< "You are directed to the main menu." << endl;
            sleep(3);
            system("cls");
            display_menu();
        }
    }
};



void display_menu(){
     string first_name, last_name, address, phone_no, birthday;
     string origin;
     string dest;
     int seats, ticket;
     int selection;
    start:
    cout << endl;
    cout << "\t\t\t\t\t\tFLIGHT MANAGEMENT SYSTEM\t\t\t\t\t" << endl << endl;
    cout << "Press 1 for Booking" << endl;
    cout << "Press 2 for Routes" << endl;
    cout << "Press 3 for Complaint" << endl;
    cout << "Press 4 for About us" << endl;
    cout << "Press 5 for Manage" << endl;
    cout << "Press 0 for Exit" << endl;
    cout << "Enter your choice: ";

    cin >> selection;
    Passenger p(first_name, last_name, address, phone_no, birthday, origin, dest, seats, ticket);
    Complaint c;
    Routes r;
    About a;
    Manage manager;
    char enter;
    switch(selection){
        case 1:
        cout << "\t\t\t***BOOKING***\t\t\t" << endl;
        p.information(first_name, last_name, address, phone_no, birthday);
        p.display_information(first_name, last_name, address, phone_no, birthday, origin, dest, seats, ticket);
        p.to_approve();
        cin.get(enter);
        cin.ignore();
        system("cls");
        goto start;
        break;
        case 2:
        cout << "\n***ROUTES***" << endl;
        r.print();
        cin.get(enter);
        cin.ignore();
        system("cls");
        display_menu();
        break;
        case 3:
        cout << "\n***COMPLAINT***" << endl;
        c.complaint_func();
        c.getComplaintText();
        cin.get(enter);
        cin.ignore();
        system("cls");
        display_menu();
        break;
        case 4:
        cout << "\n***ABOUT US***" << endl;
        a.displayAirlineInfo();
        cout << "Press Enter to continue...";
        cin.ignore(); // Clear extra characters when Enter key is pressed
        cin.get();
        system("cls");
        display_menu();
        break;
        case 5:
        cout << "\n***MANAGE***" << endl;
        manager.rescheduleFlight();
        cin.get(enter);
        cin.ignore();
        system("cls");
        break;
        case 0:
        cout << "\n***EXIT***" << endl;
        Exit::quit(0);
        break;
    }
}

int main() {
    display_menu();
    return 0;
}