#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define n 100
using namespace std;
class crypt
	{
	char str[n];
	char estr[n*4-1];
	char dstr[n];
	public:
		crypt();
		void encrypt();
		void decrypt();
	};
crypt::crypt()
	{
	cout<<"Enter the String to Encode : - ";
	gets(str);
	estr[0]='\0';
	dstr[0]='\0';
	}
void crypt::encrypt()
	{
		int i=0;
		while(str[i])
		    {
				int key=llround((toupper(str[i])-64)*13.84);
				key=abs((rand()%14)+(key-14));
				sprintf(estr,"%s%03d.",estr,key);
				i++;
			}
		//cout<<"\nThe Decoded String : - "<<estr;
		estr[i*4-1]='\0';
		for(i=0;i<strlen(estr);i=i+4)
		    {
				char temp=estr[i];
				estr[i]=estr[i+2];
				estr[i+2]=temp;
			}
		cout<<"\nThe Decoded String : - "<<estr;
	}
void crypt::decrypt()
	{
		char temp[3];
		int j,i;
		
		for(i=0;i<strlen(estr);i=i+4)
		    {
                char Char=estr[i];
				estr[i]=estr[i+2];
				estr[i+2]=Char;
				for(j=0;j<3;j++)
				    temp[j]=estr[i+j];
				j=1;
				int num=atoi(temp);
				while(j<27)
				    {
							if(llround(j*13.84)>num)
						    {
							int l=strlen(dstr);
						    dstr[l]=(char)(64+j);
						    dstr[l+1]='\0';
						    break;
							}
						j++;
					}
			}
			cout<<"\n\nString decoded from the Decoded String : - "<<dstr<<"\n\n";
	}

int main()
	{
	crypt obj;
	obj.encrypt();
	obj.decrypt();
	system("pause");
	return 0;
	}
