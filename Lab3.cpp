//Jared Howie
//27 september 2018
//


#include <iostream>	// for cin, cout
#include "MyLabC3WorkTicket.h" 	// version 2018.02
#include "MyConsoleInput.h" // for ReadInteger()

using namespace std;
using namespace ConsoleInput;

class ExtendedWorkTicket : public WorkTicket
{
	public :
		//constructors
		ExtendedWorkTicket() : WorkTicket(), isOpen(true) {}
		ExtendedWorkTicket(int ticketNumber, string clientId, int day, int month, int year, string description, bool openStatus)  :WorkTicket(ticketNumber, clientId, day, month, year, description), isOpen(openStatus){}
		
		//accessors
		bool IsOpen(){ return isOpen;}
		
		void ShowWorkTicket()
		{
			if(isOpen == true)
			{
				this->WorkTicket::ShowWorkTicket();
				cout << "TICKET:        " << "Open" <<endl;

			}
			if(isOpen == false)
			{
				this->WorkTicket::ShowWorkTicket();
				cout << "TICKET:        " << "Closed" <<endl;

			}
			
			
		}  
		
		friend ostream& operator<<(ostream& os, ExtendedWorkTicket& ewt);
		//mutators
		void CloseTicket(){this->isOpen = false;};
		bool SetWorkTicket(int ticketNumber, string clientId, int day, int month, int year, string description, bool openStatus)
		{
			bool isSet = false;
			if(ticketNumber > 0)
			{
				if(clientId.length() > 0)
				{
					if(day >= 1 && day <= 31)
					{
						if(month >= 1 && month <= 12)
						{
							if(year >= 2000 && year <= 2099)
							{
								if(description.length() > 0)
								{
									this->WorkTicket::SetWorkTicket(ticketNumber, clientId, day, month, year, description);
			
									isOpen = openStatus;
									isSet = true;
								}
							}
						}
					}
				}
			}
		
			return isSet;
		}
		
		
	private :
		bool isOpen;
	
};


ostream& operator<<(ostream& os, ExtendedWorkTicket& ewt)  
{  
	if(ewt.IsOpen() == true)
	{
		 os<< "\nWork Ticket Number: " << ewt.GetTicketNumber() << " Client Number: " << ewt.GetClientId() << " Date: " << ewt.GetDate() << " TICKET: OPEN";
	}
   	else
   	{
   		os<< "\nWork Ticket Number: " << ewt.GetTicketNumber() << " Client Number: " << ewt.GetClientId() << " Date: " << ewt.GetDate() << " TICKET: CLOSED";
	}
    return os;  
}


int main()
{
 ExtendedWorkTicket testTicket1;
 ExtendedWorkTicket testTicket2(1, "AMCE_123", 1, 7, 2014, "Password Reset", true);

 cout << endl << "As Initialized: " << endl;
 testTicket1.ShowWorkTicket();
 testTicket2.ShowWorkTicket();


 if(!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
 {
 
 	cout << "\nErrors! No changes to the ticket made." << endl;
 }
 	

 cout << endl << "Ticket 1: " << testTicket1 << endl;

 if(!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false))
 {
 	
 	cout << "\nErrors! No changes to the ticket made." << endl;
 }
 

 cout << endl << "Ticket 2: " << testTicket2 << endl;
 testTicket2.CloseTicket();
//
 cout << endl << "After Ticket 2 closed: " << testTicket2 << endl;
//
 cout << endl << endl;
 return 0;
ExtendedWorkTicket os();
    cout << os;

}



