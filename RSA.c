#include <stdio.h>
#include <math.h>

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod){
    unsigned long long result = 1;
    base = base % mod;// gets the value of power

    while(exp > 0){
        if(exp%2 == 1)
            result = (base*result)%mod;
        exp = exp/2;
        base = (base*base) % mod;
    }

    return result;
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

unsigned long long modInv(unsigned long long e, unsigned long long phi){
    long long t = 0, newt = 1;
    long long r = phi, newr = e;
    long long quotient, temp;

    while (newr!=0){
        quotient = r/newr;
        temp = t; t = newt; newt = temp - quotient*newt;
        temp = r; r = newr; newr = temp - quotient*newr;
    }

    if (r>1) return 0;
    if (t<0) t = t+phi;

    return t;
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
    unsigned long long p = 43, q = 59;
    unsigned long long n = p * q; //== 2537
    unsigned long long e = 13;
    // Compute φ(n) = (p-1) * (q-1)
    unsigned long long phi_n = (p - 1) * (q - 1); //2437
    unsigned long long d = modInv(e, phi_n);

    unsigned long long message[3] = {19,1900,210};
    int length = 3;
    unsigned long long encrypted[3] = {2299, 1317,2117};

    encryptMes(message, length, e,n);
    printf("\n");
    decryptMes(encrypted, length, d,n);
}

