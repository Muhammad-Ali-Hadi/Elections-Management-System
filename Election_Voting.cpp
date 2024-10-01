#include"elections.hpp"

class Election{
    int PTI;
    int MQM;
    int PPP;
    int PMLN;
    int PMLQ;
    int JI;
    int JUI;
    string *CNIC;
    int TotalVotes;
    int size;
    string Representation[7] = {"🏏","🪁","🏹","⚖️","🦁","🚜","🏁"};

public:
    Election() : PTI(0),MQM(0),PPP(0),PMLN(0),PMLQ(0),JI(0),JUI(0),TotalVotes(0),size(0),CNIC(nullptr) {}

    void RecordVote(string cnic)
    {
        int choice = 8;

        fstream file("Elections_Record.txt",ios::in | ios::app); 
        if(!file.is_open())
        {
            cout<<"Cannot Open File\n";
            return;
        }

        string record;
        while(getline(file,record))
        {
            if(record==cnic)
            {
                cout<<"Vote Already Registered\n";
                file.close();
                return;
            }
        }
        file.clear();
        file<<cnic<<endl;
        file.close();

        string *TempCNIC=new string[size+1];
        for (int i=0;i<size;++i)
        {
            TempCNIC[i]=CNIC[i];
        }
        TempCNIC[size++]=cnic;

        while(choice>7)
        {
            cout<<"Press Button according to Respective Numbers to Record Your Vote"<<endl<<"(1)-->PTI "<<Representation[0]<<endl<<"(2)-->MQM " <<Representation[1]<<endl<<"(3)-->PPP "<<Representation[2]<<endl<<"(4)-->JI "<<Representation[3]<<endl<<"(5)-->PMLN "<<Representation[4]<<endl<<"(6)-->PMLQ "<<Representation[5]<<endl<<"(7)-->JUI "<<Representation[6]<<endl;
            cin>>choice;

            switch(choice)
            {
                case 1:
                    cout<<"Vote Recorded Successfully!"<<endl;
                    PTI++;
                break;

                case 2:
                    cout<<"Vote Recorded Successfully!"<<endl;
                    MQM++;
                break;

                case 3:
                    cout<<"Vote Recorded Successfully!"<<endl;
                    PPP++;
                break;

                case 4:
                    cout<<"Vote Recorded Successfully!"<<endl;
                    JI++;
                break;

                case 5:
                    cout<<"Vote Recorded Successfully!"<<endl;
                    PMLN++;
                break;

                case 6:
                    cout<<"Vote Recorded Successfully!"<<endl;
                    PMLQ++;
                break;

                case 7:
                    cout<<"Vote Recorded Successfully!"<<endl;
                    JUI++;
                break;

                default:
                    cout<<"Invalid Input! Try Again!"<<endl;
            }
        }
        ++TotalVotes;

        delete[] CNIC;
        CNIC=TempCNIC;
    }

    void DislayVotes()
    {
        cout<<"Election Status (Results) : "<<endl;
        cout<<"<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>"<<endl;
        cout<<"PTI : "<<PTI<<endl;
        cout<<"MQM : "<<MQM<<endl;
        cout<<"PPP : "<<PPP<<endl;
        cout<<"JI : "<<JI<<endl;
        cout<<"PMLN : "<<PMLN<<endl;
        cout<<"PMLQ : "<<PMLQ<<endl;
        cout<<"JUI : "<<JUI<<endl;
        cout<<"Total Votes Recorded : "<<TotalVotes<<endl;
    }

    void compileFinalResults()
    {
        fstream file;
        file.open("Election_Results.txt",ios::out);
        if(!file.is_open())
        {
            cout<<"CannotOpen File\n";
            return;
        }

        file<<"----Election Results----\n";
        file<<"------------------------\n";
        file<<"Votes For PTI : "<<PTI<<endl;
        file<<"Votes for PPP : "<<PPP<<endl;
        file<<"Votes for PMLN : "<<PMLN<<endl;
        file<<"Votes for PMLQ : "<<PMLQ<<endl;
        file<<"Votes for MQM : "<<MQM<<endl;
        file<<"Votes for JI : "<<JI<<endl;
        file<<"Votes for JUI : "<<JUI<<endl;
        file<<"------------------------\n";
        file<<"Total Votes Recorded : "<<TotalVotes<<endl;
        file<<"------------------------\n";
        int winner=ElectionResult();
        if(winner==1)
        {
            file<<"Seat Won by : PTI\n";
        }
        else if(winner==2)
        {
            file<<"Seat Won by : MQM\n";
        }
        else if(winner==3)
        {
            file<<"Seat Won by : PPP\n";
        }
        else if(winner==4)
        {
            file<<"Seat Won by : JI\n";
        }
        else if(winner==5)
        {
            file<<"Seat Won by : PMLN\n";
        }
        else if(winner==6)
        {
            file<<"Seats Won by : PMLQ\n";
        }
        else if(winner==7)
        {
            file<<"Seats Won by : JUI\n";
        }
        else
        {
            file<<"Results Tied\n";
        }
        file.close();
    }

    int ElectionResult()
    {
        int winner=-1;
        if(PTI>MQM && PTI>PPP && PTI>JI && PTI>PMLN && PTI>PMLQ && PTI>JUI)
        {
            cout<<"PTI🏏 WON the seat of National Assembly!\nVotes Secured : "<<PTI<<endl;
            winner=1;
        }
        else if(MQM>PTI && MQM>PPP && MQM>JI && MQM>PMLN && MQM>PMLQ && MQM>JUI)
        {
            cout<<"MQM🪁 Won the Seat of National Assembly!\n Votes Secured : "<<MQM<<endl;
            winner=2;
        }
        else if(PPP>PTI && PPP>MQM && PPP>JI && PPP>PMLN && PPP>PMLQ && PPP>JUI)
        {
            cout<<"PPP🏹 Won the Seat of Nationa Assembly!\n Votes Secured : "<<PPP<<endl;
            winner=3;
        }
        else if(JI>PTI && JI>MQM && JI>PPP && JI>PMLN && JI>PMLQ && JI>JUI)
        {
            cout<<"JI⚖️ Won the Seat of National Assembly!\nVotes Secured : "<<JI<<endl;
            winner=4;
        }
        else if(PMLN>PTI && PMLN>MQM && PMLN>PPP && PMLN>JI && PMLN>PMLQ && PMLN>JUI)
        {
            cout<<"PMLN🦁 Won the Seat of National Assembly!\nVotes Secured : "<<PMLN<<endl;
            winner=5;
        }
        else if(PMLQ>PTI && PMLQ>MQM && PMLQ>PPP && PMLQ>JI && PMLQ>PMLN && PMLQ>JUI)
        {
            cout<<"PMLQ🚜 Won the Seat of National Assembly!\nVotes Secured : "<<PMLQ<<endl;
            winner=6;
        }
        else if(JUI>PTI && JUI>MQM && JUI>PPP && JUI>JI && JUI>PMLN && JUI>PMLQ)
        {
            cout<<"JUI🏁 Won the Seat of National Assembly!\nVotes Secured : "<<JUI<<endl;
            winner=7;
        }
        cout<<"Total Votes Recorded : "<<TotalVotes<<endl;
        return winner;
    }

    ~Election()
    {
        delete[] CNIC;
    }
};

int main()
{
    string CNIC;
    int choice=4;
    Election e;

    while (choice!=3)
    {
        cout<<"Press 1 to Record Votes"<<endl<<"Press 2 to Display Total Recorded Votes of Every Party"<<endl<<"Press 3 to Display Final Result and End Program"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    while(CNIC!="0")
                    {
                        cout<<"Enter CNIC Number (#####-#######-#) <or> Enter (0) to Go Back : ";
                        cin>>CNIC;
                        if(validateCNIC(CNIC) || CNIC=="0")
                        break;
                        else
                        cout<<"Invalid CNIC Number! Try Again\n";
                    }
                    if(CNIC=="0")
                    {
                        CNIC.pop_back();
                        break;
                    }
                e.RecordVote(CNIC);
                }
            break;

            case 2:
                e.DislayVotes();
            break;

            case 3:
                e.compileFinalResults();
            break; 

            default:
                cout<<"Invalid Input Try Again!"<<endl;   
        }
    }
}