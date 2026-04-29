#include "FileAnalyzer.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor: Nesne oluşturulur oluşturulmaz dosyayı okumaya çalışır
FileAnalyzer::FileAnalyzer(const std::string& path) {
    this->filePath = path;
    this->fileExists = false;
    readFile(); // Okuma fonksiyonunu tetikle
}

void FileAnalyzer::readFile() {
    // Dosyayı binary (ikili) modda açmak, antivirüsler için kritik bir standarttır
    std::ifstream file(filePath, std::ios::binary); 

    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf(); // Dosya içeriğini belleğe (buffer) aktar
        content = buffer.str(); // String değişkene ata
        fileExists = true;
        file.close(); // Bellek yönetimi için dosyayı kapat
    } else {
        std::cerr << "[SISTEM UYARISI] Dosya acilamadi veya bulunamadi: " << filePath << std::endl;
    }
}

// Kapsülleme (Encapsulation) gereği değişkenleri dışarıya kontrollü açıyoruz
std::string FileAnalyzer::getFilePath() const { return filePath; }
std::string FileAnalyzer::getContent() const { return content; }
bool FileAnalyzer::isValid() const { return fileExists; }