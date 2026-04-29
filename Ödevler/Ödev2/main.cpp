#include <iostream>
#include <string>
#include "FileAnalyzer.h"
#include "Scanners.h"
#include "AntivirusEngine.h"

using namespace std;

int main() {
    // Motoru ve tarayıcıları başlat
    AntivirusEngine engine;
    engine.addScanner(new HeuristicScanner());
    engine.addScanner(new SignatureScanner());

    int secim = 0;
    string filePath;

    while (secim != 2) {
        cout << "\n=========================================\n";
        cout << "   DEFENSIVE MALWARE SCANNER - v1.0\n";
        cout << "=========================================\n";
        cout << "[1] Yeni Dosya Tara\n";
        cout << "[2] Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 1) {
            cout << "\nTaranacak dosyanin tam yolunu girin (ornek: main.cpp veya eicar_test.txt): ";
            cin >> filePath;

            FileAnalyzer targetFile(filePath);
            if (targetFile.isValid()) {
                engine.scanFile(targetFile);
            } else {
                cout << "[HATA] Dosya bulunamadi veya erisim engellendi: " << filePath << "\n";
            }
        } else if (secim != 2) {
            cout << "[UYARI] Gecersiz secim, lutfen tekrar deneyin.\n";
        }
    }

    cout << "\nSistem guvenli bir sekilde kapatiliyor...\n";
    return 0;
}