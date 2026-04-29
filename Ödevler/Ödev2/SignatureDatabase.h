#ifndef SIGNATURE_DATABASE_H
#define SIGNATURE_DATABASE_H

#include <string>
#include <unordered_set>

class SignatureDatabase {
private:
    std::unordered_set<std::string> maliciousSignatures;

public:
    SignatureDatabase();
    // Gelen dosya içeriği/hash'i veritabanında var mı kontrol eder
    bool isMalicious(const std::string& data) const; 
};

#endif