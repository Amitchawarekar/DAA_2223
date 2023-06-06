#include<iostream>
using namespace std;

class Matrix{
	public:
		void input()
		{
			int a[2][2];
			int b[2][2];
			
			cout<<"Enter the matrix 1 of order 2"<<endl;
			for (int i=0;i<2;i++){
				for (int j=0;j<2;j++){
					cout<<"Enter the element at A("<<i<<" "<<j<<") "<<endl;
					cin>> a[i][j];
				}
			}
			
			cout<<endl;
			
			cout<<"Enter the matrix 2 of order 2 "<<endl;
			for (int i=0;i<2;i++){
				for (int j=0;j<2;j++){
					cout<<"Enter the element at B("<<i<<" " <<j<<")"<<endl;
					cin>> b[i][j];
				}
			}
			
			//Displaying the matrix
			cout<<"Matrix 1 is " <<endl;
			for(int i=0;i<2;i++){
				for (int j=0;j<2;j++){
					
					cout<< " " << a[i][j];
				}
				cout<<endl;
			}
			
			cout<<"Matrix 2 is" <<endl;
			for (int i=0;i<2;i++){
				for (int j=0;j<2;j++){
					
					cout<< " " << b[i][j]; 
				}
				cout<<endl;
			}
			
			//Strassen's Matrix formulas
			int m1,m2,m3,m4,m5,m6,m7;
			m1 = (a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
			m2 = (a[1][0] + a[1][1]) * b[0][0]; 
			m3 = a[0][0] * (b[0][1] - b[1][1]);
			m4 = a[1][1] * (b[1][0] - b[0][0]);
			m5 = (a[0][0] + a[0][1]) * b[1][1];
			m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
			m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
			
			
			//Resultant Matrix
			int res[2][2];
			res[0][0] = m1 + m4 +- m5 + m7;
			res[0][1] = m3 + m5;
			res[1][0] = m2 + m4;
			res[1][1] = m1 + m3 - m2 + m6;
			
			
			//Display Resultant Matrix
			cout<<"Strassen's Matrix Multiplication = "<<endl;
			for(int i=0; i<2; i++){
				for(int j=0;j<2;j++){
					
					cout<< " " << res[i][j];
					
				}
				cout<<endl;
				
			}
		}
};

int main(){
	Matrix a;
	a.input();
	
	return 0;
}
