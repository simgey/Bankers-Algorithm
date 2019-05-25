#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


int  process;
 int main()
{ int kaynak,i,j,sayac=0;
    printf("Kaynak sayısını giriniz:");//kaynak sayisi
    scanf("%d",&kaynak);
    printf("Process sayısını giriniz:");
    scanf("%d",&process);
   int *CalismaSirasi;
    int Alloc[process][kaynak];
    int Max[process][kaynak];
    int Need[process][kaynak];
    int Kalan[kaynak];
    CalismaSirasi=(int*)malloc(sizeof(int));

    int hangisi=0;
   
    for(i=0;i<kaynak;i++)
    
    {
        printf("%d Kaynaktan Toplam Kaç Tane Olduğu Giriniz:\n",i+1);
        scanf("%d",&Kalan[i]);
       
    }
    for(i=0;i<process;i++) // process kadar dönüyor.
    {
       CalismaSirasi[i]=0; // processlerin calisma sirasini veriyor.
    }
    for(i=0;i<process;i++) //alloc matrisini aldığımız döngü.
    {
        for(j=0;j<kaynak;j++)
        {  printf("Alloc Matrisini Giriniz:\n");
            printf("%d.processin %d. kaynağı=",i+1,j+1);
            scanf("%d",&Alloc[i][j]);
        }
        
    }
    for(i=0;i<process;i++) //max matrisini aldığımız döngü
    {
        for(j=0;j<kaynak;j++)
        {  printf("Max Matrisini giriniz:\n");
            printf("%d.processin %d. kaynağı=",i+1,j+1);
            scanf("%d",&Max[i][j]);
        }
        
    }
  
    for(i=0;i<process;i++)
    {
        for(j=0;j<kaynak;j++)
        {
            Need[i][j]=Max[i][j]-Alloc[i][j]; // need matrini maxtan alloc u  çıkartarak olusturuyoruz.
        }
        
        
    }
    
    
    
    for(i=0;i<process;i++)
    {
        for(j=0;j<kaynak;j++)  //processler her çalıştığındaki kalan toplam kahnak sayısı matrisini olusturuyıruz.
        {
            Kalan[j]-=Alloc[i][j];
        }
      
    }
    
    int uygunmu=1;
    int Sira=0;
  
   
    while(sayac<process)
    {
        for(i=0;i<process;i++)
        {
            hangisi=0;
            uygunmu=1;
        
            if(uygunmu==1)
        {
            for(j=0;j<kaynak;j++)
            {
                if(Kalan[j]>=Need[i][j])
                {
                    uygunmu=1;
                    Kalan[j]+=Alloc[i][j];
                    hangisi++;
                }
                else
                {
                    uygunmu=0;
                    break;
                    
                    
                  
                }
                if(hangisi==kaynak)
                {
                    
                    CalismaSirasi[Sira]=i+1;
                    Sira++;
                    
                }
                
                
            }
            
        }
        }
        sayac++;
    }
    if(uygunmu==0)
    {
        printf("DEADLOCK!!!");
        return -1;
    }
 
       for(i=0;i<process;i++)
        {
            printf("%d.calısan process %d dir\n",i+1,CalismaSirasi[i]);
        }
   
    return 0;
}
