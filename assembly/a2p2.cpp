#include <iostream>
using namespace std;

int a1[12],
    a2[12],
    a3[12];
char einStr[]    = "Enter integer #";
char moStr[]     = "Max of ";
char ieStr[]     = " ints entered...";
char emiStr[]    = "Enter more ints? (n or N = no, others = yes) ";
char begA1Str[]  = "beginning a1: ";
char am1dA1Str[] = "a1 (dups<=1): ";
char procA1Str[] = "processed a1: ";
char procA2Str[] = "          a2: ";
char procA3Str[] = "          a3: ";
char dacStr[]    = "Do another case? (n or N = no, others = yes) ";
char dlStr[]     = "================================";
char byeStr[]    = "bye...";

int main()
{
               char reply;
               int used1,
                   used2,
                   used3,
                   truncAvg,
                   found,
                   sum,
                   *hopPtr1,
                   *hopPtr11,
                   *hopPtr2,
                   *hopPtr3,
                   *endPtr1,
                   *endPtr11,
                   *endPtr2,
                   *endPtr3;

               reply = 'y';
               while (reply != 'n' && reply != 'N')
               {
                  used1 = 0;
                  hopPtr1 = a1;
                  while (reply != 'n' && reply != 'N')
                  {
                     cout << einStr;
                     cout << (used1 + 1);
                     cout << ':' << ' ';
                     cin >> *hopPtr1;
                     ++used1;
                     ++hopPtr1;
                     if (used1 < 12)
                     {
                        cout << emiStr;
                        cin >> reply;
                     }
                     else
                     {
                        cout << moStr << 12 << ieStr << endl;
                        reply = 'n';
                     }
                  }

                  cout << begA1Str;
                  if (used1 > 0)
                  {
                     hopPtr1 = a1;
                     endPtr1 = a1 + used1;
                     do
                     {
                        cout << *hopPtr1 << ' ' << ' ';
                        ++hopPtr1;
                     }
                     while (hopPtr1 < endPtr1);
                  }
                  cout << endl;

                  if (used1 > 1)
                  {
                     hopPtr1 = a1;
                     endPtr1 = a1 + used1 - 1;
                     while (hopPtr1 < endPtr1)
                     {
                        found = 0;
                        for (hopPtr2 = hopPtr1 + 1, endPtr2 = a1 + used1; hopPtr2 < endPtr2; ++hopPtr2)
                        {
                           if (*hopPtr2 == *hopPtr1)
                           {
                              if (found == 1)
                              {
                                 for (hopPtr3 = hopPtr2 + 1, endPtr3 = a1 + used1; hopPtr3 < endPtr3; ++hopPtr3)
                                 {
                                    *(hopPtr3 - 1) = *hopPtr3;
                                 }
                                 --used1;
                                 --endPtr1;
                                 --endPtr2;
                                 --endPtr3;
                                 --hopPtr2;
                              }
                              else
                              {
                                ++found;
                              }
                           }
                        }
                        ++hopPtr1;
                     }

                     cout << am1dA1Str;
                     if (used1 > 0)
                     {
                        hopPtr1 = a1;
                        endPtr1 = a1 + used1;
                        do
                        {
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
                        }
                        while (hopPtr1 < endPtr1);
                     }
                     cout << endl;

                     if (used1 > 0)
                     {
                        sum = 0;
                        hopPtr1 = a1 + used1 - 1;
                        endPtr1 = a1;
                        do
                        {
                           sum += *hopPtr1;
                           --hopPtr1;
                        }
                        while (hopPtr1 >= endPtr1);
                        truncAvg = sum / used1;

                        used2 = 0;
                        used3 = 0;
                        hopPtr2 = a2;
                        hopPtr3 = a3;
                        for (hopPtr1 = a1, endPtr1 = a1 + used1; hopPtr1 < endPtr1; ++hopPtr1)
                        {
                           if (*hopPtr1 != truncAvg)
                           {
                              if (*hopPtr1 < truncAvg)
                              {
                                 *hopPtr2 = *hopPtr1;
                                 ++used2;
                                 ++hopPtr2;
                              }
                              else
                              {
                                 *hopPtr3 = *hopPtr1;
                                 ++used3;
                                 ++hopPtr3;
                              }
                              for (hopPtr11 = hopPtr1 + 1, endPtr11 = a1 + used1; hopPtr11 < endPtr11; ++hopPtr11)
                              {
                                 *(hopPtr11 - 1) = *hopPtr11;
                              }
                              --used1;
                              --endPtr1;
                              --hopPtr1;
                           }
                        }

                        if (used1 == 0)
                        {
                           *(a1+ 0) = truncAvg;
                           ++used1;
                        }
                     }
                  }
                  else
                  {
                     hopPtr1 = a1;
                     cout << am1dA1Str;
                     cout << *hopPtr1;
                     cout << endl;
                     used2 = 0;
                     used3 = 0;
                  }

                  cout << procA1Str;
                  if (used1 > 0)
                  {
                     hopPtr1 = a1;
                     endPtr1 = a1 + used1;
                     do
                     {
                        cout << *hopPtr1 << ' ' << ' ';
                        ++hopPtr1;
                     }
                     while (hopPtr1 < endPtr1);
                  }
                  cout << endl;

                  cout << procA2Str;
                  if (used2 > 0)
                  {
                     hopPtr2 = a2;
                     endPtr2 = a2 + used2;
                     do
                     {
                        cout << *hopPtr2 << ' ' << ' ';
                        ++hopPtr2;
                     }
                     while (hopPtr2 < endPtr2);
                  }
                  cout << endl;

                  cout << procA3Str;
                  if (used3 > 0)
                  {
                     hopPtr3 = a3;
                     endPtr3 = a3 + used3;
                     do
                     {
                        cout << *hopPtr3 << ' ' << ' ';
                        ++hopPtr3;
                     }
                     while (hopPtr3 < endPtr3);
                  }
                  cout << endl;

                  cout << dacStr;
                  cin >> reply;
               }

               cout << dlStr << '\n';
               cout << byeStr << '\n';
               cout << dlStr << '\n';

               return 0;
}

