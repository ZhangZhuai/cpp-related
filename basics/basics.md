#### typedef
typedef 修饰复合类型
```cpp
typedef char Line[81];
Line text;
getline(text);
```
```cpp
typedef const char* pstr;
int mystrcmp(pstr, pstr);
// typedef char* pstr;
// int mystrcmp(pstr, pstr); const pstr -> char* const
typedef 代码简化
```cpp
typedef int (*PF) (const char *, const char *);
PF Register(PF pf);
int (*Register (int (*pf)(const char *, const char *))) (const char *, const char *); 
```