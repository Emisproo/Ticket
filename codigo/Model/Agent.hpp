#ifndef AGENT_HPP
#define AGENT_HPP
#include <iostream>
using namespace std;

class Agent 
{
    private:
        string m_area;
        int m_id;
        string m_name;
        int m_dni;
        string m_email;
    
    public:
        Agent();
        Agent(int id, string area, string name, int dni, string email);
        virtual ~Agent();

        void setArea(string area);
        string getArea();
        void setId (int id);
        int getId ();
        void setName (string name);
        string getName ();
        void setDNI (int dni);
        int getDNI ();
        void setEmail (string email);
        string getEmail();

};

Agent :: Agent (){}
Agent :: Agent (int id, string area, string name, int dni, string email)
{
    m_area = area;
    m_id = id;
    m_name = name;
    m_dni = dni;
    m_email = email;
}
Agent :: ~Agent(){}


void Agent :: setArea ( string area)
{
    m_area = area;
}

string Agent :: getArea ()
{
    return m_area;
}

void Agent :: setId(int id)
{
    m_id = id;
}
int Agent :: getId()
{
    return m_id;
}
void Agent :: setDNI ( int dni)
{
    m_dni= dni;
}
int Agent:: getDNI()
{
    return m_dni;
}

void Agent :: setName(string name)
{
    m_name= name;
}
string Agent:: getName()
{
    return m_name;
}

void Agent :: setEmail(string email)
{
    m_email= email;
}
string Agent :: getEmail()
{
    return m_email;
}


#endif // AGENT_HPP
