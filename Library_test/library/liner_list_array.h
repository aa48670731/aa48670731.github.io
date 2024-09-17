#include <iostream>
#include <cmath>
#define list_init_size 100
#define listincrease_size 10
using namespace std;
typedef int Elemtype; // 随时可利用Elemtype改变线性表数据类型

// 基于数组的线性表
typedef struct
{
    Elemtype *array; // 线性表内数组
    int length;      // 线性表目前的长度
    int listsize;    // 线性表的最大长度
} List;

// 判空
int List_empty(List &L)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return -1;
    }
    return (L.length == 0);
}

// 初始化线性表
void Init_list(List &L)
{
    L.array = (Elemtype *)malloc(list_init_size * sizeof(Elemtype));
    // 若地址分配失败则提示错误
    if (!L.array)
    {
        cout << "malloc error" << endl;
        return;
    }
    // 更新线性表的长度为0
    L.length = 0;
    // 更新线性表的最大长度
    L.listsize = list_init_size;
    return;
}

// 清除线性表
void Destroy_list(List &L)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return;
    }
    // 释放空间
    free(L.array);
    // 更新指针
    L.array = NULL;
    return;
}

// 将线性表重置为空表
void Clear_list(List &L)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return;
    }
    // 更新长度为0
    L.length = 0;
    return;
}

// 返回目前长度
int List_length(List &L)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return -1;
    }
    return L.length;
}

// 用e接收线性表第i个元素
void Get_elem(List &L, int i, Elemtype &e)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return;
    }
    // 注意：这里的i范围是1~l.length，和数组下标有区别，加了1
    // 判断位置是否合法
    if (i < 1 || i > L.length)
    {
        cout << "location error" << endl;
        return;
    }
    Elemtype *q = &(L.array[i - 1]);
    e = *q;
    return;
}

// 返回线性表中第一个与e满足compare函数关系的元素的位序，若不存在则返回0
int Locate_elem(List &L, Elemtype e, int (*compare)(Elemtype, Elemtype))
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return -1;
    }
    int n = List_length(L);
    for (int i = 0; i < n; i++)
    {
        if ((*compare)(e, L.array[i]))
        {
            return i + 1;
        }
    }
    return 0;
}

// 若cur_e是线性表的数据元素，且不是第一个，则用pre_e存储它的前驱，否则pre_e置为-1
void Prior_Elem(List &L, Elemtype cur_e, Elemtype &pre_e)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        pre_e = -1;
        return;
    }
    int n = List_length(L);
    for (int i = 0; i < n; i++)
    {
        if (cur_e == L.array[i])
        {
            // 如果cur_e是第一个元素
            if (!i)
            {
                cout << "The cur_e is the first elem" << endl;
                pre_e = -1;
                return;
            }
            else
            {
                pre_e = L.array[i - 1];
                return;
            }
        }
    }
    pre_e = -1;
    return;
}

// 若cur_e是线性表的数据元素，且不是最后一个，则用next_e存储它的前驱，否则next_e置为-1
void Next_Elem(List &L, Elemtype cur_e, Elemtype &next_e)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        next_e = -1;
        return;
    }
    int n = List_length(L);
    for (int i = 0; i < n; i++)
    {
        if (cur_e == L.array[i])
        {
            // 如果cur_e是最后一个元素
            if (i == n - 1)
            {
                cout << "The cur_e is the last elem" << endl;
                next_e = -1;
                return;
            }
            else
            {
                next_e = L.array[i + 1];
                return;
            }
        }
    }
    next_e = -1;
    return;
}

// 插入元素
void Insert_elem(List &L, int i, Elemtype e)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return;
    }
    // 注意：这里的i范围是1~l.length+1，和数组下标有区别，加了1
    // 判断插入位置是否合法
    if (i < 1 || i > L.length + 1)
    {
        cout << "location error" << endl;
        return;
    }

    // 若此时线性表长度达到最大，则扩容
    if (L.length >= L.listsize)
    {
        // 利用realloc扩容（拷贝一份源数据并在基础上扩大空间，返回的是新地址）
        Elemtype *newbase = (Elemtype *)realloc(L.array, (list_init_size + listincrease_size) * sizeof(Elemtype));
        // newbase用于暂存地址，若分配失败则提示信息
        if (!newbase)
        {
            cout << "something error with realloc" << endl;
            return;
        }
        // 记得把新地址赋值给线性表的数组
        L.array = newbase;
        // 更新最大长度
        L.listsize += listincrease_size;
    }
    Elemtype *q = &(L.array[i - 1]);
    if (L.length >= 1)
    {

        for (Elemtype *p = &(L.array[L.length - 1]); p >= q; p--)
        {
            *(p + 1) = *(p);
        }
    }
    *q = e;
    // 更新长度
    L.length += 1;
    return;
}

// 删除线性表第i个元素，并用e来接收它的值
void Delete_elem(List &L, int i, Elemtype &e)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return;
    }
    // 判断线性表长度是否为0
    if (List_empty(L))
    {
        cout << "The List is empty" << endl;
        return;
    }
    // 注意：这里的i范围是1~l.length，和数组下标有区别，加了1
    // 判断删除位置是否合法
    if (i < 1 || i > L.length)
    {
        cout << "location error" << endl;
        return;
    }

    Elemtype *q = &(L.array[i - 1]);
    e = *q;
    for (Elemtype *p = &(L.array[L.length - 1]); q < p; q++)
    {
        *(q) = *(q + 1);
    }
    // 更新长度
    L.length -= 1;
    return;
}

// 遍历线性表，对每个元素调用函数visit(),一旦visit()失败，则操作失败
void List_Traverse(List &L, int (*visit)(Elemtype &))
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return;
    }
    int n = List_length(L);

    for (int i = 0; i < n; i++)
    {
        // 若visit()调用失败，则返回异常
        if (!(*visit)(L.array[i]))
        {
            cout << "Call function visit Error" << endl;
            return;
        }
    }
    return;
}

// 打印线性表
void Print_list(List &L)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return;
    }
    if (List_empty(L))
    {
        cout << "the array is empty" << endl;
        return;
    }
    int n = List_length(L);
    for (int i = 0; i < n; i++)
    {
        cout << L.array[i] << ' ';
    }
    cout << endl;
    return;
}

int Find_elem(List &L, Elemtype target)
{
    // 判断所给线性表是否存在
    if (!L.array)
    {
        cout << "there is no array" << endl;
        return -1;
    }
    int n = List_length(L);
    for (int i = 0; i < n; i++)
    {
        if (L.array[i] == target)
        {
            return i + 1;
        }
    }
    return -1;
}
// 判等函数
int Equal(Elemtype a, Elemtype b)
{
    return (a == b);
}

// 平方函数
int Square(Elemtype &x)
{
    x *= x;
    return 1;
}

// 开根函数
int Sqrt(Elemtype &x)
{
    if (x < 0)
    {
        return 0;
    }
    x = sqrt(x);
    return 1;
}
