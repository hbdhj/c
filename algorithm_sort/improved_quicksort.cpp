/***
*对于快速排序递归函数栈的深度的改进
*author：Allen
*date：2012-11-01
*说明：
*由于只是简单实现算法，对于代码风格没太在意。
*原快速排序算法的代码是从网上找的，并做了一点修改。
*/
#include <iostream>
#include<ctime>
using namespace std;
const int a_size = 128;//带排序数列长度
int a[a_size];
void swap(int *pLeft,int *pRight)
{
    int temp;
    temp = *pLeft;
    *pLeft= *pRight;
    *pRight = temp;
}
//原快速排序
void qs(int begin,int end)
{
    static int deep = 0;//递归深度
    static int allnum =0;//函数调用总次数
    static int mostDeep = 0;//最大递归深度
    ++allnum;
    ++deep;
    if(deep>mostDeep){
        mostDeep=deep;
    }
    int compare=a[begin], left =begin,right = end;
    if(abs(right-left)<=1)
    {
        --deep;
        if(left<right && a[left]>a[right]){
            swap(a[right],a[left]);
        }
        return;
    }
    while (left <right)
    {
        while ((left <right) && a[right]>=compare)
            right--;
        swap(a[left],a[right]);
        while ((left <right) &&(a[left] <compare))
            left++;
        swap(a[right],a[left]);
    }
    a[right] = compare;
    qs(begin,right-1);
    qs(right+1,end);
    --deep;
    if(deep<=0){
        cout<<"函数调用总次数:"<<allnum<<endl;
        cout<<"最大递归深度数:"<<mostDeep<<endl;
    }
}
//改进快排，每次递归函数中还剩一组未排序列，即回溯到上级。
//优先排短的序列
//递归函数参数表里还要保留两个未排序列的参数，返回给上级递归处理
//可以认为是下级递归函数（B）完成一半原来任务（C）后，即将自身的函数栈释放，将另一半任务（D）仍交给上级函数（A）
//由此另一半任务(D)执行时，所使用的函数栈深度和下级递归函数(B)的深度是一样的都是上级函数（A）+1
//但是要注意顶级部分的函数仍然要处理掉C、D两个任务。
void qs(int p_begin,int p_end,int &p_unBegin,int &p_unEnd)
{
    static int deep = 0;//递归深度
    static int allnum =0;//函数调用总次数
    static int mostDeep = 0;//最大递归深度
    ++allnum;
    ++deep;
    if(deep>mostDeep){
        mostDeep=deep;
    }
    //    cout<<"递归深度:"<<deep << ' ' <<p_begin <<' ' <<p_end<<' ' <<p_unBegin<<' ' <<p_unEnd<<' ' <<endl;
    int compare=a[p_begin], left =p_begin,right = p_end;
    if(abs(right-left)<=1)
    {
        --deep;
        if(left<right && a[left]>a[right]){
            swap(a[right],a[left]);
        }
        p_unBegin=-1;
        p_unEnd=-1;
        return;
    }
    while (left <right)
    {
        while ((left <right) && a[right]>=compare)
            --right;

        swap(a[left],a[right]);
        while ((left <right) &&(a[left] <compare))
            ++left;

        swap(a[right],a[left]);
    }
    a[right] = compare;

    int newBegin;
    int newEnd;
    int unBegin=p_begin;
    int unEnd=p_end;

    if( (right-1)-p_begin <= p_end-(right+1) ){
        newBegin=p_begin;
        newEnd=right-1;
        p_unBegin=right+1;
        p_unEnd=p_end;
        qs(newBegin,newEnd,unBegin,unEnd);
        while(unBegin!=-1&&unEnd!=-1){
            qs(unBegin,unEnd,unBegin,unEnd);
        }
        if(deep>1){
            --deep;
            return;
        }
    }else{
        p_unBegin=p_begin;
        p_unEnd=right-1;
        newBegin=right+1;
        newEnd=p_end;
        qs(newBegin,newEnd,unBegin,unEnd);
        while(unBegin!=-1&&unEnd!=-1){
            qs(unBegin,unEnd,unBegin,unEnd);
        }
        if(deep>1){
            --deep;
            return;
        }
    }
    //另一部分
    qs(p_unBegin,p_unEnd,unBegin,unEnd);
    while(unBegin!=-1&&unEnd!=-1){
        qs(unBegin,unEnd,unBegin,unEnd);
    }
    --deep;
    if(deep<=0){
        cout<<"函数调用总次数:"<<allnum<<endl;
        cout<<"最大递归深度数:"<<mostDeep<<endl;
    }
}

void printArray(const int * p_arr,const int size){
    for (int i=0;i<size;i++)
    {
//        cout<<"array["<<i<<"] = "<<p_arr[i]<< ' ';
        cout<< p_arr[i]<< ' ';
    }
    cout<<endl;
}

int main()
{
    int i=0;
    srand(time(0));
    int b[a_size];//原数列数组
    for (i =0;i< a_size;i++)
    {
        b[i] =rand()%a_size;
        //    b[i] =a_size-i;
        //    b[i] =i;
    }
    cout<<"排序前"<<endl;
    printArray(b,a_size);
    for (i= 0;i<a_size;i++)
    {
        a[i]=b[i];
    }
    cout<<"原来的排序后"<<endl;
    qs(0,a_size-1);
    printArray(a,a_size);
    //下面为改进的
    for (i= 0;i<a_size;i++)
    {
        a[i]=b[i];
    }
    cout<<"改进的排序后"<<endl;
    int st=0;
    int en=a_size-1;
    qs(0,a_size-1,st,en);
    printArray(a,a_size);
    system("pause");
    return 0;
}
