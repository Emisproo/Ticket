#include "Client.hpp"
#include "ClientManager.hpp"
#include "Agent.hpp"
#include "AgentManager.hpp"
#include "TicketManager.hpp"


int main()
{
    int id, op, op2;
    
    
    Client client1(1, "Emi", 4554545, "emi@gmail.com");
    Client client2(2, "Pepe", 878779, "pepe@gmail.com");

    Agent agent1(1, "tech", "Jose", 45454545, "jose@gmail.com");
    Agent agent2(2, "soporte", "Pedro", 78787878, "pedro@gmail.com" );

    ClientManager* cManager = new ClientManager();
    AgentManager* aManager = new AgentManager();
    TicketManager* tManager = new TicketManager();

    Ticket ticket1(1, client1, agent1, "Connection Problems", " 16-10-2022");
    tManager->addTicket(ticket1);
    tManager->serialize(ticket1);
    Ticket ticket2(2, client2, agent2, "Interface problems", " 16-10-2022");
    tManager->addTicket(ticket2);
    tManager->serialize(ticket2);


    do
    {   cout<< "CHOOSE A OPTION TO CREATE TICKETS"<<endl;
        cout<< "1. Add Clients to ticket"<<endl;
        cout<< "2. Add Agents to ticket"<<endl;
        cout<< "3. List tickets"<< endl;
        cout<< "4. Extra functions"<< endl;
        cout<< "5. Exit" << endl;
        cin>>op;

        switch (op)
        {
        case 1: cout<< "Add Client and message 1"<< endl << endl;
                cManager->addClient(client1);
                cManager->serialize(client1);
            
                cout<< "Add Client and message 2"<< endl << endl;
                cManager->addClient(client2);
                cManager->serialize(client2);
        break;
        case 2: cout<< "Add Agent 1"<< endl <<endl;
                aManager->addAgent(agent1);
                aManager->serialize(agent1);
                cout << "Add Agent 2"<< endl <<endl;
                aManager->addAgent(agent2);
                aManager->serialize(agent2);
        break;
        case 3: tManager->list();
        break;     
        case 4: 

            do
            {
                cout<<endl<< "1. List Clients"<<endl;
                cout<< "2. Find a Client"<<endl;
                cout<< "3. Delete a Client"<<endl;
                cout<< "4. List Agents"<<endl;
                cout<< "5. Find a Agent"<<endl;
                cout<< "6. Delete a Agent"<<endl;
                cout<< "7. Exit"<<endl;
                cin>> op2;

                switch(op2)
                {
                    case 1:  cManager->list();
                    break;
                    case 2: cout<< endl<<" Find Client by id: "<<endl;
                            cin>>id;
                            cManager->find(id);
                    break;
                    case 3: cout << "Delete client by Id: ";
                            cin>>id;
                            cManager->supr(id);
                    break;
                    case 4: aManager->list();
                    break;
                    case 5: cout<< endl<<" Find Agent by id: "<<endl;
                            cin>>id;
                            aManager->find(id);
                    break;
                    case 6: cout << "Delete agent by Id: ";
                            cin>>id;
                            aManager->supr(id);
                    break;       
                }
        
            } while (op2!=7);
             

        default:
            break;
        }
    } while (op!=5);
    

    delete cManager;
    delete aManager;
    delete tManager;
    

}