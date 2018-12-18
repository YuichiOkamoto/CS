#include<stdio.h>
#include <stdlib.h>

#define N 256 //文字数

int main(void) {
	FILE *fp; // FILE型構造体
	char fname[] = "test8cs_6.pch";
	char str[N];
	float data[5000][20]={0};
  int count = 0;
	// float f0, f1, f2, f3, f4, f5, f6, f7;


	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
	if(fp == NULL) {
		printf("%s file not open!\n", fname);
		return -1;
	}

	while(fgets(str, N, fp) != NULL) {
		//printf("%s", str);
		// sscanf(str, "%f %f %f %f %f %f %f %f", &f0, &f1, &f2, &f3, &f4, &f5, &f6, &f7);
    // printf(" %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", f0 f1, f2, f3, f4, f5, f6, f7);
			sscanf(str, "%f %f %f %f %f %f %f %f", &data[count][0],&data[count][1],&data[count][2],&data[count][3],&data[count][4],&data[count][5],&data[count][6],&data[count][7]);
			printf(" %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", data[count][0],data[count][1],data[count][2],data[count][3],data[count][4],data[count][5],data[count][6],data[count][7]);
			count++;
	}

	fclose(fp); // ファイルを閉じる

  // printf("%c", str[0]);

// 	for(int i=0;i<N;i++)
// 	{
// //	sscanf(str[i], "%f %f %f %f %f %f %f %f", &data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][4],&data[i][5],&data[i][6],&data[i][7]);
// //	printf(" %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", data[i][0],data[i][1],data[i][2],data[i][3],data[i][4],data[i][5],data[i][6],data[i][7]);
// }

	return 0;
 }


// int main(void) {
// 	FILE *fp; // FILE型構造体
// 	char fname[] = "test8cs_6.pch";
// 	char str[16];
// 	float f1, f2, f3, f4, f5, f6, f7, f8 ;
//
// 	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。
// 	if(fp == NULL) {
// 		printf("%s file not open!\n", fname);
// 		return -1;
// 	}
//
// 	while(fscanf(fp, "%f %f %f %f %f %f %f %f", &f1, &f2, &f3, &f4, &f5, &f6, &f7, &f8) != EOF) {
// 		printf(" %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", f1, f2, f3, f4, f5, f6, f7, f8);
// 	}
//
// 	fclose(fp); // ファイルを閉じる
//
// 	return 0;
// }
