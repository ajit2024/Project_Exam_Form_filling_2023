#include<iostream>
#include<string>
using namespace std;
int ginti=0;
class mca
{
private:
    int roll,total_class,p_sub1,p_sub2,p_sub3,p_sub4,
    sub1,sub2,sub3,sub4,total_marks;
    char name[20];
    string grade;
    float percent;


public:
    float per_attend;
    mca():roll(0),total_class(0),sub1(0),sub2(0),total_marks(0),
    sub3(0),sub4(0),p_sub1(0),p_sub2(0),p_sub3(0),p_sub4(0),per_attend(0),percent(0)
    {
        per_attend=input_attendence();
        if(per_attend>=75)
        {
            cout<<"\n Your are qualified to fill up the form !!!"<<endl;
            cout<<"--------------------------------------------------------------------------------";
            getdata();
        }
        else
        {
            cout<<"\n Soory!! not qualified to fill the form !!!"<<endl;
            cout<<"--------------------------------------------------------------------------------";
        }
    }

    void getdata();
    float input_attendence(void);
    void showdata();
    float check()
    {
        return percent;
    }
    int check_roll()
    {
        return roll;
    }
    void grade_check();
};

float mca::input_attendence(void)
{
    cout<<"////////////////////////////////////////////////////////////////////////////////"<<endl;
    ginti=ginti+1;
    printf("(%d)\n\n",ginti);
    cout<<"\n Presents in Subject1(outof 100): ";cin>>p_sub1;
    cout<<"\n Presents in Subject2(outof 100): ";cin>>p_sub2;
    cout<<"\n Presents in Subject3(outof 100): ";cin>>p_sub3;
    cout<<"\n Presents in Subject4(outof 100): ";cin>>p_sub4;
    cout<<"--------------------------------------------------------------------------------";
    total_class=(p_sub1+p_sub2+p_sub3+p_sub4);
    return(float(total_class)/4);
}
void mca::getdata(void)
{
    cin.ignore();
    cout<<"\n Enter your name: ";cin.getline(name,20);
    cout<<"\n Enter your roll: ";cin>>roll;
    cout<<"\n Enter marks of Subject1: ";cin>>sub1;
    cout<<"\n Enter marks of Subject2: ";cin>>sub2;
    cout<<"\n Enter marks of Subject3: ";cin>>sub3;
    cout<<"\n Enter marks of Subject4: ";cin>>sub4;
    total_marks=(sub1+sub2+sub3+sub4);
    percent=float(total_marks)/4;
    grade_check();
}

void mca::showdata(void)
{
    cout<<"  *******************************************************************************"<<endl;
    cout<<"\n Name: "<<name<<"\n Roll: "<<roll<<"\n Total Marks: "<<total_marks
    <<"\n Percentage: "<<percent<<" %"<<"\n Grade: "<<grade<<endl;
}
void mca::grade_check()
{
    if(percent<45)
    {
        grade="F";
    }
    else if(percent>=45&&percent<=50)
    {
        grade="B";
    }
    else if(percent>=51&&percent<=60)
    {
        grade="B+";
    }
    else if(percent>=61&&percent<=70)
    {
        grade="A";
    }
    else if(percent>=71&&percent<=80)
    {
        grade="A+";
    }
    else if(percent>=81&&percent<=90)
    {
        grade="A++";
    }
    else
    {
        grade="O";
    }
}
/////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int i,j,choice,c,k;
    int n;
    cout<<"\n     Program to get result details of class M.C.A II"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"\n Number of Students: ";
    cin>>n;
    mca obj[n];
// now to sorting the data in decreasing order............!!!

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(obj[j].check()>obj[i].check())
            {
                swap(obj[i],obj[j]);
            }
        }
    }
// now to use switch statement for choice!!
    while(1)
    {
        cout<<"-------------------------------------------------------------------------";
        cout<<"\n 1. For your Result"<<endl;
        cout<<" 2. The class merit list"<<endl;
        cout<<" 3. Grading Chart"<<endl;
        cout<<" 4. Exit"<<endl;
        cout<<"\n\n Enter your choice: ";cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\n Enter your roll: ";cin>>k;
                for(i=0;i<n;i++)
                    {
                        if(obj[i].check_roll()==k)
                            {
                                obj[i].showdata();
                            }
                    }
                break;
            case 2:
                c=0;
                for(i=0;i<n;i++)
                    {
                        if(obj[i].check()>0)
                        {
                            cout<<"\n Rank "<<c+1;
                            obj[i].showdata();
                            c++;
                            cout<<"---------------------------------------------------------------------------";
                            }
                    }
                break;
            case 3:
                cout<<"\n     GRADE CRITERIA \n";
                cout<<"=============================================="<<endl;
                cout<<" O    [91-100]  =  Outstanding \n A++  [81-90]  =  Excellent \n A+   [71-80]  =  Very Good";
                cout<<"\n A    [61-70]  =  Good \n B+   [51-60]  =  Average \n B    [45-50]  =  Pass";
                cout<<"\n F    [less than 45]  =  Fail"<<endl;
                break;
            case 4:
                cout<<endl<<"!!! Thank You !!!"<<endl<<" Program End "<<endl;
                exit(1);
            default:
                cout<<"\n wrong choice \n";
        }
    }

return 0;
}
