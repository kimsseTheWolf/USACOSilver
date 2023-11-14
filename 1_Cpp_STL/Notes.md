```cpp
#include<bits/stdc++.h>
using namespace std;

int d[13] = {3,4,6,6,6,6,8,8,8,10,20,30,50};


// lower_bound(启点,终点,查找值);  在[起点,终点)范围内找「查找值」第1次出现的位置，或者找第1次大于它的位置；
// upper_bound(起点,终点,查找值); 在[起点,终点)范围内找「查找值」找第1次大于它的位置；

int main(void){

    // sort(d,d+13);

    // int num = (upper_bound(d,d+13,8)-d) - (lower_bound(d,d+13,6)-d);
    // cout << num << endl;


   int deltaa = upper_bound(d,d+13,150) - d; 
    cout << deltaa << endl; //

    int delta = lower_bound(d,d+13,7) - d; 
    cout << delta << endl; //




    // cout << (lower_bound(d,d+13,6)) << endl;
    // cout << d << endl;





    // cout << (lower_bound(d,d+13,17) - d) << endl;
    // cout << (upper_bound(d,d+13,9) - d) << endl;
    // sort(d,d+13);  //静态数组的排序方式
    // int pos;
    // pos = lower_bound(d,d+13,5) - d;  
    // cout << pos <<endl;
    // pos = upper_bound(d,d+13,4) - d; //6
    // cout << pos <<endl;

   // pos = lower_bound(d,d+13,7) - d;  //
    // cout << pos <<endl;
    // pos = upper_bound(d,d+13,7) - d;  //6
    // cout << pos <<endl;

    // int posa = lower_bound(d,d+13,6) - d;
    // int posb = upper_bound(d,d+13,8) - d;
    // cout << posb - posa << endl;


    return 0;
}





// lower_bound / upper_bound:
// 适用的数据结构： 静态数组array / 动态数组vector / set / multiset <====== 数列 / 序列
// 适用的场景：
// 1、找元素第1次或者最后出现的位置;
// 2、找比元素第1次大或者最后1次小的位置；
// 3、找元素或者元素区间个数
// 4、找元素间隔最小值
// 5、既可以在单一序列之中使用，又可以应用2个序列之间的匹配或者查找



// 如下方法是涉及到所有2个序列之间进行匹配到方法，时间复杂度可以控制到O（mlgn）
S = {a,b,c,d,e,f,g,h,i,j,k.....} n个元素
P = {a1,a2,a3,...,am} m个元素
请计算P中有多少个元素存在于S之中？

//
S1; sort(S,S+n);  // S 可以考虑使用multiset结构实现～～～
    sort(P,P+m);

for(int i = 1; i <= m ; i++){
    // int pos = lower_bound(S,S+n,P[i]);
    // if(pos < n and S[pos] == P[i]){
    //     ans++;
    // }
    int pos = S.count(P[i]);
    if(pos >= 1){
        ans++;
    }
}
//O(nm)
for(int i = 1; i <= m ; i++){
    for(int j = 1; j <= n ; j++){
        if(P[i] == S[j]){
            ans++;
        }
    }
}
```