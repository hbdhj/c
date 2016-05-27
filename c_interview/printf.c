#include "stdarg.h"  
/********************************************************** 
     
***********************************************************/  
void printch(const char ch)  
{
    putchar(ch);
}
/********************************************************** 
     
***********************************************************/  
void printint(const int dec)  
{  
    if(dec == 0)  
    {  
        return;
    }  
    printint(dec / 10);
    putchar((char)(dec % 10 + '0'));
}  
/********************************************************** 
     
***********************************************************/  
void printstr(const char *ptr)  
{
    while(*ptr)  
    {
        putchar(*ptr);  
        ptr++;  
    }  
}
/********************************************************** 
     
***********************************************************/  
void printfloat(const float flt)  
{  
    int tmpint = (int)flt;  
    int tmpflt = (int)(100000 * (flt - tmpint));  
    if(tmpflt % 10 >= 5)  
    {  
        tmpflt = tmpflt / 10 + 1;  
    }  
    else  
    {  
        tmpflt = tmpflt / 10;  
    }  
    printint(tmpint);
    putchar('.');
    printint(tmpflt);
}  
/********************************************************** 
     
***********************************************************/  
void my_printf(const char *format,...)  
{  
    va_list ap;  
    va_start(ap, format);  
    while(*format)  
    {  
        if(*format != '%')  
        {  
            putchar(*format);  
            format++;  
        }  
        else  
        {  
            format++;
            switch(*format)
            {  
                case 'c':  
                {  
                    char valch = va_arg(ap, int);
                    printch(valch);  
                    format++;  
                    break;  
                }  
                case 'd':  
                {  
                    int valint = va_arg(ap, int);
                    printint(valint);  
                    format++;  
                    break;  
                }  
                case 's':
                {  
                    char *valstr = va_arg(ap, char *);
                    printstr(valstr);  
                    format++;  
                    break;  
                }  
                case 'f':  
                {  
                    float valflt = va_arg(ap, double);
                    printfloat(valflt);
                    format++;
                    break;
                }  
                default:
                {
                    printch(*format);
                    format++;  
                }
            }  
            va_end(ap);
        }
    }  
}  
/********************************************************** 
     
***********************************************************/  
int main()  
{  
    char ch = 'A';  
    char *str = "holle world";  
    int dec = 1234;  
    float flt = 1234.3456789;   
    my_printf("str = %s,dec = %d,ch = %c,flt = %f\n",str,dec,ch,flt);  
    return 0;  
}  