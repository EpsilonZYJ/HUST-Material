/***在下面Begin至End间，按原型 void diceGame(int randSeed) 定义函数***/
/********** Begin **********/
void diceGame(int randSeed)
{
    int a, b;
    int round = 0;
    int x,y;
    int add;
    int i;
    srand(randSeed);

    a = rand()%6 + 1;
    b = rand()%6 + 1;
    if( a + b == 7 || a + b == 11){
        printf("Round 1:  Score:%d  Success!\n",a + b);
    }
    else if(a + b == 2||a + b == 3||a + b == 12){
        printf("Round 1:  Score:%d  Failed!",a+b);
    }
    else{
        printf("Round 1:  Score:%d  Continue!\n",a+b);
        printf("Next rounds: Score %d:Success, Score 7:Failed, others:Continue\n",a + b);
        for(i = 2;;i++){
            x = rand()%6 + 1;
            y = rand()%6 + 1;
            add = x + y;
            if( add == a + b){
                printf("Round %d:  Score:%d  Success!",i,add);
                break;
            }
            else if( add == 7 ){
                printf("Round %d:  Score:7  Failed!",i);
                break;
            }
            else
            {
                printf("Round %d:  Score:%d  Continue!\n",i,add);
            }
        }
    }
}


/********** End **********/