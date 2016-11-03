#include <exception>
#include <stdexcept>
#include "imatrix.h"

using std::exception;
using std::range_error;

IMatrix :: IMatrix (int nRow, int nCol, int* vals)
    : NRows (nRow),
    NColumns (nCol),
    values (new int [NRows*NColumns])
{
    if (vals)
    {
        int N = NRows*NColumns;
        int nVals = sizeof (vals)/sizeof (int);
        int n = std::min (N, nVals);
        for (int i=0; i<n; i++)
            values[i] = vals[i];
    }
}

IMatrix :: IMatrix (const IMatrix& IM)
    : NRows (IM.NRows),
    NColumns (IM.NColumns),
    values (new int [NRows*NColumns])
{
    int n = NRows*NColumns;
    for (int i=0; i<n; i++)
        values[i] = IM.values[i];
}

IMatrix :: ~IMatrix (void)
{
    delete values;
}

const int& IMatrix :: operator() (int i, int j) const
{
    if (i<0 || i>=NRows || j<0 || j>=NColumns)
        throw std::range_error("Invalid index");
    int n = i*NRows+j;
    return values[n];
}

int& IMatrix :: operator() (int i, int j)
{
    if (i<0 || i>=NRows || j<0 || j>=NColumns)
        throw std::range_error("Invalid index");
    int n = i*NRows+j;
    return values[n];
}

int IMatrix :: nrows (void) const
{
    return NRows;
}

int IMatrix :: ncolumns (void) const
{
    return NColumns;
}

int * IMatrix :: data (void) const
{
    return values;
};

//
// Symmetric matrix
//
SymmIMatrix :: SymmIMatrix (int nRow, int * vals)
    : IMatrix (nRow, nRow)
{
}

SymmIMatrix :: SymmIMatrix (const SymmIMatrix& SIM)
    : IMatrix (SIM)
{
}

SymmIMatrix :: ~SymmIMatrix (void)
{
}

const int& SymmIMatrix :: operator() (int i, int j) const
{
}

int& SymmIMatrix :: operator() (int i, int j)
{
}


