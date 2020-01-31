#include <iostream>
#include "HarmonicSeries.h"

SeriesPtr* allSeries = nullptr;
int counter = 0;

void PrintSeries(SeriesPtr array, int size)
{
    for( int i=0; i<size; i++)
    {
        printf("%.2f ", array[i]);
    }
    std::cout << "\n";
}

SeriesPtr InitializeHarmonicSeries( Size size )
{
    SeriesPtr array = new SeriesType[size];
    for( int i=0; i<size; i++ )
    {
        array[i] = 1/( float )(i+1);
    }

    counter++;
    SeriesPtr* temp = new SeriesPtr[ counter ];
    for( int i=0; i<counter-1; i++ )
    {
        if( allSeries != nullptr )  
            temp[i] = allSeries[i];
    }
    temp[ counter-1 ] = array;
    
    if( allSeries!= nullptr )
        delete[] allSeries;
    allSeries = temp;
    return array;
}
//funkcja zwraca sume wszystkich elementow ciagu
SeriesType SeriesSum(SeriesPtr seriesPtr1, Size size)
{
    SeriesType sum = 0;
    for( int i=0; i<size; i++)
    {
        sum += seriesPtr1[i];
    }
    return sum;
}

void RunAndPrint(SeriesFunctionPtr func, SeriesPtr array, Size size)
{
    if(func == SeriesSum)   {std::cout << "Sum: ";}
    else if(func == SeriesProduct) {std::cout << "Product: ";}
    else if(func == SeriesMax) {std::cout << "Maximum: ";}
    else if(func == SeriesMin) {std::cout << "Minimum: ";}
    SeriesType a =  func(array, size);
            printf("%.2f\n", a);
}

// funkcja zwalnia pamiec zajeta przez ciag
void DeleteSeries()
{
    std:: cout << "Deleting " << counter << " series..." << std::endl;
    for( int i=0; i<counter; i++ )
    {
        delete[] allSeries[i];
    }
    counter = 0;
    if( allSeries != nullptr )
        delete[] allSeries;
        allSeries = nullptr;
    std::cout << " *** Memory cleanded up ***" << std::endl;
}
SeriesType SeriesProduct(SeriesPtr array, Size size)
{
    SeriesType product=1.0;
    for( int i=0; i<size; i++)
    {
        product*=array[i];
    }
    return (float)product;
}

SeriesType SeriesMax(SeriesPtr array, Size size)
{
    SeriesType max = 0.0;
    for( int i=0; i<size; i++)
    {
        if(max<array[i])    max=array[i];
    }
    return max;
}

SeriesType SeriesMin(SeriesPtr array, Size size)
{
    SeriesType min=array[0];
    for( int i=0; i<size; i++)
    {
        if(min>array[i])    min=array[i];
    }
    return min;
}
