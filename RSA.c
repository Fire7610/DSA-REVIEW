#include <stdio.h>
#include <math.h>

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod){
    unsigned long long result = 1;
    base = base%mod;

    while (exp>0){
        if(exp%2 == 1) 
            result = (result *base)%mod;
        exp/=2;
        base = (base*base)%mod;
    }
    return result;
}

unsigned long long modInv(unsigned long long e, unsigned long long phi){
    /*
    long long t = 0, newt = 1; 
    long long r = phi, newr = e;
    long long q, temp;

    while(newr!=0){
        q = r/newr;
        temp = t; t = newt; newt = temp - q*newt;
        temp = r; r = newr; newr = temp - q*newr;
    }

    if(t<0) t = t+phi;
    return t;
    */

    unsigned long long int prod;
    for(long long int i = phi; i > 0; i--)
    {
        prod = e * i;
        if(prod % phi == 1)
            return i;
    }

    return prod;
}

void encryptMes(unsigned long long message[], int length, unsigned long long e, unsigned long long n){
    for (int i = 0; i < length; i++){
        printf("%llu ", modExp(message[i], e, n));
    }
}

void decryptMes(unsigned long long message[], int length, unsigned long long d, unsigned long long n){
    for(int i = 0; i<length; i++ ){
        printf("%llu ", modExp(message[i], d, n));
    }
}
int main(){ 
    // Public Key (n, e)
    unsigned long long p = 43, q = 67;
    unsigned long long n = p * q; //== 2537
    unsigned long long e = 65;
    // Compute φ(n) = (p-1) * (q-1)
    unsigned long long phi_n = (p - 1) * (q - 1); //2437
    unsigned long long d = modInv(e, phi_n);
    printf("%d", d);
    unsigned long long message[3] = {19,1900,210};
    int length = 3;
    unsigned long long encrypted[3] = {2299, 1317,2117};

    //encryptMes(message, length, e,n);
    //printf("\n");
    //decryptMes(encrypted, length, d,n);
}