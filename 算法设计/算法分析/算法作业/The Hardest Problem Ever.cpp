#include <stdio.h>
 
int main() {
	char a[20],b[1000],c[20];
	while(1){
		gets(a); 
 
		if(a[0]=='E') {
			break;
		}else 
		if(a[0]=='S'){
			gets(b); 
			int i=0;
			for(;b[i];i++){
				if(b[i]>=(int)'A'&&b[i]<=(int)'E'){
					printf("%c",b[i]+21);
				}else if(b[i]>=(int)'F'&&b[i]<=(int)'Z'){
					printf("%c",b[i]+21-26);
				}else{
					printf("%c",b[i]);
				}
			}
		}
		gets(c); 
		printf("\n");
	} 
	 
    return 0;
}
