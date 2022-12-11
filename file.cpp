//tugas besar sistem pendukung keputusan
//faisal faiz 60900121004
//aris munandar nim nda tau s

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
int pilihan;
void menu(){
	system("cls");
	cout <<"=============================================|"<<endl;
	cout <<"|Nama kelompok : Faisal Faiz  ( 60900121004 )|"<<endl;
	cout <<"=============================================|"<<endl;
    cout <<"| berikut metode sistem pendukung keputusan  |"<<endl;
    cout <<"| [1].metode AHP                             |"<<endl;
    cout <<"| [2].metode SAW                             |"<<endl;
    cout <<"| [3].metode WP                              |"<<endl;
    cout <<"| [3].keluar                                 |"<<endl;
    cout <<"=============================================|"<<endl;
    cout <<"| pilih metode yang di inginkan : ";
}

void ahp()
{
    cout << "   Sistem Pendukung Keputusan dengan Metode AHP" << endl;
    cout<<endl;
    // Menentukan Data Kriteria
    cout << "Tahap 1. Menentukan Data Kriteria" << endl;
    cout << "Masukkan jumlah kriteria yang diinginkan: ";
    int jumlahKriteria;
    cin >> jumlahKriteria;
    
    vector<string> namaKriteria;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        cout << "Masukkan nama kriteria ke-" << i+1 << ": ";
        string nama;
        cin >> nama;
        namaKriteria.push_back(nama);
    }
    cout << "Data kriteria berhasil ditentukan." << endl << endl;
    
    // Menentukan Nilai Kriteria
    cout << "Tahap 2. Menentukan Nilai Kriteria" << endl;
    vector<vector<double>> nilaiKriteria(jumlahKriteria, vector<double>(jumlahKriteria));
    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int j = 0; j < jumlahKriteria; j++)
        {
            if (i == j)
            {
                nilaiKriteria[i][j] = 1;
            }
            else
            {
                cout << "Berapa nilai yang pantas untuk " << namaKriteria[i] << " dibandingkan dengan " << namaKriteria[j] << "? ";
                double nilai;
                cin >> nilai;
                nilaiKriteria[i][j] = nilai;
            }
        }
    }
    cout << "Nilai kriteria berhasil ditentukan." << endl << endl;
    
    // Memeriksa Konsistensi Hierarki
    cout << "Tahap 3. Memeriksa Konsistensi Hierarki" << endl;
    cout << "Menghitung nilai konsistensi..." << endl;
    vector<double> jumlahKolom(jumlahKriteria);
    for (int i = 0; i < jumlahKriteria; i++)
    {
        double jumlahBaris = 0;
        for (int j = 0; j < jumlahKriteria; j++)
        {
            jumlahBaris += nilaiKriteria[i][j];
        }
        jumlahKolom[i] = jumlahBaris;
    }
    
    vector<double> rataKolom(jumlahKriteria);
    double jumlahRataKolom = 0;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        double rataBaris = jumlahKolom[i] / jumlahKriteria;
        rataKolom[i] = rataBaris;
        jumlahRataKolom += rataBaris;
    }
    
    double lambdaMax = jumlahRataKolom / jumlahKriteria;
    double ci = (lambdaMax - jumlahKriteria) / (jumlahKriteria - 1);
    double cr = ci / 0.58;
    cout << "Nilai konsistensi (CR) = " << cr << endl;
    if (cr < 0.1)
    {
        cout << "Konsistensi hierarki diterima." << endl;
    }
    else
    {
        cout << "Konsistensi hierarki ditolak." << endl;
    }
    cout << "Program selesai." << endl;
    
    system("cls");
    system("pause");
}

void saw()
{
    string kriteria[3];
    double bobot[3];
    double nilai[3][3];
    double hasil[3][3];

    // Input Kriteria
      cout<<endl;
    cout <<"sistem pendukung keputusan metode saw "<<endl;
    cout << "Masukkan Kriteria : " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Kriteria " << i + 1 << " : ";
        cin >> kriteria[i];
    }

    // Input Bobot
    cout << "Masukkan Bobot : " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Bobot " << i + 1 << " : ";
        cin >> bobot[i];
    }

    // Input Nilai
    cout << "Masukkan Nilai : " << endl;
    for (int i = 0; i < 3; i++) {
        cout << kriteria[i] << " : " << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Nilai " << j + 1 << " : ";
            cin >> nilai[i][j];
        }
    }

    // Hitung Nilai Akhir
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = nilai[i][j] * bobot[j];
        }
    }

    // Tampilkan Nilai Akhir
    cout << endl << "Nilai Akhir :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    // Hitung Nilai Total
    double total[3] = { 0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            total[i] += hasil[i][j];
        }
    }

    // Tampilkan Nilai Total
    cout << endl << "Nilai Total :" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Total " << i + 1 << " : " << total[i] << endl;
    }

    // Urutkan Nilai Total
    vector<pair<double, int>> v;
    for (int i = 0; i < 3; i++) {
        v.push_back({ total[i], i });
    }

    sort(v.rbegin(), v.rend());

    // Tampilkan Hasil Ranking
    cout << endl << "Hasil Ranking :" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Ranking " << i + 1 << " : " << v[i].second + 1 << endl;
    }

    system("pause");
}
void wp(){
    //Inisialisasi Variabel
    int jumlahKriteria, jumlahAlternatif;

    //Menentukan Data Kriteria
    cout <<"siste pendukung keputusan metode WP"<<endl;
      cout<<endl;
    cout << "Masukkan Jumlah Kriteria : ";
    cin >> jumlahKriteria;

    //Membuat Array untuk Kriteria
    vector< string > namaKriteria;
    vector< int > nilaiKriteria;

    for (int i = 0; i < jumlahKriteria; i++)
    {
        string nama;
        int nilai;

        cout << "Masukkan Nama Kriteria " << i + 1 << " : ";
        cin >> nama;
        cout << "Masukkan Nilai Kriteria " << i + 1 << " : ";
        cin >> nilai;
        namaKriteria.push_back(nama);
        nilaiKriteria.push_back(nilai);
    }

    //Menentukan Data Alternatif
    cout << "Masukkan Jumlah Alternatif : ";
    cin >> jumlahAlternatif;

    //Membuat Array untuk Alternatif
    vector< string > namaAlternatif;
    vector< vector< int > > nilaiAlternatif;

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        string nama;
        vector< int > alternatif;

        cout << "Masukkan Nama Alternatif " << i + 1 << " : ";
        cin >> nama;

        for (int j = 0; j < jumlahKriteria; j++)
        {
            int nilai;

            cout << "Masukkan Nilai Alternatif " << i + 1 << " untuk Kriteria " << j + 1 << " : ";
            cin >> nilai;
            alternatif.push_back(nilai);
        }

        nilaiAlternatif.push_back(alternatif);
        namaAlternatif.push_back(nama);
    }

    //Menentukan Bobot Kriteria
    vector< double > bobotKriteria;

    for (int i = 0; i < jumlahKriteria; i++)
    {
        double bobot;

        cout << "Masukkan Bobot Kriteria " << i + 1 << " : ";
        cin >> bobot;
        bobotKriteria.push_back(bobot);
    }

    //Menentukan Vektor V
    cout << "\nHasil Vektor V : \n";
    cout << setw(10) << "Alternatif";

    for (int i = 0; i < jumlahKriteria; i++)
    {
        cout << setw(15) << namaKriteria[i];
    }

    cout << setw(15) << "Vektor V" << endl;

    vector< double > vektorV;

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        double total = 0;

        cout << setw(10) << namaAlternatif[i];

        for (int j = 0; j < jumlahKriteria; j++)
        {
            double nilai = nilaiAlternatif[i][j];
            double bobot = bobotKriteria[j];
            double hasil = nilai * bobot;

            cout << setw(15) << hasil;

            total += hasil;
        }

        cout << setw(15) << total << endl;
        vektorV.push_back(total);
    }

    //Menentukan Ranking Nilai Vektor V
    cout << "\nRanking Nilai Vektor V : \n";
    cout << setw(10) << "Rank";
    cout << setw(10) << "Vektor V";
    cout << setw(10) << "Alternatif" << endl;

    vector< pair< double, string > > ranking;

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        pair< double, string > pasangan;
        pasangan.first = vektorV[i];
        pasangan.second = namaAlternatif[i];
        ranking.push_back(pasangan);
    }

    sort(ranking.begin(), ranking.end());
    reverse(ranking.begin(), ranking.end());

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        cout << setw(10) << i + 1;
        cout << setw(10) << ranking[i].first;
        cout << setw(10) << ranking[i].second << endl;
    }
    cout<<"tekan apa saja untuk kembali ke menu "<<endl;
    system("pause");
}

int main(){
	bool keluar = false;
	while (!keluar){
    int pilih;
    menu();
    cin>>pilih;
    switch (pilih) {
    case 1:
     cout<<"======== metode Analytic Hierarchy Process (AHP) ========"<<endl;
     ahp();
      break;
    case 2:
      cout<<"======== metode Simple Additive Weighting ========"<<endl;
      saw();
      break;
    case 3:
        cout<<"======== metode  Weighted Product ========"<<endl;
      wp();
      break;
    case 4:
      cout << "Goodbye semoga dapat A" << endl;
      keluar = true;
      break;
    default:
      cout << "pilihanmu salah" << endl;
      break;
  }
}

}
