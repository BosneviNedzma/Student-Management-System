#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

class student{
	private:
	string name, roll_no, course, address, email_id, contact_no;
	public: 
	   void menu();
	   void insert();
	   void display();
	   void modify();
	   void search();
	   void deleted();
};
void student::menu(){
	menustart: 
	int choice;
	string x;
	system("cls");
	
	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"\t\t\t| STUDENT MENAGMENT SYSTEM |"<<endl;
	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"\t\t\t1. Enter New Record"<<endl;
	cout<<"\t\t\t2. Display Record"<<endl;
	cout<<"\t\t\t3. Modify Record"<<endl;
	cout<<"\t\t\t4. Search Record"<<endl;
	cout<<"\t\t\t5. Delete Record"<<endl;
	cout<<"\t\t\t6. Exit"<<endl;
	
		cout<<"\t\t\t---------------------------"<<endl;
        cout<<"\t\t\tChoose Option:[1/2/3/4/5/6]"<<endl;
        cout<<"\t\t\t---------------------------"<<endl;
        cout<<"Enter Your Choose: ";
        cin>>choice;
        
    switch(choice){
    	case 1:
    		do{
    			insert();
    			cout<<"\n\t\t\t Add Another Student Record (Y, N): ";
    			cin>>x;
			}while(x == "y" || x == "Y");
    		
    		break;
    	case 2:
    		display();
    		break;
    	case 3:
    		modify();
    		break;
    	case 4:
    		search();
    		break;
    	case 5:
    		deleted();
    		break;
    	case 6:
    		exit (0);
    	default:
    		cout<<"\n\t\t\tInvalid choice... Please Try Again...";
    		break;
	}
	getch();
	goto menustart;
}

void student::insert(){
	system("cls");
	fstream file;
	cout<<"\n---------------------------------------------------------------------------------";
	cout<<"\n---------------------------Add Student Deatails----------------------";
    cout<<"\n\t\t\tEnter Name: ";
    cin>>name;
    cout<<"\t\t\tEnter Roll No.:";
    cin>>roll_no;
    cout<<"\t\t\tEnter Course: ";
    cin>>course;
    cout<<"\t\t\tEnter Email ID: ";
    cin>>email_id;
    cout<<"\t\t\tEnter Contact No.: ";
    cin>>contact_no;
    cout<<"\t\t\tEnter Adress: ";
    cin>>address;
    
    file.open("studentRecord.txt", ios::app);
    file<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<contact_no
    <<" "<<address<<"\n";
    file.close();
    
}

void student::display(){
	system("cls");
	fstream file;
	int total=1;
	cout<<"\n---------------------------------------------------------------------------------";
	cout<<"\n---------------------------Student Record Table----------------------";
    file.open("studentRecord.txt", ios::in);
    if(!file){
    	cout<<"\n\t\t\tNo Data Is Present...";
        file.close();
	}else{
		file>>name>>roll_no>>course>>email_id>>contact_no>>address;
		while(!file.eof()){
			cout<<"\n\n\t\t\tStudent No.: "<<total++<<endl;
			cout<<"\n\n\t\t\tStudent Name: "<<name<<endl;
			cout<<"\n\n\t\t\tStudent Roll No.: "<<roll_no<<endl;
			cout<<"\n\n\t\t\tStudent course: "<<course<<endl;
			cout<<"\n\n\t\t\tStudent Email Id.: "<<email_id<<endl;
			cout<<"\n\n\t\t\tStudent Address: "<<address<<endl;
            file>>name>>roll_no>>course>>email_id>>contact_no>>address;
		}
		
		if(total == 0){
			cout<<"\n\t\tNo data is present"<<endl;
		}
	}
	file.close();
}

void student::modify(){
	system("cls");
	fstream file, file1;
	int found = 0;
	string rollno;
	cout<<"\n---------------------------------------------------------------------------------";
	cout<<"\n---------------------------Student Modify Details----------------------";
  file.open("studentRecord.txt", ios::in);
  if(!file){
  	cout<<"\n\t\t\tNo Data is Present...";
  		file.close();
  }else{
  	cout<<"\nEnter Roll No. of student which you want to Modify: ";
  	cin>>rollno;
  	file1.open("record.txt", ios::app | ios::out);
  	file>>name>>roll_no>>course>>email_id>>contact_no>>address;
  	while(!file.eof()){
  		if(rollno != roll_no){
  			file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<
  			email_id<<" "<<contact_no<<" "<<address<<"\n";
		  }else{
		  	 cout<<"\n\t\t\tEnter Name: ";
             cin>>name;
             cout<<"\t\t\tEnter Roll No.:";
             cin>>roll_no;
             cout<<"\t\t\tEnter Course: ";
             cin>>course;
             cout<<"\t\t\tEnter Email ID: ";
             cin>>email_id;
             cout<<"\t\t\tEnter Contact No.: ";
             cin>>contact_no;
             cout<<"\t\t\tEnter Adress: ";
             cin>>address;
             file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<
  			email_id<<" "<<contact_no<<" "<<address<<"\n";
  		found++;
		  }
	file>>name>>roll_no>>course>>email_id>>contact_no>>address;
    if(found == 0){
    	cout<<"\n\t\t\t Student Roll No. Not Found...";
	}
	  }
	  file1.close();
	  file.close();
	  remove("studentRecord.txt");
	  rename("record.txt", "studentRecord.txt");
  }	
}

void student::search(){
	system("cls");
	fstream file;
	int found=0;
	file.open("studentRecord.txt", ios::in);
	if(!file){
	cout<<"\n---------------------------------------------------------------------------------";
	cout<<"\n---------------------------Student Search Data----------------------";

	}else{
		string rollno;
	cout<<"\n---------------------------------------------------------------------------------";
	cout<<"\n---------------------------Student Search Data----------------------";
    cout<<"\n Enter Roll No. of Student Which You Want to Search: ";
    cin>>rollno;
    file>>name>>roll_no>>course>>email_id>>contact_no>>address;
    while(!file.eof()){
    	if(rollno == roll_no){
			cout<<"\n\n\t\t\tStudent Name: "<<name<<endl;
			cout<<"\n\n\t\t\tStudent Roll No.: "<<roll_no<<endl;
			cout<<"\n\n\t\t\tStudent course: "<<course<<endl;
			cout<<"\n\n\t\t\tStudent Email Id.: "<<email_id<<endl;
			cout<<"\n\n\t\t\tStudent Address: "<<address<<endl;
			found++;
		}
		file>>name>>roll_no>>course>>email_id>>contact_no>>address;
	}
	if (found == 0){
		cout<<"\n\t\t\tStudent Roll No. Not Found...";
	}
	file.close();
	}
}

void student::deleted(){
	system("cls");
	fstream file, file1;
	string roll;
	int found = 0;
		cout<<"\n---------------------------------------------------------------------------------";
	cout<<"\n---------------------------Delete Student Details----------------------";
    file.open("studentRecord.txt", ios::in);
    if(!file){
    	cout<<"\n\t\t\tNo Data is Present...";
    	file.close();
	}else{
		cout<<"\n Enter Roll No. of Student which You Want to Delete Data: ";
	    cin>>roll;
	    file1.open("record.txt", ios::app | ios::out);
	    file>>name>>roll_no>>course>>email_id>>contact_no>>address;
	    while(!file.eof()){
	    	if(roll != roll_no){
	    		file1<<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
			}else{
				found++;
				cout<<"\n\t\tSuccessfully delete data!";
			}
		file>>name>>roll_no>>course>>email_id>>contact_no>>address;

		}
		if(found == 0){
			cout<<"\n\t\t\tStudent Roll No. not found...";
		}
		file1.close();
		file.close();
		remove("studentRecord.txt");
		rename("record.txt", "studentRecord.txt");
	}
}
 main(){
	student project;
	project.menu();
	return 0;
}
