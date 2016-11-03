#ifndef _IMatrix_H
#define _IMatrix_H

class IMatrix
{
public:
    IMatrix (int nRow, int nCol, int* vals=0);
    IMatrix (const IMatrix& IM);
    virtual ~IMatrix (void);

    virtual const int& operator() (int i, int j) const;
    virtual int& operator() (int i, int j);

    int nrows (void) const;
    int ncolumns (void) const;

    int * data (void) const;
private:
    int NRows;
    int NColumns;
    int * values;
};

class SymmIMatrix : public IMatrix
{
public:
    SymmIMatrix (int nRow, int * vals=0);
    SymmIMatrix (const SymmIMatrix& SIM);
    virtual ~SymmIMatrix (void);

    virtual const int& operator() (int i, int j) const;
    virtual int& operator() (int i, int j);

};

#endif
