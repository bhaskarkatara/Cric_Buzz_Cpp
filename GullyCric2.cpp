//Gully Cricket App
// #include <bits/stdc++.h>
#include<iostream>
// #include"GullyCric22.h"
#include<vector>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<limits.h>
#include<time.h>
#include <chrono>
#include <thread>


using namespace std;


class greeting{
    
    public:

         void GreetingMsg(){

            cout<<  "        ------------------------------------------         "<<endl;
            cout<<  "        |                                        |         "<<endl;
            cout<<  "        |*** WELCOME TO VIRTUAL CRICKET GAME *** |         "<<endl;
            cout<<  "        |                                        |         "<<endl;
            cout<<  "        ------------------------------------------        "<<endl;

            cout <<endl << endl;

            cout <<"                        -------------- "                  <<endl;
            cout <<"          |-------------[Instructions]----------------| " <<endl;
            cout <<"                        --------------   "                <<endl;

            cout<<"         ------------------------------------------------------  " <<endl;
            cout<<"       | 1.Create 2 Team (Team A and Team B with 4 Player each)| "<<endl;
            cout<<"       |   from a given pool of 11 Player                      | "<<endl;
            cout<<"       | 2.Lead the Toss and divide the Choice of Play         | "<<endl;
            cout<<"       | 3.Each inning will be of 6 balls                      | "<<endl;
            cout<<"         ------------------------------------------------------  " <<endl;
            cout<<endl;
            cout<<"        -------------------------------------------------------- " <<endl;
            cout<<"        ||--------------[Pool OF Players]---------------------||  " <<endl;
            cout<<"        -------------------------------------------------------- " <<endl;

     
         } 
          
};

class AllPlayers: public greeting{
  public:
    vector<string>player{" Virat " ," Rohit ", " Dhawan " 
    ," Shubham "," Bhaskar " ," MSD ",
    " Suresh "," Rishab "
    ," Shami "," Sachin "," Bumrah " 
    };

    //constructor
    void printPlayer(){
      
      for( int i = 1; i<player.size() ; i++)
      {
         cout<<"         ["<<i<<"]"<<player[i]    <<endl;
      }
   }
};


class ChoosePlayersForTeamATeamB: public AllPlayers{
    public:
    int n = 0,m = 0;
      vector<string>TeamA,TeamB;
       void SelectPlayer()
       {
         
        for(int i = 1; i<=4; i++)
         {
            cout<<"Select Player "<< i << " for Team A (enter index for choosing player which is mention above) : ";
           
            cin>>n;

               if(n >= 1 && n <= 10)
               {
                 TeamA.push_back(player[n]);
               //   count++;
               }
               else
               {   
                  int local = 0;
                   while(n > 10){
                     cout<<endl;
                     cout<<"Please Enter a Valid Index :)";
                     cout<<endl;
                     cout<<"Select Player "<< i << " for Team A (enter index for choosing player which is mention above): ";
                     cin>>n;
                      local = n;
                     n = local;
                   }
                     TeamA.push_back(player[local]);
               }
            
           cout<<"Select Player "<< i << " for Team B enter index for choosing player which is mention above) :";
          
           cin>>m;
           if(m >= 1 && m <= 10)
           {
           TeamB.push_back(player[m]);
           }

           else
           { 
               int local = 0;
               while(m > 10){
               cout<<endl;
               cout<<"Please Enter a Valid Index :)"<<endl;
               cout<<"Select Player "<< i << " for Team B (enter index for choosing player which is mention above): ";
               cin>>m;
                    local = m;
                     m = local;
               }
               TeamB.push_back(player[local]);
           }
         }
           cout<< "----------[TEAM A PLAYERS]----------- "<<endl;
           cout<<endl;

         for(int i =0; i<TeamA.size() ;i++)
         {
            cout<< " [ " << i << " ] " << TeamA[i] <<endl;
         }
      
      
          cout<< "----------[TEAM B PLAYERS]----------- "<<endl;
          cout<<endl;
         for(int i =0; i<TeamB.size() ;i++)
         {
            cout<< " [ " << i << " ] " << TeamB[i] <<endl;
         }
       }
      
          vector<string>FteamA,FteamB;
      void Assign(){
          for(int i= 0; i<TeamA.size(); i++) FteamA.push_back(TeamA[i]);
          for(int i = 0; i < TeamB.size(); i++)FteamB.push_back(TeamB[i]);
      }  

     
  
};


 class toss{
     public:
     int num;
     void enterToss(){
       cout<< "Please Enter to toss " <<endl;
       cout << endl;
     }
     
     void letsToss(){
            cout<<"        -------------------------------------------------- " <<endl;
            cout<<"        ||--------------[Let's Toss]---------------------||  " <<endl;
            cout<<"        --------------------------------------------------- " <<endl;
     }

     void tossProcessing()
     {

          cout<<"Tossing the Coin....." <<endl;
         
          _sleep(10000);
            srand(time(0));
            num = rand()%2;
            if(num == 1){
               cout<<"Team-A Won the Toss " <<endl;
            }
            else{
            cout<<"Team-B Won the Toss " <<endl;
    }
     }
         int inputNumber;
    void tossProcessing2()
    {
         
         cout << "press 1 for batting / 2 for bowling.... " << endl;
         cin >> inputNumber;

        if(inputNumber == 1){
         if(num == 1)
           cout<<"Congratulations Team-A opted to bat first ..." <<endl;
             else 
               cout<<"Congratulations Team-B opted to bat first ..." <<endl;
        }
        else{
           if(num == 1)
             cout<<"Congratulations Team-A opted to ball first ... " <<endl;
               else 
                  cout<<"Congratulations Team-B opted to ball first ..." <<endl;
        }
    }
 };


 // inherit class ChoosePlayersForTeamATeamB  and class toss

class Inning:public ChoosePlayersForTeamATeamB,public toss{
   
   public:
   
    string curr_bolwer,curr_batsman;
    bool checkbatsmanTA = false,checkbatsmanTB = false;
    bool checkbowlerTA = false,checkbowlerTB = false;
    int curr_Score_teamA = 0,curr_Score_teamB = 0;
     int idx = 1;

   void FirstInning(){

            cout<< "------- First Inning Start -------"<<endl;
            cout<<endl;
            
            if(num == 1){ // means teamA win 
               if(inputNumber == 1){ // team A choose bat
                  checkbatsmanTA = true;
                  checkbatsmanTB = true;
                  curr_batsman = FteamA[0];
                  curr_bolwer = FteamB[0];
                  cout<< " TeamA :- " << FteamA[0] << " is batting ..."<<endl;
                  cout<< " TeamB :- " << FteamB[0] << " is bowling ..."<<endl;
               }
               else{
                  checkbatsmanTB = true;
                  checkbowlerTA = true;
                  curr_batsman = FteamB[0];
                  curr_bolwer = FteamA[0];
                  cout<< " TeamA :- " << FteamA[0] << " is bowling ..."<<endl;
                  cout<< " TeamB :- " << FteamB[0] << " is bating ..."<<endl;
               }
            }
            else{ // means teamb win
               if(inputNumber == 1){
                  checkbatsmanTB = true;
                   checkbowlerTA = true;
                  curr_batsman = FteamB[0];
                  curr_bolwer = FteamA[0];
                  cout<< " TeamB :- " << FteamB[0] << " is batting ..."<<endl;
                  cout<< " TeamA :- " << FteamA[0] << " is bowling ..."<<endl;
               }
               else{
                  checkbatsmanTA = true;
                  checkbatsmanTB = true;
                  curr_batsman = FteamA[0];
                  curr_bolwer = FteamB[0];
                  cout<< " TeamB :- " << FteamB[0] << " is bowling ..."<<endl;
                  cout<< " TeamA :- " << FteamA[0] << " is bating ..."<<endl;
               }
            }
            int wicket = 0;
            int ball = 0;
         for(int i = 0; i < 6;i++){
            ball++;
            cout<< " Press Enter to bowl ..."<<endl<<endl;
            cout<< " Bowling..." <<endl;

             srand(time(0));
            int curr_val =  rand()%6;
            
            if(curr_val == 0){ // 0 means OUT
                wicket++;
                cout<< curr_bolwer  << " to " << curr_batsman << " OUT!!"<<endl;

                if(checkbatsmanTA) curr_batsman = FteamA[idx++];
                else if(checkbatsmanTB) curr_batsman = FteamB[idx++];

             // Add score Card
                if(checkbatsmanTA){
                  
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A  " << curr_Score_teamA << " - " << wicket << "(" << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B " << curr_Score_teamA << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }

            }
            else if(curr_val == 1){
                  curr_Score_teamA += 1;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                  cout<< "  Team-A  " << curr_Score_teamA << " - " << wicket << "(" << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B " << curr_Score_teamA << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 2){
                curr_Score_teamA += 2;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A  " << curr_Score_teamA << " - " << wicket << "(" << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B " << curr_Score_teamA << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 3){
               curr_Score_teamA += 3;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                 cout<< "  Team-A  " << curr_Score_teamA << " - " << wicket << "(" << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B " << curr_Score_teamA << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 4){
               curr_Score_teamA += 4;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A  " << curr_Score_teamA << " - " << wicket << "(" << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B " << curr_Score_teamA << "-" << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 5){
                curr_Score_teamA += 5;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                  cout<< "  Team-A  " << curr_Score_teamA << " - " << wicket << "(" << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B"  << curr_Score_teamA << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 6){
                curr_Score_teamA += 6;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                  cout<< "  Team-A  " << curr_Score_teamA << " - " << wicket << "(" << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B " << curr_Score_teamA << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }  
         }
         cout<<endl;
           cout<<"SUMmary of first Inning........."<<endl<<endl;
         //Summary of first Inning
               if(checkbatsmanTA){

                  cout<< " Team-A " << curr_Score_teamA <<" - " << wicket <<" ( " << ball << " ) "<<endl;
                  cout<<endl;
                  cout<<" Team-B " << "needs " << curr_Score_teamA+1 <<" runs to win the match "<<endl;

                }else if(checkbatsmanTB){
                      cout<< " Team-B " << curr_Score_teamA <<" - " << wicket <<" ( " << ball << " ) "<<endl;
                      cout<<endl;
                     cout<<" Team-A " << "needs " << curr_Score_teamA+1 <<" runs to win the match "<<endl;

                }
   }
 

 // reset score


   void SecondInning(){
    
        cout<<endl;
        cout<< "------- Second Inning Start ------ "<<endl;
        cout<<endl;

        // reArrange batsman and bolwer
        if(checkbatsmanTA){
          checkbatsmanTA = false;
          checkbowlerTA = true;
          checkbatsmanTB = true;
          curr_bolwer = FteamA[0];
          cout<< "Team-A " << curr_bolwer << " is bowling... "<<endl;
         //  cout<< "Team-B " << curr_batsman << "is batting..." <<endl; 
        }
        else if(checkbatsmanTB){
          checkbatsmanTB = false;
          checkbatsmanTA = true;
          checkbowlerTB = true;
          curr_bolwer = FteamB[0];
           cout<< "Team-B " << curr_bolwer << " is bowling... "<<endl;
            // cout<< "Team-A " << curr_batsman << " is bating... "<<endl;
        }


       if(checkbowlerTA){
         checkbatsmanTA = true;
         checkbowlerTA = false;
         checkbowlerTB = true;

          curr_batsman = FteamA[0];
          cout<< "Team-A " << curr_batsman << " is batting... "<<endl;
         //  cout<< "Team-B " << curr_bolwer << " is bowling..." <<endl;
          
       }
       else if(checkbowlerTB){
         checkbatsmanTB = true;
         checkbowlerTB = false;
         checkbowlerTA = true;
         curr_batsman = FteamB[0];
         cout<< "Team-B " << curr_batsman << " is batting... "<<endl;
         // cout<<" Team-A" << curr_bolwer << "   is bowling..."<<endl;
       }

       idx = 1;
       int wicket = 0;
       int ball = 0;
         for(int i = 0; i < 6; i++){
            ball++;
             cout<< "Press Enter to bowl ..."<<endl<<endl;
             cout<< " Bowling..." <<endl;

              srand(time(0));
              int curr_val =  rand()%6;

            if(curr_val == 0){ // 0 means OUT
               wicket++;
                cout<< curr_bolwer  << " to " << curr_batsman << " OUT!!" <<endl;

               if(checkbatsmanTA) curr_batsman = FteamA[idx++];
              else if(checkbatsmanTB) curr_batsman = FteamB[idx++];


               if(checkbatsmanTA){
                  
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                         cout<< "  Team-B " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
                 
            }
            else if(curr_val == 1){
                curr_Score_teamB += 1;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                        cout<< "  Team-B " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 2){
               curr_Score_teamB += 2;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A "  << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                          cout<< "  Team-B " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 3){
               curr_Score_teamB += 3;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                         cout<< "  Team-B " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 4){
               curr_Score_teamB += 4;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A " << curr_Score_teamB << " - "  << wicket << " ( " << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                        cout<< "  Team-B " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 5){
               curr_Score_teamB += 5;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                        cout<< "  Team-B " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
             else if(curr_val == 6){
               curr_Score_teamB += 6;
               if(checkbatsmanTA){
                   cout<< "----------------------------------------------------------------"<<endl;
                   cout<< "  Team-A " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                   cout<<"-----------------------------------------------------------------"<<endl;

                }else if(checkbatsmanTB){
                      cout<< "----------------------------------------------------------------"<<endl;
                      cout<< "  Team-B " << curr_Score_teamB << " - " << wicket << " ( " << ball <<" ) "  <<endl;
                      cout<<"-----------------------------------------------------------------"<<endl;
                }
            }
            
         }
        
        cout<<"SUMmary of Second Inning........."<<endl;
         //Summary of second Inning
               if(checkbatsmanTA){

                  cout<< " Team-A " << curr_Score_teamB <<" - " << wicket <<" ( " << ball << ")"<<endl;
                  cout<<endl;

                }else if(checkbatsmanTB){
                      cout<< " Team-B " << curr_Score_teamB <<" - " << wicket <<" ( " << ball << ")"<<endl;
                      cout<<endl;
                }
       
        if(curr_Score_teamA > curr_Score_teamB){
          cout<< "----Team-A WON the Match-----"<<endl;
        }
        else{
          cout<< "----Team-B WON the Match-----"<<endl<<endl;
        }

        cout<< " MATCH ENDS  " <<endl;
         }

     void MatchConclusion(){

       // todo : add each player scoreCard of Each team
     }    
      


};



int main(){
   //dynamical allocated object
      //class1
         greeting *greet = new greeting;
         greet ->GreetingMsg();
         
         //class2
         AllPlayers * pool = new AllPlayers; 
         pool->printPlayer();
     
     // for acces class ChoosePlayersForTeamATeamB
        Inning* inning = new Inning();
         inning->SelectPlayer();
         inning->Assign();
      
      //class4
         inning->enterToss();
         inning->letsToss();
         inning->tossProcessing();
         inning->tossProcessing2();
      

      // class5
         inning->FirstInning();
         inning->SecondInning();
         // inning->MatchConclusion();
         delete greet;
         delete pool;
         delete inning;

    return 0;
}