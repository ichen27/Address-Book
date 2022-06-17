//Ivan Chen
//Final Project
//Address Book

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct address{
  string house;
  string street;
  string city;
  string state;
  string zip;
};
struct entry {
  string last;
  string first; 
  string email;
  string phone;
  address a;
};


 entry e;
 //entry::address a;

bool load(vector<entry>&);
bool save(vector<entry>&);
bool add(vector<entry> &);
bool remove(vector<entry> &);
bool edit(vector<entry> &);
void sort(vector<entry> &);
bool search(vector<entry> &);
void print(vector<entry>);


int main(){

  
  vector<entry>data;
  int quit = 0;
  while(quit == 0){
  int choice = 0;
  cout<<"1) Load from file"<<endl;
  cout<<"2) Save to file"<<endl;
  cout<<"3) Add an entry"<<endl;
  cout<<"4) Remove and entry"<<endl;
  cout<<"5) Edit an existing entry"<<endl;
  cout<<"6) Sort the address book"<<endl;
  cout<<"7) Search for a specific entry"<<endl;
  cout<<"8) Quit"<<endl;
  while(choice < 1 || choice > 8){
    cin>>choice;
  }
  switch(choice){
    case 1:
    load(data);
    break;

    case 2:
    save(data);
    break;

    case 3:
    add(data);
    break;

    case 4:
    remove(data);
    break;

    case 5:
    edit(data);
  
    break;

    case 6:
    sort(data);
    break;

    case 7:
    search(data);
    break;

    case 8:
    quit = 1;
    break;
  }
  }
  
}


bool load(vector<entry>& data){
  
  vector<string>open;
  string doc;

  cin.ignore(80,'\n');
  cout<<"What file would you like to load: ";
  getline(cin, doc);

  doc = doc + ".csv";
  
  ifstream file(doc, ios::in);
  string line;
  
  if(!file){
    cout<<"File did not load"<<endl;
    return false;
    
  }else{
    cout<<"File successfully loaded"<<endl;
    int num = 0;
    while(!file.eof()){
    getline(file, line);
    //cout<<line<<endl;
    if(num>0){
  
    int comma1 = line.find(",", 0);
    //cout<<"comma1: "<<comma1<<" ";
    e.last = line.substr(0, comma1);
    //cout<<e.last<<" ";
    int comma2 = line.find(",", comma1+1);
      //cout<<"comma2: "<<comma2<<" ";
    e.first = line.substr(comma1+1, (comma2-1)-comma1);
     // cout<<e.first<<" ";
    int comma3 = line.find(",", comma2+1);
      //cout<<"comma3: "<<comma3<<" ";
    e.a.house = line.substr(comma2+1, (comma3-1)-comma2);
      //cout<<a.house<<" ";
    int comma4 = line.find(",", comma3+1);
      ///cout<<"comma4: "<<comma4<<" ";
    e.a.street = line.substr(comma3+1, (comma4-1)-comma3);
      //cout<<a.street<<" ";
    int comma5 = line.find(",", comma4+1);
      //cout<<"comma5: "<<comma5<<" ";
    e.a.city = line.substr(comma4+1, (comma5-1)-comma4);
      //cout<<a.city<<" ";
    int comma6 = line.find(",", comma5+1);
      //cout<<"comma6: "<<comma6<<" ";
    e.a.state = line.substr(comma5+1, (comma6-1)-comma5);
      //cout<<a.state<<" ";
    int comma7 = line.find(",",comma6+1);
      //cout<<"comma7: "<<comma7<<" ";
    e.a.zip = line.substr(comma6+1, (comma7-1)-comma6);
      //cout<<a.zip<<" ";
    int comma8 = line.find(",", comma7+1);
      //cout<<"comma8: "<<comma8<<" ";
    e.phone = line.substr(comma7+1, (comma8-1)-comma7);
      //cout<<e.phone<<" ";
    e.email = line.substr(comma8+1, (line.length()-1)-comma8);
      //cout<<e.email<<" ";
    data.push_back(e);
      //cout<<endl<<endl;

      }
      num++;
  }

  /*
  for(int i = 0; i < data.size(); i++){
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
  }
  */

  /*
  for(entry x : data){
   cout<<x.first<<" "<<x.last<<" "<<x.a.house<<" "<<x.a.street<<" "<<x.a.city<<", "<<x.a.state<<", "<<x.a.zip<<" "<<x.phone<<" "<<x.email<<endl;
  }
  */



    

    return true;
    }
  
  /*
  
  while (file >> line){
    files.push_back(line);
  }

  
  for(string output : files){
    cout<<output;
    cout<<endl<<endl;
  }
  */

}

void sort(vector<entry>& data){
  int choice = 0;
  while(choice < 1 || choice > 5){
  cout<<"Sort by:"<<endl;
  cout<<"1)Last Name"<<endl;
  cout<<"2)First Name"<<endl;
  cout<<"3)Phone Number"<<endl;
  cin>>choice;
  }
  if(choice == 1){
    string lastp, firstp, housep, streetp, cityp, statep, zipp, phonep, emailp;
    for(int i = 0; i < data.size()-1; i++){
      for(int x = 1; x < data.size(); x++){
        if(data.at(i).last > data.at(x).last){
            lastp = data.at(i).last ;
            firstp = data.at(i).first;
            housep = data.at(i).a.house;
            streetp = data.at(i).a.street;
            cityp = data.at(i).a.city;
            statep = data.at(i).a.state;
            zipp = data.at(i).a.zip;
            phonep = data.at(i).phone;
            emailp = data.at(i).email;

            data.at(i).last = data.at(x).last;
            data.at(i).first = data.at(x).first;
            data.at(i).a.house = data.at(x).a.house;
            data.at(i).a.street = data.at(x).a.street;
            data.at(i).a.city = data.at(x).a.city;
            data.at(i).a.state = data.at(x).a.state;
            data.at(i).a.zip = data.at(x).a.zip;
            data.at(i).phone = data.at(x).phone;
            data.at(i).email = data.at(x).email;

            data.at(x).last = lastp;
            data.at(x).first = firstp;
            data.at(x).a.house = housep;
            data.at(x).a.street = streetp;
            data.at(x).a.city = cityp;
            data.at(x).a.state = statep;
            data.at(x).a.zip = zipp;
            data.at(x).phone = phonep;
            data.at(x).email = emailp;
        }
      }
    }
    cout<<"Sorted by last name: "<<endl;
    for(int i = 1; i < data.size(); i++){
    cout<<"Name: "<<data.at(i).last<<", "<< data.at(i).first<<endl;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
  }

  }else if(choice == 2){
    string lastp, firstp, housep, streetp, cityp, statep, zipp, phonep, emailp;
    for(int i = 0; i < data.size()-1; i++){
      for(int x = 1; x < data.size(); x++){
        if(data.at(i).first > data.at(x).first){
            lastp = data.at(i).last ;
            firstp = data.at(i).first;
            housep = data.at(i).a.house;
            streetp = data.at(i).a.street;
            cityp = data.at(i).a.city;
            statep = data.at(i).a.state;
            zipp = data.at(i).a.zip;
            phonep = data.at(i).phone;
            emailp = data.at(i).email;

            data.at(i).last = data.at(x).last;
            data.at(i).first = data.at(x).first;
            data.at(i).a.house = data.at(x).a.house;
            data.at(i).a.street = data.at(x).a.street;
            data.at(i).a.city = data.at(x).a.city;
            data.at(i).a.state = data.at(x).a.state;
            data.at(i).a.zip = data.at(x).a.zip;
            data.at(i).phone = data.at(x).phone;
            data.at(i).email = data.at(x).email;

            data.at(x).last = lastp;
            data.at(x).first = firstp;
            data.at(x).a.house = housep;
            data.at(x).a.street = streetp;
            data.at(x).a.city = cityp;
            data.at(x).a.state = statep;
            data.at(x).a.zip = zipp;
            data.at(x).phone = phonep;
            data.at(x).email = emailp;
        }
      }
    }
    cout<<"Sorted by first name:"<<endl;
    for(int i = 0; i < data.size(); i++){
      cout<<"Entry "<<i+1<<endl;
    cout<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip<<endl;
    cout<<" Phone: "<<data.at(i).phone<<endl;
    cout<<" Email: "<<data.at(i).email<<endl; 
    cout<<endl;
  }
  }else if(choice  == 3){
    string lastp, firstp, housep, streetp, cityp, statep, zipp, phonep, emailp;
    for(int i = 0; i < data.size()-1; i++){
      for(int x = 1; x < data.size(); x++){
        if(data.at(i).phone.substr(0,3) > data.at(x).phone.substr(0,3)){
            lastp = data.at(i).last ;
            firstp = data.at(i).first;
            housep = data.at(i).a.house;
            streetp = data.at(i).a.street;
            cityp = data.at(i).a.city;
            statep = data.at(i).a.state;
            zipp = data.at(i).a.zip;
            phonep = data.at(i).phone;
            emailp = data.at(i).email;

            data.at(i).last = data.at(x).last;
            data.at(i).first = data.at(x).first;
            data.at(i).a.house = data.at(x).a.house;
            data.at(i).a.street = data.at(x).a.street;
            data.at(i).a.city = data.at(x).a.city;
            data.at(i).a.state = data.at(x).a.state;
            data.at(i).a.zip = data.at(x).a.zip;
            data.at(i).phone = data.at(x).phone;
            data.at(i).email = data.at(x).email;

            data.at(x).last = lastp;
            data.at(x).first = firstp;
            data.at(x).a.house = housep;
            data.at(x).a.street = streetp;
            data.at(x).a.city = cityp;
            data.at(x).a.state = statep;
            data.at(x).a.zip = zipp;
            data.at(x).phone = phonep;
            data.at(x).email = emailp;
        }
      }
    }
    cout<<"Sorted by phone number:"<<endl;
    for(int i = 0; i < data.size(); i++){
    cout<<data.at(i).phone;
    cout<<" Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Email: "<<data.at(i).email<<endl; 
  }

  }

}

bool add(vector<entry> & data){
  string last, first, house, phone, zip, street, city, state, email;

  cin.ignore(80, '\n');
  cout<<"Add new entry: "<<endl;
  cout<<"First name: ";
  getline(cin, first);
  e.first = first;
  cout<<"Last Name: ";
  getline(cin, last);
  e.last = last;
  cout<<"House number: ";
  getline(cin,house);
  e.a.house = house;
  cout<<"Street: ";
  getline(cin, street);
  e.a.street = street;
  cout<<"City: ";
  getline(cin, city);
  e.a.city = city;
  cout<<"State: ";
  getline(cin, state);
  e.a.state = state;
  cout<<"Zip: ";
  getline(cin,zip);
  e.a.zip = zip;
  cout<<"Phone number: ";
  getline(cin,phone);
  cout<<"E-mail: ";
  getline(cin, email);
  e.email = email;
  cout<<"Entry successfully added"<<endl;
  data.push_back(e);
  for(int i = 0; i < data.size(); i++){
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
  }
}

bool remove(vector <entry>& data){
  int choice = 0, place;
  for(int i = 0; i < data.size(); i++){
    cout<<"Entry "<<i+1<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
    place = i;
  }
  while(choice < 1 || choice > place){
  cout<<"Which entry would you like to clear?: ";
  cin>>choice;
  }

  data.erase(data.begin()+choice-1);
  cout<<"Entry Successfully removed"<<endl;


}

bool edit(vector <entry>& data){
  int choice = 0, place;
  for(int i = 0; i < data.size(); i++){
    cout<<"Entry "<<i<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
    place = i;
  }
  while(choice < 1 || choice > place){
  cout<<"Which entry would you like to edit: ";
  cin>>choice;
  cin.ignore(80, '\n');
  }

  

  e.last = data.at(choice).last;
  e.first = data.at(choice).first;
  e.a.house = data.at(choice).a.house;
  e.a.street = data.at(choice).a.street;
  e.a.city = data.at(choice).a.city;
  e.a.state = data.at(choice).a.state;
  e.a.zip = data.at(choice).a.zip;
  e.phone = data.at(choice).phone;
  e.email = data.at(choice).email;

  data.erase(data.begin()+choice);

  choice = 0;
  int option;

  while(option > 10 || option < 1){
  cout<<"What would you like to edit?"<<endl;
    cout<<"1)First: "<<e.first<<endl;
    cout<<"2)Last:"<<e.last<<endl;
    cout<<"3)House: "<<e.a.house<<endl;
    cout<<"4)Street: "<<e.a.street<<endl;
    cout<<"5)city: "<<e.a.city<<endl;
    cout<<"6)state: "<<e.a.state<<endl;
    cout<<"7)zip"<<e.a.zip<<endl;
    cout<<"8)Phone: "<<e.phone<<endl;
    cout<<"9)Email: "<<e.email<<endl; 
    cout<<"10)Quit"<<endl;
    cin>>option;
    cin.ignore(80, '\n');

    if (option == 1){
      cout<<"What would you like the change the first name to?"<<endl;
      cout<<"First: ";
      getline(cin,e.first);
      cout<<"First name has been changed"<<endl;
    }else if(option == 2){
      cout<<"What would you like to change the last name to?"<<endl;
      cout<<"Last: "<<endl;
      getline(cin,e.last);
      cout<<"Last name has been changed"<<endl;
    }else if(option == 3){
      cout<<"What would you like to change the house number to?"<<endl;
      cout<<"House: ";
      getline(cin,e.a.house);
      cout<<"House Number has been changed"<<endl;
    }else if(option == 4){
      cout<<"What would you like to change the street to?"<<endl;
      cout<<"Street: ";
      getline(cin,e.a.street);
      cout<<"Street has been changed"<<endl;
    }else if(option == 5){
      cout<<"What would you like to change the city to?"<<endl;
      cout<<"City: ";
      getline(cin,e.a.city);
      cout<<"City has been changed"<<endl;
    }else if(option == 6){
      cout<<"What would you like to change the state to?"<<endl;
      cout<<"State: ";
      getline(cin,e.a.state);
      cout<<"State has been changed"<<endl;
    }else if(option == 7){
      cout<<"What would you like to change the zip code to?"<<endl;
      cout<<"Zip: ";
      getline(cin,e.a.zip);
      cout<<"Zip code has been changed"<<endl;
    }else if(option == 8){
      cout<<"What would you like to change the phone to?"<<endl;
      cout<<"Phone: ";
      getline(cin,e.phone);
      cout<<"Phone number has been changed"<<endl;
    }else if(option == 9){
      cout<<"What would you like to change the email to?"<<endl;
      cout<<"Email: ";
      getline(cin,e.email);
      cout<<"Email has been changed"<<endl;
    }else if(option == 10){
      choice = 1;
    }else{
      cout<<"Please enter a valid input"<<endl;
      choice = 0;
    }
  }
  data.push_back(e);
  e.first = " ";
  e.last = " ";
  e.phone = " ";

}
bool search(vector <entry>& data){
  int choice = 0;
  string find;
  while(choice < 1 || choice > 5){
  cout<<"What would you like to search by?"<<endl;
  cout<<"1)Last Name"<<endl;
  cout<<"2)First Name"<<endl;
  cout<<"3)Phone Number"<<endl;
  cout<<"4)Address"<<endl;
  cin>>choice;
  cin.ignore(80, '\n');
  }
  if(choice == 1){
    int valid = 0;
    int x = 0;
    while(valid == 0){
    cout<<"Enter the last name:";
    getline(cin, find);
    for(int i = 0; i < data.size(); i++){
      if(find == data.at(i).last){
        valid = 1;
        cout<<"Entry "<<i+1<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i). a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
      }else{
        x++;
      }
      if(x == data.size()){
        cout<<"Name not found"<<endl;
        x = 0;
        valid = 0;
      }

    }

    }
  }else if(choice == 2){

    int valid = 0;
    int x = 0;
    while(valid == 0){
    cout<<"Enter the first name:";
    getline(cin, find);
    for(int i = 0; i < data.size(); i++){
      if(find == data.at(i).first){
        valid = 1;
        cout<<"Entry "<<i+1<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
      }else{
        x++;
      }
      if(x == data.size()){
        cout<<"Name not found"<<endl;
        x = 0;
        valid = 0;
      }
    }
    }
  }else if(choice == 3){
    int valid = 0;
    int i = 0;
    while(valid == 0){
    cout<<"Enter the phone number:";
    getline(cin, find);
    for(int i = 0; i < data.size(); i++){
      if(find == data.at(i).phone){
        valid = 1;
        cout<<"Entry "<<i+1<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
      }else{
        cout<<"Phone number not found"<<endl;
      }
    }
    }
  }else if(choice == 4){
    int valid = 0;
    int i = 0;
    entry address;
    while(valid == 0){
    cout<<"Enter the address:";
    getline(cin, find);
    for(int i = 0; i < data.size(); i++){
      if(find == data.at(i).first){
        valid = 1;
        cout<<"Entry "<<i+1<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
      }else{
        cout<<"First name not found"<<endl;
      }
    }
    }
  }else if(choice == 5){
    int valid = 0;
    int i = 0;
    while(valid == 0){
    cout<<"Enter the email:";
    getline(cin, find);
    for(int i = 0; i < data.size(); i++){
      if(find == data.at(i).email){
        valid = 1;
        cout<<"Entry "<<i+1<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
      }else{
        cout<<"Email not found"<<endl;
      }
    }
    }
  }else{
    cout<<"Please enter a valid input"<<endl;
    choice = 0;
  }
}

bool save(vector <entry>& data){
    cin.ignore(80,'\n');
     string lastp, firstp, housep, streetp, cityp, statep, zipp, phonep, emailp;
    for(int i = 0; i < data.size()-1; i++){
      for(int x = 1; x < data.size(); x++){
        if(data.at(i).first > data.at(x).first){
            lastp = data.at(i).last ;
            firstp = data.at(i).first;
            housep = data.at(i).a.house;
            streetp = data.at(i).a.street;
            cityp = data.at(i).a.city;
            statep = data.at(i).a.state;
            zipp = data.at(i).a.zip;
            phonep = data.at(i).phone;
            emailp = data.at(i).email;

            data.at(i).last = data.at(x).last;
            data.at(i).first = data.at(x).first;
            data.at(i).a.house = data.at(x).a.house;
            data.at(i).a.street = data.at(x).a.street;
            data.at(i).a.city = data.at(x).a.city;
            data.at(i).a.state = data.at(x).a.state;
            data.at(i).a.zip = data.at(x).a.zip;
            data.at(i).phone = data.at(x).phone;
            data.at(i).email = data.at(x).email;

            data.at(x).last = lastp;
            data.at(x).first = firstp;
            data.at(x).a.house = housep;
            data.at(x).a.street = streetp;
            data.at(x).a.city = cityp;
            data.at(x).a.state = statep;
            data.at(x).a.zip = zipp;
            data.at(x).phone = phonep;
            data.at(x).email = emailp;
        }
      }
    }
    
    string name;
    ofstream file;
    cout<<"Which file do you want to save to: ";
    getline(cin, name);
    name = name + ".csv";
    file.open(name);
    for(int i = 0; i < data.size(); i++){
    file << data.at(i).last << ", "<<data.at(i).first<<", "<<data.at(i).a.house<<", "<<data.at(i).a.street<<", "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip<<", "<<data.at(i).phone<<", "<<data.at(i).email<<endl;
    }
    file.close();
    data.clear();
    

}

void print(vector <entry>& data){
  for(int i = 0; i < data.size(); i++){
    cout<<"Entry "<<i+1<<":"<<endl;
    cout<<"Name: "<<data.at(i).first<<" "<<data.at(i).last;
    cout<<" Address: "<<data.at(i).a.house<<" "<<data.at(i).a.street<<" "<<data.at(i).a.city<<", "<<data.at(i).a.state<<", "<<data.at(i).a.zip;
    cout<<" Phone: "<<data.at(i).phone;
    cout<<" Email: "<<data.at(i).email<<endl; 
  }
}

