#include "mex.h"
#include <meshmonk.hpp>
#include "mystream.cpp"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    
    //# Check input
    //## Number of input arguments
    if(nlhs != 0) {
    mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                      "Zero LHS output required.");
    }
    //## Number of output arguments
    if(nrhs != 4) {
    mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                      "4 inputs required.");
    }
    
    //# Get Inputs
    //## Old Features
    float *oldFeatures = reinterpret_cast<float *>(mxGetData(prhs[0]));
    mwSize numOldElements = mxGetM(prhs[0]);
    //## Old Original Indices
    int *oldOriginalIndices = reinterpret_cast<int *>(mxGetData(prhs[1]));
    //## New Features
    float *newFeatures = reinterpret_cast<float *>(mxGetData(prhs[2]));
    mwSize numNewElements = mxGetM(prhs[2]);
    //## New Original Indices
    int *newOriginalIndices = reinterpret_cast<int *>(mxGetData(prhs[3]));
    
    //# Execute c++ function
    meshmonk::scaleshift_mesh_mex(oldFeatures, numOldElements,
                                  oldOriginalIndices,
                                  newFeatures, numNewElements,
                                  newOriginalIndices);
    
//     //# Set Output
//     //## New Features
//     int numCols = 6;
//     plhs[0] = mxCreateNumericMatrix(numNewElements, numCols, mxSINGLE_CLASS, mxREAL);
//     auto output = mxGetPr(plhs[0]);
//     //### Copy result from c++ function into the output
//     for (unsigned i = 0 ; i < numNewElements * numCols ; i++){
//         output[i] = newFeatures[i];
//     }
  
}