#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream output;

    output.open("output.txt",ios::out);           // opening output file

  	map<int, string> s;                           // map with key as serial number of terminal/non-terminal and the value as the corresponding terminal/non-terminal

    s[0] = "Ae";
    s[1] = "Ae'";
    s[2] = "As";
    s[3] = "C";
    s[4] = "Cs";
    s[5] = "Ds";
    s[6] = "E";
    s[7] = "E'";
    s[8] = "F";
    s[9] = "Fac''";
    s[10] = "Fc";
    s[11] = "Fs";
    s[12] = "Ins";
    s[13] = "Ls";
    s[14] = "M";
    s[15] = "Mp";
    s[16] = "P";
    s[17] = "Pm";
    s[18] = "Prs";
    s[19] = "Ps";
    s[20] = "R";
    s[21] = "Re";
    s[22] = "S";
    s[23] = "S'";
    s[24] = "Sms";
    s[25] = "T";
    s[26] = "V";
    s[27] = "Vl";
    s[28] = "Vl'";
    s[29] = "Vn";
    s[30] = "eps";
    s[31] = "-";
    s[32] = "$";
    s[33] = "&&";
    s[34] = "(";
    s[35] = ")";
    s[36] = "*";
    s[37] = ",";
    s[38] = "/";
    s[39] = ":=";
    s[40] = ";";
    s[41] = "{";
    s[42] = "||";
    s[43] = "}";
    s[44] = "+";
    s[45] = "<";
    s[46] = "==";
    s[47] = ">";
    s[48] = "cin";
    s[49] = "cout";
    s[50] = "float";
    s[51] = "floatnum";
    s[52] = "for";
    s[53] = "id";
    s[54] = "if";
    s[55] = "int";
    s[56] = "intnum";
    s[57] = "main";
    s[58] = "printstring";
    s[59] = "void";
    
 

    map<string,int> s1;                                // inverse map of s
    for(auto x: s)
    {
      s1[x.second] = x.first;
    }

    map<string, int> w;                               // map of lexeme number and the corresponding lexeme
    w["34"] = 53; // id
    w["3"] = 36; // *
    w["4"] = 38; // /
    w["$"] = 1000; // $
    w["6"] = 41; //{
    w["7"] = 43; //}
    w["8"] = 34; //(
    w["9"] = 35; //)
    w["12"] = 40; // ;
    w["13"] = 37; // ,
    w["16"] = 46; // ==
    w["18"] = 39; // :=
    w["22"] = 47; // >
    w["25"] = 45; // < 
    w["30"] = 33; // &&
    w["32"] = 42; // ||
    w["47"] = 58; // printstring
    w["37"] = 51; // float const
    w["38"] = 56; // integer const
    w["39"] = 44; // +
    w["50"] = 31; // -
    w["100"] = 55; // int
    w["101"] = 50; // float
    w["103"] = 59; // void
    w["104"] = 48; // cin
    w["105"] = 49; // cout
    w["106"] = 57; // main 
    w["108"] = 54; // if
    w["109"] = 52; // for
    
    map<pair<int,int>,vector<int>> par;                     // modelling the parse table and inserting the entries
    vector<int> t;  

    t.push_back(s1["Fs"]);
    t.push_back(s1["M"]);
    par[make_pair(s1["P"],s1["float"])] = t;
    par[make_pair(s1["P"],s1["int"])] = t;
    par[make_pair(s1["P"],s1["main"])] = t;
    par[make_pair(s1["P"],s1["void"])] = t;

    t.clear();
    t.push_back(s1["main"]);
    t.push_back(s1["("]);
    t.push_back(s1[")"]);
    t.push_back(s1["{"]);
    t.push_back(s1["Sms"]);
    t.push_back(s1["}"]);
    par[make_pair(s1["M"],s1["main"])] = t;
    

    t.clear();
    t.push_back(s1["F"]);
    t.push_back(s1["Fs"]);
    par[make_pair(s1["Fs"],s1["float"])] = t;
    par[make_pair(s1["Fs"],s1["int"])] = t;
    par[make_pair(s1["Fs"],s1["void"])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Fs"],s1["main"])] = t;

    t.clear();
    t.push_back(s1["R"]);
    t.push_back(s1["id"]);
    t.push_back(s1["("]);
    t.push_back(s1["Ps"]);
    t.push_back(s1[")"]);
    t.push_back(s1["{"]);
    t.push_back(s1["Sms"]);
    t.push_back(s1["}"]);
    par[make_pair(s1["F"],s1["float"])] = t;
    par[make_pair(s1["F"],s1["int"])] = t;
    par[make_pair(s1["F"],s1["void"])] = t;


    t.clear();
    t.push_back(s1["void"]);
    par[make_pair(s1["R"],s1["void"])] = t;

    t.clear();
    t.push_back(s1["V"]);
    par[make_pair(s1["R"],s1["float"])] = t;
    par[make_pair(s1["R"],s1["int"])] = t;

    t.clear();
    t.push_back(s1["Pm"]);
    t.push_back(s1["Mp"]);
    par[make_pair(s1["Ps"],s1["float"])] = t;
    par[make_pair(s1["Ps"],s1["int"])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Ps"],s1[")"])] = t;

    t.clear();
    t.push_back(s1[","]);
    t.push_back(s1["Pm"]);
    t.push_back(s1["Mp"]);
    par[make_pair(s1["Mp"],s1[","])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Mp"],s1[")"])] = t;

    t.clear();
    t.push_back(s1["V"]);
    t.push_back(s1["id"]);
    par[make_pair(s1["Pm"],s1["float"])] = t;
    par[make_pair(s1["Pm"],s1["int"])] = t;

    t.clear();
    t.push_back(s1["S"]);
    t.push_back(s1["Sms"]);
    par[make_pair(s1["Sms"],s1["cin"])] = t;
    par[make_pair(s1["Sms"],s1["cout"])] = t;
    par[make_pair(s1["Sms"],s1["float"])] = t;
    par[make_pair(s1["Sms"],s1["for"])] = t;
    par[make_pair(s1["Sms"],s1["id"])] = t;
    par[make_pair(s1["Sms"],s1["if"])] = t;
    par[make_pair(s1["Sms"],s1["int"])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Sms"],s1["}"])] = t;

    t.clear();
    t.push_back(s1["Cs"]);
    par[make_pair(s1["S"],s1["if"])] = t;

    t.clear();
    t.push_back(s1["Ls"]);
    par[make_pair(s1["S"],s1["for"])] = t;

    t.clear();
    t.push_back(s1["Ds"]);
    par[make_pair(s1["S"],s1["float"])] = t;
    par[make_pair(s1["S"],s1["int"])] = t;

    t.clear();
    t.push_back(s1["id"]);
    t.push_back(s1["S'"]);
    par[make_pair(s1["S"],s1["id"])] = t;

    t.clear();
    t.push_back(s1["Prs"]);
    par[make_pair(s1["S"],s1["cout"])] = t;

    t.clear();
    t.push_back(s1["Ins"]);
    par[make_pair(s1["S"],s1["cin"])] = t;

    t.clear();
    t.push_back(s1["As"]);
    par[make_pair(s1["S'"],s1[":="])] = t;

    t.clear();
    t.push_back(s1["Fc"]);
    par[make_pair(s1["S'"],s1["("])] = t;

    t.clear();
    t.push_back(s1["T"]);
    t.push_back(s1["E'"]);
    par[make_pair(s1["E"],s1["floatnum"])] = t;
    par[make_pair(s1["E"],s1["intnum"])] = t;
    par[make_pair(s1["E"],s1["id"])] = t;


    t.clear();           // check E' and Ae
    t.push_back(s1["Ae"]);
    par[make_pair(s1["E'"],s1["-"])] = t;
    par[make_pair(s1["E'"],s1["*"])] = t;
    par[make_pair(s1["E'"],s1["/"])] = t;
    par[make_pair(s1["E'"],s1["+"])] = t;

    t.clear();
    t.push_back(s1["Re"]);
    par[make_pair(s1["E'"],s1["&&"])] = t;
    par[make_pair(s1["E'"],s1["||"])] = t;
    par[make_pair(s1["E'"],s1["<"])] = t;
    par[make_pair(s1["E'"],s1["=="])] = t;
    par[make_pair(s1["E'"],s1[">"])] = t;
    

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["E'"],s1[")"])] = t;
    par[make_pair(s1["E'"],s1[";"])] = t;
    

    t.clear();
    t.push_back(s1["id"]);
    par[make_pair(s1["T"],s1["id"])] = t;

    t.clear();
    t.push_back(s1["intnum"]);
    par[make_pair(s1["T"],s1["intnum"])] = t;

    t.clear();
    t.push_back(s1["floatnum"]);
    par[make_pair(s1["T"],s1["floatnum"])] = t;

    t.clear();
    t.push_back(s1["Fac''"]);
    t.push_back(s1["Ae'"]);
    par[make_pair(s1["Ae"],s1["-"])] = t;
    par[make_pair(s1["Ae"],s1["*"])] = t;
    par[make_pair(s1["Ae"],s1["/"])] = t;
    par[make_pair(s1["Ae"],s1["+"])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Ae"],s1[")"])] = t;
    par[make_pair(s1["Ae"],s1[","])] = t;
    par[make_pair(s1["Ae"],s1[";"])] = t;

    t.clear();
    t.push_back(s1["&&"]);
    t.push_back(s1["E"]);
    par[make_pair(s1["Re"],s1["&&"])] = t;

    t.clear();
    t.push_back(s1["||"]);
    t.push_back(s1["E"]);
    par[make_pair(s1["Re"],s1["||"])] = t;

    t.clear();
    t.push_back(s1["<"]);
    t.push_back(s1["E"]);
    par[make_pair(s1["Re"],s1["<"])] = t;

    t.clear();
    t.push_back(s1[">"]);
    t.push_back(s1["E"]);
    par[make_pair(s1["Re"],s1[">"])] = t;

    t.clear();
    t.push_back(s1["=="]);
    t.push_back(s1["E"]);
    par[make_pair(s1["Re"],s1["=="])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Re"],s1[")"])] = t;
    par[make_pair(s1["Re"],s1[";"])] = t;

    t.clear();
    t.push_back(s1["V"]);
    t.push_back(s1["Vl"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["Ds"],s1["float"])] = t;
    par[make_pair(s1["Ds"],s1["int"])] = t;


    t.clear();
    t.push_back(s1["int"]);
    par[make_pair(s1["V"],s1["int"])] = t;

    t.clear();
    t.push_back(s1["float"]);
    par[make_pair(s1["V"],s1["float"])] = t;

    t.clear();
    t.push_back(s1["id"]);
    t.push_back(s1["Vn"]);
    t.push_back(s1["Vl'"]);
    par[make_pair(s1["Vl"],s1["id"])] = t;

    t.clear();
    t.push_back(s1[":="]);
    t.push_back(s1["T"]);
    t.push_back(s1["Ae"]);
    par[make_pair(s1["Vn"],s1[":="])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Vn"],s1[","])] = t;
    par[make_pair(s1["Vn"],s1[";"])] = t;
    
    t.clear();
    t.push_back(s1[":="]);
    t.push_back(s1["T"]);
    t.push_back(s1["Ae"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["As"],s1[":="])] = t;

    t.clear();
    t.push_back(s1["for"]);
    t.push_back(s1["("]);
    t.push_back(s1["Ds"]);
    t.push_back(s1["T"]);
    t.push_back(s1["Re"]);
    t.push_back(s1[";"]);
    t.push_back(s1["id"]);
    t.push_back(s1["As"]);
    t.push_back(s1[")"]);
    t.push_back(s1["{"]);
    t.push_back(s1["Sms"]);
    t.push_back(s1["}"]);
    par[make_pair(s1["Ls"],s1["for"])] = t;

    t.clear();
    t.push_back(s1["if"]);
    t.push_back(s1["("]);
    t.push_back(s1["T"]);
    t.push_back(s1["Re"]);
    t.push_back(s1[")"]);
    t.push_back(s1["{"]);
    t.push_back(s1["Sms"]);
    t.push_back(s1["}"]);
    par[make_pair(s1["Cs"],s1["if"])] = t;

    t.clear();
    t.push_back(s1["("]);
    t.push_back(s1["Ps"]);
    t.push_back(s1[")"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["Fc"],s1["("])] = t;

    t.clear();
    t.push_back(s1["cout"]);
    t.push_back(s1["("]);
    t.push_back(s1["C"]);
    t.push_back(s1[")"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["Prs"],s1["cout"])] = t;
    
    t.clear();
    t.push_back(s1["printstring"]);
    par[make_pair(s1["C"],s1["printstring"])] = t;

    t.clear();
    t.push_back(s1["id"]);
    par[make_pair(s1["C"],s1["id"])] = t;

    t.clear();
    t.push_back(s1["cin"]);
    t.push_back(s1["("]);
    t.push_back(s1["id"]);
    t.push_back(s1[")"]);
    t.push_back(s1[";"]);
    par[make_pair(s1["Ins"],s1["cin"])] = t;

    t.clear();
    t.push_back(s1["+"]);
    t.push_back(s1["T"]);
    t.push_back(s1["Fac''"]);
    t.push_back(s1["Ae'"]);
    par[make_pair(s1["Ae'"],s1["+"])] = t;

    t.clear();
    t.push_back(s1["-"]);
    t.push_back(s1["T"]);
    t.push_back(s1["Fac''"]);
    t.push_back(s1["Ae'"]);
    par[make_pair(s1["Ae'"],s1["-"])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Ae'"],s1[";"])] = t;
    par[make_pair(s1["Ae'"],s1[")"])] = t;

    t.clear();
    t.push_back(s1["*"]);
    t.push_back(s1["T"]);
    t.push_back(s1["Fac''"]);
    par[make_pair(s1["Fac''"],s1["*"])] = t;

    t.clear();
    t.push_back(s1["/"]);
    t.push_back(s1["T"]);
    t.push_back(s1["Fac''"]);
    par[make_pair(s1["Fac''"],s1["/"])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Fac''"],s1["-"])] = t;
    par[make_pair(s1["Fac''"],s1[")"])] = t;
    par[make_pair(s1["Fac''"],s1[","])] = t;
    par[make_pair(s1["Fac''"],s1[";"])] = t;
    par[make_pair(s1["Fac''"],s1["+"])] = t;

    t.clear();
    t.push_back(s1[","]);
    t.push_back(s1["id"]);
    t.push_back(s1["Vn"]);
    t.push_back(s1["Vl'"]);
    par[make_pair(s1["Vl'"],s1[","])] = t;

    t.clear();
    t.push_back(s1["eps"]);
    par[make_pair(s1["Vl'"],s1[";"])] = t;


    t.clear();
    t.push_back(101);               // synch state
    par[make_pair(25,31)] = t;
    par[make_pair(14,32)] = t;
    par[make_pair(16,32)] = t;
    par[make_pair(25,33)] = t;
    par[make_pair(2,35)] = t;
    par[make_pair(3,35)] = t;
    par[make_pair(6,35)] = t;
    par[make_pair(17,35)] = t;
    par[make_pair(25,35)] = t;
    par[make_pair(25,36)] = t;
    par[make_pair(17,37)] = t;
    par[make_pair(25,37)] = t;
    par[make_pair(25,38)] = t;
    par[make_pair(6,40)] = t;
    par[make_pair(25,40)] = t;
    par[make_pair(27,40)] = t;
    par[make_pair(25,42)] = t;
    par[make_pair(2,43)] = t;
    par[make_pair(4,43)] = t;
    par[make_pair(5,43)] = t;
    par[make_pair(12,43)] = t;
    par[make_pair(13,43)] = t;
    par[make_pair(18,43)] = t;
    par[make_pair(22,43)] = t;
    par[make_pair(23,43)] = t;
    par[make_pair(25,44)] = t;
    par[make_pair(25,45)] = t;
    par[make_pair(25,46)] = t;
    par[make_pair(25,47)] = t;
    par[make_pair(2,48)] = t;
    par[make_pair(4,48)] = t;
    par[make_pair(5,48)] = t;
    par[make_pair(10,48)] = t;
    par[make_pair(13,48)] = t;
    par[make_pair(18,48)] = t;
    par[make_pair(23,48)] = t;
    par[make_pair(2,49)] = t;
    par[make_pair(4,49)] = t;
    par[make_pair(5,49)] = t;
    par[make_pair(10,49)] = t;
    par[make_pair(12,49)] = t;
    par[make_pair(13,49)] = t;
    par[make_pair(23,49)] = t;
    par[make_pair(2,50)] = t;
    par[make_pair(4,50)] = t;
    par[make_pair(10,50)] = t;
    par[make_pair(12,50)] = t;
    par[make_pair(13,50)] = t;
    par[make_pair(18,50)] = t;
    par[make_pair(5,51)] = t;
    par[make_pair(2,52)] = t;
    par[make_pair(4,52)] = t;
    par[make_pair(5,52)] = t;
    par[make_pair(10,52)] = t;
    par[make_pair(12,52)] = t;
    par[make_pair(18,52)] = t;
    par[make_pair(23,52)] = t;
    par[make_pair(2,53)] = t;
    par[make_pair(4,53)] = t;
    par[make_pair(5,53)] = t;
    par[make_pair(10,53)] = t;
    par[make_pair(12,53)] = t;
    par[make_pair(13,53)] = t;
    par[make_pair(18,53)] = t;
    par[make_pair(20,53)] = t;
    par[make_pair(23,53)] = t;
    par[make_pair(26,53)] = t;
    par[make_pair(2,54)] = t;
    par[make_pair(5,54)] = t;
    par[make_pair(10,54)] = t;
    par[make_pair(12,54)] = t;
    par[make_pair(13,54)] = t;
    par[make_pair(18,54)] = t;
    par[make_pair(23,54)] = t;
    par[make_pair(2,55)] = t;
    par[make_pair(4,55)] = t;
    par[make_pair(10,55)] = t;
    par[make_pair(12,55)] = t;
    par[make_pair(13,55)] = t;
    par[make_pair(18,55)] = t;
    par[make_pair(23,55)] = t;
    par[make_pair(5,56)] = t;
    par[make_pair(8,57)] = t;


    t.clear();
    t.push_back(100);                 // skip state
    for(int i = 0; i <= 29; i++)      // for all NTs
    {
        for(int j = 30; j <= 59; j++) // for all terminals
        {
            if(par.find(make_pair(i,j)) == par.end()) // if NT, T pair does not exist
            {
                par[make_pair(i,j)] = t;              // make pair with skip state
            }
        }
    }


    stack<int> stk;              // stack for parsing
    stk.push(32);
    stk.push(16);

    vector<int> input;          // vector to store input lexemes
    vector<int> linenum;        // vector to store line numbers 

    fstream newfile;                          // opening input file
    newfile.open("text.txt",ios::in);
    string tp;
    while(getline(newfile, tp))
    {
    	string tm = "";
    	tm += tp[6];
    	if(tp[7] != ',')
    	{	tm += tp[7];
    		if(tp[8] != ',')
    			tm += tp[8];
    	}	
      string num,temp;
      stringstream ss(tp);
      while(ss>>temp){
        num=temp;
      }
      linenum.push_back(stoi(num));
    	input.push_back(w[tm]);
    }
    input.push_back(32);             // inserting $ at the end of the input
    linenum.push_back(9999);

    vector<int> matched;

    while(input.size() > 0)                             // parsing the input
    {
       if((stk.size() == 1) && (input.size() > 1))
        {

          output<<endl<<"\nInput :\n";
          for(int i = 0; i < input.size(); i++)        // print the remaining part of input left
          {
              output<<s[input[i]]<<" ";
          }

          stack<int> forPrint(stk);                   // print the current content of the stack
            output<<endl<<"Stack :\n";
          while (!forPrint.empty()) 
          {  output<<s[forPrint.top()]<<" ";
              forPrint.pop();
          }

          output<<endl<<"Matched :\n";

          for(int i = 0; i < matched.size(); i++)     // print the terms that hve been matched till then 
          {
              output<<s[matched[i]]<<" ";
          }

          output<<"\nError in Line Number : "<<*linenum.begin()<<", Recovery not possible";  // Error message
          break;	
        }

       output<<endl<<"\nInput :\n";                // print the remaining part of input left
       for(int i = 0; i < input.size(); i++)
       {
       		output<<s[input[i]]<<" ";
       }

       stack<int> forPrint(stk);
        output<<endl<<"Stack :\n";
       while (!forPrint.empty())                 // print the current content of the stack
       {  output<<s[forPrint.top()]<<" ";
      	  forPrint.pop();
       }

       output<<endl<<"Matched :\n";               // print the terms that hve been matched till then 

       for(int i = 0; i < matched.size(); i++)
       {
       		output<<s[matched[i]]<<" ";
       }

       if(input[0] == stk.top())                 // if input and stack top match, remove the terminal from both
	     {
       	 matched.push_back(input[0]);
       	 input.erase(input.begin());
          linenum.erase(linenum.begin());
       	 stk.pop();
       }

       else if(par.find(make_pair(stk.top(),input[0])) == par.end())                                 // Error if top of stack does not match with the first of input and both are terminals
       {
       		output<<"\nError in Line Number : "<<*linenum.begin()<<"Pop Terminal : "<<s[stk.top()];
          stk.pop();
       }

       else if(par[make_pair(stk.top(),input[0])][0] == 100)                                        // skip the input lexeme for skip state
       {
         output<<endl<<"Error in Line Number : "<<*linenum.begin()<<" Skip Lexeme : "<<s[*input.begin()]<<endl;
          input.erase(input.begin());
          linenum.erase(linenum.begin());
       }

       else if(par[make_pair(stk.top(),input[0])][0] == 101)                                       // pop the top of stack for synch state 
       {
         output<<endl<<"Error in Line Number : "<<*linenum.begin()<<" Pop Non-Terminal : "<<s[stk.top()]<<endl;
         stk.pop();
       }

       else                                            // replace top of stack with its correspondng RHS of production
       {
       	 int nt = stk.top();
       	 stk.pop();
       	 int t = input[0];
       	 vector<int> tmp = par[make_pair(nt,t)];
       	 reverse(tmp.begin(), tmp.end());
       	 if(tmp[0] == 30)
       	 	continue;
       	 for(int i = 0; i < tmp.size(); i++)
       	 	stk.push(tmp[i]);	
       }
       
	   

   }

    output<<endl;   
       	
}