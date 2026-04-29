#include "Scanners.h"

bool HeuristicScanner::scan(const FileAnalyzer& file) {
    std::string content = file.getContent();
    
    // Antivirüslerin sıkça aradığı bazı şüpheli komut/fonksiyon desenleri
    // İleride burası çok daha genişletilebilir
    if (content.find("system(") != std::string::npos || 
        content.find("eval(") != std::string::npos ||
        content.find("rm -rf") != std::string::npos ||
        content.find("CreateRemoteThread") != std::string::npos) { // Windows API injection
        return true; // Tehdit bulundu!
    }
    
    return false; // Dosya temiz
}

std::string HeuristicScanner::getScannerName() const {
    return "Sezgisel (Heuristic) Analiz Motoru";
}// ... (HeuristicScanner kodları kalsın) ...

bool SignatureScanner::scan(const FileAnalyzer& file) {
    // Dosyanın içeriğini veritabanına soruyoruz.
    // Gerçek bir senaryoda burada file.getContent()'ın SHA-256 hash'i alınır ve o aranır.
    return db.isMalicious(file.getContent()); 
}

std::string SignatureScanner::getScannerName() const {
    return "Imza Tabanli (Signature) Analiz Motoru";
}