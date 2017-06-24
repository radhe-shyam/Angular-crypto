#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define n 100
#define div 9
using namespace std;
class crypt
	{
	char str[n];
	int etype;
	char estr[500];
	char dstr[n];
	void line();
	int penc(char ch);
	char pdec(int num);
	int nenc(char ch);
	char ndec(int num);
	public:
		crypt();
		void encrypt();
		void decrypt();
	};
crypt::crypt()
	{
	str[0]='\0';
	start:
	system("cls");
	line();
	cout<<"\t\t\tANGULAR CRYPTOGRAPHY\n";
	line();
	cout<<"\nEnter a Message : ";
	if(str[0]=='\0')
		gets(str);
	else
	    cout<<str<<endl;
	line();
	cout<<"\n\tPress 1 for Encryptino using Positive Angle Traversal Method\n\n";
	cout<<"\tPress 2 for Encryption using Negative Angle Traversal Method\n\n";
	cout<<"\tPress 3 for Encryption using Positive-Negative Angle Traversal Method\n\n";
	cout<<"\tPress 4 for Encryption using Negative-Positive Angle Traversal Method\n\n";
	cout<<"\n\t\t\tEnter Your choice : ";
	cin>>etype;
	if(!(etype>=1 && etype<=4))
	    {
		cout<<"\nWrong choice\nEnter Again...\n";
		system("pause");
     	goto start;
		}
	line();
	estr[0]='\0';
	dstr[0]='\0';
	}
int crypt::penc(char ch)
{
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
		return (toupper(ch)-50)*div;
	else if(ch>=48 && ch<=57)
		return (ch-44)*div;
	else
		{
			switch(ch)
				{
					case ' ': return 9;
		           				break;
					case ',': return 18;
		           				break;
					case '.': return 27;
					            break;
					case '?': return 126;
					            break;
					default:  cout<<"\nFound undefined symbol - "<<ch<<endl<<"Program terminated\n";
		       			     	system("pause");
		       			     	exit(0);
				}
		}
}
char crypt::pdec(int num)
{
	int j;
   	if(num>-1 && num<10)
	    return ' ';
	else if(num>9 && num<19)
	    return ',';
	else if(num>18 && num<28)
	    return '.';
	else if(num>117 && num<127)
	    return '?';
	else if(num>126 && num<361)
	    {
		j=15;
		while(j<41)
				    {
							if(num<=(j*div) && num>((j-1)*div))
								return (char)j+50;
							j++;
					}
		}
	else
	    {
		j=4;
		while(j<14)
				    {
							if(num<=(j*div) && num>((j-1)*div))
								return (char)j+44;
							j++;
					}
		}
}
int crypt::nenc(char ch)
{
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
		return (91-toupper(ch))*div;
	else if(ch>=48 && ch<=57)
		return (85-ch)*div;
	else
		{
			switch(ch)
				{
					case ' ': return 360;
		           				break;
					case ',': return 351;
		           				break;
					case '.': return 342;
					            break;
					case '?': return 243;
					            break;
					default:  cout<<"\nFound undefined symbol - "<<ch<<endl<<"Program terminated\n";
		       			     	system("pause");
		       			     	exit(0);
				}
		}
}
char crypt::ndec(int num)
{
	int j;
   	if(num>351 && num<360)
	    return ' ';
	else if(num>342 && num<352)
	    return ',';
	else if(num>333 && num<343)
	    return '.';
	else if(num>234 && num<244)
	    return '?';
	else if(num>-1 && num<235)
	    {
		j=26;
		while(j>0)
				    {
							if(num<=(j*div) && num>((j-1)*div))
								return (char)91-j;
							j--;
					}
		}
	else
	    {
		j=37;
		while(j>27)
				    {
							if(num<=(j*div) && num>((j-1)*div))
								return (char)85-j;
							j--;
					}
		}
}
void crypt::encrypt()
	{
		int i=0,key;
		switch(etype)
			{
				case 1:	sprintf(estr,"%s%03d",estr,penc('p')-(rand()%div));
      					while(str[i])
		    				{
							key=penc(str[i])-(rand()%div);
							sprintf(estr,"%s%03d",estr,key);
							i++;
							}
							break;
				case 2: sprintf(estr,"%s%03d",estr,penc('q')-(rand()%div));
      					while(str[i])
		    				{
							key=nenc(str[i])-(rand()%div);
							sprintf(estr,"%s%03d",estr,key);
							i++;
							}
							break;
				case 3: sprintf(estr,"%s%03d",estr,penc('r')-(rand()%div));
      					while(str[i])
		    				{
								if(i%2==0)
								    {
									key=penc(str[i])-(rand()%div);
									sprintf(estr,"%s%03d",estr,key);
									i++;
									}
								else
								    {
									key=nenc(str[i])-(rand()%div);
									sprintf(estr,"%s%03d",estr,key);
									i++;
									}
							}
							break;
				case 4: sprintf(estr,"%s%03d",estr,penc('s')-(rand()%div));
      					while(str[i])
		    				{
								if(i%2==0)
								    {
									key=nenc(str[i])-(rand()%div);
									sprintf(estr,"%s%03d",estr,key);
									i++;
									}
								else
								    {
									key=penc(str[i])-(rand()%div);
									sprintf(estr,"%s%03d",estr,key);
									i++;
									}

							}
			}
		/*for(i=0;i<strlen(estr);i=i+3)
		    {
				char temp=estr[i];
				estr[i]=estr[i+2];
				estr[i+2]=temp;
			}*/
		cout<<"\nAfter Encryption, Cipher text : "<<estr<<endl;
		line();
	}
void crypt::decrypt()
	{
		char temp[3];
		int j,i;
		/*for(i=0;i<strlen(estr);i=i+3)
		    {
				char Char=estr[i];
				estr[i]=estr[i+2];
				estr[i+2]=Char;
			}*/
    	for(j=0;j<3;j++)
		    temp[j]=estr[j];
		i=atoi(temp);
		if(i>261 && i<271)
		    i=1;
		else if(i>270 && i<280)
		    i=2;
		else if(i>279 && i<289)
		    i=3;
		else
		    i=4;
		switch(i)
		    {
				case 1: for(i=3;i<strlen(estr);i=i+3)
		    				{
               				for(j=0;j<3;j++)
				    			temp[j]=estr[i+j];
							dstr[(i-1)/3]=pdec(atoi(temp));
							}
						dstr[(i-1)/3]='\0';
						break;
				case 2: for(i=3;i<strlen(estr);i=i+3)
		    				{
               				for(j=0;j<3;j++)
				    			temp[j]=estr[i+j];
							dstr[(i-1)/3]=ndec(atoi(temp));
							}
							dstr[(i-1)/3]='\0';
						break;
				case 3: for(i=3;i<strlen(estr);i=i+3)
                            {
								for(j=0;j<3;j++)
				    					temp[j]=estr[i+j];
								if((i/3)%2==1)
										dstr[(i-1)/3]=pdec(atoi(temp));
				    			else
										dstr[(i-1)/3]=ndec(atoi(temp));
                            }
                        dstr[(i-1)/3]='\0';
						break;
				case 4: for(i=3;i<strlen(estr);i=i+3)
                            {
								for(j=0;j<3;j++)
				    					temp[j]=estr[i+j];
								if((i/3)%2==1)
										dstr[(i-1)/3]=ndec(atoi(temp));
				    			else
										dstr[(i-1)/3]=pdec(atoi(temp));
                            }
                        dstr[(i-1)/3]='\0';
			}
			cout<<"\nAfter Decryption, Message : "<<dstr<<"\n";
			line();
	}
void crypt::line()
	{
		for(int i=1;i<=80;i++)
		    cout<<"ß";
	}
int main()
	{
	crypt obj;
	obj.encrypt();
	obj.decrypt();
	system("pause");
	return 0;
	}
