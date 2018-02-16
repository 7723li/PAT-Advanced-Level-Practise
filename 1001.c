// A+B Format
#include <stdio.h>
#include <stdlib.h>

#define money 100

typedef struct sapce* walleet;
struct sapce
{
	int Money;
	walleet Next;
};

void HappyNewYear(){
	int count = 0;
	walleet mine;
	walleet Next = NULL;
	while(1){
		mine = (walleet) malloc (sizeof(struct sapce));
		mine -> Money = money;
		mine -> Next = Next;
		printf("%d %d\n", count++, mine -> Money * count);
		Next = mine;
	}
}

int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c = a + b, d, pos = 0, len = 0, val = 1;
	char temp[10];

	if(c == 0)
		printf("0");
	else{
		if(c < 0){
			d = -c;
			temp[pos++] = '-';
			printf("-");
			len++;
		}
		else d = c;

		c = d;
		while(c){
			if(c >= 10) val *= 10;
			c /= 10;
			len++;
		}

		int i = pos;
		for(i; i < len; i++){
			if(val == 0) val = 1;
			temp[i] = d / val + '0';
			printf("%c", temp[i]);
			if((len - i - 1) % 3 == 0 && i != len - 1)
				printf(",");
			d %= val;
			val /= 10;
		}
		temp[len] = '\0';
	}
	

	printf("\n");

	// HappyNewYear(); // 2018-02-16
	
	
	return 0;
	
}

// Sample Input
// -1000000 9
// Sample Output
// -999,991
