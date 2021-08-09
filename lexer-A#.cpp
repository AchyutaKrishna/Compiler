/* Team - G68
   J Alvin Ronnie - 2018A7PS0029H
   Ajith PJ - 2018A7PS0040H
   Achyuta Krishna V - 2018A7PS0165H
   Anirudh G - 2018A7PS0217H





/*

Token to Token number matching

* - 			 Token 3	
/ - 			 Token 4	
% - 			 Token 5 	
{ - 			 Token 6	
} - 			 Token 7	
( - 			 Token 8	
) - 			 Token 9	
[ - 			 Token 10	
] - 			 Token 11	
; - 			 Token 12	
, - 			 Token 13	
? - 			 Token 14 
== - 			 Token 16	
:= - 			 Token 18	
: - 			 Token 19
>= - 			 Token 21	
> - 			 Token 22	
<= - 			 Token 24	
< - 			 Token 25	
!= - 			 Token 27
! - 			 Token 28
&& - 			 Token 30	
|| - 			 Token 32	
id - 			 Token 34	
floating point - Token 37	
integer - 		 Token 38	
+ - 			 Token 39	
printstring		 Token 47	
- - 			 Token 50	
int - 			 Token 100	
float - 		 Token 101	
char - 			 Token 102
void - 			 Token 103	
cin - 			 Token 104	
cout - 			 Token 105	
main - 			 Token 106	
return - 		 Token 107
if - 			 Token 108	
for - 			 Token 109	
true - 			 Token 110
false - 		 Token 111

*/

#include<bits/stdc++.h>

using namespace std;
int lb;
map<string,int> keywordtokennumber;
string keywords[]={"int","float","char","void","cin","cout","main","return","if","for","true","false"};
int linecount=1;

void lexer(vector<char> buffer1,vector<char> buffer2,int size,ofstream &File,ifstream &code)      // lexer function definition
{
	int state=0,fp=lb,x=1,flag=0;
	char c;
	string temp="",stringliteral="", intfloatliteral="";
	while(flag==0)
	{
		if(x==1)                                               // reading from the file in the form of 2 buffers
			c=buffer1[fp];
		if(x==2)
			c=buffer2[fp];
		if(c=='\0')
		{
			flag=1;
		}

		if(state == 4)                                        // ignoring comments in the input code
		{
			if(c == '/')
			{ while(c != '\n')
              {
              	if(fp<size-1)
				{
					fp++;
				}
				else
				{
					if(x==1)
					{
						fp=0;
						x=2;
					}
					else
					{
						buffer1=buffer2;
						buffer2.clear();
						buffer2.resize(size,'\0');
						code.read(buffer2.data(),size);
						x==2;
						fp=0;
					}

              	}
              	if(x==1)
					c=buffer1[fp];
				if(x==2)
					c=buffer2[fp];
			  }
			  state=0;
		    }
		 }

		switch(state)                                                        // implementing the DFA for lexical analysis where variable 'state' refers to states of the DFA
		{
			case 0:
				 if((c<='z' && c>='a')||(c<='Z' && c>='A'))
				 	{ state=43;
				 	  temp+=c;
				 	  break;
				    }

				 switch(c)
				 {
				 	case ' ':
				 		break;
				 	case '\n':
				 		linecount++;
				 		break;
				 	case '\t':
				 		break;
				 	case '*':
				 		state=3;
				 		break;
				 	case '/':
				 		state=4;
				 		break;
				 	case '%':
				 		state=5;
				 		break;
				 	case '{':
				 		state=6;
				 		break;
				 	case '}':
				 		state=7;
				 		break;
				 	case '(':
				 		state=8;
				 		break;
				 	case ')':
				 		state=9;
				 		break;
				 	case '[':
				 		state=10;
				 		break;
				 	case ']':
				 		state=11;
				 		break;
				 	case ';':
				 		state=12;
				 		break;
				 	case ',':
				 		state=13;
				 		break;
				 	case '?':
				 		state=14;
				 		break;
				 	case '=':
				 		state=15;
				 		break;
				 	case ':':
				 		state=17;
				 		break;
				 	case '>':
				 		state=20;
				 		break;
				 	case '<':
				 		state=23;
				 		break;
				 	case '!':
				 		state=26;
				 		break;
				 	case '&':
				 		state=29;
				 		break;
				 	case '|':
				 		state=31;
				 		break;
				 	case '+':
				 		state=33;
				 		intfloatliteral+=c;
				 		break;
				 	case '-':
				 		state=40;
				 		intfloatliteral+=c;
				 		break;
				 	case '0':
				 		state=41;
				 		break;
				 	case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				 	    state=34;
				 	    intfloatliteral+=c;
				 	    break;
				 	case '"':
				 		state=45;
				 		break;
				 	default:
				 		state=101;
				 		break;

				 }

				 break;
			case 3:
				File<<"Token 3,string *,line number "<<linecount<<endl;
				if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
				state=0;
				break;
            case 4:
                File<<"Token 4,string /,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 5:
                File<<"Token 5,string % ,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 6:
                File<<"Token 6,string {,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 7:
                File<<"Token 7,string },line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 8:
                File<<"Token 8,string (,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 9:
                File<<"Token 9,string ),line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 10:
                File<<"Token 10,string [,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 11:
                File<<"Token 11,string ],line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 12:
                File<<"Token 12,string ;,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 13:
                File<<"Token 13,string ,,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 14:
                File<<"Token 14,string ?,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 15:
                if(c=='=')
                    state=16;
                else
                    state=100;
                break;
            case 16:
                File<<"Token 16,string ==,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;

            case 17:
                if(c == '=')
                    state=18;
                else
                    state=19;
                break;
            case 18:
                File<<"Token 18,string :=,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 19:
                File<<"Token 19,string :,line number "<<linecount<<endl;
                if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
				state=0;
                break;

            case 20:
                if(c=='=')
                    state=21;
                else
                    state=22;
                break;
            case 21:
                File<<"Token 21,string >=,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 22:
                File<<"Token 22,string >,line number "<<linecount<<endl;
                if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 23:
                if(c=='=')
                    state=24;
                else
                    state=25;
                break;
            case 24:
                File<<"Token 24,string <=,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 25:
                File<<"Token 25,string <,line number "<<linecount<<endl;
                if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;

            case 26:
                if(c=='=')
                    state=27;
                else
                    state=28;

            case 27:
                File<<"Token 27,string !=,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 28:
                File<<"Token 28,string !,line number "<<linecount<<endl;
                if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;
            case 29:
                if(c=='&')
                    state=30;
                else
                    state=100;
                break;
            case 30:
                File<<"Token 30,string &&,line number "<<linecount<<endl;
                if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
                state=0;
                break;

            case 31:
            	if(c == '|')
            	  state=32;
            	else
            	  state=100;
            	break;

            case 32:
            	File<<"Token 32,string ||,line number "<<linecount<<endl;
            	if(fp>0)
				fp--;
				else
				{
					fp=size-1;
					if(x==1)
						x=2;
					else
						x=1;
				}
            	state=0;
            	break;

            case 33:

            	if(c >= '1' && c <= '9')
            	  { state=34;
            	  	intfloatliteral+=c;
            	  }
            	else
            	  state=39;
            	break;

            case 34:

            	if(c >= '0' && c <= '9')
            	  { state=34;
            	  	intfloatliteral+=c;
            	  }
            	else if(c == '.')
            	  { state=35;
            	    intfloatliteral+=c;
            	  }
            	else
            	  state=38;
            	break;

            case 35:

                if(c >= '0' && c <= '9')
            	  { state=36;
            	  	intfloatliteral+=c;

            	  }
            	else
            	  state=100;
            	break;

            case 36:

                if(c >= '0' && c <= '9')
            	  { state=36;
            	  	intfloatliteral+=c;
            	  }
            	else
            	  state=37;
            	break;

            case 37:
                File<<"Token 37,string "<<intfloatliteral<<",line number "<<linecount<<endl;
            	if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
            	state=0;
            	intfloatliteral="";
            	break;

			case 38:
                File<<"Token 38,string "<<intfloatliteral<<",line number "<<linecount<<endl;
            	if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
            	state=0;
            	intfloatliteral="";
            	break;

            case 39:

            	File<<"Token 39,string +,line number "<<linecount<<endl;
            	if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
            	state=0;
            	intfloatliteral="";
            	break;

            case 40:

            	if(c >= '1' && c <= '9')
            	 { state=34;
                   intfloatliteral+=c;
                 }
            	else
            	  state=50;
            	break;

            case 50:

            	File<<"Token 50,string -,line number "<<linecount<<endl;
                if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
            	state=0;
            	intfloatliteral="";
            	break;

            case 41:

            	if(c == '.')
            	  { state=35;
            	    intfloatliteral+=c;
            	  }
            	else
            	  state=42;
            	break;

            case 42:

            	File<<"Token 38,string 0,line number "<<linecount<<endl;
                if(fp>1)
				fp-=2;
				else
				{
					if(fp==1)
					fp=size-1;
					else
					fp=size-2;

					if(x==1)
						x=2;
					else
						x=1;
				}
            	state=0;
            	intfloatliteral="";
            	break;


			case 43:


				 	if((c=='_')||(c<='z' && c>='a')||(c<='Z' && c>='A'))
				 		{
				 			state=43;
				 			temp+=c;
				 		}

				 	else
				 	{
				 		state=44;

				 	}
					break;
			case 44:
					if(keywordtokennumber.count(temp))
				 		{

				 		    File<<"Token "<<keywordtokennumber[temp]<<",string "<<temp<<",line number "<<linecount<<endl;
				            if(fp>1)
							fp-=2;
							else
							{
							if(fp==1)
							fp=size-1;
							else
							fp=size-2;

							if(x==1)
								x=2;
							else
								x=1;
							}
				 		}
				 		else
				 		{
				 		    File<<"Token 34,string "<<temp<<",line number "<<linecount<<endl;
				 			if(fp>1)
							fp-=2;
							else
							{
								if(fp==1)
								fp=size-1;
								else
								fp=size-2;

								if(x==1)
									x=2;
								else
									x=1;
							}
				 		}
				 		state=0;
				 	temp="";
				 	break;
			case 45:
					if(c=='"')
					{
						state=47;
					}
					else
						if(c=='\\')
						{
							state=46;
							stringliteral+='\\';
						}
						else
						{
							state=45;
							stringliteral+=c;

						}
					break;
			case 46:
					stringliteral+=c;
					state=45;
					break;
			case 47:
                    File<<"Token 47,string "<<stringliteral<<",line number "<<linecount<<endl;
                    if(fp>0)
					fp--;
					else
					{
						fp=size-1;
						if(x==1)
							x=2;
						else
							x=1;
					}
					state=0;
					stringliteral="";
					break;
			case 100:
                    File<<"Lexical Error in line number "<<linecount<<endl;
                    state=0;
                    fp-=2;
		    break;
		    case 101:
		    File<<"Lexical Error in line number "<<linecount<<endl;
                    state=0;
                    fp-=1;
		    break;

		}
		if(flag==1)
		{
			if(state==45||state==46)
            {
                File<<"Error:String literal not terminated in line number "<<linecount<<endl;
            }
			break;
		}
		if(fp<size-1)                                                                           // updating fp to get the next character in the buffer
		{
			fp++;
		}
		else
		{
			if(x==1)
			{
				fp=0;
				x=2;
			}
			else
			{
				buffer1=buffer2;
				buffer2.clear();
				buffer2.resize(size,'\0');
				code.read(buffer2.data(),size);
				x==2;
				fp=0;
			}
		}


	}
}
int main(int argc,char** argv)
{
	char c;                                                  // Initialise the required variables
	lb=0;
	ifstream File;
    ofstream Output;
	int size=5;
	int tokenindex=0;
		for(auto x:keywords)
		{

			keywordtokennumber[x]=100+tokenindex;
			tokenindex++;
		}

	vector<char> buffer1(size),buffer2(size);
	File.open("code.txt",ios::in);                          // opening the file containg the code
	//File.open(argv[1],ios::in);                        
	Output.open("text.txt",ios::out);                      // opening the file to load the output

	File.read(buffer1.data(),size);                          
	File.read(buffer2.data(),size);
	lexer(buffer1,buffer2,size,Output,File);                 // calling the lexer function to identify lexemes and their corresponding token numbers


	File.close();                                            // closing the input file
	Output.close();                                          // closing the output file
	return 0;
}