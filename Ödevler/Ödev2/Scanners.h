#ifndef SCANNERS_H
#define SCANNERS_H

#include "FileAnalyzer.h"
#include "SignatureDatabase.h" // Veritabanını kullanacağımız için eklendi
#include <string>

// Polimorfizm için Temel Arayüz (Interface) Sınıfı
class IScanner {
public:
    virtual bool scan(const FileAnalyzer& file) = 0; // Saf sanal fonksiyon
    virtual std::string getScannerName() const = 0;
    virtual ~IScanner() {}
};

// 1. Sezgisel (Heuristic) Tarayıcı - Şüpheli kod parçacıklarını arar
class HeuristicScanner : public IScanner {
public:
    bool scan(const FileAnalyzer& file) override;
    std::string getScannerName() const override;
};

// 2. İmza Tabanlı (Signature) Tarayıcı - Veritabanındaki tehditleri arar
class SignatureScanner : public IScanner {
private:
    SignatureDatabase db; // Tarayıcı, kendi içinde veritabanını tutar
public:
    bool scan(const FileAnalyzer& file) override;
    std::string getScannerName() const override;
};

#endif // Tüm tanımlamalar bu satırın ÜSTÜNDE olmalıdır!