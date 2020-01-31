#include "GeometricSeries.h"
#include <iostream>
void PrintSeries( SeriesPtr array, int size )
{
    for( int i=0; i<size; i++ )
    {
        std::cout << "   " << array[i]; 
    }
    std::cout << "\n";
}
SeriesPtr InitializeGeometricSeries( Size size, SeriesType ratio1 )
{
    SeriesPtr array = new SeriesType[size];
    array[0] = 1;
    for( int i=0; i<size-1; i++ )
    {
        array[i+1] = array[i] * ratio1;
    }
    return array;
}
SeriesType SeriesSum( SeriesPtr gSeriesPtr1, Size size )
{
    SeriesType sum=0;
    for( int i=0; i<size; i++ )
    {
        sum += gSeriesPtr1[i];
    }
    return sum;
}
SeriesType SeriesProduct( SeriesPtr array, Size size )
{
    SeriesType product = 1;
    for( int i=0; i<size; i++ )
    {
        product *= array[i];
    }
    return product;
}
void DeleteSeries( SeriesPtr const* ptr )
{
    delete[] *ptr;
}

SeriesType SeriesMax( SeriesPtr array, Size size )
{
    SeriesType max = 0;
    for( int i=0; i<size; i++ )
    {
        if( max<array[i] )    max=array[i];
    }
    return max;
}
SeriesType SeriesMin( SeriesPtr array, Size size )
{
    SeriesType min = array[0];
    for( int i=0; i<size; i++ )
    {
        if( min>array[i] )    min = array[i];
    }
    return min;
}
void RunAndPrint( SeriesFunctionPtr func, SeriesPtr array, Size size )
{
    SeriesType a =  func(array, size);
    if( func == SeriesProduct )    std::cout << "Product: ";
    else if( func == SeriesSum )    std::cout << "Sum: ";
    else if( func == SeriesMax )    std::cout << "Maximum: ";
    else if( func == SeriesMin )    std::cout << "Minimum: ";
    std::cout << a << "\n";
}
