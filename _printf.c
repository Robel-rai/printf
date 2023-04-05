#include <main.h>

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    for (const char *p = format; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            count++;
            continue;
        }
        p++;
        switch (*p)
        {
            case 'c':
                {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
            case 's':
                {
                    const char *s = va_arg(args, const char *);
                    for (; *s != '\0'; s++)
                    {
                        putchar(*s);
                        count++;
                    }
                    break;
                }
            case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
            default:
                break;
        }
    }

    va_end(args);
    return count;
}
