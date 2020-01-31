#include "GeometricSeries.h"
SeriesPtr InitializeGeometricSeries( Size size, float ratio1 )
{
    SeriesPtr array = new SeriesType[ size ];
    array[0]=1;
    for( int i=0; i<size-1; i++ )
    {
        array[ i+1 ] = array[i] * ratio1;
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