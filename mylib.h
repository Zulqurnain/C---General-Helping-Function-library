#include<cstdlib>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <conio.h>
#include <string.h>


/*Functions Headers Start*/

char chrand(char,char);
int bintodeci(long int);
void stf();
void fts();
void tictac();
char evenoddchar();
int paliornot(int);
void divideshow(int[]);
void displayMCIF(double);
void displayAP(double,double);
void selecsort(int[],int);
void selecsort(char);
bool bsearch(int[],int,int);
bool bsearch(char[],char);
double gsales1(double,int,int);
bool passpro(char[]);
void parr(int[],int);
void parr(char[]);
void printAsBits(uint32_t);
bool bubbleSort(T*, int);
int numOfBytesInFile(FILE*);


/*Functions Headers End*/


/*
Functions Definations In Comments:

*   chrand(initial ch,final ch) >>> it will randomize character from initial character to final character.

*   stf() >>it will input single precision number and convert to respective float decimal.

*   fts()  >> it will convert floating point (decial) to binary 32 bit single precision representation.

*   paliornot(int num) >> it will find that any number is palindrome or not return 1 if pali & if not return 0

*   divideshow(int arr[]) >> To get Values of numerator and denominator as (1/2) + (3/4) === (arr[0]/arr[1]) + (arr[3]/arr[4])

*   displayMCIF(double distance) >> it will take distance as input and convert and display its respective METERS / Centimeters / Inches / Feet

*   displayAP(double l,double b) >> // it will take any two of input as width , length ,breath and Calculate and display area and parimeters of given inputs.

*   gsales1(double fixed_sal,int days,int percentage)

--- it calculates the totlal salary of employ by adding gross salary of given days and percentage of gross profit
--- (Fixed_salary , Number_of_days ,percent_nuber) // percent_number = 9 , if 9%

*   evenoddchar() // it will get a character as input don't echo it and convert even char to odd and odd char to even e.g p=evenoddchar();

*	tictac() // it is a complete tictac toe game idiot computer + user play but not computer never loss. 

*	selecsort(int[],int) selection sort integer array array[],SIZE

*	selecsort(char) selection sort character array

*	bsearch(int[],int,int) binary search of integer array (array , SIZE , search_value)

*	bsearch(char[],char) binary search of character array (array , character_to_search)

*	passpro(char[]) password protecter ("PASSWORD") or ("12345") or (password[]) it will return 1 if matched if not then 0

*	parr(int[],int) print integer array (array,SIZE)

*	parr(char[]) print character array till null character (array)

*   void printAsBits(uint32_t);  take an integer of type uint32_t and print it as 32 bits binary

*   bool bubbleSort(T* arr, int size);  take any type of array and its size and bubble sort it , T variable should have '<' operator overloaded  

*   int numOfBytesInFile(FILE*);  take FILE* and return number of bytes in a file

*/

char chrand(char b, char z)
{
	srand(time(NULL));
	int r=0,chIni=b,chFin=z;
	char ch,a;
	for(int i=0;i!=-1;){
		r=rand();
		r=r%(chFin+1);
		ch=r;
		if((r>=chIni)&&(r<=chFin)){
			i=-1;
		}
		if(ch==a)
			i=0;
		a=r;
	}
	return ch;
}

int numOfBytesInFile(FILE* file){
	int s = -1;
	if (file != NULL){
		fseek(file, 0L, SEEK_END);
		s = ftell(file);
		fseek(file, 0L, SEEK_SET);
	}
	
	return s;
}

void printAsBits(uint32_t n) {
	if (n) {
		printAsBits(n >> 1);
		printf("%d", n & 1);
	}
}

template<typename T>
bool bubbleSort(T* tarray, int size){
	T temp;
	bool ret = false;
	for (int i = size; i > 1; i--,ret=1){
		for (int j = 0; j < i - 1; j++){
			if (tarray[j] > tarray[j + 1]){
				temp = tarray[j];
				tarray[j] = tarray[j + 1];
				tarray[j + 1] = temp;
			}
		}
		int k = 0;
	}
	return ret;
}


int bintodeci(long int num){ // converting binary to decimal
	int r=1,m=1,deciexpo=0;
	while(num!=0){
		r=num%10;
		deciexpo+=(r*m);
		m*=2;
		num/=10;
	}
	return deciexpo;
}

void stf(){ // single precision to float

	int sign,expo;
	long double manTisadeci=0.0,dFractional=0.0 ,fraFactor=0.5,manTisabin=0;
	long int dIntegral = 0,bIntegral=0,bFractional[1000];
	long int intFactor=1,remainder=0,i=0,k=0,flag=0;
	char manTisa[1000];
	cout<<"*****************Single Precision 32 bit To Float(decimal)*************\n\n";
	cout<<"Enter Sign bit (0 or 1) :=: "; cin>>sign; cout<<"\n\n";
	cout<<"Enter Exponent (8 bit value) :=: "; cin>>expo; cout<<"\n\n";
	printf("\n\nEnter manTisa in format :=: ");
	scanf("%s",manTisa);
	cout<<"\n\n";
	system("CLS");
	printf("Converted from:\n\n**************************************************\n* Sign bit* Exponent *       Mantisa             *\n\n*     %d   * %d * %s   *\n**************************************************\n\n",sign,expo,manTisa);
	int deciexpo=0;
	deciexpo=bintodeci(expo); // conveting exponent to decimal
	deciexpo-=127;

   //converting fractional binary to deimal of mantisa part fraBinary

	while(i<23){  //seperating each digit as character using array
		bFractional[k++] = manTisa[i] -48;
		 i++;
	}

	for(i=0;i<k;i++){ // Now multiplying and adding it to its decimal float value
		 dFractional  = dFractional  + bFractional[i] * fraFactor;
		 fraFactor = fraFactor / 2;
	}
	manTisadeci = 1 + dFractional ;

	manTisadeci*=pow(2,deciexpo);  // now adding as Answer = mantisa*2^exponent from sir notes of floating point conversion


	char sbit='+';
	if(sign==1)
		sbit='-';
	printf("\n\n Decimal Values of Given Binaries :=: %c%Lf",sbit,manTisadeci);
}

void fts()
{
	double n=0,df;
	int di,frag[100]={0},div=1;
	cout<<"Enter Your Number :=:"; cin>>n; cout<<"\n\n";
	long int ss=n;
	if(n<0)
		n*=-1;
	di=n;  // taking out integral part of entered num
	df=n-di; // taking out fractional part of entered num

	//	converting decimal to binary (integer part)

	long double fraBinary,bFractional = 0.0,fraFactor=0.1;
	long int bIntegral=0,deci;
	int intFactor=1,remainder=0,temp,i;

	while(di!=0){
		 remainder= di % 2;
		 bIntegral= bIntegral + remainder * intFactor;
		 di=di/2;
		 intFactor*= 10;
	}

	int e=0,s;
	long int biInt=bIntegral;

	// converting of fractional part

	for(i=1;i<=23;i++){

	   df = df * 2;
	   temp =  df;
	   frag[i-1]=temp;
	   if(temp ==1)
			 df = df - temp;

	   fraFactor/=10;
	}
	fraBinary =  bIntegral;

   // moving point to its least
	if((biInt!=0)&&(biInt!=1)){
		while(biInt!=1){
			fraBinary*=0.1;
			biInt=fraBinary;
			e+=1;
			div*=10;
		}
		deci=(fraBinary-1)*div;
	}
	int ee=22-e;
	e+=127;
	bIntegral=0, intFactor=1,remainder=0;

	while(e!=0){
		remainder=e%2;
		bIntegral+=remainder*intFactor;
		e=e/2;
		intFactor=intFactor*10;
	}

	e=bIntegral;

	if(ss<0)
		s=1;
	else
		s=0;
	if((biInt!=0)&&(biInt!=1))
		printf("\n\nConverted from:\n\n**************************************************\n* Sign bit* Exponent *       Mantisa             *\n\n*     %d   * %8d * %d",s,e,deci);
	else
		printf("\n\nConverted from:\n\n**************************************************\n* Sign bit* Exponent *       Mantisa             *\n\n*     %d   * %8d * ",s,e);
	for(int dil=0;dil<ee+1;dil+=1)
	   printf("%d",frag[dil]);
	printf("   *\n**************************************************\n\n");
}


int paliornot(int num)  // num is the number to find its palindrome
{
	int div=1,co=0,ets[200],ste[200];
	int divisor=1,cou=0;//
	for(int h=0;divisor!=0;h++){ // entering value to the array end to start
		ets[h]=(num/div)%10;
		divisor=num/div;
		div*=10; // increasing divisor
		cou++;
	}

	cou-=2;  // total number of digits in number in end to start

	for(int j=cou,g=0;j>=0;j--,g++)  // assigning reverse of the reversed array as  -(-1)=1
		ste[g]=ets[j];

	for(int k=0;k<=cou;k++){  // matching if palindrom
		if(ets[k]==ste[k]){
			co++;
		}
	}
	if(num%2==1) // if odd
		co-=1;
//	cout<<"h:=:"<<h<<"\nco:=:"<<co<<"\nk:=:"<<k<<"\n";
	if(co==cou)
		return 1;
	else
		return 0;

}


void divideshow(int arr[]){ // To get Values of numerator and denominator as (1/2) + (3/4) === (arr[0]/arr[1]) + (arr[3]/arr[4])
 	int sum[2],small=0;
	sum[1]=arr[1] * arr[3];
	sum[0]=( ((sum[1]/arr[1])*arr[0]) + ((sum[1]/arr[3])*arr[2]) );
    small=(sum[0]<sum[1])?sum[0]:sum[1];

    cout<<"\n\nSum of dividors Are :=: ";
    for(int i=2; i<=small;){
       if(sum[0]%i==0 && sum[1]%i==0){
            sum[0]/=i,sum[1]/=i;
            cout<<sum[0]<<"/"<<sum[1]<<" :=: ";
        }
       else
        i++;
    }
    cout<<"\n\n";
}

void displayMCIF(double d){

	double m=d*1000 ,c=(d*1000)*100;
	double inch=(c/100)/1000;
	double f=12*inch;

    cout<<"Distance(Km) In ::"<<"Meters ="<<m<<"\n\nDistance(Km) In ::"<<"Centimeters ="<<c<<"\n\nDistance(Km) In ::"<<"inches ="<<inch<<"\n\nDistance(Km) In ::"<<"Feet ="<<f<<"\n\n";

}


void displayAP(double len,double bre){  // it will take any two of input as width , length ,breath and Calculate and display area and parimeters of given inputs.

	double p,a;
	p=(2*len)+(2*bre),a=len*bre;
	cout<<"Area of Values :=: "<<a<<"\n\n"<<"Parimeter of Values :=: "<<p<<"\n\n";
}

double gsales1(double fixed_sal,int dd,int p){
	double tgs,c=0;
	cout<<"\n::Enter Gross Sales For "<<dd<<" days ::"<<"\n\n";
	for(int i=1;i<=dd;i++){
		cout<<"Day "<<i<<" sales amount :=: "; cin>>tgs; cout<<"\n";
		c+=tgs;
	}
	double total;
	p/=100;
	total=(fixed_sal+(p*c));

	return total;
}

char evenoddchar(){ // A function to take input but Show odd character as small letters but even as big letter.
    
	char c;
    c=getch();
    for(int i=1;i<26;i++){
        if((c%2==1)&&(c>=65 && c<=90)){
            c+=32;
        }
        else if((c%2==0) && (c>=97 && c<=122)){
            c-=32;
        }
    }
    
    return c;
}

void tictac(){

	/* it Requires : cstdlib.h , and chrand function,  */
	int f=9,p1loop=1,p2loop=1,iter=1;
	char e,temp;
	int a,b;
	char a1,a2,v1,v2,charac;
	int loop2=0;
	char p1=32,p2=32,p3=32,p4=32,p5=32,p6=32,p7=32,p8=32,p9=32,te=32;
	cout<<"**************Tick And Cross Game By Zulqurnain jutt********************\n*\t\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t*\n";
	cout<<"****************KINDLY ENTER 1 FOR Tick AND 0 For Cross******************\n\n\n";
	while(f){

		cout<<".-.So Here Is The New Game.-.\n\n";
		cout<<"      *    *  \n"<<"   A  * B  * C \n"<<"      *    *  \n"<<"******************\n"<<"   D  * E  * F \n"<<"      *    *  \n"<<"******************\n"<<"   G  * H  * I \n"<<"      *    *  \n"<<"      *    *  \n\n\n";
		cout<<"Player 1 enter Value [O or 1]:=:";
		cin>>temp;
		cout<<"\n\n";
		if(temp=='0'){
			a=0;
			cout<<"Player 2 Value is selected:=: "; 
			cout<<"1 (Tick)\n\n";
			b=1;		
		}
		else if(temp=='1'){
			a=1;
			cout<<"Player 2 Value is selected:=: ";
			cout<<"0 (Cross)\n\n";
			b=0;
	
		}
		else if((a!=0)&&(a!=1)){ 
			system("CLS");
			cout<<"Invalid Value Entered\n\nEnter Correct Value\n\n";
			continue;
		}
		cout<<"Computer Play As Second User (y/n) "; cin>>charac; cout<<"\n\n";
		system("CLS");
		if(f!=0){
			cout<<"!!! Lets Start Playing !!!\n\n";
			cout<<"      *    *  \n"<<"   A  * B  * C \n"<<"      *    *  \n"<<"******************\n"<<"   D  * E  * F \n"<<"      *    *  \n"<<"******************\n"<<"   G  * H  * I \n"<<"      *    *  \n"<<"      *    *  \n\n\n";
			loop2=0;
			p1=32,p2=32,p3=32,p4=32,p5=32,p6=32,p7=32,p8=32,p9=32,te=32;
			while (loop2==0){
				while(p1loop==1){
					cout<<"Player 1 Enter your Position(IN CAPITAL LETTERS PLZ):=:";
					cin>>a1; cout<<"\n\n";
					if((a1=='A' || a1=='a')&&(a2!=a1)&&(a1!=v1)&&(p1==32)){      //for the player 1 & 2 graph value comparison
						if((a==1)){
							p1='1';
						}
						else{
							p1='0';
						}
						p1loop=0;
					}
					else if((a1=='B' || a1=='b')&&(a2!=a1)&&(a1!=v1)&&(p2==32)){
						if((a==1)){
							p2='1';
						}
						else{
							p2='0';
						}
						p1loop=0;				
					}
					else if((a1=='C' || a1=='c')&&(a2!=a1)&&(a1!=v1)&&(p3==32)){
						if((a==1)){
							p3='1';
						}
						else{
							p3='0';
						}
						p1loop=0;				
					}
					else if((a1=='D' || a1=='d')&&(a2!=a1)&&(a1!=v1)&&(p4==32)){
						if((a==1)){
							p4='1';
						}
						else{
							p4='0';
						}
						p1loop=0;				
					}
					else if((a1=='E' || a1=='e')&&(a2!=a1)&&(a1!=v1)&&(p5==32)){
						if((a==1)){
							p5='1';
						}
						else{
							p5='0';
						}
						p1loop=0;					
					}
					else  if((a1=='F' || a1=='f')&&(a2!=a1)&&(a1!=v1)&&(p6==32)){
						if((a==1)){
							p6='1';
						}
						else{
							p6='0';
						}
						p1loop=0;				
					}
					else if((a1=='G' || a1=='g')&&(a2!=a1)&&(a1!=v1)&&(p7==32)){
						if((a==1)){
							p7='1';
						}
						else{
							p7='0';
						}
						p1loop=0;				
					}
					else if((a1=='H' || a1=='h')&&(a2!=a1)&&(a1!=v1)&&(p8==32)){
						if((a==1)){
							p8='1';
						}
						else{
							p8='0';
						}
						p1loop=0;				
					}
					else if((a1=='I' || a1=='i')&&(a2!=a1)&&(a1!=v1)&&(p9==32)){
						if((a==1)){
							p9='1';
						}
						else{
							p9='0';
						}
						p1loop=0;
					}
					v1=a1;
				}
									//showing of the graph of values in numbers forms
				cout<<"      *    *  \n"<<"   A  * B  * C \n"<<"      *    *  \n"<<"******************\n"<<"   D  * E  * F \n"<<"      *    *  \n"<<"******************\n"<<"   G  * H  * I \n"<<"      *    *  \n"<<"      *    *  \n\n\n";
				cout<<"So you Selected This Location\n\n"<<"      *    *  \n"<<"   "<<p1<<"  * "<<p2<<"  * "<<p3<<"\n"<<"      *    *  \n"<<"******************\n"<<"   "<<p4<<"  * "<<p5<<"  * "<<p6<<"\n"<<"      *    *  \n"<<"******************\n"<<"   "<<p7<<"  * "<<p8<<"  * "<<p9<<"\n"<<"      *    *  \n"<<"      *    *  \n\n\n";

				if (((p1==p5)&&(p5==p9)&&(p9!=te))||(p1==p4&&p4==p7&&(p7!=te))||(p1==p2&&p2==p3&&(p3!=te))||(p2==p5&&p5==p8&&(p8!=te))||(p3==p6&&p6==p9&&(p9!=te))||(p4==p5&&p5==p6&&(p6!=te))||(p7==p8&&p8==p9&&(p9!=te))||(p3==p5&&p5==p7&&(p7!=te))){
					cout<<"Player 1 ,Congratulations You Have Won\n\n";
					loop2+=1;	p2loop=0;
					continue;
				}
					/* **************player2 Area Starts Here******************* */
				while(p2loop==1){
					if((charac=='y')||(charac=='Y')){
						a2=chrand('A','I');
					}
					else{
						cout<<"Player 2 Enter your Position(IN CAPITAL LETTERS PLZ):=:";
						cin>>a2; cout<<"\n\n";
					}
					cout<<"\n\n";					
					if((a2!=v2)&&(a2=='A' || a2=='a')&&(a2!=v1)&&(p1==32)){             //for the player 1 & 2 graph value comparison
						if((b==1)){
							p1='1';
						}
						else{
							p1='0';
						}
						p2loop=0;
					}
					else if((a2!=v2)&&(a2=='B' || a2=='b')&&(a2!=v1)&&(p2==32)){
						if((b==1)){
							p2='1';
						}
						else{
							p2='0';
						}
						p2loop=0;					
					}
					else if((a2!=v2)&&(a2=='C' || a2=='c')&&(a2!=v1)&&(p3==32)){
						if((b==1)){
							p3='1';
						}
						else{
							p3='0';
						}
						p2loop=0;				
					}
					else if((a2!=v2)&&(a2=='D' || a2=='d')&&(a2!=v1)&&(p4==32)){
						if((b==1)){
							p4='1';
						}
						else{
							p4='0';
						}
						p2loop=0;					
					}
					else if((a2!=v2)&&(a2=='E' || a2=='e')&&(a2!=v1)&&(p5==32)){
						if((b==1)){
							p5='1';
						}
						else{
							p5='0';
						}
						p2loop=0;					
					}
					else  if((a2!=v2)&&(a2=='F' || a2=='f')&&(a2!=v1)&&(p6==32)){
						if((b==1)){
							p6='1';
						}
						else{
							p6='0';
						}
						p2loop=0;					
					}
					else if((a2!=v2)&&(a2=='G' || a2=='g')&&(a2!=v1)&&(p7==32)){
						if((b==1)){
							p7='1';
						}
						else{
							p7='0';
						}
						p2loop=0;					
					}
					else if((a2!=v2)&&(a2=='H' || a2=='h')&&(a2!=v1)&&(p8==32)){
						if((b==1)){
							p8='1';
						}
						else{
							p8='0';
						}
						p2loop=0;					
					}
					else if((a2!=v2)&&(a2=='I' || a2=='i')&&(a2!=v1)&&(p9==32)){
						if((b==1)){
							p9='1';
						}
						else{
							p9='0';
						}
						p2loop=0;					
					}
					v2=a2;					
				}
									//showing of the graph of values in numbers forms
				cout<<"      *    *  \n"<<"   A  * B  * C \n"<<"      *    *  \n"<<"******************\n"<<"   D  * E  * F \n"<<"      *    *  \n"<<"******************\n"<<"   G  * H  * I \n"<<"      *    *  \n"<<"      *    *  \n\n\n";
				cout<<"So you Selected This Location\n\n"<<"      *    *  \n"<<"   "<<p1<<"  * "<<p2<<"  * "<<p3<<"\n"<<"      *    *  \n"<<"******************\n"<<"   "<<p4<<"  * "<<p5<<"  * "<<p6<<"\n"<<"      *    *  \n"<<"******************\n"<<"   "<<p7<<"  * "<<p8<<"  * "<<p9<<"\n"<<"      *    *  \n"<<"      *    *  \n\n\n";
	
				if (((p1==p5)&&(p5==p9)&&(p9!=te))||(p1==p4&&p4==p7&&(p7!=te))||(p1==p2&&p2==p3&&(p3!=te))||(p2==p5&&p5==p8&&(p8!=te))||(p3==p6&&p6==p9&&(p9!=te))||(p4==p5&&p5==p6&&(p6!=te))||(p7==p8&&p8==p9&&(p9!=te))||(p3==p5&&p5==p7&&(p7!=te))){
					cout<<"Player 2 ,Congratulations You Have Won\n\n";
					loop2+=1;
					//continue;
				}
				p1loop=1; p2loop=1;				
	
			}          // while loop of the tick croxx game
			iter+=1;
			if(iter>9){
				system("CLS");
				cout<<"\n\n!!!!!!!!!!!!!!!!!!Game Drwaw!!!!!!!!!!!!!!!!!!!!!!\n\n";
				f=0;
			}
		}
		cout<<"Enter Y to play again or N to Exit==>"; cin>>e; cout<<"\n\n";
		temp='1';
		if(e=='Y'||e=='y'){
			system("CLS");
			cout<<"\n\n\n\n\n";
		}
		else if(e=='N'||e=='n'){
			system("CLS");
			cout<<"Nice To Meet Donot Forget to visit www.H4ck3rCracks.com\n\n";
			f=0;
		}

	}   // external looping

	return;
}

void selecsort(int a[],int S){  // selection sort of int array

	for(int p=0;p<S;p++){
		for(int i=0;i<S;i++){
			if(a[i]>a[p]){
				a[i]+=a[p];

				a[p]=a[i]-a[p];
				
				a[i]-=a[p];
			}
		}
	}
}

void selecsort(char a[]){  // selection sort of character array

	for(int y=0;a[y]!='\0';y++);

	for(int p=0;p<y;p++){
		for(int i=0;i<y;i++){
			if(a[i]>a[p]){
				a[i]+=a[p];

				a[p]=a[i]-a[p];
				
				a[i]-=a[p];
			}
		}
	}

}

bool bsearch(int arr[],int s,int val){  // binary search of int array 


	int st=0;
	int m=(st+s)/2;

	for(st=0;st<=s;){
		if(arr[m]== val){
			return true;
			break;
		}
		else if(val > arr[m])
			st=m+1;
		else if(val < arr[m])
			s=m-1;
		m=(st+s)/2;
	}
	return false;
}

bool bsearch(char arr[],char val){  // binary search of character array array should be sorted a,b,c,d etc

	int st=0,s;
	
	for(s=0;arr[s]!='\0';s++);
	
	s--;
	
	int m=(st+s)/2;

	for(st=0;st<=s;){
		if(arr[m]== val){
			return true;
			break;
		}
		else if(val > arr[m])
			st=m+1;
		else if(val < arr[m])
			s=m-1;
		m=(st+s)/2;
	}
	return false;
}

bool passpro(char pass[]){

	char InputStr[2000];//The users input will be saved in this variable.
	int co=0; // counter of wrong attepts
	
	do{
		printf("\t\t\n\n\n\n\n\t\n\n\t\t\t\n\n\t\t\tEnter the password :");
		scanf("%s",InputStr);
		system("CLS");
		printf("\n\nWrong Attempts :=: %d\n\n\t::Wrong Attepts Must Not be greater than 5::",co++);
	}
	while((strcmp(pass, InputStr)!=0)&&(co<7));	//The loop will run until the input = Password.
	system("CLS");
	if(co<7){
		return 1;
	}
	else
		return 0;
	/*{
		printf("\t\t\n\n\n\n\n\t\n\n\t\t\t\n\n\t\t\tAccess Denied\t\t\n\n\n\n\n\t\n\n\t\t\t\n\n\t\t\t");  // access denied :p
	}*/
}

void parr(int t[],int s){

	for(int q=0;q<s;q++){
		if((q+1)%10==0)
			cout<<"\n";
		cout<<t[q]<<"\t";
	}
	cout<<"\n";
}

void parr(char t[]){

	for(int q=0;t[q]!='\0';q++){
		if((q+1)%10==0)
			cout<<"\n";
		cout<<t[q]<<"\t";
	}
	cout<<"\n";
}