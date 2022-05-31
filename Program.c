//LOG Progress Skripsi - Kelompok 13
//Fakhri Putra Laksono - 1906384081
//Harsya Adytia Nugraha - 1906384125

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void coverpage();
void menu();
void addlog();
void editlog();
void deletelog();
void loglist();
int getdata();
int checknpm(int);
int rekursi(int);
void cari();
int getjadwal();
void jadwalbimb();
void listjadwal();
int tanggal(int, int, int);

FILE *fp,*ft,*fs;

char find;

struct data {
	int npm;
	char nama[50];
	char judul[50];
	int minggu;
	char progres[50];
	char keterangan[50];
}; struct data a;

struct jadwal{
	int tanggal;
	int bulan;
	int tahun;
	char namabimb[50];
	int npmbimb;
}; struct jadwal b;

struct listNode {
	struct listNode *leftPtr;
	int data;
	struct listNode *rightPtr;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert ( ListNodePtr *startPtr, int value); //untuk input linkedlist
char delete ( ListNodePtr *startPtr, int value); //untuk menghapus node linkedlist
int listempty (ListNodePtr startPtr);
void printlist (ListNodePtr startPtr); //untuk print linkedlist
void instructions (void );

void insertNode(ListNodePtr *startPtr, int value); //untuk input ke binarytree
void inOrder(ListNodePtr startPtr); //untuk print binary tree

ListNodePtr startPtr = NULL;

int main(){
	
	int item;
	
	coverpage();
	
	printf("\n\n\t\tEnter a NPM : ");
	scanf("%d", &item);
	
	insert (&startPtr, item); //buat masukin ke linkedlist
	insertNode (&startPtr, item); //buat masukin ke binarytree
	
	menu();
	
	return 0;
}

void coverpage(){
	system("cls");
	int r = 10;
	rekursi(r);
	printf("Selamat Datang di Program Log Skripsi");
	rekursi(r);
	printf("\n\t\t\tKelompok 13");
	printf("\n\t\tProgram dibuat oleh : \n\tFakhri Putra Laksono - 1906384081 \n\tHarsya Adytia Nugraha - 1906384125");
	Sleep(1700);
}

void menu(){
	system("cls");
	int a;
	char j;
	char i=0;
	int npm;
	while(i!=1){
		system("cls");
		inOrder(startPtr);
		printf("MENU : \n");
		printf("1. Add Log\n");
		printf("2. Edit Log\n");
		printf("3. Delete Log\n");
		printf("4. Show Log List\n");
		printf("5. Cari Log\n");
		printf("6. Add Jadwal Bimbingan\n");
		printf("7. Show Jadwal Bimbingan\n");
		printf("8. Hapus log NPM\n");
		for (j=0; j < 70; j++){
			printf ( "-" ) ;
		}
		printf("\nSilakan memilih salah satu opsi di atas sesuai nomor opsi tersebut\n");
		printf("Opsi yang Anda pilih: ");
		scanf("%d", &a);
		
		switch(a){
			case 1 :
				addlog();
				i= 1;
				break;
				
			case 2 : 
				editlog();
				i= 1;
				break;
			
			case 3 :
				deletelog();
				i= 1;
				break;
				
			case 4 :
				loglist();
				i= 1;
				break;
			
			case 5 :
				cari();
				i= 1;
				break;
				
			case 6 : 
				jadwalbimb();
				i= 1;
				break;
				
			case 7 :
				listjadwal();
				i= 1;
				break;
				
			case 8 : 
				printf("Masukan NPM yang ingin di hapus : ");
				scanf("%d", &npm);
				delete(&startPtr, npm);
				menu();
				i=1;
				break;
				
			default:
				printf("Silakan masukkan angka sesuai opsi");
				Sleep(1500);
		}
	}
}

void addlog(){
	system("cls");

	fp=fopen("logdata.txt","ab+");
	if(getdata()==1){
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	printf("Log berhasil tersimpan\n");
	printf("Apakah ingin menambah log lagi?(Y / N):");
	if(getch()=='n')
	menu();
	else
	system("cls");
	addlog();
	}	
}

int getdata(){
	
	printf("Mohon maaf, tolong gunakan (_) sebagai spasi\n");
	printf("NPM Mahasiswa :");
	scanf("%d",&a.npm);
	
	printf("Nama Mahasiswa:");
	scanf("%s", &a.nama);
	
	printf("Judul Skripsi :");
	scanf("%s", &a.judul);
	
	printf("Progres minggu ke-:");
	scanf("%d",&a.minggu);
	
	printf("Progres :");
	scanf("%s", &a.progres);
	
	printf("Keterangan :");
	scanf("%s", &a.keterangan);
	
	return 1;
}

void editlog(){
	system("cls");
	int d;
	printf("****Edit LOG Section****\n");
	char another='y';
	while(another=='y')
	{
	system("cls");
	
	printf("Jika ingin kembali ke menu, silahkan ketik 0.\n");
	printf("Masukan NPM anda : ");
	scanf("%d",&d);
	if(d==0){
		menu();
	}
	
	fp=fopen("logdata.txt","rb+");
	while(fread(&a,sizeof(a),1,fp)==1)	{	
	
	if(checknpm(d)==0) {
	printf("LOG tersedia");
	printf("Mohon maaf, tolong gunakan (_) sebagai spasi\n");
	
	printf("NPM Mahasiswa :");
	scanf("%d",&a.npm);
	
	printf("Nama Mahasiswa:");
	scanf("%s", &a.nama);
	
	printf("Judul Skripsi :");
	scanf("%s", &a.judul);
	
	printf("Progres minggu ke-:");
	scanf("%d",&a.minggu);
	
	printf("Progres :");
	scanf("%s", &a.progres);
	
	printf("Keterangan :");
	scanf("%s", &a.keterangan);
	
	printf("\nLOG telah diubah");
	
	fseek(fp,ftell(fp)-sizeof(a),0);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	menu();
	}
}
}
}

void deletelog(){
	system("cls");
int d;
	char another='y';
	while(another=='y')
	{
	system("cls");
	printf("Masukan NPM LOG yang ingin dihapus : ");
	scanf("%d",&d);
	fp=fopen("logdata.txt","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	if(a.npm==d)
	{
	find='t';
	}
	}
	if(find!='t')
	{
	printf("NPM yang dicari tidak ada.");
	if(getch())
	menu();
	}
	if(find=='t' )
	{
	printf("Apakah ingin menghapus LOG?(Y/N):");
	if(getch()=='y')
	{
	ft=fopen("test.txt","wb+"); 
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	if(a.npm!=d)
	{
	fseek(ft,0,SEEK_CUR);
	fwrite(&a,sizeof(a),1,ft); 
	}                         
	}
	fclose(ft);
	fclose(fp);
	remove("logdata.txt");
	rename("test.txt","logdata.txt");
	fp=fopen("logdata.txt","rb+");
	if(find=='t')
	{
	printf("LOG berhasil dihapus.\n");
	printf("Apakah ingin menghapus LOG lain?(Y/N)");
	}
	}
	else
	menu();
	fflush(stdin);
	another=getch();
	}
	}
	menu();
	}
	

void loglist(){

	system("cls");
	printf("*********************************LOG List*****************************\n");

	fp=fopen("logdata.txt","rb");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	printf("NPM Mahasiswa : %d\n", a.npm);
	printf("Nama Mahasiswa: %s\n", a.nama);
	printf("Judul Skripsi : %s\n", a.judul);
	printf("Progres minggu ke-: %d\n", a.minggu);
	printf("Progres : %s\n", a.progres);
	printf("Keterangan : %s\n", a.keterangan);
	printf("\n\n");

	}
	printf("Apakah anda ingin kembali ke menu?(Y/N)");
	if(getch()=='y')
	{
	menu();
	}
	else {
		loglist();
	}
}

int checknpm(int t){
	//untuk cek npm
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.npm==t)
{
return 0; //returns 0 ; npm ada
} 
return 1; //return 1 ; npm tidak ada
}

int rekursi(int k){
	if(k==0){
		return 0;
	}
	if(0<k || k<=10){
		printf("*");
	}
	return rekursi(k-1);
}

void cari(){
	system("cls");
	int d;
	printf("****Edit LOG Section****");
	char another='y';
	while(another=='y')
	{
	system("cls");

	printf("Masukan NPM anda : ");
	scanf("%d",&d);
	
	fp=fopen("logdata.txt","rb+");
	while(fread(&a,sizeof(a),1,fp)==1)	{	
	
	if(checknpm(d)==0) {
	printf("LOG tersedia\n");
	
	printf("NPM Mahasiswa : %d\n", a.npm);
	printf("Nama Mahasiswa: %s\n", a.nama);
	printf("Judul Skripsi : %s\n", a.judul);
	printf("Progres minggu ke-: %d\n" ,a.minggu);
	printf("Progres : %s\n", a.progres);	
	printf("Keterangan : %s\n",  a.keterangan);
		printf("Apakah anda ingin kembali ke menu?(Y/N)");
	if(getch()=='y')
	{
	menu();
	}
	else {
		cari();
	}
	}
}
}
}

int getjadwal(){
	printf("Mohon maaf, tolong gunakan (_) sebagai spasi\n");
	printf("NPM Mahasiswa :");
	scanf("%d",&b.npmbimb);
	
	printf("Nama Mahasiswa:");
	scanf("%s", &b.namabimb);
	
	printf("Masukan tanggal untuk bimbingan dd/mm/yyyy\n");
	printf("Tanggal : ");
	scanf("%d", &b.tanggal);
	printf("\nBulan : ");
	scanf("%d", &b.bulan);
	printf("\nTahun : ");
	scanf("%d", &b.tahun);
	
	return 1;
}

void jadwalbimb(){
	system("cls");

	fp=fopen("logjadwal.txt","ab+");
	if(getjadwal()==1){
	fseek(fp,0,SEEK_END);
	fwrite(&b,sizeof(b),1,fp);
	fclose(fp);
	printf("Jadwal berhasil tersimpan\n");
	printf("Apakah ingin menambah jadwal lagi?(Y / N):");
	if(getch()=='n')
	menu();
	else
	system("cls");
	addlog();
	}
	
}

void listjadwal(){
	system("cls");
	printf("*********************************List Jadwal*****************************\n");

	fp=fopen("logjadwal.txt","rb");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
	printf("NPM Mahasiswa : %d\n", b.npmbimb);
	printf("Nama Mahasiswa: %s\n", b.namabimb);
	tanggal(b.tanggal, b.bulan, b.tahun);
	printf("\n");

	}
	printf("Apakah anda ingin kembali ke menu?(Y/N)");
	if(getch()=='y')
	{
	menu();
	}
	else {
		listjadwal();
	}
}
int tanggal (int u, int y, int t){
	printf("Jadwal bimbingan : %d/%d/%d\n", u, y, t);
}
void absen (ListNodePtr startPtr){
//	ListNodePtr startPtr = NULL;
//	int choice;
	int item;
	
	printf("Enter a NPM : ");
	scanf("%d", &item);
	
	insert (&startPtr, item);
	insertNode (&startPtr, item);
//	printlist(startPtr);
//	
//	sleep(5000);
	
	
//	instructions();
//	printf("?");
//	scanf("%d", &choice);
	
//	while(choice != 0){
//		switch (choice){
//			case 1 : 
//			printf("Enter a NPM : ");
//			scanf("\n%d", &item);
//			insert (&startPtr, item);
//			insertNode (&startPtr, item);
//			printlist(startPtr);
//			break;
//			
//			case 2 :
//			if(listempty(startPtr)){
//				printf("enter character to be deleted : ");
//				scanf("\n%d", item);
//				
//				if (delete(&startPtr, item)){
//					printf("%d deleted.\n", item);
//					printlist(startPtr);
//				}
//				else {
//					printf("%d not found.\n\n", item);
//				}
//			}
//			else {
//			printf("List is empty.\n\n");
//			}
//			
//			break;
//			
//			case 3 :
//				inOrder(startPtr);
////				preOrder(startPtr);
////				postOrder(startPtr);
////				printlist(startPtr);
//				
//			break;
//			
//			default :
//				printf("invalid choice.\n\n");
//				instructions();
//				break;
//		}
//		printf("?");
//		scanf("%d", &choice);
//	}
//	printf("end of run.\n");
	
//	return 0;
}

void instructions (void){
	printf("enter choice : "
	" 1 untuk masukan jadwal.\n" 
	" 2 untuk hapus jadwal.\n" 
	" 3 Print dengan tree.\n");
}

void insert(ListNodePtr *startPtr, int value){
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	
	newPtr = malloc(sizeof(ListNode));
	
	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *startPtr;
		
		while (currentPtr != NULL && value > currentPtr->data){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if(previousPtr==NULL){
			newPtr->nextPtr = *startPtr;
			*startPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
		
	}
	else {
		printf("%d not inserted", value);
	}
}

char delete(ListNodePtr *startPtr, int value){
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;
	
	if(value == (*startPtr)->data){
		tempPtr = *startPtr;
		*startPtr = (*startPtr)->nextPtr;
		free(tempPtr);
		return value;
	}
	else{
		previousPtr = *startPtr;
		currentPtr = (*startPtr)->nextPtr;
		
		while(currentPtr != NULL && currentPtr->data != value){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (currentPtr != NULL){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	return '\0';
}

int listempty(ListNodePtr startPtr){
	return startPtr == NULL;
}

void printlist (ListNodePtr startPtr){
	if (startPtr == NULL){
		printf("List Empty\n");
	}
	else {
		printf("the list is : \n");
		while(startPtr != NULL){
			printf("%d --> ", startPtr->data);
			startPtr = startPtr->nextPtr;
		}
	}
}

void insertNode(ListNodePtr *startPtr, int value){
	if(*startPtr == NULL){
		*startPtr = malloc(sizeof(ListNode));
		
		if(*startPtr != NULL){
		(*startPtr)->data = value;
		
		(*startPtr)->leftPtr = NULL;
		(*startPtr)->rightPtr = NULL;
		}
		else{
		printf("%d not inserted. No memory available\n", value);
		}
	}
	else {
		if(value <(*startPtr)->data){
			insertNode(&((*startPtr)->leftPtr), value);
		}
		else if(value >(*startPtr)->data){
			insertNode(&((*startPtr)->rightPtr), value);
		}
		else {
		}
	}
}

void inOrder(ListNodePtr startPtr){
	if (startPtr != NULL){
//		inOrder(startPtr->leftPtr);
		printf("NPM : %d --> ", startPtr->data);
//		inOrder(startPtr->rightPtr);
	}
}

