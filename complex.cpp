#include <iostream>
#include <complex>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{

complex<float>  matrix1 [100][100]; string s1; getline(cin,s1); int row1 =1; int col1 =1; int columns1; int x1 =0;
 int y1 =0 ; float v1 =0; int count1 = 0;complex <float> result[100][100];
for(int i=0;i < s1.length();i++)
{
 if (s1[i]==';')
   {
    x1 = 0;
    y1 += 1;
    row1 += 1;
   }
  if(s1[i]==' ' || s1[i]=='[' || s1[i]==';')
   {
    string str  = s1.substr(i+1);
    float rel1 = atof(str.c_str());
    matrix1[x1][y1].real(rel1);
    count1++;
   }
    if(s1[i]=='-' && s1[i-1]!=' ' && s1[i-1]!=';' && s1[i-1]!='[')
    {
         string str  = s1.substr(i);
    float imj1 = atof(str.c_str());
    matrix1[x1][y1].imag(imj1);
    x1 += 1 ;
    }
    if(s1[i]=='+')

    {
         string str  = s1.substr(i);
    float imj1 = atof(str.c_str());
    matrix1[x1][y1].imag(imj1);
    x1 += 1 ;

   }
}

for(int i=0;i < s1.length();i++)
{
    if(s1[i]==';')
        break;
   else if(s1[i]==' ')
        col1 += 1;
}
if(count1%row1!=0)
{
    cout<<"ERROR";
    exit(1);
}
for(int i=0;i<row1;i++)
{
    for(int j=0;j<col1;j++)
    {
        cout<<matrix1[j][i]<<" ";
    }
    cout<<endl;
}
cout<<endl;
string oper;
getline(cin,oper);


complex<float>  matrix2 [100][100]; string s2; getline(cin,s2); int row2 =1; int col2 =1; int columns2; int x2 =0;
 int y2 =0 ; float v2 =0; int count2 = 0;
for(int i=0;i < s2.length();i++)
{
 if (s2[i]==';')
   {
    x2 = 0;
    y2 += 1;
    row2 += 1;
   }
  if(s2[i]==' ' || s2[i]=='[' || s2[i]==';')
   {
    string str  = s2.substr(i+1);
    float rel2 = atof(str.c_str());
    matrix2[x2][y2].real(rel2);
    count2++;
   }
    if(s2[i]=='-' && s2[i-1]!=' ' && s2[i-1]!=';' && s2[i-1]!='[')
    {
         string str  = s2.substr(i);
    float imj2 = atof(str.c_str());
    matrix2[x2][y2].imag(imj2);
    x2 += 1 ;
    }
    if(s1[i]=='+')

    {
          string str  = s2.substr(i);
    float imj2 = atof(str.c_str());
    matrix2[x2][y2].imag(imj2);
    x2 += 1 ;

   }
   }


for(int i=0;i < s2.length();i++)
{
    if(s2[i]==';')
        break;
   else if(s2[i]==' ')
        col2 += 1;
}
if(count2%row2!=0)

{
    cout<<"ERROR";
    exit(1);
}

for(int i=0;i<row2;i++)
{
    for(int j=0;j<col2;j++)
    {
        cout<<matrix2[j][i]<<" ";
    }
    cout<<endl;
}
cout<<endl;
if(oper == "+")
{
    if(col1 != col2 || row1 != row2)
    {
        cout<<"ERROR";
    }
    else
    {
        cout<<"[";
for(int i=0;i <row1;i++)
{
    for(int j=0;j < col1  ;j++)
    {
      result[j][i].real(matrix1[j][i].real() + matrix2[j][i].real());
      result[j][i].imag(matrix1[j][i].imag() + matrix2[j][i].imag());
      float r =  result[j][i].real();
      float s =  result[j][i].imag();
         if(s>=0)
            cout<<r<<"+"<<s<<"i";
         else
            cout<<r<<"-"<<-1*s<<"i";
    // cout<<matrix1[j][i].getReal() + matrix2[j][i].getReal()<<"+";
        if(j+1==col1)
            break;
        cout<<" ";
        }

if (i+1 == row1)
break;
cout<<";";
}
cout<<"]";
    }
}

if(oper == "-")
{
      if(col1 != col2 || row1 != row2)
    {
        cout<<"ERROR";
    }
    else
    {
        cout<<"[";
for(int i=0;i <row1;i++)
{
    for(int j=0;j < col1  ;j++)
    {
      result[j][i].real(matrix1[j][i].real() - matrix2[j][i].real());
      result[j][i].imag(matrix1[j][i].imag() - matrix2[j][i].imag());
      float r =  result[j][i].real();
      float s =  result[j][i].imag();
         if(s>=0)
            cout<<r<<"+"<<s<<"i";
         else
            cout<<r<<"-"<<-1*s<<"i";
        if(j+1==col1)
            break;
        cout<<" ";
        }

if (i+1 == row1)
break;
cout<<";";
}
cout<<"]";
    }
}
if(oper == "*")
{

    if(col1 == row2)
      {
for(int i=0;i<=row2+2;i++)
{
    for(int j=0;j<=col2+2;j++)
    {
     result[i][j].real(0);
     result[i][j].imag(0);

        for(int k=0;k<=col1+2;k++)
        {
            result[i][j] += matrix2[i][k]*matrix1[k][j];
        }
    }
}
cout<<"[";
for(int i=0;i <row1;i++)
{
    for(int j=0;j < col2;j++)
    {
     float r =  result[j][i].real();
      float s =  result[j][i].imag();
         if(s>=0)
            cout<<r<<"+"<<s<<"i";
         else
            cout<<r<<"-"<<-1*s<<"i";
        if(j+1==col2)
            break;
        cout<<" ";
        }
if (i+1 == row1)
break;
cout<<";";
}
cout<<"]";
}
else
    cout<<"ERROR";
}
    return 0;
}

