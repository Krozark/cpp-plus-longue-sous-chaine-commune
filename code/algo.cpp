#include <iostream>
#include <vector>

using namespace std;

vector<string> plus_longues_sous_chaines(const string str1,const string str2)
{
    unsigned int size_str1 = str1.size();
    unsigned int size_str2 = str2.size();
    unsigned int size_max_find = 0;


    vector<string> solutions; //juste la fleme de le faire en c

    for(int i1=0;i1<size_str1;++i1) //loop sur la 1er chaine
    {
        for(int i2=0;i2<size_str2;++i2) //loop sur la 2eme chaine
        {
            if(str1[i1] == str2[i2])//caractère commun
            {
                //increment sur les sous chaines
                int inc1 = i1+1;//pour éviter de recalculer a chaque fois dans les condition du while
                int inc2 = i2+1;//idem
                while ((str1[inc1] == str2[inc2]) && (inc1 < size_str1) && (inc2 < size_str2))
                {
                    ++inc1;
                    ++inc2;
                }
                //on a maintenant la case de fin
                int size_find = inc1-i1;
                if (size_find > size_max_find) //plus grand que ce que trouvé acctuelement, on delet les autres
                {
                    solutions.clear();//on vide tout
                    size_max_find = size_find;
                    solutions.emplace_back(str1.begin()+i1,str1.begin()+inc1+i1);// str[i1] ... str1[inc1-1] exclu
                }
                else if (size_find == size_max_find) // on ajoute
                {
                    solutions.emplace_back(str1.begin()+i1,str1.begin()+inc1+i1);// str[i1] ... str1[inc1-1] exclu
                }
            }
        }
    }
    return solutions;
}

int main(int argc,char* argv[])
{
    vector<string> res = plus_longues_sous_chaines("testestest","geshestatestesta");
    for(auto s:res)
        cout<<s<<endl;
    return 0;
}
