#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void podmiana (char* tab)
{
	for (int i = 0; tab[i] != 0; i += 1)
	{
		if(tab[i] >= 'a' && tab[i] <= 'z')
		{
			tab[i] = tab[i] - 'a' + 'A';
		}
	}
}

void wytnij(char* napis, int n, int m)
{
    int i,j;
    for(j=0; napis[j]!=0; j++);
    {

    }
    if(j+1>m){
        for (i=0; i+m<j; i++)
        {
            napis[n+1]=napis[m+i+1];
        }
    }
    else if((n<j)&&(j+1<=m))
    {
        napis[n]=0;
    }

}

void wytnijzw(char* nap1, char* nap2)
{
    int i,j;
    int wyst[256]={};
    for(i=0;nap2[i]!=0;i++)
    wyst[nap2[i]==1];
    for(i=0,j=0;nap1[i]!=0; i++)
    if (wyst[nap1[i]]==0){
            if(j<i)
            nap1[j]=nap1[i];
    j++;
    }
    nap1[j]=0;
}
void wytnijtm(wchar_t *nap1, wchar_t *nap2){
int i,j;
for(i=0,j=0;nap1[i]!=0;i++)
{
    if(nap1[i]!=nap2[i])
    {
        if(i>j)
        {
            nap1[j]=nap1[i];
            j++;
        }
    }
    nap1[j]=0;
}
}
char* godzina ( int godz, int min, int sek )
{
	char* napis = malloc( 9 );

	napis[ 0 ] = godz / 10 + '0';
	napis[ 1 ] = godz % 10 + 48;
	napis[ 2 ] = 58;
	napis[ 3 ] = min / 10 + '0';
	napis[ 4 ] = min % 10 + 48;
	napis[ 5 ] = 58;
	napis[ 6 ] = sek / 10 + '0';
	napis[ 7 ] = sek % 10 + 48;
	napis[ 8 ] = 0;

	return napis;
}
void usunSpacje(char *napis) {
    int i, j;
    for (i = 0, j = 0; napis[i]; i++) {
        if (napis[i]!=' ') {
            napis[j++] = napis[i];
        }
    }
    napis[j] = '\0';
}

int main ()
{
	char s[] = "MEDI to Nie Aniol tyLkO FARAon";
    printf ( "%s \n", s );
    podmiana ( s );
    ///char napis[] = "Cristiano Ronaldo";
    char nap1[] = "Ronaldo";
    char nap2[] = "Rsaalds";
    int n = 2;
    int m = 30;
    ///printf("Napis przed przycieciem: %s\n", napis);
    ///wytnij(napis, n, m);
    ///printf("Napis po przycieciu: %s\n", napis);
    ///printf("Napis przed przycieciem: %s\n", nap1);
    ///wytnijzw(nap1,nap2);
    ///printf("Napis po: %s\n", nap1);
    printf("Napis przed przycieciem: %s\n", nap1);
    wytnijtm(nap1,nap2);
    printf("Napis po: %s\n", nap1);
    printf ( "%s \n", godzina( 12, 34, 57 ) );
	printf ( "%s \n", godzina( 13, 14, 15 ) );
	printf ( "%s \n", godzina( 2, 0, 0 ) );
	char napis[] = "To jest napis z spacjami.";
    printf("Przed usunieciem spacji: %s\n", napis);
    usunSpacje(napis);
    printf("Po usunieciu spacji: %s\n", napis);


	return 0;
}
