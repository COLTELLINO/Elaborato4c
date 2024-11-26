#include "prime.h"
#include <limits.h>
#include <math.h>

unsigned short int is_prime(unsigned short int n) {

    unsigned short int i;                   //inizializzo la variabile c
    for (i = 2; i <= n / 2; i++) {          
        if (n % i == 0) {                   //calcolo se il numero è primo
            return 0;
        }
    }
    return 1;
}


unsigned short int nth_prime(unsigned short int n) {
    unsigned short int count = 0;           //inizializzo le variabili              
    unsigned short int a = 2;

    while (1) {
        if (is_prime(a)) {                  //controllo se il numero è primo
            if (count == n) return a;       //mi fermo se sono arrivato al primo n-esimo
            count++;                        //se é primo aggiungo 1 al counter
        }
        if (a >= USHRT_MAX) {               //se sforo il valore massimo output 0
            return 0;
        }
        a++;
    }
}



unsigned short int succ_prime(int reset) {
    static unsigned int p = 2;              //inizializzo la variabile che corrisponde al numero primo a cui sono arrivato

    if (reset || p > USHRT_MAX) {           //la funzione si resetta quando supera il valore massimo
        p = 2;                              //reinizializzo la varabile p a 2
        return 2;
    }

    while (1) {
        if (is_prime(++p)) {                //passo al numero successivo finchè non ne incontro uno primo
            return p;                       //ritorno il numero primo a cui sono arrivato
        }
    }
}



unsigned short int co_prime(unsigned short int m, unsigned short int n) {

    while (n != 0) {                    //ciclo while che termina quando il resto è 0
        unsigned short int c = n;       //variabile per mantenere in memoria il valore di n
        n = m % n;                      //controllo se hanno divisori in comune
        m = c;                          //assegno c ad m
    }
    if (m == 1) return 1;               //se non hanno divisori in comune ritorno 1
    else return 0;                      //sennò
}