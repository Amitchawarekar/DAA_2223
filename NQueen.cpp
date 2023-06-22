#include <bits/stdc++.h>

using namespace std;

class NQueens{
    int n;
    vector<vector<string> > res;

    public:
        NQueens(int a){
            n = a;
            vector<string> curr(n);
            for(int i=0; i<n; i++) curr[i] = string(n, '.');
            solve(curr, 0);
            print();
        }

        void solve(vector<string> curr, int col){
            if(col==n){
                res.push_back(curr);
                return;
            }

            for(int i=0; i<n; i++){
                if(check(curr, i, col)){
                    curr[i][col] = 'Q';
                    solve(curr, col+1);
                    curr[i][col] = '.';
                }
            }
        }

        bool check(vector<string>& curr, int row, int col){
            int c=col-1, r;
            while(c>=0){
                if(curr[row][c]=='Q') return false;
                c--;
            }
            
            c=col-1;
            r=row-1;
            while(c>=0 && r>=0){
                if(curr[r][c]=='Q') return false;
                r--;
                c--;
            }

            c=col-1;
            r=row+1;
            while(c>=0 && r<n){
                if(curr[r][c]=='Q') return false;
                r++;
                c--;
            }
            
            return true;
        }

        void print(){
            for(auto temp: res){
                for(string str: temp){
                    cout<<str<<endl;
                }
                cout<<endl<<string(n+4, '-')<<endl;
            }
        }
};

int main(){
    int a;
    cout<<"\nEnter the dimension of the board: ";
    cin>>a;
    NQueens n(a);

    return 0;
}
