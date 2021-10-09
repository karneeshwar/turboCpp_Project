      #include<conio.h>
      #include<dos.h>
      #include<graphics.h>
      #include<iostream.h>
      #include<fstream.h>
      #include<stdio.h>
      #include<stdlib.h>
      #include<string.h>
      class patient
      {
       float pl,pr;
       int pcode;
       int dcode;
       char pdef[20];
       char pname[25];
       char dob[20];
       char area[20];
       long int phone;

       public:

       patient()
       {
	pcode=1;
	strcpy(pdef,"NORMAL");
	dcode=0;
	strcpy(pname,"null");
	strcpy(dob,"null");
	strcpy(area,"null");
	phone=0;
	pl=0;
	pr=0;
       }
       void getdata()
       {
	cout<<"\n\t ENTER PATIENT CODE: ";
	cin>>pcode;
	cout<<"\n\t ENTER PATIENT NAME: ";
	gets(pname);
	cout<<"\n\t ENTER DATE OF BIRTH(ddmmyyyy): ";
	gets(dob);
	cout<<"\n\t ENTER AREA: ";
	gets(area);
	cout<<"\n\t ENTER PHONE NUMBER: ";
	cin>>phone;
	cout<<"\n\t ENTER TYPE OF DEFECT: ";
	cin>>dcode;
	cout<<"\n\t ENTER POWER OF LEFT EYE: ";
	cin>>pl;
	cout<<"\n\t ENTER POWER OF RIGHT EYE: ";
	cin>>pr;
       }
       void dispdata()
       {
	cout<<"\n\t ------------------------------------------- ";
	cout<<"\n\t PATIENT CODE   : "<<pcode;
	cout<<"\n\t PATIENT NAME   : "<<pname;
	cout<<"\n\t DATE OF BIRTH  : "<<dob;
	cout<<"\n\t AREA           : "<<area;
	cout<<"\n\t PHONE NUMBER   : "<<phone;
	if(dcode==1)
	strcpy(pdef,"MYOPIA");
	if(dcode==2)
	strcpy(pdef,"HYPERMETROPIA");
	if(dcode==3)
	strcpy(pdef,"PRESBYOPIA");
	cout<<"\n\t TYPE OF DEFECT : "<<pdef;
	cout<<"\n\t LEFT EYE POWER : "<<pl;
	cout<<"\n\t RIGHT EYE POWER: "<<pr;
	cout<<"\n\t ------------------------------------------- \n";
       }
       int retpc()
       {
	return pcode;
       }
       void modi();
      };
      void patient::modi()
      {
       dispdata();
       char s;
       char nname[25], narea[20], ndob[20];
       long int nphone;
       cout<<"\n\n\t DO YOU WANT TO MODIFY THIS RECORD: ";
       cin>>s;
       delay(500);
       clrscr();
       cout<<"\n\t PROCESSING..... ";
       delay(3000);
       clrscr();
       cout<<"\n\t MODIFICATION ";
       cout<<"\n\t ~~~~~~~~~~~~ ";
       if(s=='y')
       {
	cout<<"\n\n\t ENTER 1 TO RETAIN THE DATA \n ";
	cout<<"\n\t ENTER NEW PATIENT NAME : ";
	gets(nname);
	cout<<"\n\t ENTER NEW AREA         : ";
	gets(narea);
	cout<<"\n\t ENTER NEW DATE OF BIRTH: ";
	gets(ndob);
	cout<<"\n\t ENTER NEW PHONE NUMBER : ";
	cin>>nphone;
	if(strcmp(nname,"1")!=0)
	strcpy(pname,nname);
	if(strcmp(narea,"1")!=0)
	strcpy(area,narea);
	if(strcmp(ndob,"1")!=0)
	strcpy(dob,ndob);
	if(nphone!=1)
	phone=nphone;
       }
      }
      void common()
      {
       cout<<"\n\t COMMON EYE DEFECTS ";
       cout<<"\n\t ^^^^^^^^^^^^^^^^^^ \n";
       cout<<"\n\t 1.MYOPIA: It is also known as Nearsightedness. ";
       cout<<"\n\t People having this kind of defect could not see far objects. ";
       cout<<"\n\t The image is formed before the retina. ";
       cout<<"\n\t It is caused due to the elongation of eye ball. ";
       cout<<"\n\t It can be corrected using concave lens. \n";
       cout<<"\n\t 2.HYPERMETROPIA: It is also known as Farsightedness. ";
       cout<<"\n\t People having this defect could not see near objects or read books. ";
       cout<<"\n\t The image is formed after the retina. ";
       cout<<"\n\t It is caused due to the shrinkage of eye ball. ";
       cout<<"\n\t It can be corrected using a convex lens. \n";
       cout<<"\n\t 3.PRESBYOPIA: It is commonly found in aged people. ";
       cout<<"\n\t They have difficaultly in both reading and seeing far objects. ";
       cout<<"\n\t It is caused due to the weakening of ciliary muscles. ";
       cout<<"\n\t It can be corrected using a bifocal lens. ";
       cout<<"\n\t The upper part of lens is for seeing far objects, is convex lens. ";
       cout<<"\n\t The lower part is for reading, is concave lens. \n";
      }
      void write()
      {
       patient p[100];
       int n;
       fstream f("PATIENT.DAT",ios::app | ios::binary);
       cout<<"\n\t ENTER NUMBER OF PATIENTS WHOSE DETAILS TO BE ADDED: ";
       cin>>n;
       for(int i=0;i<n;i++)
       {
	p[i].getdata();
	f.write((char*)&p[i],sizeof(p[i]));
	cout<<"\n\t .....RECORD ADDED SUCCESSFULLY..... \n";
       }
       f.close();
      }
      void read()
      {
       patient p;
       ifstream f("PATIENT.DAT",ios::in|ios::binary);
       cout<<"\n\t THE FILE CONTAINS THE FOLLOWING DETAILS \n";
       while(!f.eof())
       {
	f.read((char*)&p,sizeof(p));
	if(!f.eof())
	p.dispdata();
       }
       f.close();
      }
      void search()
      {
       patient p;
       int code;
       char found='n';
       ifstream f("PATIENT.DAT",ios::in|ios::binary);
       cout<<"\n\t ENTER PATIENT CODE FOR SEARCHING: ";
       cin>>code;
       while(!f.eof())
       {
	f.read((char*)&p,sizeof(p));
	if(code==p.retpc())
	{
	 p.dispdata();
	 found='y';
	 break;
	}
       }
       if(found=='n')
       cout<<"\n\t <<!! RECORD NOT FOUND !!>> \n";
       f.close();
      }
      void deldata()
      {
       patient p,pat;
       ifstream f1("PATIENT.DAT",ios::in,ios::binary);
       ofstream f2("TEMP.DAT",ios::out,ios::binary);
       int code;
       char found='f';
       char confirm='n';
       cout<<"\n\t ENTER PATIENT CODE TO DELETE: ";
       cin>>code;
       while(!f1.eof())
       {
	f1.read((char*)&p,sizeof(p));
	if(p.retpc()==code)
	{
	 p.dispdata();
	 found='t';
	 cout<<"\n\t ARE YOU SURE YOU WANT TO DELETE THIS RECORD(y/n): ";
	 cin>>confirm;
	 if(confirm=='n')
	 f2.write((char*)&p,sizeof(p));
	}
	else
	f2.write((char*)&p,sizeof(p));
       }
       if(found=='f')
       {
	cout<<"\n\t <<!! RECORD NOT FOUND !!>> \n";
       }
       f1.close();
       f2.close();
       remove("PATIENT.DAT");
       rename("TEMP.DAT","PATIENT.DAT");
       f1.open("PATIENT.DAT",ios::in|ios::binary);
       cout<<"\n\n\t NOW THE FILE CONTAINS: \n";
       while(!f1.eof())
       {
	f1.read((char*)&pat,sizeof(pat));
	if(!f1.eof())
	pat.dispdata();
       }
       f1.close();
      }
      void modify()
      {
       patient p;
       fstream f("PATIENT.DAT",ios::in|ios::out|ios::binary);
       int code;
       long pos;
       char found='f';
       cout<<"\n\t ENTER PATIENT CODE WHOSE DETAILS IS TO BE MODIFIED: ";
       cin>>code;
       while(!f.eof())
       {
	pos=f.tellg();
	f.read((char*)&p,sizeof(p));
	if(p.retpc()==code)
	{
	 p.modi();
	 f.seekg(pos);
	 f.write((char*)&p,sizeof(p));
	 found='t';
	 break;
	}
       }
       if(found=='f')
       cout<<"\n\t <<!! RECORD NOT FOUND !!>> \n";
       f.seekg(0);
       cout<<"\n\t NOW THE FILE CONTAINS: \n";
       while(!f.eof())
       {
	f.read((char*)&p,sizeof(p));
	if(code==p.retpc())
	{
	 p.dispdata();
	 found='y';
	 break;
	}
       }
       f.close();
      }
      void aboutus()
      {
       cout<<"\n\t\t\t ^^^^^^^^^^^^^^^^^^^^^^^ ";
       cout<<"\n\t\t\t ^ VAIKAR EYE HOSPITAL ^ ";
       cout<<"\n\t\t\t ^  CHENNAI - 600 080  ^ ";
       cout<<"\n\t\t\t ^^^^^^^^^^^^^^^^^^^^^^^ ";
       cout<<"\n\n       * Started in 1965 by Dr. Nalli Kuppuswamy Chettiar in Korattur. ";
       cout<<"\n       * Infrastructure: 2 multistoreyed building with total pf 250 rooms. ";
       cout<<"\n       * Computerised eye testing. ";
       cout<<"\n       * Test result and correcting glasses within 1 - hour. ";
       cout<<"\n       * Open for 24x7. ";
       cout<<"\n       * An ISO 9001:1970 hospital with grade A+ from Ministry Of Health,India. ";
       cout<<"\n       * 100+ doctors. ";
       cout<<"\n\n\t   * Visit Us..... ";
       cout<<"\n\t\t VAIKAR CARES FOR YOU ";
       cout<<"\n\t\t Visit us @ www.vaikarhospitals.org ";
      }
      void intro()
      {
       cout<<"\n\t\t\t     -------------- ";
       cout<<"\n\t\t\t     | e-EYE CARE | ";
       cout<<"\n\t\t\t     | ********** | ";
       cout<<"\n\t\t\t     -------------- ";
       cout<<"\n\n    AIM OF THE PROJECT: ";
       cout<<"\n\n    *The project entitled 'e-EYE CARE' \n     is aimed to store the patient details. ";
       cout<<"\n\n    *It also offers the patients to know about the common eye defects. ";
       cout<<"\n\n    *Searching, modification and deletion of records can be done. ";
       cout<<"\n\n    *The patient database is being protected by a password \n     which can be only accessed by the hospitals data base manager. ";
       cout<<"\n\n    *Patient's details such as code, name, address,\n     date of birth, phone number can be stored. ";
       cout<<"\n\n    *Type of defect and power of left and right  eyes \n     can also be stored after consultaion with the doctor. ";
      }
      void main()
      {
       clrscr();
       textbackground(YELLOW);textcolor(WHITE);
       char s;
       int ch1=0,ch2=0;
       char b[3];
       intro();
       delay(2000);
       into:cout<<"\n\n\t ENTER * TO ENTER MAIN MENU: ";
       cin>>s;
       clrscr();
       if(s=='*')
       {
	main:
	cout<<"\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^";
	cout<<"\n\t\t\t^ VAIKAR EYE HOSPITAL ^";
	cout<<"\n\t\t\t^   CHENNAI -600080   ^";
	cout<<"\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^";
	do
	{
	cout<<"\n\n\t MAIN MENU ";
	cout<<  "\n\t ~~~~~~~~~ ";
	cout<<"\n\n\t 1. COMMON EYE DEFECTS. ";
	cout<<  "\n\t 2. PATIENT DATABASE. ";
	cout<<  "\n\t 3. ABOUT US. ";
	cout<<  "\n\t 4. EXIT. ";
	cout<<"\n\n\t ENTER YOUR CHOICE: ";
	cin>>ch1;
	clrscr();
	switch(ch1)
	{
	 case 1: common();
		 delay(5000);
		 break;
	 case 2: pass: cout<<"\n\t ENTER PASSWORD: ";
		 gets(b);
		 cout<<"\n\t CHECKING ...... ";
		 delay(3000);
		 clrscr();
		 if(strcmp(b,"vk1")==0)
		 {
		  cout<<"\n\n\n\t :) WELCOME TO PATIENT DATABASE :) \n";
		  cout<<"\n\n\t Please Wait ...... ";
		  delay(5000);
		  clrscr();
		  do
		  {
		   cout<<  "\n\t PATIENT DATABASE ";
		   cout<<  "\n\t ~~~~~~~~~~~~~~~~ ";
		   cout<<"\n\n\t 1. ADD PATIENT DETAILS. ";
		   cout<<  "\n\t 2. VIEW ALL PATIENT DETAILS. ";
		   cout<<  "\n\t 3. VIEW A PARTICULAR PATIENT'S DETAIL. ";
		   cout<<  "\n\t 4. MODIFY A PARTICULAR PATIENT'S DETAIL. ";
		   cout<<  "\n\t 5. DELETE A PARTICULAR PATIENT'S DETAIL.";
		   cout<<  "\n\t 6. GOTO MAIN MENU. ";
		   cout<<  "\n\t 7. EXIT. ";
		   cout<<"\n\n\t ENTER YOUR CHOICE: ";
		   cin>>ch2;
		   clrscr();
		   switch(ch2)
		   {
		     case 1: cout<<"\n\t ADD PATIENT DETAILS. ";
			     cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~ ";
			     write();
			     delay(3000);
			     clrscr();
			     break;
		     case 2: cout<<"\n\t VIEW ALL PATIENT DETAILS. ";
			     cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~~~~~~ ";
			     read();
			     delay(8000);
			     break;
		     case 3: cout<<"\n\t VIEW A PARTICULAR PATIENT'S DETAIL. ";
			     cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
			     search();
			     delay(5000);
			     break;
		     case 4: cout<<"\n\t MODIFY A PARTICULAR PATIENT'S DETAIL. ";
			     cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
			     modify();
			     delay(5000);
			     break;
		     case 5: cout<<"\n\t DELETE A PARTICULAR PATIENT'S DETAIL. ";
			     cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
			     deldata();
			     delay(5000);
			     break;
		     case 6: goto main;
		     case 7: exit(1);
			     break;
		   default : cout<<"\n\t ! SORRY WRONG CHOICE ! ";
			     break;
		   }
		  }while(ch2);
		 }
		 else
		 {
		  cout<<"\n\t :( SORRY WRONG PASSWORD :( \n\n ";
		  cout<<"\n\t ENTER AGAIN.... \n\n ";
		  goto pass;
		 }
		 break;
	 case 3: aboutus();
		 delay(5000);
		 break;
	 case 4: exit(1);
		 break;
	 default: cout<<"\n\t ! SORRY WRONG CHOICE !";
		  break;
	}
	}while(ch1);
       }
       else
       {
	clrscr();
	cout<<"\n\t SORRY! PLEASE ENTER AGAIN..... ";
	goto into;
       }
      }
