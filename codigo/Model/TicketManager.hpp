#ifndef TICKETMANAGER_HPP
#define TICKETMANAGER_HPP
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Ticket.hpp"
#include "json.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

class TicketManager
{
    
    public:
        vector<Ticket> tickets;

        TicketManager();
        virtual ~TicketManager();
    
        void addTicket( Ticket ticket);
        void showTicket(Ticket ticket);
        int find(int id);
        void supr(int id);
        void list();
        void serialize(Ticket ticket);
        //void writeJson();
        //void readJson();


};

TicketManager :: TicketManager (){}
TicketManager :: ~TicketManager(){}

void TicketManager :: addTicket( Ticket ticket)
{
    tickets.push_back(ticket);
    
}
void TicketManager::showTicket(Ticket ticket)
{
    ticket.getId();
    ticket.getCreatedDate();
    ticket.getClient();
    ticket.getAgent();

}
int TicketManager :: find(int id)
{
    int index = -1;
    for (int i = 0; i < tickets.size(); i++)
    {
        Ticket t = tickets[i];
        if (t.getId() == id)
        {
            index = i;
            cout<< "Found"<<endl;
        }
        
    }
    return index++;
}

void TicketManager :: supr(int id)
{
    find(id);
    int pos= find(id);
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if( tickets[i].getId()==id)
        {
            tickets.erase(begin(tickets) + pos); 
        }
    }
}

void TicketManager :: list ()
{
    cout<< endl<<"LIST"<<endl;
    for (int i = 0; i < tickets.size(); i++)
    {
        cout<< "Ticket's Id: "<< tickets[i].getId()<<"    "<< tickets[i].getCreatedDate()<<endl
        << "Client: "<< tickets[i].getClient()<< endl
        << "Agent: "<< tickets[i].getAgent()<<endl
        << "Messagge: "<< tickets[i].getMessage()<< endl;
        
    }
}

void TicketManager :: serialize(Ticket ticket)
{
    json storage;
    storage["id"] = ticket.getId();
    storage["created date"] = ticket.getCreatedDate();
    storage["client"] = ticket.getClient();
    storage["agent"] = ticket.getAgent();
    storage["messagge"] = ticket.getMessage();  

    //cout << setw(4) << storage << endl;

    ofstream myfile;
    myfile.open ("tickets.json", ios::app);
    myfile << std::setw(4) << storage;
    myfile.close();
}

/*void TicketManager :: writeJson( )
{
    json j = tickets;
    ofstream myfile;
    myfile.open ("tickets.json", ios::app);
    myfile << std::setw(4) << j;
    myfile.close();
}*/
/*void TicketManager :: readJson( )
{
    ifstream myfile("tickets.json");
    json j = json::parse(myfile);

    j = tickets;
    for (int i = 0; i < tickets.size(); i++)
    {
       
    }

}*/



#endif // TICKETMANAGER_HPP
