#include "AntivirusEngine.h"
#include <iostream>

AntivirusEngine::~AntivirusEngine() {
    for (auto scanner : scanners) {
        delete scanner; 
    }
    scanners.clear();
}

void AntivirusEngine::addScanner(IScanner* scanner) {
    scanners.push_back(scanner);
}

void AntivirusEngine::scanFile(const FileAnalyzer& file) {
    std::cout << "\n=== Tarama Baslatiliyor: " << file.getFilePath() << " ===\n";
    bool isInfected = false;
    std::string detectionDetails = "";

    for (auto scanner : scanners) {
        std::cout << "[SISTEM] " << scanner->getScannerName() << " devrede...\n";
        
        if (scanner->scan(file)) {
            std::cout << "-> [TEHLIKE] Zararli yazilim belirtisi bulundu! Kaynak: " << scanner->getScannerName() << "\n";
            isInfected = true;
            detectionDetails += scanner->getScannerName() + " ";
        }
    }

    if (!isInfected) {
        std::cout << "-> [GUVENLI] Dosya tamamen temiz.\n";
    }
    std::cout << "=================================================\n\n";

    // Tarama bittikten sonra sonucu .txt dosyasına yazdırıyoruz
    reporter.logScan(file.getFilePath(), isInfected, detectionDetails);
}