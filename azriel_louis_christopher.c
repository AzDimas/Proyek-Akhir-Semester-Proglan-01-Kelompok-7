//Program Kelompok 7
//Azriel Dimas Ash-Shidiqi (2206059414)
//Christopher Satya Fredella Balakosa (2206059755)
//Louis Benedict Archie (2206025224)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pembuka.h"

struct detail{
	char username[100];
	char password[100];
	char email[100];
	char nomor[10];
};

typedef struct {
    char nama[255];
    int harga;
} data;

struct detail s[100];

int menu_utama(int, int , char*, char*, char*, char*,char*);
int signup(int, int , char*, char*, char*, char*,char*);
int cek_akun(char*, char*, char*, char*,char*);
int validasi(char*, char*, char*, char*,char*);
int login( int, int , char*, char*, char*, char*,char*);
int nusantara_food();
int western_food();
int indian_food();
void back(int , int , char* , char* , char* , char* , char* );
int confirms_food(int , int , char* , char* , char* , char* , char* );
int sum_menu();
void sorting (data makanan[], data temp, int jumlah, int sort);
void clearScreenWithSaldo();
int tambahSaldo();
void help();
int list_makanan(int, int , char* , char* ,char*,char*,char*);
void backFood(int , int , char* , char* , char* , char* , char* );

int total[3]; 
int saldo = 0;

typedef struct Node {
    char drink[50];
    int price;
    struct Node* next;
} Node;

Node* createNode(char* drink, int price) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->drink, drink);
    newNode->price = price;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* drink, int price) {
    Node* newNode = createNode(drink, price);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Daftar minuman kosong.\n");
    } else {
        Node* temp = head;
        printf("\n\n\t\t\t\t\t\tDaftar Minuman:\n");
        while (temp != NULL) {
            printf("\t\t\t\t\t\t%s - Rp %d\n", temp->drink, temp->price);
            temp = temp->next;
        }
    }
}

int buyDrink(Node** head, int *total) {
    char drink[50];
    printf("\n\n\t\t\tMasukkan nama minuman yang ingin Anda beli (perhatikan penulisan minuman): ");
    scanf(" %[^\n]s", drink);
    int drink_price = 0;

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->drink, drink) == 0) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            *total += temp->price; 
            free(temp);
            printf("\n\t\t\tAnda telah membeli minuman %s.\n", drink);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\n\n\t\t\t\t\t\tMinuman %s tidak tersedia.\n", drink);

    return drink_price;
}

int confirms_drinks(int , int , char* , char* , char* , char* , char*, int);

int main(){
	int choice, x, tema;
    int total = 0;
	char temp_name[100], temp_password1[100];
	char temp_password2[100], temp_email[100];
	char nomor_telepon[100];
	
	while(1){
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\tSilahkan pilih tema:\n\t\t\t\t\t\t\t1.Dark Mode\n\t\t\t\t\t\t\t2.Blue Mode\n\t\t\t\t\t\t\t3.Light Mode\n");
	printf("\t\t\t\t\t\t\tPilihan anda: ");
	tema = getch();
	if(tema == '1') {
		system("CLS");
		break;
		}
	else if(tema =='2') {
		system("color b0");
		system("CLS");
		break;
		}
	else if(tema == '3'){
		system("COLOR FC") ;
		system("CLS");
		break;
		}
	else {
		printf("\n\n\t\t\t\t\t\t\tPilihan anda tidak valid !") ;
		Sleep(1000) ;
		system("CLS");
		}
	}
    intro();
	welcome();
	system("cls");
	
	menu_utama(choice, x, temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);

	return 0;
}

int menu_utama(int choice,int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
	while(1) {
    printf("\n\n\n\n\n\n\t\t\t\t\t********************Selamat Datang****************");
		printf("\n\n\t\t\t\t\t1)Sign up\n");
		printf("\t\t\t\t\t2)Log in\n\t\t\t\t\t3)Keluar\n\n");
		printf("\t\t\t\t\tMasukkan Pilihan Anda:");
		choice = getch();
		switch (choice) {
		case '1': {
            system("CLS");
			signup(choice, x, temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
			break;
		}
		case '2': {
            system("CLS");
			login(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
			break;
		}
		case '3': {
            system("CLS");
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t**********************Terima Kasih*******************\n");
			exit(0);
		}
		default: {
			printf("\n\n\t\t\t\t\tTolong masukkan input yang valid \n");
            Sleep(1000);
			break;
		}
	}
    system("CLS");
    }
}

int signup(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
	system("CLS");
	printf("\n\n\n\n\n\n\t\t\t\t\t************Silakan Daftarkan Akun Anda*************\n");
	printf("\t\t\t\t\tMasukkan Nama Anda: ");
	scanf(" %[^\n]", temp_name);

	printf("\t\t\t\t\tMasukkan Email Anda: ");
	scanf("%s", temp_email);

	printf("\t\t\t\t\tMasukkan Kata Sandi: ");
	scanf("%s", temp_password1);

	printf("\t\t\t\t\tKonfirmasi Kata Sandi:");
	scanf("%s", temp_password2);

	printf("\t\t\t\t\tMasukkan Nomor Telepon: ");
	scanf("%s", nomor_telepon);

	x = validasi(temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
	if (x == 1){
		cek_akun(temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
		login(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
	}
}

int validasi(char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
	int success= 0, small = 0,numbers = 0,caps= 0, count = 0;
	int flag =1 ;
	int i;
	for (i = 0; temp_name[i] != '\0'; i++) {
		if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
			|| (temp_name[i] >= 'A'
				&& temp_name[i] <= 'Z'|| temp_name[i] == 32))) {
			printf("\n\n\t\t\t\t\tMasukkan Nama Yang Valid\n");
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		count = 0;

	
		for (i = 0;temp_email[i] != '\0'; i++) {
			if (temp_email[i] == '@'|| temp_email[i] == '.')
				count++;
		}
		if (count >= 2&& strlen(temp_email) >= 5) {
			if (!strcmp(temp_password1,
						temp_password2)) {
				if (strlen(temp_password1) >= 8
					&& strlen(temp_password1) <= 12) {
					for (i = 0; temp_password1[i] != '\0';
						i++) {
						if (temp_password1[i] >= 'A'
							&& temp_password1[i] <= 'Z')
							caps++;
						else if (temp_password1[i] >= 'a'
								&& temp_password1[i]
										<= 'z')
							small++;
						else if (temp_password1[i] >= '0'
								&& temp_password1[i]
										<= '9')
							numbers++;
					}
					if (caps >= 0 || small >= 0
						|| numbers >= 0 ) {
							if (strlen(nomor_telepon) == 12) {
								for (i = 0; i < 12; i++) {
									if (nomor_telepon[i]
											>= '0'
										&& nomor_telepon[i]
											<= '9') {
										success = 1;
									}
									else {
										printf("\n\n\t\t\t\t\tTolong Masukkan Nomor Telepon yang Valid\n\n");
										return 0;
										break;
									}
								}

								if (success == 1)
									return 1;
							}
							else {
								printf("\n\n\t\t\t\t\tMasukkan Nomor Telepon 12 Digit\n");
								return 0;
							}
					}
					else {
						printf("\n\n\t\t\t\t\tMasukkan Kata Sandi yang Lebih Kuat");
						return 0;
					}
				}
				else {
					printf("\n\n\t\t\t\t\tKata Sandi Terlalu SIngkat\nSilakan Masukkan Kata Sandi Minimal 8-12 Kata\n\n");
					return 0;
				}
			}
			else {
				printf("\n\n\t\t\t\t\tPassword Tidak Cocok\n\n");
				return 0;
			}
		}
		else {
			printf("\n\n\t\t\t\t\tMasukkan E-Mail yang Valid\n\n");
				
			return 0;
		}
	}
}

int cek_akun(char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
	int i;
	int j= 0;
	for (i = 0; i < 100; i++) {
	
		if (!(strcmp(temp_email, s[i].email)
			&& strcmp(temp_password1,
						s[i].password))) {
			printf("\n\n\t\t\t\t\tAkun Sudah Terdaftar. Silakan Log in Akun Anda\n\n");
			main();
			break;
		}
	}

	if (i == 100) {
		strcpy(s[j].username, temp_name);
		strcpy(s[j].password, temp_password1);
		strcpy(s[j].email, temp_email);
		strcpy(s[j].nomor, nomor_telepon);
		j++;
		printf("\n\n\n\t\t\t\t\tAkun Berhasil di Buat!\n\n");
	}
}

int login(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
    int pilih ,i;
	system("CLS");
	printf("\n\n\t\t\t\t\t**************Welcome to Login page ****************\n\n");
	printf("\t\t\t\t\tMasukkan E-Mail: ");
	scanf("%s", temp_email);
	printf("\t\t\t\t\tMasukkan Password: ");
	scanf("%s", temp_password1);
	system("CLS");
	for (i = 0; i < 100; i++) {
		if (!strcmp(s[i].email, temp_email)) {
			if (!strcmp(s[i].password, temp_password1)) {
                while(1){
				printf("\n\nSelamat Datang %s, ", s[i].username);
                while(1){
                clearScreenWithSaldo(saldo);
				printf("\n\t\t\t\t\t\tAnda Berhasil Masuk!\n\n");
				printf("\t\t\t\t\t\t1) Top up saldo\n");
				printf("\t\t\t\t\t\t2) Daftar makanan\n");
				printf("\t\t\t\t\t\t3) Pesan minuman\n");
				printf("\t\t\t\t\t\t4) Help\n");
				printf("\t\t\t\t\t\t5) Menu Utama\n");
				printf("\t\t\t\t\t\tSilakan Masukkan Pilihan Anda: ");
                pilih = getch();
                switch(pilih){
                    case '1':{
                    	system("CLS");
                        tambahSaldo(saldo);
						back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    case '2':{
						system("CLS");
                        list_makanan(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
                        back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
                    }
                    case '3':{
                    	system("CLS");
                    	drinks(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                    	back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
					}
                    case '4':{
						system("CLS");
                        help();
                        back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
                    }
                    case '5':{
						system("CLS");
                        menu_utama(choice, x, temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    default :{
                    	printf("\n\n\t\t\t\t\tTolong Masukkan Pilihan yang Benar !\n");
                        Sleep(1000);
						break;
					}
                }
            }
                system("CLS");
                }
			}
			else {
				system("CLS");
				printf("\n\n\t\t\t\t\tPassword Salah! ");
				printf("\t\t\t\t\tTolong Masukkan Password yang Benar\n\n");
				menu_utama(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
				break;
			}
		}
		else {
			system("CLS");
			printf("\n\n\t\t\t\t\tAkun Tidak Terdaftar!\n\t\t\t\t\tSilakan Daftarkan Akun Terlebih Dahulu\n\n ");
			sleep(1);
			system("CLS");
			menu_utama(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
			break;
		}
	}
}

int western_food(){
	int sort, jumlah = 8;
    data makanan[jumlah];
    data temp;
    
    do {
    clearScreenWithSaldo(saldo);
    printf("\n\n\t\t\t\t\t ~~~~~ Pilihan Sorting ~~~~~\n");
    printf("\n\t\t\t\t\t1. Urutkan berdasarkan nama makanan secara ascending\n");
    printf("\t\t\t\t\t2. Urutkan berdasarkan nama makanan secara descending\n");
    printf("\t\t\t\t\t3. Urutkan berdasarkan harga secara ascending\n");
    printf("\t\t\t\t\t4. Urutkan berdasarkan harga secara descending\n");
        printf("\t\t\t\t\tPilihlah salah satu! (1, 2, 3, atau 4): ");
        sort = getch();
        system("CLS");
    } while (sort < '1' || sort > '4');
    
    FILE *fptr;
    fptr = fopen("western_food.txt", "r");
    
    int i = 0;
    while (fscanf(fptr, "%s %d", makanan[i].nama, &makanan[i].harga) == 2) {
        i++;
    }
    clearScreenWithSaldo(saldo);
    printf("\nSebelum diurutkan:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %s - Rp %d\n", i+1, makanan[i].nama, makanan[i].harga);
    }
    
    sorting(makanan, temp, jumlah, sort);
    
    printf("\nSetelah diurutkan:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %s - Rp %d\n", i+1, makanan[i].nama, makanan[i].harga);
    }
    
    fclose(fptr);
    
    fptr = fopen("western_food_sorted.txt", "w");
    for(i = 0 ; i<8 ; i++){
   	fprintf(fptr, "%s   %d\n", makanan[i].nama, makanan[i].harga);
    }

    fclose(fptr);

    fptr = fopen("western_food_sorted.txt", "r");
    
    printf("Masukkan nomor makanan yang Anda pilih (pisahkan dengan spasi jika lebih dari satu) dan tekan enter: \n");
	char choices[255]; 
    scanf(" %[^\n]s", choices);

	int choice;
	char buffer[255];
	
	fseek(fptr, 0, SEEK_SET);
	char *choice_ptr = strtok(choices, " "); 
	while (choice_ptr != NULL){
    choice = atoi(choice_ptr);
    i++;
    int j = 0;
    fseek(fptr, 0, SEEK_SET);
    while (fgets(buffer, 255, fptr)) {
        j++;
        if (j == choice) {
            sscanf(buffer, "%s %d", makanan[i].nama, &makanan[i].harga);
            printf("%s - Rp %d\n", makanan[i].nama, makanan[i].harga);
            total[0] += makanan[i].harga; // Menambahkan harga ke total
            break;
        	}
    	}
    choice_ptr = strtok(NULL, " "); 
	}	

	printf("Total harga: Rp %d\n", total[0]); 

	fclose(fptr);
	Sleep(3000);
	
	return total[0];
}

int indian_food(){
	int sort, jumlah = 8;
    data makanan[jumlah];
    data temp;
    
    do {
    clearScreenWithSaldo(saldo);
    printf("\n\n\t\t\t\t\t ~~~~~ Pilihan Sorting ~~~~~\n");
    printf("\n\t\t\t\t\t1. Urutkan berdasarkan nama makanan secara ascending\n");
    printf("\t\t\t\t\t2. Urutkan berdasarkan nama makanan secara descending\n");
    printf("\t\t\t\t\t3. Urutkan berdasarkan harga secara ascending\n");
    printf("\t\t\t\t\t4. Urutkan berdasarkan harga secara descending\n");
        printf("\t\t\t\t\tPilihlah salah satu! (1, 2, 3, atau 4): ");
        sort = getch();
        system("CLS");
    } while (sort < '1' || sort > '4');
    
    FILE *fptr;
    fptr = fopen("indian_food.txt", "r");
    
    int i = 0;
    while (fscanf(fptr, "%s %d", makanan[i].nama, &makanan[i].harga) == 2) {
        i++;
    }
    clearScreenWithSaldo(saldo);
    printf("\nSebelum diurutkan:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %s - Rp %d\n", i+1, makanan[i].nama, makanan[i].harga);
    }
    
    sorting(makanan, temp, jumlah, sort);
    
    printf("\nSetelah diurutkan:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %s - Rp %d\n", i+1, makanan[i].nama, makanan[i].harga);
    }
    
    fclose(fptr);
    
    fptr = fopen("indian_food_sorted.txt", "w");
    for(i = 0 ; i<8 ; i++){
   	fprintf(fptr, "%s   %d\n", makanan[i].nama, makanan[i].harga);
    }

    fclose(fptr);

    fptr = fopen("indian_food_sorted.txt", "r");
    
    printf("Masukkan nomor makanan yang Anda pilih (pisahkan dengan spasi jika lebih dari satu) dan tekan enter: \n");
	char choices[255]; 
    scanf(" %[^\n]s", choices);

	int choice;
	char buffer[255];
	
	fseek(fptr, 0, SEEK_SET);
	char *choice_ptr = strtok(choices, " "); 
	while (choice_ptr != NULL){
    choice = atoi(choice_ptr);
    i++;
    int j = 0;
    fseek(fptr, 0, SEEK_SET);
    while (fgets(buffer, 255, fptr)) {
        j++;
        if (j == choice) {
            sscanf(buffer, "%s %d", makanan[i].nama, &makanan[i].harga);
            printf("%s - Rp %d\n", makanan[i].nama, makanan[i].harga);
            total[1] += makanan[i].harga; // Menambahkan harga ke total
            break;
        	}
    	}
    choice_ptr = strtok(NULL, " "); 
	}	

	printf("Total harga: Rp %d\n", total[1]); 

	fclose(fptr);
	Sleep(3000);
	
	return total[1];
}

int nusantara_food(){
	int sort, jumlah = 8;
    data makanan[jumlah];
    data temp;
    
    do {
    clearScreenWithSaldo(saldo);
   	printf("\n\n\t\t\t\t\t ~~~~~ Pilihan Sorting ~~~~~\n");
    printf("\n\t\t\t\t\t1. Urutkan berdasarkan nama makanan secara ascending\n");
    printf("\t\t\t\t\t2. Urutkan berdasarkan nama makanan secara descending\n");
    printf("\t\t\t\t\t3. Urutkan berdasarkan harga secara ascending\n");
    printf("\t\t\t\t\t4. Urutkan berdasarkan harga secara descending\n");
        printf("\t\t\t\t\tPilihlah salah satu! (1, 2, 3, atau 4): ");
        sort = getch();
        system("CLS");
    } while (sort < '1' || sort > '4');
    
    FILE *fptr;
    fptr = fopen("nusantara_food.txt", "r");
    
    int i = 0;
    while (fscanf(fptr, "%s %d", makanan[i].nama, &makanan[i].harga) == 2) {
        i++;
    }
    clearScreenWithSaldo(saldo);
    printf("\nSebelum diurutkan:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %s - Rp %d\n", i+1, makanan[i].nama, makanan[i].harga);
    }
    
    sorting(makanan, temp, jumlah, sort);
    
    printf("\nSetelah diurutkan:\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d. %s - Rp %d\n", i+1, makanan[i].nama, makanan[i].harga);
    }
    
    fclose(fptr);
    
    fptr = fopen("nusantara_food_sorted.txt", "w");
    for(i = 0 ; i<8 ; i++){
   	fprintf(fptr, "%s   %d\n", makanan[i].nama, makanan[i].harga);
    }

    fclose(fptr);

    fptr = fopen("nusantara_food_sorted.txt", "r");
    
    printf("Masukkan nomor makanan yang Anda pilih (pisahkan dengan spasi jika lebih dari satu) dan tekan enter: \n");
	char choices[255]; 
    scanf(" %[^\n]s", choices);

	int choice;
	char buffer[255];
	
	fseek(fptr, 0, SEEK_SET);
	char *choice_ptr = strtok(choices, " "); 
	while (choice_ptr != NULL){
    choice = atoi(choice_ptr);
    i++;
    int j = 0;
    fseek(fptr, 0, SEEK_SET);
    while (fgets(buffer, 255, fptr)) {
        j++;
        if (j == choice) {
            sscanf(buffer, "%s %d", makanan[i].nama, &makanan[i].harga);
            printf("%s - Rp %d\n", makanan[i].nama, makanan[i].harga);
            total[2] += makanan[i].harga; // Menambahkan harga ke total
            break;
        	}
    	}
    choice_ptr = strtok(NULL, " "); 
	}	

	printf("Total harga: Rp %d\n", total[2]); 

	fclose(fptr);
	Sleep(3000);
	
	return total[2];
}

void back(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
	system("CLS");
    int pilih;
    while(1){
    			clearScreenWithSaldo(saldo);
    			printf("\n\t\t\t\t\t\tMenu\n");
    			printf("\t\t\t\t\t\t1) Top up saldo\n");
				printf("\t\t\t\t\t\t2) Daftar makanan\n");
				printf("\t\t\t\t\t\t3) Pesan minuman\n");
				printf("\t\t\t\t\t\t4) Help\n");
				printf("\t\t\t\t\t\t5) Menu Utama\n");
				printf("\t\t\t\t\t\tSilakan Masukkan Pilihan Anda: ");
                pilih = getch();
                switch(pilih){
                    case '1':{
                    	system("CLS");
                        saldo= tambahSaldo (saldo);
						back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    case '2':{
						system("CLS");
                        list_makanan(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
                        back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
                    }
                    case '3':{
						system("CLS");
                        drinks(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
                        back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
                    }
                    case '4':{
						system("CLS");
                        help();
                        back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    case '5':{
                        system("CLS");
                        menu_utama(choice, x, temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                        break; 
                    }
                    default :{
                    	printf("\n\n\t\t\t\t\t\tTolong Masukkan Pilihan yang Benar !\n");
                        Sleep(1000);
						break;
					}
                system("CLS");
            }
        }
}

int confirms_food(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
system("CLS");
int ch, confirm;
	while(1){
	clearScreenWithSaldo(saldo);
	printf("Total pembelian anda: Rp %d", sum_menu());
    printf("\n\nApakah Anda Ingin Mengonfirmasi Pembelian? (1 = Ya / 2 = Tidak): ");
    ch = getch();
    if (ch == '1') {
    	if(sisa_saldomakanan() < 0){
    		printf("\nMaaf Saldo Anda Kurang\n\n");
    		printf("Silakan isi saldo terlebih dahulu\n");
    		printf("Press Any Key To Continue......");
    		getch();
    		tambahSaldo(saldo);
    		confirms_food(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
		}
		else{
			printf("\nSisa Saldo anda: Rp %d", sisa_saldomakanan());
        printf("\n\nTerima Kasih Untuk Pembelian Anda!!\n\n");
        printf("Makanan Sedang Dalam Perjalanan. ");
    }
		exit(0);
    }
    else if (ch == '2') {
    	system("CLS");
    	while(1){
        printf("Apakah Anda Mau Keluar = 1 ");
        printf("Atau Kembali Ke Layar Utama = 0");
        printf("\nPilihan anda: ");
        confirm = getch();
        if (confirm == '1') {
            printf("\n\nPesanan Anda Dibatalkan");
            printf("\nTerima Kasih Sudah Menggunakan Aplikasi Kami!\n");
            exit(0);
        }
        else if (confirm == '0'){
            printf("\n\nTerima Kasih\n\n");
            login(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
        }
        else{
        	printf("Tolong Masukkan Opsi yang Benar !");
        	Sleep(1000);
		}
		system("CLS");
        }
    }
    else {
        printf("Tolong Masukkan Opsi yang Benar !");
        Sleep(1000);
    }
    system("CLS");
    }
}

int confirms_drinks(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[], int total){
system("CLS");
Node* head = NULL;
int ch, confirm;
	while(1){
	clearScreenWithSaldo(saldo);
	printf("Total pembelian anda: Rp %d", total);
    printf("\n\nApakah Anda Ingin Mengonfirmasi Pembelian? (1 = Ya / 2 = Tidak): ");
    ch = getch();
    if (ch == '1') {
    	if(sisa_saldominuman(total) < 0){
    		printf("\nMaaf Saldo Anda Kurang\n\n");
    		printf("Silakan isi saldo terlebih dahulu\n");
    		printf("Press Any Key To Continue......");
    		getch();
    		tambahSaldo(saldo);
    		confirms_drinks(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon, total);
		}
		else{
			printf("Sisa Saldo anda: Rp %d", sisa_saldominuman(total));
		printf("\nApa Anda Ingin Membeli Lagi? (1 = Ya / 2 = Tidak):\n");
		ch = getch();
		if (ch == '1'){
			back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
		}
		else if (ch == '2'){
        printf("\n\nTerima Kasih Untuk Pembelian Anda!!\n\n");
        printf("Minuman Sedang Dalam Perjalanan. ");
    	}
    }
		exit(0);
    }
    else if (ch == '2') {
    	system("CLS");
    	while(1){
        printf("Apakah Anda Mau Keluar = 1 ");
        printf("Atau Kembali Ke Layar Utama = 0");
        printf("\nPilihan anda: ");
        confirm = getch();
        if (confirm == '1') {
            printf("\n\nPesanan Anda Dibatalkan");
            printf("\nTerima Kasih Sudah Menggunakan Aplikasi Kami!\n");
            exit(0);
        }
        else if (confirm == '0'){
            printf("\n\nTerima Kasih\n\n");
            login(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
        }
        else{
        	printf("Tolong Masukkan Opsi yang Benar !");
        	Sleep(1000);
		}
		system("CLS");
        }
    }
    else {
        printf("\n\nTolong Masukkan Opsi yang Benar !");
        Sleep(1000);
    }
    system("CLS");
    }
}

int sum_menu(){
	int i;
	int total_menu = 0;
	printf("\n");
	#pragma omp parallel for schedule (static) num_threads(omp_get_max_threads())
	for(i=0; i< 3; i++){
		#pragma omp critical
	total_menu += total[i];
	printf("Terjadi penambahan total pembelian sebesar %d, dalam thread %d\n", total[i], omp_get_thread_num());
	}
		
	return total_menu;
}

void sorting (data makanan[], data temp, int jumlah, int sort){
    int  j;
    if (jumlah == 0) {
        return ;
    }
        for (j = 0; j < jumlah - 1; j++) {
            switch (sort) {
                case '1':
                    if (strcmp(makanan[j].nama, makanan[j+1].nama) > 0) {
                        temp= makanan[j];
                        makanan[j] = makanan[j+1];
                        makanan[j+1] = temp;
                    }
                    break;
                case '2':
                    if (strcmp(makanan[j].nama, makanan[j+1].nama) < 0) {
                        temp = makanan[j];
                        makanan[j] = makanan[j+1];
                        makanan[j+1] = temp;
                    }
                    break;
                case '3':
                    if (makanan[j].harga > makanan[j+1].harga) {
                        temp = makanan[j];
                        makanan[j] = makanan[j+1];
                        makanan[j+1] = temp;
                    }
                    break;
                case '4':
                    if (makanan[j].harga < makanan[j+1].harga) {
                        temp = makanan[j];
                        makanan[j] = makanan[j+1];
                        makanan[j+1] = temp;
                    }
                    break;
            }
        }
    sorting (makanan, temp, jumlah - 1, sort) ;
}

void clearScreenWithSaldo() {
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\tSaldo Anda:%d\n", saldo);
}

int tambahSaldo() {
    clearScreenWithSaldo(saldo);
    int tambahan;
    printf("\n\t\t\t\t\tMasukkan jumlah tambahan saldo: ");
    scanf("%d", &tambahan);
    saldo += tambahan;
    clearScreenWithSaldo(saldo);
    return saldo;
}

void help(){
	int c;

	printf("\n\n\n\n\t\t\t\tPanduan menggunakan program\n");
	printf("\t\t\t\t1. Silakan top up saldo jika ingin membeli makanan\n");
	printf("\t\t\t\t2. Setelah top up, silakan beli makanan atau minuman yang diinginkan\n");
	printf("\t\t\t\t3. Konfirmasi pembelian, lalu lakukan pembayaran\n\n\n");
    printf("\t\t\t\tPress 1 to continue...\n");
    while ((c = getch()) != '1') {
    }
}

int list_makanan(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[] ){
	int pilih;
				while(1){
				clearScreenWithSaldo(saldo);
				printf("\n\t\t\t\t\t\tKami Menyediakan Makanan :\n ");
				printf("\t\t\t\t\t\t1) Western Food\n ");
				printf("\t\t\t\t\t\t2) Indian Food\n ");
				printf("\t\t\t\t\t\t3) Nusantara\n ");
                printf("\t\t\t\t\t\t4) Back\n\n");
				printf("\t\t\t\t\t\tSilakan Masukkan Pilihan Anda: ");
                pilih = getch();
                switch(pilih){
                    case '1':{
                    	system("CLS");
                        western_food();
						backFood(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    case '2':{
						system("CLS");
                        indian_food();
                        backFood(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
                    }
                    case '3':{
						system("CLS");
                        nusantara_food();
                        backFood(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
                    }
                    case '4':{
						system("CLS");
                        back(choice, x, temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    default :{
                    	printf("\n\n\t\t\t\t\t\tTolong Masukkan Pilihan yang Benar !\n");
                        Sleep(1000);
						break;
					}
                }
            }
}

void backFood(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
	system("CLS");
    int pilih;
    while(1){
    			clearScreenWithSaldo(saldo);
    			printf("\n\t\t\t\t\t\tKami Menyediakan Makanan : \n");
				printf("\t\t\t\t\t\t1) Western Food\n ");
				printf("\t\t\t\t\t\t2) Indian Food\n ");
				printf("\t\t\t\t\t\t3) Nusantara\n ");
                printf("\t\t\t\t\t\t4) Confirm\n\n");
				printf("\t\t\t\t\t\tSilakan Masukkan Pilihan Anda:");
                pilih = getch();
                switch(pilih){
                    case '1':{
                    	system("CLS");
                        western_food();
						backFood(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    case '2':{
						system("CLS");
                        indian_food();
						backFood(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                        break;
                    }
                    case '3':{
						system("CLS");
                        nusantara_food();
                        backFood(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
						break;
                    }
                    case '4':{
						confirms_food(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon);
                    	break;
                    }
                    default :{
                    	printf("\n\n\t\t\t\t\t\tTolong Masukkan Pilihan yang Benar !\n");
                        Sleep(1000);
                        system("CLS");
						break;
				}
				system("CLS");
            }
        }
}

int drinks(int choice, int x, char temp_name[], char temp_password1[],char  temp_password2[],char temp_email[],char nomor_telepon[]){
    Node* head = NULL;  // Inisialisasi linked list kosong

    // Menambahkan beberapa minuman ke dalam linked list
    addNode(&head, "Teh Manis", 5000);
    addNode(&head, "Kopi Susu", 7000);
    addNode(&head, "Es Jeruk", 6000);
    addNode(&head, "Alpukat Kocok", 10000);
    addNode(&head, "Air Mineral", 2000);
	addNode(&head, "Soda Gembira", 8000);

    int pilih;
    int total = 0;  // Variabel untuk menyimpan total harga minuman yang dipilih
    char drink[50];

    clearScreenWithSaldo(saldo);
	
    do {
        printf("\n\n\t\t\t\t\t\tMenu:\n");
        printf("\t\t\t\t\t\t1. Lihat daftar minuman\n");
        printf("\t\t\t\t\t\t2. Beli minuman\n");
        printf("\t\t\t\t\t\t3. Konfirmasi pembelian\n");
        printf("\t\t\t\t\t\t4. Kembali ke menu\n");
        printf("\t\t\t\t\t\tPilihan Anda: ");
        pilih = getch();

        switch (pilih) {
            case '1':
                system("CLS");
                printList(head);
                break;
            case '2': 
                system("CLS");
                printList(head);
                buyDrink(&head, &total);
                break;
            case '3':
                system("CLS");
                confirms_drinks(choice,x,temp_name,temp_password1, temp_password2, temp_email, nomor_telepon, total);
                break;
            case '4':
                system("CLS");
                back(choice, x, temp_name, temp_password1, temp_password2, temp_email, nomor_telepon);
                break;
            default:
                printf("\n\n\t\t\t\t\t\tPilihan tidak valid. Silakan coba lagi.\n");
                Sleep(1000);
                system("CLS");
                break;
        }
    } while (1);

    Node* temp = head;
    while (temp != NULL) {
        Node* curr = temp;
        temp = temp->next;
        free(curr);
    }
}

int sisa_saldomakanan(){
   int sisa_saldo = 0;

   sisa_saldo = saldo - sum_menu();

   return sisa_saldo;
}

int sisa_saldominuman(int total){
    int sisa_saldo = 0;
    
    sisa_saldo = saldo - total;

   return sisa_saldo;
}
