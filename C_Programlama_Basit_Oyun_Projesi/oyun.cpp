#include <stdio.h>                                  //1.level	 3  digit  /         1'section    5s                 2'section   3s            3'section  2s
#include <time.h>                       			//2.level	 6  digit  /         1'section    7s       	         2'section   5s            3'section  3s
#include <stdlib.h>									//3.level 	10  digit  /         1'section    12s                2'section   8s            3'section  4s
#include <windows.h>
#include <conio.h>

int main() {
	
	int interval;                   // digit zorlu�unu ayarl�yor
	int level;                      // digitlerin i�erisindeki levelleri degistiriyor
	unsigned long long number;      // program�n sordugu sorular
	int entry;                      // girdigimiz deger    number ile kontrol icin kullan�l�yor
    int key;                        //programda yazmaya baslamadan �nce bir tusa basmam�z� istiyor haz�r oldugumuzda basmam�z icin.  
    int TIMEOUT;                    // kronometre zamani    ayarlayabiliyoruz
    time_t mark;                    // millisteki son zamana esitliyoruz belli bir zamana ayarlan�yor
    time_t now;                     // if yap�s� icerisinde s�rekli kalan zaman� ayarlad�g�m�z zaman degiskenine g�re kontrol etmek icin kullan�l�yor
	
	game:                                                                                    // oyunu bitirdigimizde bizi en basa at�yor
	printf("   Welcome the Random Number Writing Challenge\n\n");
	printf("You must write the given numbers as quickly as possible.\n");
	levell:                                                                                 // levellerin sonunda yanl�s yazd�g�m�zda bizi aral�k secmeye yolluyor
	printf("\nWhat is your interval ?? (1)[3 DIGIT] (2)[6 DIGIT] (3)[9 DIGIT]\n\n");
	scanf("\t\t\t%d",&interval);
	                                                                                    
	
	switch(interval){  
	                                    
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////1.zorluk	 
	
	case 1:
	
	printf("\n");	
	printf("What is your level 1-3 (basic-hard)\n");
	scanf("%d",&level);
	
	
	switch(level){
		
	case 1:                                                  //1/1

	printf("\nYou have 5 seconds. If you are ready Press any button\n");
	getch();                    //haz�r oldugumuzda tusa basmam�z� bekliyor 
			
	TIMEOUT=5;                  //her levelde sab�t olarak ayarlanm�s kronometre degeri       
	mark = time(NULL);          // sistemin baslang�c zaman�n� isaretliyor kronometre degeri icin
    srand(mark);                // random kumeleri icerisinden zamanda g�re esitledigimiz mark degerine g�re esitleniyor.
    number = rand();            // rakam� random fonksiyonu �zerinden seciyor
    
    numberr1:                                      // her bolumde bu kod var eger rakam buyuk yada kucukse bu k�s�ma tekrar yollay�p baska rakam seciyor
	srand(time(NULL));	                           // random k�melerini simdiki zamana g�re seciyor b�ylelikle her zaman farkl� k�me secmis oluyor.
	number= ((unsigned long long)(rand()%1000));
		if(number>1000){
		goto numberr1;                             //rakam buyukse tekrardan basl�yor
	}	
	
		if(number<100){
			number=number*11;
		}
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {                          //arduino millis fonksiyonu gibi cal�s�yor 
        while (!_kbhit()) {
            now = time(NULL);                           //son zaman� simdiki zamana esitliyor
            if (now - mark > TIMEOUT) {                 //kronometre zmaan�n�  kontrol ediyor
                printf("\nTimeout failure!\n"); 
                goto levell;                            //eger zaman bittiyse basa at�yor
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';                    
    }

    if (entry == number){                                //girilen deger numara ile esitse tebrik ediyor ve level k�sm�na at�yor
    
        printf("\nNice! You're good\n");
        goto levell;
    }
    else{
	 
        printf("\nIncorrect code\n");                     // yanl�s kod ise bu sefer yine basa at�yor ve tekrar bolum sectiriyor
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 1/2
	case 2:

	printf("\nYou have 3 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=3;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr2:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()%1000));
		if(number>1000){
		goto numberr2;
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're succesful\n");
        goto levell;
    }
    else{
	    printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 1/3
 
	case 3:

	printf("\nYou have 2 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=2;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr3:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()%1000));
		if(number>1000){
		goto numberr3;
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto game;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're very succesful\n\n\n");
        goto game;
    }
    else{
		printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////2.zorluk	
	
	case 2:                                                  
	
	printf("\n");	
	printf("What is your level 1-3 (basic-hard)\n");
	scanf("%d",&level);
	
	
	switch(level){
		
	case 1:                                                  //2/1

	printf("\nYou have 7 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=7;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr4:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()*158));
		if(number>1000000){
			
			number=number/10;
			if(number>1000000){	
		goto numberr4;
	}
	}
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're good\n");
        goto levell;
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 2/2
	case 2:

	printf("\nYou have 5 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=5;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr5:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()*158));
		if(number>1000000){
			
			number=number/10;
			if(number>1000000){	
		goto numberr5;
	}
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're succesful\n");
        goto levell;
    }
    else{
		printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 2/3
 
	case 3:

	printf("\nYou have 3 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=3;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr6:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()*158));
		if(number>1000000){
			
			number=number/10;
			if(number>1000000){	
		goto numberr6;
	}
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're very succesful\n\n\n");
        goto game;
    }
    else{
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////3.zorluk
	
	case 3:                                                  
	
	printf("\n");	
	printf("What is your level 1-3 (basic-hard)\n");
	scanf("%d",&level);
	
	
	switch(level){
		
	case 1:                                                  //3/1
 
	printf("\nYou have 12 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=12;
	mark = time(NULL);
    srand(mark);
    number = rand();
    number=number*237;
    
    numberr7:
	srand(time(NULL));	
	number= ((unsigned long long)rand()%10000000);
		if(number<10000000){
		number=number*11;
		if(number<100000000){
		number=number*13;
		}
		if(number<1000000000){
		number=number*12;
		}
		}
		if(number>10000000000){
		number=number/10;
		if(number>10000000000){
		number=number/10;	
		goto numberr7;
	}
	}
	number=number*10;
    printf("The code is %d\n",number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
        }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're good\n");
        goto levell;
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 3/2
	case 2:

	printf("\nYou have 8 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=8;
	mark = time(NULL);
    srand(mark);
    number = rand();
    number=number*237;
    
    numberr8:
	srand(time(NULL));	
	number= ((unsigned long long)rand()%10000000);
		if(number<10000000){
		number=number*11;
		if(number<100000000){
		number=number*13;
		}
		if(number<1000000000){
		number=number*12;
		}
		}
		if(number>10000000000){
		number=number/10;
		if(number>10000000000){
		number=number/10;	
		goto numberr8;
	}
	}
	number=number*10;	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're succesful\n");
        goto levell;
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 3/3
 
	case 3:

	printf("\nYou have 4 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=4;
	mark = time(NULL);
    srand(mark);
    number = rand();
    number=number*237;
    
    numberr9:
	srand(time(NULL));	
	number= ((unsigned long long)rand()%10000000);
		if(number<10000000){
		number=number*13;
		if(number<100000000){
		number=number*13;
		}
		if(number<1000000000){
		number=number*12;
		}
		}
		if(number>10000000000){
		number=number/10;
		if(number>100000000000){
		number=number/10;	
		goto numberr9;
	}
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nPerfect !! You're Best player in this game\n\n\n");
        goto game;
        
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	break;
}
}
	return 0;
}

