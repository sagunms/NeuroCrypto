NeuroCrypto:
============

### C++ Implementation of Neural Cryptography for Public Key Exchange and Secure Message Encryption with Rijndael Cipher

This work is the software implementation of the concept of neural cryptography, which is a communication of two tree parity machines for agreement on a common key over a public channel. This key is utilized to encrypt a sensitive message to be transmitted over an insecure channel using Rijndael cipher. This is a new potential source for public key cryptography schemes which are not based on number theoretic functions, and have small time and memory complexities.

# NeuroCrypto Library [neurocrypto.c and neurocrypto.h]

The following code in the NeuroCrypto library is used to implement classes for tree parity machines which is a special type of multi-layer feed-forward neural network consisting of It consists of one output neuron, K hidden neurons and K * N input neurons. The TPM synchronization algorithm generates random input vector X, computes the values of the hidden and output neurons, compares the values of both TPMs and if same, applies the suitable learning rule to the weights. After synchronization is completed, the public key is used by Rijndael cipher to encrypt or decrypt the given plain text. A brief explaination of the various code snippets in NeuroCrypto library is given below.

## InputVector class structure

	class TPMInputVector {
		public:
		DynamicArray <int> X;
		void CreateRandomVector(int K,int N);
		void xLength (int K, int N);
	};

This class dynamically allocates and updates the randomized input vector X which will be constantly accessed by NeuroCrypto class for updating the weights during synchronization.

The input vector X is used throughout the synchronization process to randomly assign weights of the neural network. The two functions of TPMInputVector class are CreateRandomVector and xLength. CreateRandomVector assigns random signed bits (-1 or 1) to all the K*N number of neurons while, xLength is used to allocate the K*N long dynamic array X to store the input vector.

## TreeParityMachine class structure

	class TreeParityMachine {
		public:
		DynamicArray <int> W, H;
		int K, N, L;
		int TPMOutput;
		void Initialize ();
		void ComputeTPMResult (const DynamicArray <int> &X); 
		void UpdateWeight (const DynamicArray <int> &X);
		void RandomWeight ();
	};

This is the TPM class which is composed of weight and hidden intermediate DynamicArray objects, K, N and L parameters to characterize TPM and a TPM output variable. Various functions for initialization, weight updating and result computation are defined.

## NeuroCrypto class structure

	class NeuroCrypto {
		public:
		unsigned int itrMax;
		TreeParityMachine A, B;
		TPMInputVector objInput;
		char publickey[100];
		//Default Constructor
		NeuroCrypto (int k, int n, int l);
	};

This is the superset class of NeuroCrypto program module which consists of two TreeParityMachine objects A and B for Alice and Bob's TPM, a TPMInputVector object objInput, a character array to store the final public key. The default constructor takes the common TPM parameters K, N and L inputted by the user during runtime.

## Variable Declarations and Initialization

	int i, ii, ss, itrMax, j, K=0,sum, key_size, key_length, initN, initL;
	TreeParityMachine A, B;
	TPMInputVector objInput;
	DynamicArray <char> publickey;
	const char Dictionary [38] = "01234567890_abcdefghijklmnopqrstuvwxyz";
	
	srand (time(NULL)); //random generator
	cout << "Parameter settings (K, N, L)";
	cin >> initK >> initN >> initL;
	
	A.K=initK, A.N=initN, A.L=initL;//InitA
	A.Initialize (); A.RandomWeight ();
	
	B.K=initK, B.N=initN, B.L=initL;//InitB
	B.Initialize (); B.RandomWeight ();
	
	itrMax=(A.L*A.L*A.L*A.L)*A.N*A.K; /////
	cout << "Maximum Iterations: "<<itrMax;
	objInput.xLength (B.K, B.N);
	cout<<"Synchronizing TPM Networks...";

A and B (TPMs of Alice and Bob) are instances of TreeParityMachine class. The publickey object of DynamicArray class stores the final publickey after successful sync. Dictionary array stores 38 symbols (10 numbers, 26 alphabets, and an underscore) as a template for key generation. The system time is used as a seed to generate random numbers. The program takes the parameters K, N and L from the user and initializes the TPMs with the common parameters. 

## Main Iteration

	for (i=1; i!=itrMax; i++) {
		objInput.CreateRandomVector(B.K, B.N);
		A.ComputeTPMResult(objInput.X);
		B.ComputeTPMResult(objInput.X);
		
		if(A.TPMOutput == B.TPMOutput) {
			A.UpdateWeight (objInput.X);
			B.UpdateWeight (objInput.X);
			sum = 0;
			for(ss=0;ss<A.K*A.N;ss++)	//Find sum
				sum += abs(A.W.Z[ss]-	B.W.Z[ss]);
			if ( sum == 0 ) break;	
		} 
	}
	if (sum == 0)
		cout << "Status: SUCCESS!";
	else cout << "Status: FAILED!";

For each iteration of Alice's TPM, random input vector will be produced (using CreateRandomVector function of TPMInputVector class), the output value of TPM will be computed (using ComputeTPMResult function) and this output value will be available to Bob's TPM B. Bob's TPM should follow the same iterative procedure. During synchronization, both parties A and B continually check for the equality of both their TPMOutput values.

## Key Generation and Synchronization Outputs

	cout << "Iterations:" << i << "DataExchanged:" << (i*(A.K*A.N+4)/1024) << " KiB";
	key_size = 37 / (A.L * 2 + 1);
	key_length = A.K * A.N / key_size;

	cout << "Key length: " << key_length;
	publickey.length(key_length + 1);
		
	for(i = 0; i < key_length; i++)
		publickey.Z[i] = 0;
		
	for (i=1; i < key_length+1; i++) {
		K = 1;
		for(j=(i-1)*key_size; j<i*key_size;j++)
			K = K + A.W.Z[j] + A.L;
		//
		publickey.Z[i-1]=Dictionary[K];
	}
	
	publickey.Z[key_length]='\0'; //Null char
	cout << "Public Key: " << publickey.Z;

The actual iterations that were required to accomplish TPMs of matching weights are recorded in i. For each iteration, the data transferred is K*N+4 bytes. So for whole synchronization, it would be i*(K*N+4)/1024 kilobytes. The length of the public key is calculated as the total number of neurons of TPM divided by the key size, where again key size depends on the number of symbols assigned in the dictionary and the depth of weights in both within the range {-L, L}. This explains the formula L*2+1 (to include origin). For publickey generation of key_length characters, the ith character of publickey will be assigned as the kth symbol in the dictionary. This will be done such that the location K depends on jth neural weight, which again depends on the ith position of publickey array. This iterative formula for key generation is done by a nested loop to produce a seemingly random public key which actually depends on the weights, dictionary size, and the TPM parameters (depends on key_size).


# Rjindael Cipher [frmMain.h]

The Rjindael Cipher was implemented using System::Security::Cryptography library in VS2010. AES-128 was used using CBC mode and PKCS7 padding for encryption and decryption of the plain text.

## Encryption

	cipherData = text_Plain->Text;
	plainbytes = Encoding::ASCII->GetBytes(cipherData);
	
	// generating symmetric key
		plainKey = Encoding::ASCII->GetBytes(this->text_Key->Text);
		desObj->Key = plainKey;

	// choose other appropriate modes (CBC, CFB, CTS, ECB, OFB)
	desObj->Mode = CipherMode::CBC;
	
	// setting the padding mode
	desObj->Padding = PaddingMode::PKCS7;
	
	// --------------- ECRYPTION ---------------
	// memory stream used as a target to write enrypted data
	MemoryStream^ ms = gcnew MemoryStream();
	
	// transforms and encrypts plaintext data to memorystream object
	CryptoStream^ cs = gcnew CryptoStream(ms, desObj->CreateEncryptor(), CryptoStreamMode::Write);
	cs->Write(plainbytes, 0, plainbytes->Length);
	cs->Close();
	
	// getting encrypted data from memorystream to bytes
	cipherbytes = ms->ToArray();
	ms->Close();
	text_Encrypt->Text = Encoding::ASCII->GetString(cipherbytes);
	
## Decryption
	
	// --------------- DECRYPTION ---------------
	MemoryStream^ ms1 = gcnew MemoryStream(cipherbytes);
	CryptoStream^ cs1 = gcnew CryptoStream(ms1, desObj->CreateDecryptor(), CryptoStreamMode::Read);
	
	// decrypt the ciphertext from previous section
	cs1->Read(cipherbytes, 0, cipherbytes->Length);
	plainbytes2 = ms1->ToArray();
	cs1->Close();
	ms1->Close();
	text_Decrypt->Text = Encoding::ASCII->GetString(plainbytes2);

	
# Software Used

* Microsoft Visual Studio 2010 Ultimate (Visual C++)
* Rjindael Cipher was implemented using using System::Security::Cryptography library in VS2010.
* .NET Framework v4 is required to run the binary file that is available in the Downloads section.


# License

NeuroCrypto is intended to be used in both open-source and commercial environments. It is licensed under Apache License v2.0 license. Please review LICENSE.txt for more details.

Sagun Man Singh Shrestha [sagunms.wordpress.com](http://sagunms.wordpress.com) | [sagunms.com.np](http://sagunms.com.np)

Follow me on Twitter [@sagunms](http://www.twitter.com/sagunms)