#include "ReportGenerator.h"
#include <fstream>
#include <iostream>
#include <ctime>

ReportGenerator::ReportGenerator(const std::string& path) {
    reportFilePath = path;
}

void ReportGenerator::logScan(const std::string& targetFile, bool isInfected, const std::string& details) {
    // std::ios::app -> Dosya varsa silme, sonuna ekle. Yoksa yeni oluştur.
    std::ofstream file(reportFilePath, std::ios::app); 

    if (file.is_open()) {
        // O anki zamanı alalım
        time_t now = time(0);
        char* dt = ctime(&now);
        
        file << "[TARAMA ZAMANI] " << dt;
        file << "Taranan Dosya: " << targetFile << "\n";
        file << "Sonuc: " << (isInfected ? "[TEHLIKE] Zararli Yazilim Bulundu!" : "[GUVENLI] Temiz") << "\n";
        
        if (isInfected) {
            file << "Tespit Eden Motor(lar): " << details << "\n";
        }
        file << "--------------------------------------------------\n";
        
        file.close();
    } else {
        std::cerr << "[SISTEM UYARISI] Rapor dosyasi olusturulamadi/yazilamadi!" << std::endl;
    }
}