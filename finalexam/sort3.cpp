void sort3(int &a,int &b, int &c){
    int tmp;
    if(a>b){
        tmp = a;
        a = b;
        b = tmp;
    }
    if(a>c){
        tmp = a;
        a=c;
        c = tmp;
    }
    if(b>c){
        tmp = b;
        b=c;
        c=tmp;
    }
    return;

}

