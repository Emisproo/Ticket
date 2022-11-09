#ifndef CLIENTMANAGER_HPP
#define CLIENTMANAGER_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Client.hpp"
#include "json.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

class ClientManager
{
    public:
        vector<Client> clients;//para memoria dinamica <IClient*>
       // vector<json>Jclients;
        ClientManager();
        virtual ~ClientManager();
        void addClient(Client client);
        int find( int id);
        void supr( int id);
        void list();
        void serialize(Client client);
};

ClientManager :: ClientManager (){}
ClientManager :: ~ClientManager(){} //para memoria dinamica delete clients;

void ClientManager :: addClient (Client client )
{
    //Client* client = new Client(id, name, dni, email);
    //Client client(id, name, dni, email);
    clients.push_back(client); 
    cout << " Client " <<client.getName() << " was added"<< endl;  
}

int ClientManager :: find( int id)
{
    int index = -1;
    for (int i = 0; i < clients.size(); i++)
    {
        Client c = clients[i];
        if (clients[i].getId() == id)
        {
            index = i;
            cout<< "Found"<<endl;
        }

    }
    return index++;
} 

void ClientManager :: list ()
{
    cout<< endl<<"LIST"<<endl;
    for (int i = 0; i < clients.size(); i++)
    {
        cout<<clients[i].getId()<<" "<< clients[i].getName()<<" "<< clients[i].getDNI()<< " " << clients[i].getEmail()<< endl;
    }
}


void ClientManager :: supr ( int id) 
//funciona solo si los clientes son ingresados 
//con un id en orden sin saltear. ej en pos 0 cliente 1, pos 1 cliente 2.
{
    
    int pos= find(id);
    
    for(int i = 0; i < clients.size(); i++)
    {
        if( clients[i].getId()==id)
        {
            clients.erase(begin(clients) + pos); 
            cout << "Client removed"<< endl;
        }
    }
     
}
void ClientManager :: serialize(Client client)
{
    json storage;
    storage["id"] = client.getId();
    storage["name"] = client.getName();
    storage["dni"] = client.getDNI();
    storage["email"] = client.getEmail(); 

   // cout << setw(4) << storage << endl;

    ofstream myfile;
    myfile.open ("client.json", ios::app);
    myfile << std::setw(4) << storage;
    myfile.close();
}
#endif // CLIENTMANAGER_HPP
