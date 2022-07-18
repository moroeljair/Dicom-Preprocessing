#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <math.h>
#include <omp.h>

#include "performance/benchmark.h"
#include "hybridmedianfilter/hybridmedianfilter.h"
#include "dicom/DicomReader.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    omp_set_num_threads(4);


    //utiliza la libreria DicomClassifier, el archivo dicom/DicomReader.h
    //lee la imagen dicom
    DicomReader dicomObj("/home/jair/Pictures/datasetDicom/MasaMicro1.dcm");
    //la convierte en vector de vectores int
    vector<vector<int>> data = dicomObj.getIntImageMatrix(12);

    //utiliza la libreria DicomPreprocessing, el archivo hybridmedianfilter/hybridmedianfilter.h
    //aplicar el filtro y guardar en la variable vect
    double tbegin = omp_get_wtime();
    vector<vector<int>> vect = hybridmedianfilterN(data,7);
    double time = omp_get_wtime() - tbegin;
    cout<<"Time: "<<time<<endl;


    //guarda el archivo en csv con libreria DicomClassifier
    string urlCsv="/home/jair/Pictures/MasaMicro1ejemplo.csv";
    dicomObj.saveData(vect,"/home/jair/Pictures/MasaMicro1ejemplo.csv",",",false);

    cout<<"Ejecución exitosa"<<endl;
    cout << "DIMENSIONES IMG DICOM: Filas:"<<vect.size()<<"; Columnas:"<<vect[0].size() << endl;
    cout << "Csv guardado en src:"<<urlCsv<<endl;

    return 0;
}
