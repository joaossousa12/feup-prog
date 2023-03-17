#include "fraction.h"

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

fraction reduce(fraction a){
    fraction res = {a.num / gcd(a.num, a.den), a.den / gcd(a.num, a.den)};
    if(res.den < 0){
        res.num = -res.num;
        res.den = -res.den;
    }
    return res;
}

fraction add(fraction a, fraction b){
    return reduce({a.num * b.den + b.num * a.den, a.den * b.den});
}

fraction mul(fraction a, fraction b){
    return reduce({a.num * b.num, a.den * b.den});
}

int main(){
    { fraction a { 0, 1 }, b { 2, 1};
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    //2 0
    { fraction a { 1, 1 }, b { -1, 2};
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    //1/2 -1/2
    { fraction a { -3, 2 }, b { 3, 2 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    //0 -9/4
    { fraction a { -3, 2 }, b { -2, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    //-13/6 1
    { fraction a { -7, 24 }, b { 1, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    //1/24 -7/72
    { fraction a { -8, 25 }, b { 3, 4 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    //43/100 -6/25
    cout << add({7,4536}, mul({-5,21}, add({1,2}, mul({-2,3}, {1,9})))) << '\n';
    //-151/1512
    return 0;
}