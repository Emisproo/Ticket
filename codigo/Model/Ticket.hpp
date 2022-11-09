#ifndef TICKET_HPP
#define TICKET_HPP

#include "Client.hpp"
#include "Agent.hpp"
#include <iostream>
using namespace std;

class Ticket
{
    private:
        int m_id;
        Client m_client;
        Agent m_agent;
        string m_message;
        string m_createdDate;
    public:
        Ticket();
        Ticket (int id, Client client, Agent agent, string message, string createdDate);
        virtual ~Ticket();

        void setId(int id);
        int getId ();

        void setClient (Client client);
        string getClient();
        void setAgent (Agent agent);
        string getAgent();

        void setMessage ( string message);
        string getMessage();

        void setCreatedDate(string date);
        string getCreatedDate();

};

Ticket:: Ticket(){}
Ticket:: Ticket (int id, Client client, Agent agent, string message, string createdDate)
{
    m_id = id;
    m_client = client;
    m_agent = agent;
    m_message = message;
    m_createdDate = createdDate;
}

Ticket :: ~Ticket ( )
{
   
}
void Ticket :: setId (int id)
{
    m_id = id;
}
int Ticket :: getId ()
{
    return m_id;
}

void Ticket ::setClient( Client client)
{
    m_client = client;
}
string Ticket :: getClient()
{
   return m_client.getName();
}

void Ticket ::setAgent( Agent agent)
{
    m_agent = agent;
}
string Ticket :: getAgent()
{
    return m_agent.getName();
}

void Ticket :: setMessage(string message)
{
    m_message = message;
}
string Ticket :: getMessage()
{
    return m_message;
}

void Ticket :: setCreatedDate(string date)
{
    m_createdDate = date;
}
string Ticket :: getCreatedDate()
{
    return m_createdDate;
}

#endif // TICKET_HPP