#include<iostream>
#include<conio.h>
#include<fstream>
#include<vector>
#include<string.h>
#include<ctime>

using namespace std;


template <class T1,class T2,class T3,class T4>

class Employee{
	T1 E_id;
	T2 E_name[10];
	T3 E_row;
	T4 Salary;
	public:
		void input()
		{
			system("cls");
		    cout<<"\n\t\t\t\t\t ______ Employee Setup ______\n\n\n";
			cout<<"Enter Employee id: ";
			cin>>E_id;
			cin.ignore();
			cout<<"Enter Employee Name: ";
			gets(E_name);
			cout<<"Enter Employee Row: ";
			cin>>E_row;
			cout<<"Enter Salary: ";
			cin>>Salary;
		}
		void display()
		{
			system("cls");
		    cout<<"\n\t\t\t\t\t ______ Employee Details ______\n\n\n";
			cout<<"Employee id: ";
			cout<<E_id<<endl;
			cout<<"Employee name: ";
			cout<<E_name<<endl;
			cout<<"Employee Section row: ";
			cout<<E_row<<endl;
			cout<<"Employee Salary: ";
			cout<<Salary<<endl;
		}
		
		   bool check(int x)
           {
                return (E_id == x);
           }
           
           ~Employee()
           {
           	    system("cls");
	 	        cout<<"\n\n\t\t\t\t\t\t*** Thanks For chosing DR store ***";
	 	        cout<<"\n\n\n\t\t\t\t\t  "<<char(3)<<"_____"<<" We are the one who really cares you _____"<<char(3)<<"\n\n";
	 	        cout<<"\n\n\t\t\t\t\t\t   "<<char(4)<<"_____"<<" Happy Shopping _____"<<char(4)<<"\n\n\n";
		   }

};

template <class ID,class n,class p,class q>

class stock{
	protected:
		ID id;
        n name;
        p price;
        q quantity;
	
	public:
		
		void input()
    	{
    		system("cls");
    		cout<<"\n\t\t\t\t\t ______ Adding Products into file ______ \n";
    		cout<<"\nEnter ID of Product :";
    		cin>>id;
    		cin.ignore();
    		cout<<"Enter name of Product :";
			getline(cin,name);
			cout<<"Enter Price of Product :";
			cin>>price;
			cout<<"Enter Quantity of Product :";
			cin>>quantity;
    		ofstream file("product_enteries.txt",ios::app);
    		file<<id<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
    		file.close();
		}
		
		void display()
       {

           ifstream file2("product_enteries.txt");
           cout<<"ID \t\t Name \t\t Price \t\t Quantity \n";
           while(file2 >> id >> name >> price >> quantity)
           {
                cout << id << "\t\t" << name << "\t\t " << price << "\t\t " << quantity << endl;
                  }
            file2.close();
       }
       
       void add_item()
       {
       	    system("cls");
       	    
       	    cout<<"\n\t\t\t\t\t ______ Adding Item ______\n\n";
       	    
       	    ofstream file("product_enteries.txt",ios::app);
       	    
       	    cout<<"\nEnter ID of Product :";
    		cin>>id;
    		cin.ignore();
    		cout<<"Enter name of Product :";
			getline(cin,name);
			cout<<"Enter Price of Product :";
			cin>>price;
			cout<<"Enter Quantity of Product ";
			cin>>quantity;
       	    
    		file<<id<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
    		file.close();
        }
       
	   
};

template <class ID,class n,class p,class q>

class product:public stock<int,string,float,int>{
	protected:
		ID id;
        n name;
        p price;
        q quantity;
    	
	   
};

template <class ID,class n,class p,class q>

class admin{
	protected:
		ID id;
        n name;
        p price;
        q quantity;
    public:
    	
        friend void admin_options();
    	
    	admin()
    	{
    		system("cls");
			cout<<"\n\t\t\t\t\t ______ You login as administrator ______\n";
		}
    	
       void truncate()
      {
      	system("cls");
      	
      	cout<<"\n\t\t\t\t\t ______ Adding New Products ______\n";
      	
    	int x;
    	
    	ofstream file3("product_enteries.txt",ios::trunc);
        file3.close();
        
    	cout<<"\nEnter the number of products you will enter: ";
    	cin>>x;
    	
	    product<int,string,float,int> p1;
	    for(int i=0;i<x;i++)
	     {
	    	 p1.input();
		 }
	    
	  }
	
	    void stock_details()
	  {
	  	 system("cls");
	  	 cout<<"\n\t\t\t\t\t ______ Stock Details ______\n\n";
		 product<int,string,float,int> p1;
		 p1.display();
	  }
	
	  void add_item()
	 {
	 	system("cls");
	  	cout<<"\n\t\t\t\t\t ______ Adding item ______\n\n";
	  	 
	 	cout<<"Enter how many products you want to enter :";
	 	int x;
	 	cin>>x;
	 	
	 	product<int,string,float,int> p1;
	 	
		for(int i=0;i<x;i++)
		{
			p1.add_item();
		}
		
	 }
	
	  void update_item()
	{
		system("cls");
		cout<<"\n\t\t\t\t\t ______ Update options ______\n\n";
		int x;
		vector<int> ids;
    	vector<float> prices;
    	vector<int> quantitys;
    	vector<string> names;
    	
    	ifstream file3("product_enteries.txt");
    	
    	
           while(file3 >> id >> name >> price >> quantity)
           {
           	    
                ids.push_back(id);
                names.push_back(name);
                quantitys.push_back(quantity);
                prices.push_back(price);
                
            }
            file3.close();
            
            cout<<"Enter Product id whose details you want to change: ";
            cin>>x;
            
            for( int i=0; i< ids.size();++i)
            {
            	if(ids[i]==x)
            	{
        	        cout<<"\n\nProduct-id    Product-name    Price    Stock "<<endl;
        	        cout<<"\n"<<ids[i]<<"\t\t"<<names[i]<<"\t  "<<prices[i]<<"    "<<quantitys[i]<<endl;
                    cout<<"\n\nWhat do you want to update?\n";
                    cout<<"\nPress 1 to update name:\n";
                    cout<<"\nPress 2 to update price:\n";
                    cout<<"\nPress 3 to update stock:\n"; 
                    cout<<"\nEnter choice:";

                    switch (getch()) {
                        case '1': {
                        string y;
                        cout << "\n\nEnter new name: ";
                        cin >> y;
                        names[i]=y;
                        break;
                        }
                        case '2': {
                        float new_price; 
                        cout << "\n\nEnter new price: ";
                        cin >> new_price;
                        prices[i] = new_price;
                        break;
                        }
                        case '3': {
                        int new_stock;
                        cout << "\n\nEnter new stock: ";
                        cin >> new_stock;
                        quantitys[i] = new_stock;
                        break;
                        }
                        default:
                        cout << "Invalid input\n";
                    }
                    
                	ofstream file3("product_enteries.txt",ios::trunc);
                	for( int i=0; i< ids.size();++i)
                	{
                		file3<<ids[i]<<" "<<names[i]<<" "<<" "<<prices[i]<<" "<<quantitys[i]<<"\n";
					}
					file3.close();	
					cout<<"\nItem updated: ";
					break;			
				}
			}
			    
				cout<<"\nContinue: ";
			    getch();
			      
	}
	
	void update_discount()
	{
		system("cls");
		cout<<"\n\t\t\t\t\t ______ Update Discount ______\n\n\n";
		int baby,cosmetics,jewelery,grocery;
		int x;  
		string y;
		
		ifstream file("update_discount.txt");
		file>>x;
        file>>y;
        file>>baby;
        file>>cosmetics;
        file>>jewelery;
        file>>grocery;
		file.close();
	    ofstream file2("update_discount.txt");
	    cout<<"Discount in percent: ";
	    cin>>x;
	    cin.ignore();
	    cout<<"Occasion ? ";
	    getline(cin,y);
		file2<<x<<" "<<y<<" "<<baby<<" "<<cosmetics<<" "<<" "<<jewelery<<" "<<grocery;	
		file2.close();	
	}
	
	void sales_record()
	{
		system("cls");
		cout<<"\n\t\t\t\t\t ______ Sales Record ______\n\n\n";
		
		string line;
		ifstream fileread("sales.txt");
		cout << "\n\n\t\t\t\t\tSales Details:\n\n";
        while (getline(fileread, line)) {
        cout << line << endl;
        }
        fileread.close();
	}
	
	void low_stock()
	{
		system("cls");
		cout<<"\n\t\t\t\t\t ______ Low Stock Details ______\n\n\n";
		
		vector<int> ids;
    	vector<float> prices;
    	vector<int> quantitys;
    	vector<string> names;
    	
    	ifstream file3("product_enteries.txt");
    	
           while(file3 >> id >> name >> price >> quantity)
           {
           	    
                ids.push_back(id);
                names.push_back(name);
                quantitys.push_back(quantity);
                prices.push_back(price);
                
            }
            
        cout<<"\n\nProduct-id    Product-name    Stock    Price "<<endl;
            
        for( int i=0; i< ids.size();++i)
        {
            if(quantitys[i]<5)
		        {
        	        cout<<"\n"<<ids[i]<<"\t\t"<<names[i]<<"\t  "<<quantitys[i]<<"    "<<prices[i]<<endl;
				}
	    }
    }
    
           void set_sections()
           {
           	    system("cls");
		        cout<<"\n\t\t\t\t\t ______ Section Setup ______\n\n\n";
           	    
           	    int baby,cosmetics,jewelery,grocery;
           	    int x;  string y;
           	    ifstream file("discount_update.txt");
           	    file>>x>>y;
           	    file.close();
           	    ofstream file2("discount_update.txt",ios::trunc);
           	    cout<<"\nEnter baby section row : ";
           	    cin>>baby;
           	    cout<<"Enter cosmetics section row : ";
           	    cin>>cosmetics;
           	    cout<<"Enter jewelery section row : ";
           	    cin>>jewelery;
           	    cout<<"Enter grocery section row : ";
           	    cin>>grocery;
           	    file2<<x<<" "<<y<<" "<<baby<<" "<<cosmetics<<" "<<jewelery<<" "<<grocery;
           	    file2.close();
		   }
		   
		   	void set_discount()
	    {
		        system("cls");
		        cout<<"\n\t\t\t\t\t ______ Set discount ______\n\n\n";
		        int x;
		        string y;
	            ofstream file("update_discount.txt");
	            cout<<"Discount in percent: ";
	            cin>>x;
	            cin.ignore();
	            cout<<"Occasion ? ";
	            getline(cin,y);
		        file<<x<<" "<<y;	
		        file.close();	
	    }
	    
	    void remove() {
	
	    system("cls");
		cout<<"\n\t\t\t\t\t ______ Removing Item ______\n\n";
    
        ifstream file3("products_enteries.txt");
    
        vector<int> ids;
    	vector<float> prices;
    	vector<int> quantitys;
    	vector<string> names;
    	 
    	ifstream file4("product_enteries.txt");
    	
           while(file4 >> id >> name >> price >> quantity)
           {
           	    
                ids.push_back(id);
                names.push_back(name);
                quantitys.push_back(quantity);
                prices.push_back(price);
                
            }
            
            file4.close();
    

    int x;
    cout << "\nEnter product \"ID\" that needs to be deleted: ";
    cin >> x;

    bool found = false;
    int m;
    
    for (int i = 0; i < ids.size(); i++) {
        if ( ids[i]== x) {
            found = true;
            m=i;
            cout<<"\n\nProduct-id    Product-name    Price    Stock "<<endl;
        	cout<<"\n"<<ids[i]<<"\t\t"<<names[i]<<"\t  "<<prices[i]<<"    "<<quantitys[i]<<endl;
        	cout<<"\nCONTINUE ???  Y for Yes: ";
        	char z=getch();
        	if(z!='Y' && z!='y')
        	{
        		cout<<"Process cancelled: \n";
        		return;
			}
        }
        break;
    }

    if (!found) {
        cout << "Product not found.\n";
        return;
    }

    ofstream file("product_enteries.txt", ios::trunc); 
    
    
    for (int i = 0; i < ids.size(); i++) {
    	if(i != m)
        file << ids[i] << " " << names[i] << " " << prices[i] << " " << quantitys[i] << endl;
        else 
           continue;
    }
    
       
    file.close();


    cout << "Product removed successfully.\n";
}


        void Employee_setup()
        {
        	static Employee<int,char,int,float> s;
            s.input();

           ofstream fout("Employee_data", ios::binary | ios :: app); 
           if (!fout) {
           cout << "File could not be opened for writing.\n";
           return;
           }
           fout.write((char*)&s, sizeof(s));
           fout.close();
		}
		
		  void delete_Employee_file()
		  {
		    system("cls");
		    cout<<"\n\t\t\t\t\t ______ Removing Employees ______\n\n";	
		  	ofstream fout("Employee_data", ios::binary);
			cout<<"All Employee Removed successfully: "; 
		  	
		  }
	    
		   
		   ~admin()
		   {
		   	    system("cls");
	 	        cout<<"\n\n\t\t\t\t\t\t*** Thanks For chosing DR store ***";
	 	        cout<<"\n\n\n\t\t\t\t\t  "<<char(3)<<"_____"<<" We are the one who really cares you _____"<<char(3)<<"\n\n";
	 	        cout<<"\n\n\t\t\t\t\t\t   "<<char(4)<<"_____"<<" Happy Shopping _____"<<char(4)<<"\n\n\n";
		    }
    	
};

template <class ID,class n,class p,class q>

class customer{
	protected:
		ID id;
        n name;
        p price;
        q quantity;
	
	public:
		
		friend void customer_options();
		
		customer()
		{
			system("cls");
			cout<<"\n\t\t\t\t\t ______ You login as customer ______\n";
		}
		
	    void bill()
	    {
	    	system("cls");
	    	cout<<"\n\t\t\t\t\t ______ Billing ______\n";
	    	
	    	float total = 0;
            char ch; 
            
            vector<int> ids;
    	    vector<float> prices;
    	    vector<int> quantitys;
    	    vector<string> names;
    	    
    	    vector<int> temp_ids;
    	    vector<float> temp_prices;
    	    vector<int> temp_quantitys;
    	    vector<string> temp_names;
    	    vector<float> temp_totals;
            
	    	 
            ofstream salesout("sales.txt", ios::app); 
            
            ifstream file3("product_enteries.txt");
            
           while(file3 >> id >> name >> price >> quantity)
           {
           	    
                ids.push_back(id);
                names.push_back(name);
                quantitys.push_back(quantity);
                prices.push_back(price);    
            }
            
            file3.close();
            
            
            do {
                int x, flag = 0, y;
                cout << "\n\nEnter product \"ID\" that is written on product: ";
                cin >> x;

                for (int i = 0; i < ids.size() ; i++) {
                    if (ids[i] == x) {
        	            cout<<"\n\nProduct-id    Product-name    Price   Stock "<<endl;
        	            cout<<"\n"<<ids[i]<<"\t\t"<<names[i]<<"\t  "<<prices[i]<<"    "<<quantitys[i]<<endl;
                        cout << "\nIs the order confirmed? (Y for Yes): ";
                        ch = getch();
                        if (ch == 'y' || ch == 'Y') {
                        cout << "\n\nEnter quantity: ";
                        cin >> y;

                    if (y <= quantitys[i]) { 
                        total += prices[i] * y;
                        quantitys[i] -= y; 
                        flag = 1;

                        temp_ids.push_back(ids[i]);
                        temp_names.push_back(names[i]);
                        temp_prices.push_back(prices[i]);
                        temp_quantitys.push_back(quantitys[i]);
                        temp_totals.push_back(prices[i] * y);

    
                        salesout << "Product ID: " << ids[i] << "\n";
                        salesout << "Product Name: " << names[i] << "\n";
                        salesout << "Price: " << prices[i] << "\n";
                        salesout << "Quantity: " << y << "\n";
                        salesout << "Total Price: " << (prices[i] * y) << "\n";
                        salesout << "--------------------------\n";
                        
                    } else {
                        cout << "\n\nInsufficient stock available. Only " << quantitys[i] << " left.\n";
                    }
                    break;
                }
            }
        }

        if (flag != 1) {
            cout << "\n\nProduct not found or insufficient stock or may be you didnot confimed order.\n";
        }

        cout << "\nDo you want to enter more products? (Y for Yes): ";
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
    
    
               ofstream file5("product_enteries.txt",ios::trunc);
                	for( int i=0; i< ids.size();++i)
                	{
                		file5<<ids[i]<<" "<<names[i]<<" "<<" "<<prices[i]<<" "<<quantitys[i]<<"\n";
					}
					file5.close();	
					
					system("cls");
					cout<<"\nOrder_details : "<<endl;

                    for(int i=0;i<temp_ids.size();i++)
                    {
                    	cout<<"\nProduct id :        ";
						cout<<temp_ids[i]<<endl;
						
						cout<<"Product name :      ";
                    	cout<<temp_names[i]<<endl;
                    	
                    	cout<<"Product price :     ";
                    	cout<<temp_prices[i]<<endl;
                    	
                    	cout<<"Product Quantity :  ";
                    	cout<<temp_quantitys[i]<<endl;
                    	
                    	cout<<"Product total :     ";
                    	cout<<temp_totals[i]<<endl;
                    	cout<<"--------------------------\n";
                   }    


                    float x = discount_view();
                    total = total - (total*(x/100));
                    cout << "\nYour total after discount will be:  " << total << endl;
                    cout<<"Continue:\n";
                    getch();
                    
                    salesout<<"Customer total after discount : "<<total<<endl;
                    
                    string feedback;
					cout<<"Any Feedback : \n";
					cin.ignore();
					getline(cin,feedback);
					salesout << "--------------------------\n";
					salesout << "Customer Feedback: \n";
					salesout << feedback <<endl<<endl;
					salesout << "--------------------------\n\n";
					
					
					salesout.close();
		}
		
		
		int discount_view()
		{
			
			system("cls");
		    cout<<"\n\t\t\t\t\t ______ Viewing Discount ______\n\n";
			
			int x;
			string y;
		    ifstream file("update_discount.txt");
		    file>>x>>y;
			cout<<"\nWe have discount today upto "<<x<<"%"<<" on this beautiful occasion of "<<y; 
			
			file.close();
			
			return x;
			
			
			
		}
		
		 void check_sections() 
		{
			    system("cls");
		        cout<<"\n\t\t\t\t\t ______ Viewing Section ______\n\n";
		        
			    int baby,cosmetics,jewelery,grocery;
			    int x;  
			    string y;
			
           	    ifstream file("discount_update.txt");
           	    file>>x;
           	    file>>y;
           	    file>>baby;
           	    file>>cosmetics;
           	    file>>jewelery;
           	    file>>grocery;
           	    
           	    system("cls");
                cout<<" Sections :\n";
           	    
           	    cout<<"Baby section        |"<<baby<<endl;
           	    cout<<"Cosmetics section   |"<<cosmetics<<endl;
           	    cout<<"Jewelary section    |"<<jewelery<<endl;
           	    cout<<"Grocery section     |"<<grocery;
           	    
           	    file.close();
           	    
		}
		
		
		
		~customer()
		   {
		   	    system("cls");
	 	        cout<<"\n\n\t\t\t\t\t\t*** Thanks For chosing DR store ***";
	 	        cout<<"\n\n\n\t\t\t\t\t  "<<char(3)<<"_____"<<" We are the one who really cares you _____"<<char(3)<<"\n\n";
	 	        cout<<"\n\n\t\t\t\t\t\t   "<<char(4)<<"_____"<<" Happy Shopping _____"<<char(4)<<"\n\n\n";
		    }
		
};

void admin_options()
{
	static admin<int,string,float,int> *a = new admin<int,string,float,int>;
	
	static char z;

	start:	
	cout<<"\n\nPress 1 to delete and add new data: \n";
	cout<<"Press 2 to display stock details: \n";
	cout<<"Press 3 to update an item: \n";
	cout<<"Press 4 to add an item: \n";
	cout<<"Press 5 to set discount : \n";
	cout<<"Press 6 to display sales record: \n";
	cout<<"Press 7 to check low stock: \n";
	cout<<"Press 8 to set sections : \n";
	cout<<"Press 9 to update Discount for today: \n";
	cout<<"Press E to add Employee details:  \n";
	cout<<"Press 0 to remove item :  \n";
	cout<<"Press R to remove all Employees: \n";
	
	
	switch(getch())
	{
	   case '1':  a->truncate();  break;
	   case '2':  a->stock_details(); break;
	   case '3':  a->update_item();  break;
	   case '4':  a->add_item();  break;
	   case '9':  a->update_discount();  break;	
	   case '6':  a->sales_record();  break;
	   case '7':  a->low_stock();  break;
	   case '8':  a->set_sections(); break;
	   case '5':  a->set_discount(); break;
	   case 'E':  a->Employee_setup(); break;
	   case '0':  a->remove();  break;
	   case 'R':  a->delete_Employee_file(); break;
	   default:
	   	{
	   		cout<<"Invalid input: \n";
	   		cout<<"Do you want to repeat: Y for yes ";
	   		z=getch();
	   		if( z==  'y' || z=='Y')
	   		{
	   			system("cls");
	   			goto start;
			   }
			else 
			     goto end;
		   }
	}
	
	cout<<"\n\n\nDo want to go main menu  Y for yes...";
		    z=getch();
			if(z == 'y' || z=='Y')
		  	  {
		  	  	system("cls");
			    goto start;
		      }
		    else
		           end: delete a;
		       
		       
}

void customer_options()
{
	static customer<int,string,float,int> *c=new customer<int,string,float,int>;
	
	static char z;
	
	start:
	cout<<"\n\nPress 1 to add item in your bill: \n";
	cout<<"Press 2 to view todays discount: \n";
	cout<<"Press 3 to check sections of stock: \n";
	
	
	switch(getch())
	{
		case '1': c->bill();  break;
		case '2': c->discount_view(); break;
		case '3': c->check_sections(); break;
		default:
			{
			   cout<<"Invalid input: \n";
			   cout<<"Do you want to repeat: Y for yes: \n";
			   z=getch();
			   if(z=='y' || z== 'Y')	
			   {
			   	system("cls");
			    goto start;
		       }
		       else
		           goto end;
			}		
	}
	
	cout<<"\n\n\nDo want to go main menu  Y for yes...";
			z=getch();
			if(z == 'y' || z== 'Y')
		  	  {
		  	  	system("cls");
			    goto start;
		      }
		    else
		         end: delete c;

	
}

void Employee_option()
{
	char z;
	
	start:
	
	system("cls");
	cout<<"\n\t\t\t\t\t ______ Employee Options ______\n\n\n";
	
	cout<<"\n\nEnter Employee Id to check Details: ";
	
	int *x=new int;
	cin>>*x;
	bool found=false;
	
	Employee<int,char,int,float> s1;
	
    ifstream fin("Employee_data", ios::binary);
    
    if (!fin) {
        cout << "File could not be opened for reading.\n";
        return;
    }

    cout << "Stored Employee Record:\n";
    while (fin.read((char*)&s1, sizeof(s1))) {
    	
        if( s1.check(*x) )
        {
        	found=1;
        	s1.display();
		}
		
    }
    
    if(!found)
    {
    	cout<<"\n Employee not found: ";
	}

    fin.close();
    
    cout<<"\n\n\nDo want to repeat  Y for yes...";
			z=getch();
			if(z == 'y' || z== 'Y')
		  	  {
		  	  	system("cls");
			    goto start;
		   }
    delete x;
}



int main()
{
	int c=3,x;
	
	start:
	
	system("cls");
	cout<<"\n\t\t\t\t\t\t_______________________________";
	cout<<"\n\n\t\t\t\t\t\t***** Welcome to DR store *****";
	cout<<"\n\t\t\t\t\t\t_______________________________";
	cout<<"\n\n\t\t\t\t\t        \"The best Utility Store in Town\"";
	cout<<"\n\n\t\t\t\t\t        We are welcoming you with warm smile "<<char(3)<<" "<<char(3)<<" "<<char(3);
	
	cout<<"\n\n\t\t\t\t\t        Enter 4-digit login Pin:  ";
	cin>>x;
	c--;
	
	if(x!= 1122  &&   x!= 1234 &&  x!=1010  && c>0)
	{
		cout<<"\n\n\t\t\t\t\t\tIncorrect password ...\n";
	    cout<<"\n\n\t\t\t\t\t\tAttempts left:"<<c;
        clock_t start_time = clock();
        while (clock() < start_time + 3000);         //Take delay.
		goto start;
    }
	else if(x!= 1122   &&  x!= 1234 &&  x!=1010 )
	{
		
		if(c==0)
		{
		cout<<"\n\n\t\t\t\t\t\t Attempts failed:\n\n\n";
		return 0;
	    }
	    
	}
	
	
	switch(x)
	{
		case 1122:
			{
				admin_options();
				break;
			}
		case 1234:
			{
				customer_options();
				break;
			}
		case 1010:
			{
		         Employee_option();
		         break;
			}
	}
	
	
	
	return 0;
}
