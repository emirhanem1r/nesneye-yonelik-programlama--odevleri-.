#ifndef ANTIVIRUS_ENGINE_H
#define ANTIVIRUS_ENGINE_H

#include "Scanners.h"
#include "FileAnalyzer.h"
#include "ReportGenerator.h" // Raporlayıcıyı dahil ettik
#include <vector>

class AntivirusEngine {
private:
    std::vector<IScanner*> scanners;
    ReportGenerator reporter; // Motorun kendi raporlayıcısı var

public:
    ~AntivirusEngine();
    void addScanner(IScanner* scanner);
    void scanFile(const FileAnalyzer& file);
};

#endif