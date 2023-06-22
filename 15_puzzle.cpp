#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
#include<map>
using namespace std;

vector<vector<int> >PuzzleTable(4,vector<int>(4));
vector<vector<int> >ruftable(4,vector<int>(4));
map<vector<vector<int> >,int>mymap;
pair<int,int>blank;
int level=1;

// priority_queue<pair<int,    pair < pair<int,int> ,pair<int,vector<vector<int>>>> > > myq;      //val,(blank,(level,vector))
priority_queue<pair<int,    pair < pair<int,int> ,pair<int,pair<int,vector<vector<int>>>>> > > myq;      //val,(blank,(level,(operation,vector))

class branchAndBound{
    int val;
    
    int dRow[4]={-1,0,1,0};
                //up     right     down     left 
    int dCol[4]={0,1,0,-1};
    
    int times=12;
public:
     void setInput(){
            // cout<<"Enter the values ::For blank Enter 0 "<<endl;
            // for(int i=0;i<4;i++){
            //     for(int j=0;j<4;j++){
            //     cout<<"Enter the value in the "<<i <<" ->"<<j<<endl;
            //     cin>>val;
            //         if(val>0){
            //         PuzzleTable[i][j]=val;
            //         }
            //         else{
            //             blank={i,j};
            //         }
            //     }
            // }

            // myq.push()

             //displaying 
            cout<<"The Input Graph is "<<endl;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    // cout<<"The Input Graph is "<<endl;
                    cout<<PuzzleTable[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        //to print 
        void print(vector<vector<int>>PuzzleTable,int cost,int level, string operation){
            cout<<"the next one is  "<<endl;
            cout<<"The cost is "<<cost<<" "<<endl;
            cout<<"Level is "<<level<<endl;
            cout<<"The next move is "<< operation<<endl;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    // cout<<"The Input Graph is "<<endl;
                    cout<<PuzzleTable[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        // void printChild(vector<vector<int>>PuzzleTable,int cost,int level, string operation){
        //     cout<<"the next one is  "<<endl;
        //     cout<<"The cost is "<<cost<<" "<<endl;
        //     cout<<"Level is "<<level<<endl;
        //     cout<<"The next move is "<< operation<<endl;
        //     for(int i=0;i<4;i++){
        //         for(int j=0;j<4;j++){
        //             // cout<<"The Input Graph is "<<endl;
        //             cout<<PuzzleTable[i][j]<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }

        bool isValid(vector<vector<int> >&table,int i,int j){
            if(i<0 || i>3 || j<0 || j>3){
                return false;
            }
            // if(mymap.find(table)!=mymap.end()){
            //     return false;
            // }
        }





        int costfinder(vector<vector<int> >&table,int level){
            int count =0;
             for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(table[i][j]==NULL){
                        continue;
                    }
                    if(i*4+(j+1)!=table[i][j]){
                        count++;
                    }
                }
            }
            
            return count + level;
        }





        void mainstart(vector<vector<int> >&PuzzleTable,pair<int,int>&blank,int level){

                   for(int i=0;i<4;i++){
                        int dx=blank.first + dRow[i];
                        int dy=blank.second + dCol[i];

                       if(isValid(PuzzleTable,dx,dy)){
                        ruftable=PuzzleTable;
                        // visit[dx][dy]=1;
                        int temp=ruftable[dx][dy];
                        ruftable[dx][dy]=ruftable[blank.first][blank.second];
                        ruftable[blank.first][blank.second]=temp;


                        // checking condition repitition

                        if(mymap.find(ruftable)!=mymap.end()){
                            // PuzzleTable=ruftable;
                                continue;
                        }
                        
                        mymap[ruftable]++;

                        //cost finder
                        int cost=costfinder(ruftable,level) * (-1);
                        print(ruftable,cost,level+1," I am The Child ");
                        // cout<<"the cost is "<<cost<<endl;
                        myq.push({cost,{{dx,dy},{level,{i,ruftable}}}});
                    }
                   }
            }

        void next(){
            // while(!myq.empty()){
            while(!myq.empty()){
                pair<int,    pair < pair<int,int> ,pair<int,pair<int,vector<vector<int>>>>> > cell =myq.top();

//idhar dekh 
                myq.pop();



                int val=cell.first *(-1);
                blank.first=cell.second.first.first;
                blank.second=cell.second.first.second;
                int new_level=cell.second.second.first;
                int operation =cell.second.second.second.first;
                string op;
                if(operation==3){
                        op="left";
                }
                else  if(operation==2){
                        op="down";
                }
                else  if(operation==1){
                        op="right";
                }
                else  if(operation==0){
                        op="up";
                }

                PuzzleTable=cell.second.second.second.second;
                if(val==new_level){
                    print(PuzzleTable,val,new_level++,op);
                    break;
                }
                print(PuzzleTable,val,new_level++,op);

               

                mainstart(PuzzleTable,blank,new_level);

                times--;
            }
        }
        


};
int main(){
    branchAndBound c;
    PuzzleTable={{0,1,2,3},{6,7,8,4},{5,9,10,11},{13,14,15,12}};
    // PuzzleTable={{1,2,3,4},{5,6,0,8},{9,10,7,11},{13,14,15,12}};
    // blank={1,2};
    c.setInput();
    c.mainstart(PuzzleTable,blank,level);
    c.next();

    return 0;
}
