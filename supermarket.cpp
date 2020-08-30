#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>

struct Item
{
		char name[40];
		long barcode;
		int price;
		int stock;



		void getdata();
		void showdata();
		int checkN(char nm[]);
		int checkB(long bc);
		int checkS(int st);
		void Edit();
};

// ******************Input a new item*****************
void Item::getdata()
{
	cout<<setw(25)<<"\n\n Enter Name : ";
	gets(name);
	cout<<setw(25)<<"\n Enter barcode number : ";
	cin>>barcode;
	cout<<setw(25)<<"\n Enter price : ";
	cin>>price;
	cout<<setw(25)<<"\n Enter quantity in stock : ";
	cin>>stock;
}


//  ****************** Display an item****************
void Item::showdata()
{
	cout<<setw(25)<<"\n\n Name : "<<name;
	cout<<setw(25)<<"\n Barcode Number : " <<barcode;
	cout<<setw(25)<<"\n Price : "<<price;
	cout<<setw(25)<<" \n Quantity in stock : "<<stock;
}
// ******************Check by Name********************
int Item::checkN(char *nm)
{
	if(strcmp(nm,name)==0)
		return 1;
	else
		return 0;
}

// ******************Check by barcode*****************
int Item::checkB(long bc)
{
	if(bc==barcode)
		return 1;
	else
		return 0;
}
// ******************Check by stock*****************
int Item::checkS(int st)
{
	if(stock<st)
		return 0;
	else if(st==stock)
		return 1;
	else
		return 2;
}
// ******************Edit A record******************
void Item::Edit()
{
	char ch;
	do{
		cout<<"Details of the record : \n";
		showdata();
		cout<<"\n Press A if you wish to update the name \n";
		cout<<"\n Press B if you wish to update the barcode \n";
		cout<<"\n Press C if you wish to update the price \n";
		cout<<"\n Press D if you wish to update the stock \n";
		cout<<"\n Press E to make no futher changes\n";
		ch=getche();
		switch(ch)
		{
			case 'A':
			case 'a':	cout<<setw(30)<<"\n Enter new name : ";
							gets(name);
							break;
			case 'B':
			case 'b':	cout<<setw(30)<<"\n Enter new Barcode Number : ";
							cin>>barcode;
							break;
			case 'C':
			case 'c':	cout<<setw(30)<<"\n Enter new price : ";
							cin>>price;
							break;
			case 'D':
			case 'd':	cout<<setw(30)<<"\n Enter new stock left : ";
							cin>>stock;
							break;
			case 'E':
			case 'e':	break;

			default :	cout<<"\n Invalid Input !! \n Please enter a relevant choice. \n";

		}
	}while(ch!='E' && ch!='e');
}
// ******************Append(ADD) a new item***********
void Append()
{
	Item I;
	cout<<"\n Enter the Details of the item : \n";
	I.getdata();

	fstream f1;
	f1.open("INVENTORY.DAT",ios::binary|ios::app);

	f1.write((char*) &I,sizeof(I));

	f1.close();
}


// ******************Display Inventory****************
void DisplayInventory()
{
	Item I;

	fstream f1;
	f1.open("INVENTORY.DAT",ios::binary|ios::in);

	while(f1.read((char*) &I,sizeof(I)) )
	{
		I.showdata();
	}
	f1.close();
}


// ******************Search by Name*******************
void SearchN()
{
	char sn[40];
	Item I;
	int found =0;

	cout<<"\n\n Enter the name to be searched : ";
	gets(sn);

	fstream f1("INVENTORY.DAT",ios::binary|ios::in);

	while(f1.read((char*)&I,sizeof(I)))
	{
		if(I.checkN(sn)==1)
		{
			found++;
			I.showdata();
		}
	}

	f1.close();

	if (found==0)
		cout<<"\n NO MATCH FOUND ! \N";
	else
		cout<<"\n TOTAL "<<found<<" ITEMS FOUND. \N";
}


// ******************Search by Barcode****************
void SearchB()
{
	long sb;
	Item I;
	int found =0;

	cout<<"\n\n Enter the barcode to be searched : ";
	cin>>sb;

	fstream f1;
	f1.open("INVENTORY.DAT",ios::binary|ios::in);

	while(f1.read((char*)&I,sizeof(I)))
	{
		if(I.checkB(sb)==1)
		{
			found++;
			I.showdata();
		}
	}

	f1.close();

	if (found==0)
		cout<<"\n NO MATCH FOUND ! \N";
	else
		cout<<"\n TOTAL "<<found<<" ITEMS FOUND. \N";
}



// ******************search by stock******************
void SearchS()
{
	int ss;
	Item I;
	int found=0;
	fstream f1;
	char sp;
	cout<<"\n\n Select choice for search by stock quantity";
	cout<<"\n A.To search stock quantiy less than x";
	cout<<"\n B.To search stock quantity greater than x";
	cout<<"\n C.To search stock quantity  equal to x";
	sp=getche();
	switch(sp)
	{
		case 'a':
		case 'A':	cout<<"\n\n Enter the value of x : ";
						cin>>ss;


						f1.open("INVENTORY.DAT",ios::binary|ios::in);

						while(f1.read((char*)&I,sizeof(I)))
						{
							if(I.checkS(ss)==0)
							{
								found++;
								I.showdata();
							}
						}

						f1.close();

						if (found==0)
							cout<<"\n NO MATCH FOUND ! \N";
						else
							cout<<"\n TOTAL "<<found<<" ITEMS FOUND. \N";


						break;



		case 'B':
		case 'b':	cout<<"\n\n Enter the value of x : ";
						cin>>ss;


						f1.open("INVENTORY.DAT",ios::binary|ios::in);

						while(f1.read((char*)&I,sizeof(I)))
						{
							if(I.checkS(ss)==2)
							{
								found++;
								I.showdata();
							}
						}

						f1.close();

						if (found==0)
							cout<<"\n NO MATCH FOUND ! \N";
						else
							cout<<"\n TOTAL "<<found<<" ITEMS FOUND. \N";

						break;


		case 'c':
		case 'C':	cout<<"\n\n Enter the value of x : ";
						cin>>ss;


						f1.open("INVENTORY.DAT",ios::binary|ios::in);

						while(f1.read((char*)&I,sizeof(I)))
						{
							if(I.checkS(ss)==1)
							{
								found++;
								I.showdata();
							}
						}

						f1.close();

						if (found==0)
							cout<<"\n NO MATCH FOUND ! \N";
						else
							cout<<"\n TOTAL "<<found<<" ITEMS FOUND. \N";

						break;
		default:		cout<<"\n Invalid Input !! \n Please enter a relevant choice. \n";
	}

}

//******************Modify a record*******************
void modify()
{
	char sn[40];
	Item I;
	int Modified=0;

	cout<<"\n\n Enter the Item to be modified : ";
	gets(sn);

	fstream f1,f2;
	f1.open("INVENTORY.DAT",ios::binary|ios::in);
	f2.open("TEMP.DAT",   ios::binary|ios::out);

	while( f1.read((char*) &I, sizeof(I)) )
	{
		if(I.checkN(sn)==1)
		{
			Modified++ ;
			I.Edit();
		}
		f2.write((char *) &I, sizeof(I));
	}

	f1.close();
	f2.close();


	if (Modified == 0)
		cout<<"\n\n NO MATCH FOUND !! \n\n";
		  else
		{
			remove("INVENTORY.DAT");
			rename("TEMP.DAT" , "INVENTORY.DAT");
		}
}




//******************Delete a record*******************
void delete1()
{
	char sn[40];
	Item I;
	int Deleted=0;

	cout<<"\n Enter Item to be deleted : ";
	gets(sn);

	fstream f1,f2;
	f1.open("INVENTORY.DAT",ios::binary|ios::in);
	f2.open("TEMP.DAT",   ios::binary|ios::out);

	while( f1.read((char*) &I, sizeof(I)) )
	{
		if(I.checkN(sn)==1)
			Deleted ++ ;
			  else
			f2.write((char *) &I, sizeof(I));
	}

	f1.close();
	f2.close();



	if (Deleted == 0)
		cout<<"\n\n NO MATCH FOUND !! \n\n";
		  else
		{
			remove("INVENTORY.DAT");
			rename("TEMP.DAT" , "INVENTORY.DAT");
		}

}

void UpdateInventory()
{
	char choice;
	do{
		clrscr();
		cout<<"Menu\n";
		cout<<"Press 1 for APPEND AN ITEM \n";
		cout<<"Press 2 for DISPLAY COMPLETE INVENTORY \n";
		cout<<"Press 3 for SEARCH BY NAME \n";
		cout<<"Press 4 for SEARCH BY BARCODE NUMBER \n";
		cout<<"Press 5 for SEARCH BY QUANTITY IN STOCK \n";
		cout<<"Press 6 for MODIFY A ITEM \n";
		cout<<"Press 7 for DELETE A DELETE \n";
		cout<<"Press 8 for MAIN MENU \n";
		cout<<"Enter your choice : ";
		choice=getche();
		switch(choice)
		{
			case '1':	Append();
							break;
			case '2':	DisplayInventory();
							break;
			case '3':	SearchN();
							break;
			case '4':	SearchB();
							break;
			case '5':	SearchS();
							break;
			case '6':	modify();
							break;
			case '7':	delete1();
							break;
			case '8':
							break;
			default :	cout<<"\n Invalid Input !! \n Please enter a relevant choice. \n";
		}
		cout<<"\n\n Press any key to continue!";
		getch();
	}while(choice!='8');
}

//********************** ADD TO CART******************
void AddtoCart()
{
	Item I;
	long bc;
	cout<<"\n\nEnter Barcode of Item:";
	cin>>bc;
	int flag=0,quantity;
	ifstream f1("INVENTORY.DAT",ios::binary);

	while(f1.read((char*)&I,sizeof(I))&&flag==0)
	{
		if(I.checkB(bc)==1)
		{
			cout<<"\n\nItem Selected:\n";
			I.showdata();
			flag=1;
		}
	}

	f1.close();

	if (flag==0)
		cout<<"\n NO MATCH FOUND ! \n";
	else
	{
		cout<<"\n\nEnter Quantiy to be bught:\n";
		cin>>quantity;
		if(quantity>I.stock)
			cout<<"\nNot enough in stock!!\n";
		else
		{
			cout<<quantity<<" "<<I.name<<" added to cart.\n\n";
			ofstream f2("CART.DAT",ios::binary|ios::app);
			I.stock=quantity;

			f2.write((char*)&I,sizeof(I));
			f2.close();

			fstream f3,f4;
			f3.open("INVENTORY.DAT",ios::binary|ios::in);
			f4.open("TEMP.DAT",ios::binary|ios::out);
			Item N;
			while(f3.read((char*) &N,sizeof(N)) )
			{
				if(N.checkB(bc)==1)
				{

					N.stock-=I.stock;

					f4.write((char*)&N,sizeof(N));
				}

				else
				f4.write((char*)&N,sizeof(N));
			}
			f3.close();
			f4.close();

			remove("INVENTORY.DAT");
			rename("TEMP.DAT","INVENTORY.DAT");
		}

	}
}

//*************DELETE FROM CART***************
void DelCart()
{
	Item I;
	long bc;
	cout<<"\n\nEnter Barcode of Item:";
	cin>>bc;
	int flag=0;

	fstream f1,f2;
	f1.open("CART.DAT",ios::binary|ios::in);
	f2.open("TEMP.DAT",ios::binary|ios::out);

	while(f1.read((char*) &I,sizeof(I))&&flag==0)
	{
		if(I.checkB(bc)==1)
		{

			cout<<"\n\nItem DELETED:\n";
			I.showdata();
			flag=1;

			fstream f3,f4;
			f3.open("INVENTORY.DAT",ios::binary|ios::in);
			f4.open("TEMP.DAT",ios::binary|ios::out);
			Item N;
			while(f3.read((char*) &N,sizeof(N)) )
			{
				if(N.checkB(bc)==1)
				{

					N.stock+=I.stock;

					f4.write((char*)&N,sizeof(N));
				}

				else
				f4.write((char*)&N,sizeof(N));
			}
			f3.close();
			f4.close();

			remove("INVENTORY.DAT");
			rename("TEMP.DAT","INVENTORY.DAT");
		}
		else
			f2.write((char*)&I,sizeof(I));
	}
	if(flag==0)
		cout<<"No match found!!";
	f1.close();
	f2.close();
	remove("CART.DAT");
	rename("TEMP.DAT","CART.DAT");

}




void UpdateCart()
{
	char choice;
	do{
		clrscr();
		cout<<"Menu\n";
		cout<<"Press 1 to DISPLAY INVENTORY \n";
		cout<<"Press 2 to SEARCH FOR ITEM BY NAME \n";
		cout<<"Press 3 to SEARCH FOR ITEM BY BARCODE \n";
		cout<<"Press 4 to ADD ITEM TO CART \n";
		cout<<"Press 5 to DELETE ITEM FROM CART \n";
		cout<<"Press 6 to FINISH SHOPPING \n";
		cout<<"Enter your choice : ";
		choice=getche();
		switch(choice)
		{
			case '1':	DisplayInventory();
							break;
			case '2':	SearchN();
							break;
			case '3':	SearchB();
							break;
			case '4':   AddtoCart();
							break;
			case '5':	DelCart();
							break;
			case '6':
							break;
			default :	cout<<"\n Invalid Input !! \n Please enter a relevant choice. \n";
		}
		cout<<"\n\n Press any key to continue!";
		getch();
	}while(choice!='6');

}

void ShowCart()
{
	Item I;

	fstream f1;
	f1.open("CART.DAT",ios::binary|ios::in);

	while(f1.read((char*) &I,sizeof(I)) )
	{
		I.showdata();
	}
	f1.close();
}

void CheckOut()
{
	cout<<"\n\n Your Bill:\n\n";
	Item I;
	int amount=0;
	fstream f1;
	f1.open("CART.DAT",ios::binary|ios::in);

	while(f1.read((char*) &I,sizeof(I)) )
	{
		I.showdata();
		amount+=(I.price*I.stock);

	}
	f1.close();
	amount*=1.18; //GST
	cout<<"\n Total	amount : "<<amount;
	cout<<"\n\n Thank You for shopping with us today!\n";
}





void Sale()
{
	char choice;
	do{
		clrscr();
		cout<<"Menu\n";
		cout<<"Press 1 to ADD OR DELETE ITEMS FROM CART \n";
		cout<<"Press 2 to DISPLAY COMPLETE CART \n";
		cout<<"Press 3 to CHECK OUT\n";
		cout<<"Enter your choice : ";
		choice=getche();
		switch(choice)
		{
			case '1':	UpdateCart();
							break;
			case '2':	ShowCart();
							break;
			case '3':
							break;
			default :	cout<<"\n Invalid Input !! \n Please enter a relevant choice. \n";
		}
		cout<<"\n\n Press any key to continue!";
		getch();
	}while(choice!='3');
	CheckOut();
}


void ReducePrice()
{
	cout<<"\n\nEnter Maximum stock threshold for standard pricing";
	cout<<" above which a discount will be applied:";
	int threshold=0,discount=0;
	cin>>threshold;
	dis:
	cout<<"\n\nEnter %age discount for items above maximum threshold:";
	cin>>discount;
	if(discount>100)
	{
		cout<<"\nDiscount cannot be more than 100%!!\n Try Again.\n";
		goto dis;
	}
	Item I;

	fstream f1,f2;
	f1.open("INVENTORY.DAT",ios::binary|ios::in);
	f2.open("TEMP.DAT",ios::binary|ios::out);

	while(f1.read((char*) &I,sizeof(I)) )
	{
		if(I.stock>threshold)
		{
			cout<<"Original Pricing :\n ";
			I.showdata();
			I.stock*=((100-discount)/100);
			cout<<"Updated Pricing :\n";
			f2.write((char*)&I,sizeof(I));
		}

		else
		f2.write((char*)&I,sizeof(I));
	}
	f1.close();
	f2.close();

	remove("INVENTORY.DAT");
	rename("TEMP.DAT","INVENTORY.DAT");

}

void IncreasePrice()
{
	cout<<"\n\nEnter Minimum stock threshold for standard pricing";
	cout<<" below which a surcharge will be applied:";
	int threshold=0,surcharge=0;
	cin>>threshold;
	cout<<"\n\nEnter %age surcharge for items below minimum threshold:";
	cin>>surcharge;

	Item I;

	fstream f1,f2;
	f1.open("INVENTORY.DAT",ios::binary|ios::in);
	f2.open("TEMP.DAT",ios::binary|ios::out);

	while(f1.read((char*) &I,sizeof(I)) )
	{
		if(I.stock>threshold)
		{
			cout<<"Original Pricing :\n ";
			I.showdata();
			I.stock*=((100+surcharge)/100);
			cout<<"Updated Pricing :\n";
			f2.write((char*)&I,sizeof(I));
		}

		else
		f2.write((char*)&I,sizeof(I));
	}
	f1.close();
	f2.close();

	remove("INVENTORY.DAT");
	rename("TEMP.DAT","INVENTORY.DAT");

}


void Discount()
{
	char choice;
	do{
		clrscr();
		cout<<"Menu\n";
		cout<<"Press 1 to REDUCE PRICES OF ITEMS WITH SURPLUS STOCK \n";
		cout<<"Press 2 to INCREASE PRICES OF ITEMS WITH DEPLETING STOCK \n";
		cout<<"Press 3 for MAIN MENU \n";
		cout<<"Enter your choice : ";
		choice=getche();
		switch(choice)
		{
			case '1':	ReducePrice();
							break;
			case '2':	IncreasePrice();
							break;
			case '3':
							break;
			default :	cout<<"\n Invalid Input !! \n Please enter a relevant choice. \n";
		}
		cout<<"\n\n Press any key to continue!";
		getch();
	}while(choice!='3');
}

void main()
{

	int introsequence=0;
	if(introsequence==0)
	{
	gotoxy(30,10);
	cout<<"Welcome to Shreyas' Supermart!!"<<endl;  //Game name

	for(int i=0;i<1000;i++)
	for(int j=0;j<1000;j++)
	for(int l=0;l<1000;l++);	//Delay using empty loop

	clrscr();

	gotoxy(28,10);
	cout<<"Booting"<<endl;
	for( i=0;i<4;i++)
	{
      gotoxy(36+i,10);
		cout<<".";
		for(int j=0;j<1000;j++)
      for(int k=0;k<250;k++)
		for(int l=0;l<1000;l++);
	}

	clrscr();

	gotoxy(27,10);
	cout<<"Good Day! How may I help you today?"<<endl;
	for( i=0;i<1000;i++)
	for(int j=0;j<1000;j++)
	for(int l=0;l<1000;l++);
	clrscr();

	introsequence=1;
	}
	mainmenu:
	char choice;
	do{
		clrscr();
		cout<<"Main Menu\n";
		cout<<"Press 1 to UPDATE INVENTORY\n";
		cout<<"Press 2 to MAKE A SALE \n";
		cout<<"Press 3 to CHANGE PRICES \n";
		cout<<"Press 4 to QUIT\n";
		cout<<"Enter your choice : ";
		choice=getche();
		switch(choice)
		{
			case '1':	UpdateInventory();
							break;
			case '2':	Sale();
							break;
			case '3':	Discount();
							break;
			case '4':
							break;
			default :	cout<<"\n Invalid Input !! \n Please enter a relevant choice. \n";
		}
		cout<<"\n\n Press any key to continue!";
		getch();
	}while(choice!='4');
	remove("CART.DAT");
}




