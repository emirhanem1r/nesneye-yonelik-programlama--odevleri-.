#ifndef FILEANALYZER_H
#define FILEANALYZER_H

#include <string>

class FileAnalyzer {
private:
    std::string filePath;
    std::string content;
    bool fileExists;

    // Sadece sınıfın kendi içinde kullanacağı yardımcı fonksiyon
    void readFile(); 

public:
    // Constructor (Yapıcı Metot)
    FileAnalyzer(const std::string& path);
    
    // Getter Metotları (Dışarıdan okuma amaçlı)
    std::string getFilePath() const;
    std::string getContent() const;
    bool isValid() const; // Dosya başarıyla okundu mu?
};

#endif