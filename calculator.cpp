/*
Note: Start expression with  + and end with =
sample input: +5*3-4.2/2+2.7=
*/

#include<iostream>
using namespace std;

int main(void)
{
    double a, b, ans=0;
    char opertor;
    bool exit = false;
    
    while(!exit)
    {
        cin>>opertor;
        if(opertor == '='){
            break;
        }
        cin>>b;  
       
        switch(opertor)
        {
            case '+':
                ans = ans+b;
            break;

            case '-':
                ans = ans-b;
            break;

            case '*':
                ans = ans*b;
            break;

            case '/':
                if(b == 0)
                    cout<<"Cannot divide by 0";
                ans = ans/b;
            break;

            case '=':
                exit = true;
            break;

        }
    }

    cout<<ans<<endl;

    return 0;

}