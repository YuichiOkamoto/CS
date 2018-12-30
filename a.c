#include<stdio.h>
#include <stdlib.h>

#define N 256 //文字数

int main(void) {
	FILE *fp1; // FILE型構造体
	char fname1[] = "test8cs_6.fgr";
	char str1[N];
	int data1[5000][8]={0};
  int count1 = 0;
	FILE *fp2; // FILE型構造体
	char fname2[] = "test8cs_6.pch";
	char str2[N];
	float data2[5000][3]={0};
	int count2 = 0;
  int output1[5000][8]={0};
  int output2[5000][8]={0};
	int num1 = 0;//荷重面
  int num2 = 0;//底面固定
	int v1,v2,v3;//頂点の接点番号収納
	int i,j;
	FILE *outputfile;//出力ファイル
	char opname[] = "test8cs_6_f.fgr";

	fp1 = fopen(fname1, "r"); // ファイルを開く。失敗するとNULLを返す。
	if(fp1 == NULL) {
		printf("%s file not open!\n", fname1);
		return -1;
	}

	while(fgets(str1, N, fp1) != NULL) {
			sscanf(str1, "%d %d %d %d %d %d %d %d", &data1[count1][0],&data1[count1][1],&data1[count1][2],&data1[count1][3],&data1[count1][4],&data1[count1][5],&data1[count1][6],&data1[count1][7]);
			printf(" %d %d %d %d %d %d %d %d\n", data1[count1][0],data1[count1][1],data1[count1][2],data1[count1][3],data1[count1][4],data1[count1][5],data1[count1][6],data1[count1][7]);
			count1++;
	}

	fclose(fp1); // ファイルを閉じる

	fp2 = fopen(fname2, "r"); // ファイルを開く。失敗するとNULLを返す。
	if(fp2 == NULL) {
		printf("%s file not open!\n", fname2);
		return -1;
	}

	while(fgets(str2, N, fp2) != NULL) {
			sscanf(str2, "%f %f %f", &data2[count2][0],&data2[count2][1],&data2[count2][2]);
			printf(" %.1f %.1f %.1f \n", data2[count2][0],data2[count2][1],data2[count2][2]);
			count2++;
	}

	fclose(fp2); // ファイルを閉じる

//荷重面の設定
for(i=0;i<5000;i++){
	v1 = data1[i][2];
	v2 = data1[i][3];
	v3 = data1[i][4];//一行しかないものは０をとってはじかれる
	if(30<data2[v1][0] && data2[v1][0]<50 && data2[v1][1]==100 && 30<data2[v1][2] && data2[v1][2]<50 && data2[v2][1]==100 && data2[v3][1]==100){//30<x<50,y=100,30<z<50
    for(j=0;j<8;j++){
			output1[num1][j]=data1[i][j];//新しいｆｇｒに書き込み
		}
			printf("%f %f %f\n%f %f %f\n%f %f %f\n",data2[v1][0],data2[v1][1],data2[v1][2],data2[v2][0],data2[v2][1],data2[v2][2],data2[v3][0],data2[v3][1],data2[v3][2]);
			num1++;
	}
	else if(30<data2[v2][0] && data2[v2][0]<50 && data2[v2][1]==100 && 30<data2[v2][2] && data2[v2][2]<50 && data2[v1][1]==100 && data2[v3][1]==100){//30<x<50,y=100,30<z<50
    for(j=0;j<7;j++){
			output1[num1][j]=data1[i][j];//新しいｆｇｒに書き込み
		}
			printf("%f %f %f\n%f %f %f\n%f %f %f\n",data2[v1][0],data2[v1][1],data2[v1][2],data2[v2][0],data2[v2][1],data2[v2][2],data2[v3][0],data2[v3][1],data2[v3][2]);
			num1++;
	}
	else if(30<data2[v3][0] && data2[v3][0]<50 && data2[v3][1]==100 && 30<data2[v3][2] && data2[v3][2]<50 && data2[v1][1]==100 && data2[v2][1]==100){//30<x<50,y=100,30<z<50
		for(j=0;j<7;j++){
			output1[num1][j]=data1[i][j];//新しいｆｇｒに書き込み
		}
			printf("%f %f %f\n%f %f %f\n%f %f %f\n",data2[v1][0],data2[v1][1],data2[v1][2],data2[v2][0],data2[v2][1],data2[v2][2],data2[v3][0],data2[v3][1],data2[v3][2]);
			num1++;
	}
	else{
	}
}
//底面固定
for(i=0;i<5000;i++){
	v1 = data1[i][2];
	v2 = data1[i][3];
	v3 = data1[i][4];
	if(data2[v1][1]==0 && data2[v2][1]==0 && data2[v3][1]==0){//y=0
    for(j=0;j<8;j++){
			output2[num2][j]=data1[i][j];//新しいｆｇｒに書き込み
   }
			num2++;
	}
	else{
	}
}
  outputfile = fopen(opname, "w");  // ファイルを書き込み用にオープン(開く)
  if (outputfile == NULL) {          // オープンに失敗した場合
    printf("cannot open\n");         // エラーメッセージを出して
    exit(1);                         // 異常終了
  }

  fprintf(outputfile, "%d\n", num1); // ファイルに書く
	for(i=0;i<num1;i++){
		fprintf(outputfile, "%d %d %d %d %d %d %d %d\n", output1[i][0], output1[i][1], output1[i][2], output1[i][3], output1[i][4], output1[i][5], output1[i][6], output1[i][7]);
	}
	fprintf(outputfile, "%d\n", num2);
	for(i=0;i<num2;i++){
		fprintf(outputfile, "%d %d %d %d %d %d %d %d\n", output2[i][0], output2[i][1], output2[i][2], output2[i][3], output2[i][4], output2[i][5], output2[i][6], output2[i][7]);
	}
  fclose(outputfile);

	return 0;
 }
