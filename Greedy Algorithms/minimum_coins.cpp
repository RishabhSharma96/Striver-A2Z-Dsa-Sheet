vector<int> MinimumCoins(int n)
{
    vector<int> coins;
    int balance = n ;

    if(balance>=1000){
        int frequency = balance/1000 ;
        while(frequency--){
            coins.push_back(1000);
        }
        balance = balance%1000;
    }
    if(balance>=500){
        int frequency = balance/500 ;
        while(frequency--){
            coins.push_back(500);
        }
        balance = balance%500;
    }
    if(balance>=100){
        int frequency = balance/100 ;
        while(frequency--){
            coins.push_back(100);
        }
        balance = balance%100;
    }
    if(balance>=50){
        int frequency = balance/50 ;
        while(frequency--){
            coins.push_back(50);
        }
        balance = balance%50;
    }
    if(balance>=20){
        int frequency = balance/20 ;
        while(frequency--){
            coins.push_back(20);
        }
        balance = balance%20;
    }
    if(balance>=10){
        int frequency = balance/10 ;
        while(frequency--){
            coins.push_back(10);
        }
        balance = balance%10;
    }
    if(balance>=5){
        int frequency = balance/5 ;
        while(frequency--){
            coins.push_back(5);
        }
        balance = balance%5;
    }
    if(balance>=2){
        int frequency = balance/2 ;
        while(frequency--){
            coins.push_back(2);
        }
        balance = balance%2;
    }
    
    int frequency = balance;
        while(frequency--){
            coins.push_back(1);
        }

    return coins ;

}