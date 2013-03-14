#include <iostream>
#include <vector>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template<class T>
vector<T> plus_longues_sous_chaines(const T& str1,const T& str2)
{
    unsigned int size_str1 = str1.size();
    unsigned int size_str2 = str2.size();
    int size_max_find = 0;


    vector<T> solutions; //juste la fleme de le faire en c

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
                    solutions.emplace_back(str1.begin()+i1,str1.begin()+inc1);// str[i1] ... str1[inc1-1] exclu
                }
                else if (size_find == size_max_find) // on ajoute
                {
                    solutions.emplace_back(str1.begin()+i1,str1.begin()+inc1);// str[i1] ... str1[inc1-1] exclu
                }
            }
        }
    }
    return solutions;
}

int rand_a_b(int a, int b){
	return (rand()/float(RAND_MAX))*(b-a)+a;
}

char *randChaine(int minLength, int maxLength)
{
	int i = 0, stop = 0;
	char *chaineRand = new char[maxLength];

	while(i < maxLength && stop == 0)
	{	
		if(i > minLength)
			if(rand_a_b(0, 100) > 95)
				stop = 1;


		chaineRand[i] = rand_a_b(97, 122);;

		++i;
	}

	chaineRand[i] = '\0';

	return chaineRand;
}

int main(int argc,char* argv[])
{
    srand(time(NULL));

    char * c_str1 = randChaine(100,1000);
    char * c_str2 = randChaine(100,1000);
    string str1(c_str1);
    string str2(c_str2);

    free(c_str1);
    free(c_str2);

    cout<<"str1: "<<str1<<endl;
    cout<<"str2: "<<str2<<endl;


    vector<string> res = plus_longues_sous_chaines<string>(str1,str2);
    cout<<"solution"<<endl;
    for(auto s:res)
        cout<<s<<endl;
    return 0;

}
