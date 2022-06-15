#include<iostream>
#include<fstream>
#include<cmath>

using namespace std; 

int main(void)
{
    int n;
    cout<<"Enter number of sample points: ";
    cin>>n;
    //2d array to store points
    double data[n][2];
    //array to store distance
    double distance[n];

    string input, output;

    //taking input and output file path
    cout<<"Enter input path: ";
    cin>>input;
    cout<<"Enter output path: ";
    cin>>output;

    //taking points from file and storing them in 2d array
    ifstream in;
    in.open(input, ios::in);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            in >> data[i][j];
        }   
    }
    in.close();
    cout<<"\nfile read successfully \n";

    //calculate distance of each point from the origin and store it in distance array
     for(int i=0; i<n; i++)
    { 
        distance[i] = sqrt(pow(data[i][0], 2) + pow(data[i][1],2));   
    }
    cout<<"\nDistance of each point from origin calculated \n";

    //sorting distance array
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(distance[i]>distance[j]){
                double temp = distance[i];
                distance[i] = distance[j];
                distance[j] = temp;
            }
        }
    }
    cout<<"\nDistance array sorted \n";

    //writing points and distance of each point in output file
    ofstream out;
    out.open(output, ios::out);
    out << "Sorted distances: \n";
    for(int i=0; i<n; i++)
    {  
        out << distance[i]<<"\n";   
    }
     out.close();
     cout<<"\nResult written in output file\n ";

     return 0;

}