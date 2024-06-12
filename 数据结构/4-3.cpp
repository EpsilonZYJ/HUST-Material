void get_nextval(HString T, int *nextval){
    int i = 0;
    nextval[0] = -1;
    int j = -1;
    while(i < T.length - 1){
        if(j == -1 || T.ch[i] == T.ch[j]){
            ++i; ++j;
            if(T.ch[i] != T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }
}

int KMP(HString S, HString T, int pos, int *nextval){
    int i = pos;
    int j = 0;
    while(i < S.length && j < T.length)
    {
        if(j == -1 || S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }
        else
            j = nextval[j];
    }
    if(j > T.length - 1)
        return i - T.length;
    else
        return -1;
}

void Replace(HString &S,HString T,HString V){
    int *nextval = (int *) malloc(sizeof(int) * T.length);
    get_nextval(T, nextval);
    int pos = KMP(S, T, 0, nextval);
    int i_s = 0;
    int i_ans = 0;
    int listsize = S.length;
    HString ans;
    ans.ch = (char*) malloc(sizeof(char) * listsize);
    while(pos >= 0){
        for(i_s; i_s < pos; i_s ++, i_ans++){
            ans.ch[i_ans] = S.ch[i_s];
        }
        while(i_ans + V.length > listsize){
            ans.ch = (char*) realloc(ans.ch, sizeof(char) * (listsize + S.length));
            listsize += S.length;
        }
        for(int j = 0; j < V.length;i_ans ++, j ++){
            ans.ch[i_ans] = V.ch[j];
        }
        i_s += T.length;
        pos = KMP(S, T, i_s, nextval);
    }
    while(i_s < S.length){
        if(i_ans < listsize){
            ans.ch = (char*) realloc(ans.ch, sizeof(char) * (listsize + S.length));
            listsize += S.length;
        }
        ans.ch[i_ans] = S.ch[i_s];
        i_s ++;
        i_ans ++;
    }
    free(S.ch);
    S.ch = (char*) malloc(sizeof(char) * i_ans);
    for(int j = 0; j < i_ans; j ++){
        S.ch[j] = ans.ch[j];
    }
    S.length = i_ans;
}