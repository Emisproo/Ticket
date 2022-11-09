#ifndef AGENTMANAGER_HPP
#define AGENTMANAGER_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Agent.hpp"
#include "json.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

class AgentManager
{
    public:
        vector<Agent> agents;//para memoria dinamica <IAgent*>
       // vector<json> jv;
        AgentManager();
        virtual ~AgentManager();
        void addAgent(Agent agent);
        int find( int id);
        void supr( int id);
        void list();
        void serialize(Agent agent);
       
};

AgentManager :: AgentManager (){}
AgentManager :: ~AgentManager(){} //para memoria dinamica delete Agents;

void AgentManager :: addAgent (Agent agent)
{
    //Agent* Agent = new Agent(id, name, dni, email);
    //Agent Agent(id, name, dni, email);
    agents.push_back(agent); 
    cout << " Agent " <<agent.getName() << " was added"<< endl;  
}

int AgentManager :: find( int id)
{
    int index = -1;
    for (int i = 0; i < agents.size(); i++)
    {
        Agent a = agents[i];
        if (a.getId() == id)
        {
            index = i;
            cout<< "Found"<< endl;
        }
    }
    return index++;
} 

void AgentManager :: supr ( int id) 
//funciona solo si los Agentes son ingresados 
//con un id en orden sin saltear. ej en pos 0 Agente 1, pos 1 Agente 2.
{
    int pos= find(id);
    
    for(int i = 0; i < agents.size(); i++)
    {
        if( agents[i].getId()==id)
        {
            agents.erase(begin(agents) + pos); 
        }
    }
     cout<< "agent removed"<< endl;
}

void AgentManager :: list ()
{
    cout<< endl<<"LIST"<<endl;
    for (int i = 0; i < agents.size(); i++)
    {
        cout<<agents[i].getId()<<" "<<agents[i].getArea()<< " " << agents[i].getName()<<" "<< agents[i].getDNI()<< " " << agents[i].getEmail()<< endl;
    }
}
void AgentManager :: serialize(Agent agent)
{
    json storage;
    storage["id"] = agent.getId();
    storage["name"] = agent.getName();
    storage["dni"] = agent.getDNI();
    storage["email"] = agent.getEmail(); 
    storage["area"] = agent.getArea();

    //cout << setw(4) << storage << endl;
    
    ofstream myfile;
    myfile.open ("agent.json", ios::app);
    myfile << std::setw(4) << storage;
    myfile.close();
}


#endif // AGENTMANAGER_HPP
