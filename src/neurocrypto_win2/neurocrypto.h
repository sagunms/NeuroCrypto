/*[neurocrypto.h for NeuroCrypto declarations]
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

#ifndef NEUROCRYPTO_H
	#define NEUROCRYPTO_H
	#include "stdafx.h"

	#define NULL		0

	const char Dictionary[38] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";

	//========================
	//	Class declarations
	//========================

	template <class T>
	class DynamicArray {
		public:
		T* Z;
		//Functions
		~DynamicArray ();
		void length (T n);
	};

	class TreeParityMachine {
		public :
		DynamicArray <int> W, H;
		int K, N, L;
		int TPMOutput;
		void Initialize ();
		void ComputeTPMResult (const DynamicArray <int> & X);
		void UpdateWeight (const DynamicArray <int> & X);
		void RandomWeight ();
	};

	//Global Functions declaration
	int IsEqual (int A, int B);
	int RandomBit ();
	int Signum (double r);

	class TPMInputVector {
		public :
		DynamicArray <int> X;
		void CreateRandomVector (int K, int N);
		void xLength (int K, int N);
	};

	class NeuroCrypto {
	public:
			unsigned int itrMax;
			TreeParityMachine A, B;
			TPMInputVector objInput;
			char publickey[100];
			//Default Constructor
			NeuroCrypto (int k, int n, int l);
	};

#endif