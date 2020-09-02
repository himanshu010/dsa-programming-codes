def sum_digit(x):
    sum2=0;
    while x>0:
        ld=x%10;
        x=x/10;
        sum2+=ld;

    return sum2;


y=input();
if y<10:
    print(0);
else:
    sum1=y;
    cnt=0;
    while sum1/10>0:
        sum1=sum_digit(sum1);
        cnt=cnt+1;

    print(cnt);

