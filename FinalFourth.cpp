#include<bits/stdc++.h>
using namespace std;
class E_mail
{
public:
    string SendName;
    string HistoryRecieve;
    string subject;
};
class CompWhoDateSubject
{
public:
    bool Who(string rhs,string ihs)
    {
        if(ihs<=rhs)
            return true ;
        else return false;
    }
};
class CompDateWhoSubject
{
public:

    bool Who(string rhs,string ihs)
    {
        if(ihs<=rhs)
            return true ;
        else return false;
    }
};
class CompSubjectWhoDate
{
public:
    bool Who(string rhs,string ihs)
    {
        if(ihs<=rhs)
            return true ;
        else return false;
    }
};
class MailBox:public E_mail
{
    vector<E_mail>V;
public:
    MailBox() {}
    void SortWho(string name[],string date[],string subject[],int sizee)
    {
        vector<pair<pair<string,string>,string >  >VW;
        for(int i=0; i<sizee; i++)
            VW.push_back(make_pair(make_pair(name[i],date[i]),subject[i]));
        sort(VW.begin(),VW.end());
        cout<<"Do you want to print the elements int the vector ? if yes enter yes else enter no"<<endl;
        string ss;
        cin>>ss;
        if(ss=="yes")
        {
            for(int i=0; i<sizee; i++)
            {
                cout<<"the name is :"<<VW[i].first.first<<endl<<"the date is :"<<VW[i].first.second<<endl<<"the subject is :"<<VW[i].second<<endl;
            }
        }
        else cout<<"."<<endl;
    }
    void SortDate(string name[],string date[],string subject[],int sizee)
    {
        vector<pair<pair<string,string>,string >  >VD;
        for(int i=0; i<sizee; i++)
            VD.push_back(make_pair(make_pair(date[i],name[i]),subject[i]));
        sort(VD.begin(),VD.end());
        cout<<"Do you want to print the elements int the vector ? if yes enter yes else enter no"<<endl;
        string ss;
        cin>>ss;
        if(ss=="yes")
        {
            for(int i=0; i<sizee; i++)
            {
                cout<<"the date is :"<<VD[i].first.first<<endl<<"the name is :"<<VD[i].first.second<<endl<<"the subject is :"<<VD[i].second<<endl;
            }
        }
        else cout<<"."<<endl;
    }
    void SortSubject(string name[],string date[],string subject[],int sizee)
    {
        vector<pair<pair<string,string>,string >  >VS;
        for(int i=0; i<sizee; i++)
            VS.push_back(make_pair(make_pair(subject[i],date[i]),name[i]));
        sort(VS.begin(),VS.end());
        cout<<"Do you want to print the elements int the vector ? if yes enter yes else enter no"<<endl;
        string ss;
        cin>>ss;
        if(ss=="yes")
        {
            for(int i=0; i<sizee; i++)
            {
                cout<<"the subject is :"<<VS[i].first.first<<endl<<"the date is :"<<VS[i].first.second<<endl<<"the name is :"<<VS[i].second<<endl;
            }
        }
        else cout<<"."<<endl;
    }
};
int main()
{
    CompDateWhoSubject CDWS;
    CompSubjectWhoDate CSWD;
    CompWhoDateSubject CWDS;
    string who1,who2,date1,date2,subject1,subject2;
    cout<<"Enter the name1 and date1 and subject1"<<endl;
    cin>>who1>>date1>>subject1;
    cout<<"Enter the name2 and date2 and subject3"<<endl;
    cin>>who2>>date2>>subject2;
    if((CWDS.Who(who1,who2))||(!CWDS.Who(who1,who2)))
    {
        if(who1>who2)
        {
            cout<<"the person one is greater than person 2"<<endl;
        }
        else if(who1<who2)
        {
            cout<<"the person one is smaller than person 2"<<endl;
        }
        if(who1==who2)
        {
            cout<<"the names are equal "<<endl;
            if(CDWS.Who(date1,date2)||(!CDWS.Who(date1,date2)))
            {
                if(date1>date2)
                {
                    cout<<"the date one is greater than date 2"<<endl;
                }
                else if(date1<date2)
                {
                    cout<<"the date1 one is smaller than date 2"<<endl;
                }
                if(date1==date2)
                {
                    cout<<"the names and dates are equal "<<endl;
                    if(CSWD.Who(subject1,subject2)||(!CSWD.Who(subject1,subject2)))
                    {

                        if(subject1>subject2)
                        {
                            cout<<"the subject one is greater than subject 2"<<endl;
                        }
                        else if(subject1<subject2)
                        {
                            cout<<"the subject one is smaller than subject 2"<<endl;
                        }
                        if(subject1==subject2)
                        {
                            cout<<"the messages are equal "<<endl;
                        }
                    }
                }
            }
        }
    }
    string aname[5];
    string adate[5];
    string asubject[5];
    cout<<"enter five msg"<<endl;
    for(int i=0; i<5; i++)
    {

        cout<<"enter the name and date and the subject of it "<<i+1<<endl;
        cin>>aname[i]>>adate[i]>>asubject[i];
    }
    MailBox M;
    M.SortDate(aname,adate,asubject,5);
    M.SortSubject(aname,adate,asubject,5);
    M.SortWho(aname,adate,asubject,5);
    return 0;
}
