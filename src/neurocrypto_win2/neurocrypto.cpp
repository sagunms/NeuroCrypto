/*[neurocrypto.cpp for NeuroCrypto codec]
=========================================
    		NEURO-CRYPTO v3.0
-----------------------------------------	
 A proof-of-concept demonstration of
 Neural Cryptography - a novel approach 
 to public-key cryptography using 
 Tree Parity Machine - a variant of 
       Artificial Neural Networks
-----------------------------------------
 Created by: Sagun Man Singh
 Date: Fri, Oct 29. 2010 @ 1:30 PM
 Email: sagunms@gmail.com
 Website: http://sagunms.wordpress.com
 -----------------------------------------
 Started = Fri, Oct 8, 2010 @ 3:00 PM
 Latest = Fri, Oct 29. 2010 @ 1:30 PM
        (Duration = 21 days)
==========================================
*/

#include "neurocrypto.h"

//===============================
//	Class::Function declarations
//===============================
/* TreeParityMachine */
void TreeParityMachine::ComputeTPMResult (const DynamicArray <int> & X) {
	int i, j, sum;
	TPMOutput = 1;
	for (i = 0; i < K; i++) {
		sum = 0;
		for (j = 0; j < N; j++) {
			sum = sum + (W.Z[i * N + j] * X.Z[i * N + j]);
		}
		H.Z[i]= Signum(sum);
		TPMOutput = TPMOutput * Signum (sum);
	}
}

void TreeParityMachine::Initialize () {
	W.length(K * N);
	H.length(K);
}

void TreeParityMachine::RandomWeight () {
	int i;
	for ( i = 0; i < K * N; i ++ )
		W.Z[i]= L - (rand() % (2 * L + 1));
}


void TreeParityMachine::UpdateWeight (const DynamicArray <int> & X) {
	int i, j, newW;
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			newW = W.Z[i * N + j];
			newW = newW + X.Z[i * N + j] * TPMOutput * IsEqual (TPMOutput, H.Z[i]) * IsEqual (TPMOutput, TPMOutput);
			if (newW > L) 
				newW = L;
			if (newW < - L) 
				newW = - L;
			W.Z[i * N + j] = newW;
		}
	}
}

/* TPMInputVector */
void TPMInputVector::CreateRandomVector (int K, int N) {
	int i;
	for (i = 0; i < K * N; i++)
		X.Z[i]= RandomBit ();
}

void TPMInputVector::xLength (int K, int N) {
	X.length(K * N);
}

/* DynamicArray */
template <class T>
void DynamicArray<T>::length (T n)
{
	Z = new T [n];
}

//Destructor
template <class T>
DynamicArray<T>::~DynamicArray (void) {
	delete [] Z;
	Z = NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//==================
//	NEUROCRYPTO
//==================
//////////////////////////////////////////////////////////////////////////////////////////////////////

NeuroCrypto::NeuroCrypto (int initK, int initN, int initL) {
	srand (time(NULL));			//initialize random generator
	//Initialize A
	A.K = initK, A.N = initN, A.L = initL;
	A.Initialize ();
	A.RandomWeight ();
	//Initialize B
	B.K = initK, B.N = initN, B.L = initL;
	B.Initialize ();
	B.RandomWeight ();
	objInput.xLength (B.K, B.N);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//=================================
//	Global Functions declarations
//=================================
//////////////////////////////////////////////////////////////////////////////////////////////////////

int IsEqual (int A, int B) {
	int result;
	if (A == B) 
		result = 1;
	else
		result = 0;
	return result;
}

int RandomBit () {
	int result, A;
	A = rand() % 2;
	if (A == 0) 
		result = - 1;
	else
		result = 1;
	return result;
}

int Signum (double r) {
	int result;
	if ( r > 0 ) 
		result = 1;
	else
		result = - 1;
	return result;
}
