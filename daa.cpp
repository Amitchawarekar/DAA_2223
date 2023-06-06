#include<iostream>
using namespace std;
class matrix{
    public:
    void input()
    {
        int a[2][2];
        int b[2][2];
        
        cout<<"Enter the Matrix 1 of order 2"<<endl;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<"Enter the element at A("<<i<<" "<<j<<") "<<endl;
                cin>>a[i][j];
            }
        }
        cout<<endl;
        cout<<"Enter the Matrix 2 of order 2"<<endl;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<"Enter the element at B("<<i<<" "<<j<<")"<<endl;
                cin>>b[i][j];
            }
        }
        cout<<"Matrix 1 is "<<endl;
         for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<"  "<<a[i][j];
            }
            cout<<endl;
        }
        cout<<"Matrix 2 is "<<endl;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<"  "<<b[i][j];
            }
            cout<<endl;
        }
    int m1,m2,m3,m4,m5,m6,m7;
        m1=(a[0][0]+a[1][1]) * (b[0][0]+b[1][1]);
        m2=(a[1][0]+a[1][1]) * (b[0][0]);
        m3=((b[0][1]-b[1][1])*(a[0][0]));
        m4=(a[1][1]*(b[1][0]-b[0][0]));
        m5=(a[0][0]+a[0][1])*b[1][1];
        m6=(a[1][0]-a[0][0]) * (b[0][0]+b[0][1]);
        m7=(a[0][1]-a[1][1]) * (b[1][0]+b[1][1]);
        
        int c[2][2];
        c[0][0]=m1+m4-m5+m7;
        c[0][1]=m3+m5;
        c[1][0]=m2+m4;
        c[1][1]=m1+m3-m2+m6;
        /*cout<<"m1 is "<<m1<<endl;
          cout<<"m2 is "<<m2<<endl;
         cout<<"m3 is "<<m3<<endl;
     	 cout<<"m4 is "<<m4<<endl;
	   	 cout<<"m5 is "<<m5<<endl;
	   	 cout<<"m6 is "<<m6<<endl;
	   	 cout<<"m7 is "<<m7<<endl;*/
	     
    cout<<"Matrix Multiplication  is "<<endl;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<"  "<<c[i][j];
            }
            cout<<endl;
        }
    }
};
int main()
{
    matrix a;
    a.input();

    return 0;
}


