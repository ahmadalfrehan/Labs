#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Human
{
public:
    string name;
    double age;
    Human() {}
    Human(int ag,string na)
    {
        this->age=ag;
        this->name=na;
    }
    int getA()
    {
        return age;
    }
    string getN()
    {
        return name;
    }
    void print()
    {
        cout<<"age "<<age<<"name"<<name<<endl;
    }
};
class Myprint
{
    int a;
public:
    Human ob;
    void print()
    {
        ob.print();
    }
};
class MyUnOp : public Human
{
public:
    Human b;
    double get_ages()
    {
        return b.age;
    }
};
class MyFunc
{
public:
    void Unary(vector<double>v,int m)
    {
        for(int i=0; i<v.size(); i++)
        {
            v[i]-=m;
        }
    }
};
void printArray(vector<double>arr,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printSubsecuence(vector<double>v5,int index,vector<double>subarr)
{
    if(index==v5.size())
    {
        int l=subarr.size();
        if(l!=0)
        {
            printArray(subarr,l);
        }
    }
    else
    {
        printSubsecuence(v5,index+1,subarr);
        subarr.push_back(v5[index]);
        printSubsecuence(v5,index+1,subarr);
    }
    return ;
}
int main()
{

    int n,age;
    string name;
    cout<<"enter the number of objects; "<<endl;
    cin>>n;
    Human * h= new Human[n];
    vector<pair<double ,string > > v(n);
    vector<pair<double ,string > > v1(n);
    for(int i=0; i<n; i++)
    {
        h[i]=Human(i,"ahmad");
    }
    Myprint prt;
    prt.print();
    for(double i=0; i<n; i++)
    {
        v.push_back(make_pair(i,"ahmad"));
    }
    v1=v;
    for(double i=0; i<v.size(); i++)
    {
        cout<<v[i].first<<" . "<<v[i].second<<endl;
    }
    //print the alement using foreach
    //warning ! it is need c++11
    /*
    for(const auto& p : v)
    {
        cout<<p.first<<" . "<<p.second<<endl;
    }*/
    //2
    sort(v1.begin(),v1.end());
    int siz=v1.size();
    double key=v1[siz-1].first;
    for(int i=0; i<v.size(); i++)
    {
        if(key==v[i].first)
        {
            cout<<"Element found"<<v[key].first<<v[key].second<<endl;
        }
        else
        {
            cout<<"Element not found!"<<endl;
        }
    }
    /*if(count(v.begin(),v.end(),key))
    {
    	cout<<"Element found"<<v[key].first<<v[key].second<<endl;
    }
    else cout<<"Element not found!"<<endl;
    //3

    */vector<pair<double,string> >::iterator it;/*
size_t itt=adjacent_find(v.begin(),v.end());
if(itt!=v.end())
cout<<"first occurance is "<<*itt<<endl;
else {cout<<"there is no occurance "<<endl;}*/
    //if( equal( v.begin(),v.end(),h))
    //cout<<"are equal"<<endl;
    //else cout<<"are not equal"<<endl;
    vector<double>v2;
    vector<double>v3;
    v2.reserve(v.size()*2);
    for(int i=0; i<v.size(); i++) //vector<pair<double,string> >::const_iterator itt=v.begin(),end_it=v.end(); it!=end_it; it++)
    {
        v2.push_back(v[i].first);
    }
    int sum =1;
    cout<<"the v2 size is "<<v2.size()<<endl;
    int m=accumulate(v2.begin(),v2.end(),sum);
    cout<<"the average is "<<m/v2.size()<<endl;
    v3=v2;
    sort(v3.begin(),v3.end());
    int c=0;
    vector<double>v4;
    for(int i=1; i<v3.size(); i++)
    {
        if(v3[i-1]==v3[i])
        {
            if(v4.empty())
                v4.push_back(v3[i]);
            else if(v3[i]!=v4.back())
                v4.push_back(v3[i]);
        }
    }
    if(v4.size()==0)
    {
        cout<<"no objects has the same name are found "<<endl;
    }
    else
    {
        for(int i=0; i<v4.size(); i++)
        {
            cout<<"  the objects that has the same name are :"<<endl;
            cout<<v4[i]<<endl;
        }
    }/*
    vector<double>vv;
    vv[0]=1;
    vv[1]=2;
    vv[2]=3;*/
    vector<double>v8;
    printSubsecuence(v2,0,v8);
    MyFunc Mf;
    Mf.Unary(v2,m);
    for(double i=0; i<n; i++)
    {
        v2[i]-=m;
    }
    sort(v2.begin(),v2.end());
    for(double i=0; i<n; i++)
    {
        cout<<v2[i];
    }
    return 0;
}
