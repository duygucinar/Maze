#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dugum{

    int x;
    int y;
    struct dugum *sonraki;

};

struct dugum *yigin=NULL;
struct dugum *yedek,*yedek2;
int adim=0;

void yol_bul(int matris[][20],int x1,int y1,int x2,int y2,int satir,int sutun);
void push(int x,int y);
int pop();
int pop2();
void goster();


int main(){

    int satir,sutun;
    printf("Labirentin satir sayisini giriniz  :");
    scanf("%d",&satir);
    printf("Labirentin sutun sayisini giriniz  :");
    scanf("%d",&sutun);

    int i,j;
    int matris[satir][sutun];

    srand(time(NULL));

    for(i=0;i<satir;i++){
        for(j=0;j<sutun;j++){
            matris[i][j]=rand()%2;
            printf("%3d",matris[i][j]);
        }
        printf("\n");
    }

    int x1,y1,x2,y2;

    do{
        printf("Giris x-koordinatini giriniz  :");
        scanf("%d",&x1);
        printf("Giris y-koordinatini giriniz  :");
        scanf("%d",&y1);
        printf("Cikis x-koordinatini giriniz  :");
        scanf("%d",&x2);
        printf("Cikis y-koordinatini giriniz  :");
        scanf("%d",&y2);
    }while(matris[x1][y1]==0 || matris[x2][y2]==0);


    yol_bul(matris,x1,y1,x2,y2,satir,sutun);
    printf("\n");

    return 0;
}

void yol_bul(int matris[][20],int x1,int y1,int x2,int y2,int satir,int sutun){

    if(x1==x2 && y1==y2){
        matris[x1][y1]=5;
        push(x1,y1);
        goster();
        exit(0);
    }

    if(x1==0 && y1==0 && matris[x1][y1]==1){

       // matris[x1][y2]=5;

        if(matris[x1][y1+1]==1){
            matris[x1][y1]=5;
            //matris[x1][y1+1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1+1,x2,y2,satir,sutun);
        }
        else if(matris[x1+1][y1]==1){
            matris[x1][y1]=5;
           // matris[x1+1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1+1,y1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(x1==0 && y1>0 && y1<sutun-1 && matris[x1][y1]==1){

       // matris[x1][y1]=5;

        if(matris[x1][y1+1]==1 && (y1+1)<sutun){
            matris[x1][y1]=5;
           // matris[x1][y1+1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1+1,x2,y2,satir,sutun);
        }
        else if(matris[x1+1][y1]==1){
            matris[x1][y1]=5;
          //  matris[x1+1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1+1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1][y1-1]==1 && (y1-1)>=0){
            matris[x1][y1]=5;
           // matris[x1][y1-1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1-1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(x1==0 && y1==sutun-1 && matris[x1][y1]==1){

       // matris[x1][y1]=5;

        if(matris[x1+1][y1]==1){
            matris[x1][y1]=5;
           // matris[x1+1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1+1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1][y1-1]==1){
            matris[x1][y1]=5;
           // matris[x1][y1-1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1-1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(x1==satir-1 && y1==0 && matris[x1][y1]==1){

       // matris[x1][y1]=5;

        if(matris[x1][y1+1]==1){
            matris[x1][y1]=5;
           // matris[x1][y1+1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1+1,x2,y2,satir,sutun);
        }
        else if(matris[x1-1][y1]==1){
            matris[x1][y1]=5;
          //  matris[x1-1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(x1==satir-1 && y1>0 && y1<sutun-1 && matris[x1][y1]==1){

       // matris[x1][y1]=5;

        if(matris[x1][y1+1]==1 && (y1+1)<sutun-1){
            matris[x1][y1]=5;
           // matris[x1][y1+1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1+1,x2,y2,satir,sutun);
        }
        else if(matris[x1-1][y1]==1){
            matris[x1][y1]=5;
           // matris[x1-1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1][y1-1]==1 && (y1-1)>=0){
            matris[x1][y1]=5;
          //  matris[x1][y1-1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1-1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(x1==satir-1 && y1==sutun-1 && matris[x1][y1]==1){

       // matris[x1][y1]=5;

        if(matris[x1-1][y1]==1){
            matris[x1][y1]=5;
          //  matris[x1-1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1][y1-1]==1){
            matris[x1][y1]=5;
           // matris[x1][y1-1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(y1==0 && x1>0 && x1<satir-1 && matris[x1][y2]==1){

       // matris[x1][y1]=5;

        if(matris[x1-1][y1]==1 && (x1-1)>=0){
            matris[x1][y1]=5;
           // matris[x1-1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1][y1+1]==1){
            matris[x1][y1]=5;
           // matris[x1][y1+1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1+1,x2,y2,satir,sutun);
        }
        else if(matris[x1+1][y1]==1 && (x1+1)<satir){
            matris[x1][y1]=5;
           // matris[x1+1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1+1,y1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(y1>0 && y1<sutun-1 && x1>0 && x1<satir-1 && matris[x1][y1]==1){


      //  matris[x1][y1]=5;

        if(matris[x1][y1+1]==1 && (y1+1)<sutun){
            matris[x1][y1]=5;
           // matris[x1][y1+1]=5;
            push(x1,y1);
            yol_bul(matris,x1,y1+1,x2,y2,satir,sutun);
        }
        else if(matris[x1+1][y1]==1 && (x1+1)<satir){
            matris[x1][y1]=5;
           // matris[x1+1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1+1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1][y1-1]==1 && (y1-1)>=0){
            matris[x1][y1]=5;
           // matris[x1][y1-1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1-1][y1]==1 && (x1-1)>=0){
            matris[x1][y1]=5;
          //  matris[x1-1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }

    if(y1==sutun-1 && x1>0 && x1<satir-1 && matris[x1][y1]==1){

        //matris[x1][y1]=5;
        if(matris[x1-1][y1]==1 && (x1-1)>=0){
            matris[x1][y1]=5;
            //matris[x1-1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1][y1-1]==1){
            matris[x1][y1]=5;
           // matris[x1][y1-1]=5;
            push(x1,y1);
            yol_bul(matris,x1-1,y1,x2,y2,satir,sutun);
        }
        else if(matris[x1+1][y1]==1 && (x1+1)<satir){
            matris[x1][y1]=5;
           // matris[x1+1][y1]=5;
            push(x1,y1);
            yol_bul(matris,x1+1,y1,x2,y2,satir,sutun);
        }
        else{
            x1=pop();
            y1=pop2();
            matris[x1][y1]=1;
            yol_bul(matris,x1,y1,x2,y2,satir,sutun);
        }
    }
}

void push(int x,int y){

    if(yigin==NULL){
        yigin=(struct dugum *)malloc(1*sizeof(struct dugum));
        yigin->sonraki=NULL;
        yigin->x=x;
        yigin->y=y;
        printf("(%d,%d)\n",yigin->x,yigin->y);
    }
    else{
        yedek=(struct dugum *)malloc(1*sizeof(struct dugum));
        yedek->sonraki=yigin;
        yedek->x=x;
        yedek->y=y;
        yigin=yedek;

        printf("(%d,%d)\n",yigin->x,yigin->y);
    }
    adim++;
}

int pop(){

    if(yigin==NULL){
        printf("Hata  :Bos yigindan eleman alinamaz!!\n");
        return -1;
    }
    else{
        int x;
        x=yigin->x;
        printf("Pop edilen x:%d\n",x);
        return x;
    }

}

int pop2(){

    if(yigin==NULL){
        printf("Hata  :Bos yigindan eleman alinamaz!!\n");
        return -1;
    }
    else{
        int y;
        yedek2=yigin;
        y=yedek2->y;
        printf("Pop edilen y:%d\n",y);
        yigin=yigin->sonraki;
        free(yedek2);
        return y;
    }

}

void goster(){

    while(yigin->sonraki!=NULL){
        printf("->(%d,%d)",yigin->x,yigin->y);
    }
}
