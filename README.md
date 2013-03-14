cpp-plus-longue-sous-chaine-commune
===================================

une simple algo qui cherche la plus longue sous chaine commune

La fonction est un template::

    template<class T>
    vector<T> plus_longues_sous_chaines(const T& str1,const T& str2);

Avec T qui doit avoir les fonction suivante::

    T.size() renvoie sa taille
    T.begin() et T.end()
    un constructeur T(T::iterator,T::iterator)
    et les operateurs:
        B T.operator [](int)
        bool B.operator == (B& other)

Fonctionne nativement avec les strings par exemple
