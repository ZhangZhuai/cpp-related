// Reference:https://www.geeksforgeeks.org/complicated-declarations-in-c/

#include <stdio.h>

// fp * () int
// fp is pointer to function returning int
int (*fp)();
int func(void)
{
    printf("hello\n");
    return 0;
}

// daytab * [3] int
// daytab is pointer to array of 3 intergers
int (*daytab)[3];
int arr[3] = {1, 2, 3};

// f[10] * (int, int) void
// f is an array of 10 pointer to
// function which takes 2 arguments of type int and return void
void (*f[10])(int, int);
void func1(int a, int b)
{
    printf("func1 = %d, %d\n", a, b);
}

// x () * [] * () char
// x is a function returning pointer to array of pointers to function returning char
// char (*(*x())[])();
char cfunc1() { return 'a'; }
char cfunc2() { return 'b'; }
char cfunc3() { return 'c'; }
// xarr[]  * () char
char (*xarr[])() = {cfunc1, cfunc2, cfunc3};
// g++ can not compile ... gcc can
char (*(*x())[])() { return &xarr; }
// g++ can compile
// char (*(*x())[3])() { return &xarr; }

// char (*(*xs[2])())[4]
// xs[2] * () * [4] char
// xs is an array of 2 pointers to function returning pointer to array of 4 chars
// typedef to simplify code 
typedef char charray5[4];
char carr1[4] = {'a', 'b', 'c', '\0'};
charray5 carr2 = {'d', 'e', 'f', '\0'};

char((*cafunc1())[4]) { return &carr1; }
charray5 *cafunc2() { return &carr2; }

char (*(*xs[2])())[4] = {cafunc1, cafunc2};

int a = 1;
int b = 2;
int *Func1() { return &a; }
int *Func2() { return &b; }
int *(*funcp1())() { return Func1; }
int *(*funcp2())() { return Func2; }
// arr[5] * () * () * int
// arr is an array of 5 pointers to functions returning pointer
// to function returing pointer to integer
int *(*(*Arr[5])())() = {funcp1, funcp2};

void on_sig10_exit(int u) { printf("sig10 exit\n"); }
void on_sig20_exit(int u) { printf("sig20 exit\n"); }
void default_exit(int u) { printf("default exit\n"); }
void user_default_exit(int u) { printf("user default exit\n"); }
void (*exit_by)(int);
// bsd_signal (int, FUNC * (int) void) * (int) void
// bsd_signal is a function(that takes integer & (FUNC)a pointer to a function that takes int and return void)
// and returns pointer to a function(that takes integer as argument and returns void)
void (*bsd_signal(int sig, void (*FUNC)(int)))(int)
{
    switch (sig)
    {
    case 10:
        return on_sig10_exit;
        break;
    case 20:
        return on_sig20_exit;
        break;
    default:
        if (FUNC == NULL)
            return default_exit;
        else
            return user_default_exit;
    }
}
int main()
{
    printf("fp is pointer to function returning int\n");
    fp = func;
    (*fp)();

    printf("daytab is pointer to array of 3 intergers\n");
    daytab = &arr;
    printf("arr[2] = %d\n", (*daytab)[2]);

    printf("f is an array of 10 pointer to function which takes 2 arguments of type int and return void\n");
    f[0] = func1;
    (*f[0])(1, 2);

    printf("x is a function returning pointer to array of pointers to function returning char\n");
    for (int i = 0; i < 3; ++i)
    {
        printf("%c\n", ((*x())[i])());
    }

    printf("xs is an array of 2 pointers to function returning pointer to array of 4 chars\n");
    for (int i = 0; i < 2; ++i)
    {
        printf("%s\n", *(xs[i]()));
    }
    printf("arr is an array of 5 pointers to functions returning pointer to function returning pointer to integer\n");
    printf("%d %d\n", *(*(*Arr[0])())(), *(*(*Arr[1])())());


    printf("bsd_signal is a function that takes integer & a pointer to a function(that takes integer as argument and returns void)\n");
    printf("and returns pointer to a function(that take integer as argument and returns void)\n");
    (bsd_signal(10, NULL))(0);
    (bsd_signal(20, NULL))(0);
    (bsd_signal(30, NULL))(0);
    (bsd_signal(30, user_default_exit))(0);

    return 0;
}