```cpp
int d[10];
sort(d,d+10); //升序
sort(d,d+10,greater<int>()); //降序

pair<int,int>d[10];
sort(d,d+10);//升序
sort(d,d+10,greater<pair<int,int>>()); //降序

vector<int>d;
sort(d.begin(),d.end()); //升序
sort(d.rbegin(),d.rend()); //降序
```