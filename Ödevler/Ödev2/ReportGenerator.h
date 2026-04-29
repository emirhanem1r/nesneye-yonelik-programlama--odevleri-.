#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <string>

class ReportGenerator {
private:
    std::string reportFilePath;
public:
    // Varsayılan olarak "scan_report.txt" dosyasına kaydedecek
    ReportGenerator(const std::string& path = "scan_report.txt");
    
    // Tarama sonucunu dosyaya yazan fonksiyon
    void logScan(const std::string& targetFile, bool isInfected, const std::string& details);
};

#endif