#include "SignatureDatabase.h"

SignatureDatabase::SignatureDatabase() {
    // Gerçek bir sistemde bu imzalar bir .json veya .dat dosyasından okunur.
    // Biz şimdilik test amaçlı örnek zararlı imzaları (veya dosya içerikleri) ekliyoruz.
    maliciousSignatures.insert("X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"); // EICAR Test Virüsü
    maliciousSignatures.insert("cmd.exe /c del /f /s /q c:\\*.*"); // Basit bir yıkıcı komut
    maliciousSignatures.insert("WannaCry_Ransomware_Signature_0xABC123");
}

bool SignatureDatabase::isMalicious(const std::string& data) const {
    // Veritabanında (unordered_set) hızlı bir arama yapar
    return maliciousSignatures.find(data) != maliciousSignatures.end();
}