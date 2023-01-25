#include<iostream>
#include<fstream>
using namespace std;
	class login
	{
	  protected:
	  char w[3];
	  string firstname;
	  string lastname;
	  int age;
	  string email;
	  string password;
      string confirm;
	  long long int mobile;
      int chosentime;
      int chosenaim;
	  string timeslot[8]={"9:00-10:00 AM","10:00-11:00 AM","11:00-12:00 PM","3:00-4:00 PM","4:00-5:00 PM","5:00-6:00 PM","6:00-7:00 PM","7:00-8:00 PM"} ;
	  string aim[10]={"Chest","Back","Biceps","Triceps","Abs Workout","Full Body","Upper Body Only","Lower Body Only","Weight Loss","Weight Gain"} ;

	  public:
	  void who();
	  void usergetdata();
      void userdisplaydata();
	  void admingetdata();
      void admindisplaydata();
      void membergetdata();
	};

	void login::who()
	{
	    cout<<"Are you a user?\nType Yes or No: ";
	    cin>>w;
	    if(w[0]=='y'||w[0]=='Y')
	    usergetdata();
	    else
        admingetdata();
	}

	void login::usergetdata()
	{
        char x[3];
        cout<<"Already A member?\nType Yes or No: ";
        cin>>x;
        if(x[0]=='y'||x[0]=='Y')
        membergetdata();
        else
	    {
            cout<<"Enter First Name: "<<endl;
            cin>>firstname;
            cout<<"Enter Last Name: "<<endl;
            cin>>lastname;
            cout<<"Enter Age: "<<endl;
            cin>>age;
            cout<<"Enter email id: "<<endl;
            cin>>email;
            cout<<"Enter Mobile Number: "<<endl;
            cin>>mobile;
            cout<<"Enter Password: "<<endl;
            cin>>password;
            cout<<"Confirm Password: "<<endl;
            cin>>confirm;

            while(password!=confirm)
            {
                cout<<"The Passwords Do Not Match. Please Check again."<<endl;
                cout<<"Enter Password: ";
                cin>>password;
                cout<<"Confirm Password: ";
                cin>>confirm;

            }
            cout<<"Choose Your Preffered Time Slot: "<<endl;
            for(int i=0;i<8;i++)
            {
                cout<<i+1<<"."<<timeslot[i]<<endl;
            }
            cout<<"Please Provide The Serial Number Of The Time Slot You Wish To Choose: ";
            cin>>chosentime;

            cout<<"Choose Your Aim Which You Wish To Fulfill Here: "<<endl;
            for(int i=0;i<10;i++)
            {
                cout<<i+1<<"."<<aim[i]<<endl;
            }
            cout<<"Please Provide The Serial Number Of The Aim You Wish To Fulfill Here:  ";
            cin>>chosenaim;
            userdisplaydata();
	    }
    }
    void login::userdisplaydata()
    {
        char change[10];
        cout<<"First Name: "<<firstname<<endl;
        cout<<"Last Name: "<<lastname<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"email id: "<<email<<endl;
        cout<<"Mobile Number: "<<mobile<<endl;
        cout<<"Time Slot: "<<timeslot[chosentime-1]<<endl;
        cout<<"Aim: "<<aim[chosenaim-1]<<endl;
        cout<<"Please Check the Details Again."<<endl;
        cout<<"Do you wish to change any details?(type yes or no): ";
        cin>>change;
        if(change[0]=='y')
        usergetdata();
        else
        cout<<"Thank You for Joining with us.\nYou can start from Tomorrow.\nWe will contact ypu soon with Other details.";

        ofstream out("users.txt",ios::app);
        out<<"First Name: "<<firstname<<endl;
        out<<"Last Name: "<<lastname<<endl;
        out<<"Age: "<<age<<endl;
        out<<"email id: "<<email<<endl;
        out<<"Mobile Number: "<<mobile<<endl;
        out<<"Time Slot: "<<timeslot[chosentime-1]<<endl;
        out<<"Aim: "<<aim[chosenaim-1]<<endl;
        out<<"Password: "<<password<<endl;

        out.close();
    }
    void login::membergetdata()
    {

        cout<<"Enter email id: ";
        cin>>email;
        cout<<"Enter password: ";
        cin>>password;
        int c;
        string data;
        string checkemail;
        string checkpw;
        bool matched=false;
        ifstream in("users.txt");
        in.seekg(0,ios::end);
        int filesize = in.tellg();
        in.seekg(0,ios::beg);
            for(int j=0;j<filesize;j++)
            {
                in>>checkemail;
                if(checkemail=="id:")
                {
                    in>>checkemail;
                    if(checkemail==email)
                    {
                        c=j;
                    for(int i=0;i<filesize;i++)
                    {
                        in>>checkpw;
                        if(checkpw=="Password:")
                        {
                            in>>checkpw;
                            if(checkpw==password)
                            {
                                matched=true;
                                in.close();
                            }
                        }

                    }
                    }

                }
                if(matched)
                {
                    in.open("users.txt");
                    break;
                    for(int i=0;i<filesize;i++)
                        {
                            if(i==c)
                            {
                                in>>data;
                                if(data=="first")
                                getline(in,data);
                                cout<<data<<endl;
                            }
                            if(i>c+4)
                            break;

                        }
                        break;
                }
                }

            if(!matched)
            {
                cout<<"Invalid email id or password.Please try again."<<endl;
                membergetdata();
            }
            in.close();
    }
    void login::admingetdata()
    {
        cout<<"Enter email id: ";
        cin>>email;
        cout<<"Enter password: ";
        cin>>password;
        while(email!="admin@gmail.com"|| password!="admin123")
        {
            cout<<"Invalid username or password.Please try again."<<endl;
            cout<<"Enter email id: ";
            cin>>email;
            cout<<"Enter password: ";
            cin>>password;
        }
        admindisplaydata();
    }
    void login::admindisplaydata()
    {
        string read;
        ifstream ifs("admin.txt");
        getline(ifs,read);
        cout<<read<<endl;
    }

int main()
{
    login l1;
    cout<<"Welcome to The Gym Membership System Form.\nWe offer you the Best Training to make You Fit.\nKindly Fill the following details to join with us.\n";
    l1.who();


    return 0;
}
