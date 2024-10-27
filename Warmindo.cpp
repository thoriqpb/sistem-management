#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int maksBaris = 1000;
const int barisDihapus = 6;

int main() {
    int masukan;
    bool programMenu = true;
    string kataSandi = "utaganteng", namaPengguna;

    cout << "\n\n\n\n\tSilahkan login terlebih dahulu!" << endl;
    cout << "\tPassword : ";
    cin >> namaPengguna;
    cin.ignore();
    cout << endl;

    if (namaPengguna != kataSandi) {
        cout << "\tError: Anda bukan admin." << endl;
        return 0;
    }
    system("cls");

    cout << "\n\n\t     Program Warmindo\n\t\tkelompok 4\n\n";
    cout << "\t\tNama anggota" << endl;
    cout << "\t1. Thoriq Putra Belligan" << endl;
    cout << "\t2. M.Dafian Saputra Sinaga" << endl;
    cout << "\t3. Farhan Rahmat" << endl;
    cout << "\t4. IDAM SHOLIKHAH" << endl << endl;
    cout << "\tTekan enter untuk melanjutkan";
    cin.ignore();

    while (programMenu) {
        system("cls");

        cout << "\n\n\tPilihan Program\n\n";
        cout << "\t1. Menampilkan Menu\n";
        cout << "\t2. Menambahkan Menu\n";
        cout << "\t3. Mengedit Menu\n";
        cout << "\t4. Menghapus Menu\n";
        cout << "\t5. Keluar Program\n\n";
        cout << "\tMasukkan Pilihan (1-5) : ";
        cin >> masukan;
        cin.ignore();
        system("cls");

        if (masukan == 1) {
            bool pilihan = true;
            char pmenu;
            int k = 0;

            ifstream berkasMasukan("warmindo.txt");
            if (!berkasMasukan.is_open()) {
                cerr << "Error saat membuka file untuk membaca.\n";
                return 1;
            }

            const int maksBaris = 1000;
            string baris[maksBaris];

            while (pilihan) {
                system("cls");

                cout << endl << endl;

                cout << "\t        Menu ke-(" << k + 1 << ")\n" << endl;

                int j = k * 6;

                for (int i = 1; i < maksBaris && getline(berkasMasukan, baris[i]); ++i);

                cout << "\tJenis Menu\t: " << baris[1 + j] << endl;
                cout << "\tNama Menu\t: " << baris[2 + j] << endl;
                cout << "\tVarian\t\t: " << baris[3 + j] << endl;
                cout << "\tHarga\t\t: " << baris[4 + j] << endl;
                cout << "\tStok\t\t: " << baris[5 + j] << endl;

                cout << "\n\tsebelumnya(b)\tselanjutnya(n)\tkembali(x)\n\n\t\t\t   ";
                cin >> pmenu;

                if (pmenu == 'n') {
                    k = (k + 1);
                } else if (pmenu == 'b') {
                    k = max(0, k - 1);
                } else if (pmenu == 'x') {
                    pilihan = false;
                }
            }

            berkasMasukan.close();

            programMenu = true;
        }
		
		else if (masukan == 2) {
            string nama, jenis, varian, harga, stok;

            cout << "\n\n\t  Menambahkan menu\n" << endl;

            cout << "\tJenis Menu\t: ";
            getline(cin, jenis);

            cout << "\tNama Menu\t: ";
            getline(cin, nama);

            cout << "\tVarian\t\t: ";
            getline(cin, varian);

            cout << "\tHarga\t\t: ";
            getline(cin, harga);

            cout << "\tStok\t\t: ";
            getline(cin, stok);

            ofstream berkasKeluar("warmindo.txt", ios::app);

            berkasKeluar << jenis << endl;
            berkasKeluar << nama << endl;
            berkasKeluar << varian << endl;
            berkasKeluar << harga << endl;
            berkasKeluar << stok << endl << endl;

            cout << "\n          Menu berhasil ditambah!\n" << endl;
            cout << "       kembali ke menu program? (y/n)\n";
            char balik;
            cin >> balik;
            if (balik != 'y') {
                system("cls");
                cout << "\n\n\tTerima Kasih telah menggunakan program warmindo!\n\n";
                return 0;
            }
        }
		
		else if (masukan == 3) {
            const string namaBerkas = "warmindo.txt";

            int nomorMenu;
            cout << "\n\tmasukkan nomor menu yang ingin diedit : ";
            cin >> nomorMenu;

            int nomorBaris = (nomorMenu - 1) * 6;

            ifstream berkasMasukan("warmindo.txt");
            if (!berkasMasukan.is_open()) {
                cerr << "Error saat membuka file untuk membaca.\n";
                return 1;
            }

            ofstream berkasSementara("sementara.txt");
            if (!berkasSementara.is_open()) {
                cerr << "Error saat membuka file sementara untuk menulis.\n";
                berkasMasukan.close();
                return 1;
            }

            string baris;

            for (int i = 0; i < nomorBaris ; ++i) {
                if (!getline(berkasMasukan, baris)) {
                    cerr << "Error: Baris yang akan diedit tidak ditemukan.\n";
                    berkasMasukan.close();
                    berkasSementara.close();
                    return 1;
                }
                berkasSementara << baris << endl;
            }

            string jenis, nama, varian, harga, stok;

            cout << "\n\tMasukkan menu baru \n\n";
            cin.ignore();
            cout << "\tJenis Menu\t: ";
            getline(cin, jenis);

            cout << "\tNama Menu\t: ";
            getline(cin, nama);

            cout << "\tVarian\t\t: ";
            getline(cin, varian);

            cout << "\tHarga\t\t: ";
            getline(cin, harga);

            cout << "\tStok\t\t: ";
            getline(cin, stok);

            berkasSementara << jenis << endl;
            berkasSementara << nama << endl;
            berkasSementara << varian << endl;
            berkasSementara << harga << endl;
            berkasSementara << stok << endl << endl;

            int hitung = 0;
            while (getline(berkasMasukan, baris)) {
                ++hitung;
                if (hitung <= 6) {
                    
                } else {
                    berkasSementara << baris << endl;
                }
            }

            berkasMasukan.close();
            berkasSementara.close();

            if (remove(namaBerkas.c_str()) != 0) {
                cerr << "Error saat menghapus file asli.\n";
                return 1;
            }
            if (rename("sementara.txt", namaBerkas.c_str()) != 0) {
                cerr << "Error saat mengganti nama file sementara.\n";
                return 1;
            }

            cout << "\n\tMenu ke-" << nomorMenu << " berhasil diedit!\n";
            cout << "\n\tkembali ke menu program? (y/n)\n";
            char balik;
            cin >> balik;
            if (balik != 'y') {
                system("cls");
                cout << "\n\n\tTerima Kasih telah menggunakan program warmindo!\n\n";
                return 0;
            }
            programMenu = true;
        }
		
		else if (masukan == 4) {
		    ifstream fileMasukan("warmindo.txt");
		    if (!fileMasukan.is_open()) {
		        cerr << "Error saat membuka file untuk membaca.\n";
		        return 1;
		    }
		
		    string baris[maksBaris];
		    int jumlahBaris = 0;
		
		    while (getline(fileMasukan, baris[jumlahBaris++]) && jumlahBaris < maksBaris);
		    fileMasukan.close();
		
		    cout << "\n\tMasukkan nomor menu yang ingin dihapus: ";
		    int nomorMenu;
		    cin >> nomorMenu;
		
		    if (nomorMenu < 1 || nomorMenu > jumlahBaris / barisDihapus) {
		        cerr << "Nomor menu tidak valid.\n";
		        return 1;
		    }
		
		    int indeksBarisDihapus = (nomorMenu - 1) * barisDihapus;
		
		    for (int i = indeksBarisDihapus; i < jumlahBaris - barisDihapus; ++i) {
		        baris[i] = baris[i + barisDihapus];
		    }
		
		    jumlahBaris -= barisDihapus;
		
		    ofstream fileKeluaran("warmindo.txt");
		    if (!fileKeluaran.is_open()) {
		        cerr << "Error saat membuka file untuk menulis.\n";
		        return 1;
		    }
		
		    for (int i = 0; i < jumlahBaris; ++i) {
		        fileKeluaran << baris[i];
		        if (i < jumlahBaris - 1) {
		            fileKeluaran << '\n';
		        }
		    }
		
		    fileKeluaran.close();
		
		    cout << "\n\t      Menu ke-" << nomorMenu << " telah dihapus!\n";
		    cout << "\n\t    Kembali ke menu program? (y/n)\n";
		    char kembali;
		    cin >> kembali;
		    if (kembali != 'y') {
		        system("cls");
		        cout << "\n\n\tTerima kasih telah menggunakan program warmindo!\n\n";
		        return 0;
		    }
		}
        
		else if (masukan == 5) {
            cout << "\n\n\tTerima Kasih telah menggunakan program warmindo!\n\n";
            return 0;
        }
        
		else {
            cout << "\n\n\tInput tidak valid!\n";
            break;
        }
    }

    return 0;
}
