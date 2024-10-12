#include <iostream>
#include <string>

#include "Controller.h"
#include "ControllerException.h"
#include "ReturnStruct.h"

using namespace std;

int main() {

  string plainText =
      "Thisismyphenomenalstring"; // Note this can have any char in the range
                                  // 32 to 126 inclusive.
  int plainTextLength = plainText.length();
  unsigned char *arr = new unsigned char[plainTextLength];
  for (int i = 0; i < plainTextLength; i++) {
    arr[i] = plainText[i]; // don't copy null termination
  }

  Controller *c = new Controller("schema.txt");
  try {
    cout << "Beginning encryption:" << endl;
    ReturnStruct cipherReturn = c->encrypt(arr, plainTextLength);
    cout << endl << "Beginning decryption:" << endl;
    ReturnStruct plainTextReturn =
        c->decrypt(cipherReturn.returnArray, cipherReturn.arraySize);
    delete[] cipherReturn.returnArray;
    delete[] plainTextReturn.returnArray; // free memory

    cout << endl << "Example Exception:" << endl;
    arr[0] = '!'; // This character induces an underflow exception in this
                  // scenario
    ReturnStruct cipherReturn2 = c->encrypt(arr, plainTextLength);

  } catch (ControllerException &e) {
    e.printMessage();
  }

  delete c;
  delete[] arr;

  return 0;
}

/*Expected Output:
Beginning encryption:
[T,h,i,s,i,s,m,y,p,h,e,n,o,m,e,n,a,l,s,t,r,i,n,g]
[X,[,R,I,I,^,Z,Y,W,M,k,W,V,L,V,L,R,F,O,W,Z,Q,P,R,Z,Q,^,S,L,K,M,V,Q,X,X,[,R,I,I,^,Z,Y,W,M]
[S,N,b,P,c,3,5,k,K,m,M,W,Y,Z,^,I,I,R,[,X,X,Q,V,M,K,L,S,^,Q,Z,R,P,Q,Z,W,O,F,R,L,V,L,V,W,k,M,W,Y,Z,^,I,I,R,[,X,S,N,b,P,c,3,5,k,K,m]
[b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6]
[5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6,0,1,2,3,4]
[j,S,v,O,q,c,|,Z,7,h,7,8,9,:,;,2,3,4,5,6,7,8,9,:,;,d,m,|,C,6,6,G,8,p,P,U,4,e,R,d,m,7,5,O,o,M,\,[,Y,K,K,`,Z,],T,X,S,Z,N,M,O,S,`,U,R,T,\,Y,\,S,T,H,Q,N,X,N,m,Y,X,[,Y,O,K,`,\,],T,K,P,U,Z,e,R,d,m,7,5,|,o,M,6,d,m,p,C,6,4,G,8,2,3,4,5,6,j,S,v,O,q,c,|,Z,7,h]
[V,6,B,c,M,U,1,p,H,`,i,R,u,N,p,b,{,Y,6,g,6,7,8,9,:,1,2,3,4,5,6,7,8,9,:,c,l,{,B,5,5,F,7,o,O,T,3,d,Q,c,l,6,4,N,n,L,[,Z,X,J,J,_,Y,\,S,W,R,Y,M,L,N,R,_,T,Q,S,[,X,[,R,S,G,P,M,W,M,l,X,W,Z,X,N,J,_,[,\,S,J,O,T,Y,d,Q,c,l,6,4,{,n,L,5,c,l,o,B,5,3,F,7,1,2,3,4,5,i,R,u,N,p,b,{,Y,6,g,V,6,B,c,M,U,1,p,H,`]
[b,k,z,A,4,4,E,6,n,6,V,2,M,c,B,p,1,U,i,`,H,N,u,R,{,b,p,g,6,Y,8,7,6,1,:,9,4,3,2,7,6,5,:,9,8,{,l,c,5,5,B,o,7,F,3,T,O,c,Q,d,4,6,l,L,n,N,X,Z,[,_,J,J,S,\,Y,Y,R,W,N,L,M,T,_,R,[,S,Q,R,[,X,P,G,S,M,W,M,W,X,l,N,X,Z,[,_,J,J,S,\,Y,T,O,c,Q,d,4,6,l,L,n,{,l,c,5,5,B,o,7,F,3,3,2,1,i,5,4,N,u,R,{,b,p,g,6,Y,B,6,V,U,M,c,H,p,1,k,z,`,4,4,b,6,n,A,E,2]

Beginning decryption:
[b,k
,z,A,4,4,E,6,n,6,V,2,M,c,B,p,1,U,i,`,H,N,u,R,{,b,p,g,6,Y,8,7,6,1,:,9,4,3,2,7,6,5,:,9,8,{,l,c,5,5,B,o,7,F,3,T,O,c,Q,d,4,6,l,L,n,N,X,Z,[,_,J,J,S,\,Y,Y,R,W,N,L,M,T,_,R,[,S,Q,R,[,X,P,G,S,M,W,M,W,X,l,N,X,Z,[,_,J,J,S,\,Y,T,O,c,Q,d,4,6,l,L,n,{,l,c,5,5,B,o,7,F,3,3,2,1,i,5,4,N,u,R,{,b,p,g,6,Y,B,6,V,U,M,c,H,p,1,k,z,`,4,4,b,6,n,A,E,2]
[V,6,B,c,M,U,1,p,H,`,i,R,u,N,p,b,{,Y,6,g,6,7,8,9,:,1,2,3,4,5,6,7,8,9,:,c,l,{,B,5,5,F,7,o,O,T,3,d,Q,c,l,6,4,N,n,L,[,Z,X,J,J,_,Y,\,S,W,R,Y,M,L,N,R,_,T,Q,S,[,X,[,R,S,G,P,M,W,M,l,X,W,Z,X,N,J,_,[,\,S,J,O,T,Y,d,Q,c,l,6,4,{,n,L,5,c,l,o,B,5,3,F,7,1,2,3,4,5,i,R,u,N,p,b,{,Y,6,g,V,6,B,c,M,U,1,p,H,`]
[j,S,v,O,q,c,|,Z,7,h,7,8,9,:,;,2,3,4,5,6,7,8,9,:,;,d,m,|,C,6,6,G,8,p,P,U,4,e,R,d,m,7,5,O,o,M,\,[,Y,K,K,`,Z,],T,X,S,Z,N,M,O,S,`,U,R,T,\,Y,\,S,T,H,Q,N,X,N,m,Y,X,[,Y,O,K,`,\,],T,K,P,U,Z,e,R,d,m,7,5,|,o,M,6,d,m,p,C,6,4,G,8,2,3,4,5,6,j,S,v,O,q,c,|,Z,7,h]
[5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6,0,1,2,3,4]
[b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6]
[S,N,b,P,c,3,5,k,K,m,M,W,Y,Z,^,I,I,R,[,X,X,Q,V,M,K,L,S,^,Q,Z,R,P,Q,Z,W,O,F,R,L,V,L,V,W,k,M,W,Y,Z,^,I,I,R,[,X,S,N,b,P,c,3,5,k,K,m]
[X,[,R,I,I,^,Z,Y,W,M,k,W,V,L,V,L,R,F,O,W,Z,Q,P,R,Z,Q,^,S,L,K,M,V,Q,X,X,[,R,I,I,^,Z,Y,W,M]
[T,h,i,s,i,s,m,y,p,h,e,n,o,m,e,n,a,l,s,t,r,i,n,g]

Example Exception:
[!,h,i,s,i,s,m,y,p,h,e,n,o,m,e,n,a,l,s,t,r,i,n,g]
encrypt exception
underflow exception occured

Beginning encryption:
[T,h,i,s,i,s,m,y,p,h,e,n,o,m,e,n,a,l,s,t,r,i,n,g]
[X,[,R,I,I,^,Z,Y,W,M,k,W,V,L,V,L,R,F,O,W,Z,Q,P,R,Z,Q,^,S,L,K,M,V,Q,X,X,[,R,I,I,^,Z,Y,W,M]
[S,N,b,P,c,3,5,k,K,m,M,W,Y,Z,^,I,I,R,[,X,X,Q,V,M,K,L,S,^,Q,Z,R,P,Q,Z,W,O,F,R,L,V,L,V,W,k,M,W,Y,Z,^,I,I,R,[,X,S,N,b,P,c,3,5,k,K,m]
[b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6]
[5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6,0,1,2,3,4]
[j,S,v,O,q,c,|,Z,7,h,7,8,9,:,;,2,3,4,5,6,7,8,9,:,;,d,m,|,C,6,6,G,8,p,P,U,4,e,R,d,m,7,5,O,o,M,\,[,Y,K,K,`,Z,],T,X,S,Z,N,M,O,S,`,U,R,T,\,Y,\,S,T,H,Q,N,X,N,m,Y,X,[,Y,O,K,`,\,],T,K,P,U,Z,e,R,d,m,7,5,|,o,M,6,d,m,p,C,6,4,G,8,2,3,4,5,6,j,S,v,O,q,c,|,Z,7,h]
[V,6,B,c,M,U,1,p,H,`,i,R,u,N,p,b,{,Y,6,g,6,7,8,9,:,1,2,3,4,5,6,7,8,9,:,c,l,{,B,5,5,F,7,o,O,T,3,d,Q,c,l,6,4,N,n,L,[,Z,X,J,J,_,Y,\,S,W,R,Y,M,L,N,R,_,T,Q,S,[,X,[,R,S,G,P,M,W,M,l,X,W,Z,X,N,J,_,[,\,S,J,O,T,Y,d,Q,c,l,6,4,{,n,L,5,c,l,o,B,5,3,F,7,1,2,3,4,5,i,R,u,N,p,b,{,Y,6,g,V,6,B,c,M,U,1,p,H,`]
[b,k,z,A,4,4,E,6,n,6,V,2,M,c,B,p,1,U,i,`,H,N,u,R,{,b,p,g,6,Y,8,7,6,1,:,9,4,3,2,7,6,5,:,9,8,{,l,c,5,5,B,o,7,F,3,T,O,c,Q,d,4,6,l,L,n,N,X,Z,[,_,J,J,S,\,Y,Y,R,W,N,L,M,T,_,R,[,S,Q,R,[,X,P,G,S,M,W,M,W,X,l,N,X,Z,[,_,J,J,S,\,Y,T,O,c,Q,d,4,6,l,L,n,{,l,c,5,5,B,o,7,F,3,3,2,1,i,5,4,N,u,R,{,b,p,g,6,Y,B,6,V,U,M,c,H,p,1,k,z,`,4,4,b,6,n,A,E,2]

Beginning decryption:
[b,k,z,A,4,4,E,6,n,6,V,2,M,c,B,p,1,U,i,`,H,N,u,R,{,b,p,g,6,Y,8,7,6,1,:,9,4,3,2,7,6,5,:,9,8,{,l,c,5,5,B,o,7,F,3,T,O,c,Q,d,4,6,l,L,n,N,X,Z,[,_,J,J,S,\,Y,Y,R,W,N,L,M,T,_,R,[,S,Q,R,[,X,P,G,S,M,W,M,W,X,l,N,X,Z,[,_,J,J,S,\,Y,T,O,c,Q,d,4,6,l,L,n,{,l,c,5,5,B,o,7,F,3,3,2,1,i,5,4,N,u,R,{,b,p,g,6,Y,B,6,V,U,M,c,H,p,1,k,z,`,4,4,b,6,n,A,E,2]
[V,6,B,c,M,U,1,p,H,`,i,R,u,N,p,b,{,Y,6,g,6,7,8,9,:,1,2,3,4,5,6,7,8,9,:,c,l,{,B,5,5,F,7,o,O,T,3,d,Q,c,l,6,4,N,n,L,[,Z,X,J,J,_,Y,\,S,W,R,Y,M,L,N,R,_,T,Q,S,[,X,[,R,S,G,P,M,W,M,l,X,W,Z,X,N,J,_,[,\,S,J,O,T,Y,d,Q,c,l,6,4,{,n,L,5,c,l,o,B,5,3,F,7,1,2,3,4,5,i,R,u,N,p,b,{,Y,6,g,V,6,B,c,M,U,1,p,H,`]
[j,S,v,O,q,c,|,Z,7,h,7,8,9,:,;,2,3,4,5,6,7,8,9,:,;,d,m,|,C,6,6,G,8,p,P,U,4,e,R,d,m,7,5,O,o,M,\,[,Y,K,K,`,Z,],T,X,S,Z,N,M,O,S,`,U,R,T,\,Y,\,S,T,H,Q,N,X,N,m,Y,X,[,Y,O,K,`,\,],T,K,P,U,Z,e,R,d,m,7,5,|,o,M,6,d,m,p,C,6,4,G,8,2,3,4,5,6,j,S,v,O,q,c,|,Z,7,h]
[5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6,0,1,2,3,4]
[b,k,z,A,4,4,E,6,n,N,S,2,c,P,b,k,5,3,M,m,K,Z,Y,W,I,I,^,X,[,R,V,Q,X,L,K,M,Q,^,S,P,R,Z,W,Z,Q,R,F,O,L,V,L,k,W,V,Y,W,M,I,^,Z,[,R,I,N,S,X,c,P,b,k,5,3,z,m,K,4,b,k,n,A,4,2,E,6]
[S,N,b,P,c,3,5,k,K,m,M,W,Y,Z,^,I,I,R,[,X,X,Q,V,M,K,L,S,^,Q,Z,R,P,Q,Z,W,O,F,R,L,V,L,V,W,k,M,W,Y,Z,^,I,I,R,[,X,S,N,b,P,c,3,5,k,K,m]
[X,[,R,I,I,^,Z,Y,W,M,k,W,V,L,V,L,R,F,O,W,Z,Q,P,R,Z,Q,^,S,L,K,M,V,Q,X,X,[,R,I,I,^,Z,Y,W,M]
[T,h,i,s,i,s,m,y,p,h,e,n,o,m,e,n,a,l,s,t,r,i,n,g]

Example Exception:
[!,h,i,s,i,s,m,y,p,h,e,n,o,m,e,n,a,l,s,t,r,i,n,g]
encrypt exception
underflow exception occured
*/