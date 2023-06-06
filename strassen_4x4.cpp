#include<iostream>
using namespace std;

class Matrix{
	public:
		void input()
		{
			int a[4][4];
			int b[4][4];
			
			cout<<"Enter the matrix 1 of order 4"<<endl;
			for (int i=0;i<4;i++){
				for (int j=0;j<4;j++){
					cout<<"Enter the element at A("<<i<<" "<<j<<") "<<endl;
					cin>> a[i][j];
				}
			}
			
			cout<<endl;
			
//			cout<<"Enter the matrix 2 of order 4 "<<endl;
//			for (int i=0;i<4;i++){
//				for (int j=0;j<4;j++){
//					cout<<"Enter the element at B("<<i<<" " <<j<<")"<<endl;
//					cin>> b[i][j];
//				}
//			}
			
			//Displaying the matrix
			cout<<"Matrix 1 is " <<endl;
			for(int i=0;i<4;i++){
				for (int j=0;j<4;j++){
					
					cout<< " " << a[i][j];
				}
				cout<<endl;
			}
			
//			cout<<"Matrix 2 is" <<endl;
//			for (int i=0;i<4;i++){
//				for (int j=0;j<4;j++){
//					
//					cout<< " " << b[i][j]; 
//				}
//				cout<<endl;
//			}
			
			//dividing 4x4 matrix into 2x2 matrix
//			int a00;
//			a00 = (a[0][0] * a[0][1]) + (a[0][1] * a[1][0]);
//			a01 = (a[0][2] * a[1][3]) + (a[0][3] * a[1][2]);
//			a10 = (a[2][0] * a[3][1]) + (a[2][1] * a[3][0]);
//			a11 = (a[2][2] * a[3][3]) + (a[2][3] * a[3][2]);
//			
			
			int a00[2][2];
			int a01[2][2];
			int a10[2][2];
			int a11[2][2];

			for (int i = 0; i < 2; i++)
			{
    			for (int j = 0; j < 2; j++)
    			{			
        			a00[i][j] = a[i][j];
        			a01[i][j] = a[i][j+2];
        			a10[i][j] = a[i+2][j];
        			a11[i][j] = a[i+2][j+2];
    			}
			}		
			
			int b00[2][2];
			int b01[2][2];
			int b10[2][2];
			int b11[2][2];

			for (int i = 0; i < 2; i++)
			{
    			for (int j = 0; j < 2; j++)
    			{			
        			b00[i][j] = b[i][j];
        			b01[i][j] = b[i][j+2];
        			b10[i][j] = b[i+2][j];
        			b11[i][j] = b[i+2][j+2];
    			}
			}
			
			void multiply(double x[2][2], double y[2][2]){
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
				}	
				
			double c11;
			c11 = multiply(a00, b00);
			cout<< c11 << end;	
	
	}
};

int main(){
	Matrix a;
	a.input();
	
	return 0;
}
