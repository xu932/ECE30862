#include "Base.h"
#include "PrivDerived.h"
#include "ProtDerived.h"
#include "PublicDerived.h"
#include "dPriv.h"
#include "dProt.h"
#include "dPublic.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {

   Base* b = new Base( );
   PrivDerived* privd = new PrivDerived( );
   ProtDerived* protd = new ProtDerived( );
   PublicDerived* publicd = new PublicDerived( );
   dPriv* dpriv = new dPriv( );
   dProt* dprot = new dProt( );
   dPublic* dpublic = new dPublic( );

   cout << "b" << endl;
   cout << b->getPrivB() << endl;
   cout << b->getProtB() << endl;
   cout << b->publicB << endl;

   cout << "privd" << endl;
   cout << privd->getPrivB() << endl;
   cout << privd->getProtB() << endl;
   cout << privd->getPubB() << endl;

   cout << "protd" << endl;
   cout << protd->getPrivB() << endl;
   cout << protd->getProtB() << endl;
   cout << protd->getPubB() << endl;

   cout << "publicd" << endl;
   cout << publicd->getPrivB() << endl;
   cout << publicd->getPrivB() << endl;
   cout << publicd->publicB << endl;

   cout << "dpriv" << endl;
   cout << dpriv->getPrivB() << endl;
   cout << dpriv->getProtB() << endl;
   cout << dpriv->getPubB() << endl;

   cout << "dprot" << endl;
   cout << dprot->getPrivB() << endl;
   cout << dprot->getProtB() << endl;
   cout << dprot->getPubB() << endl;

   cout << "dpublic" << endl;
   cout << dpublic->getPrivB() << endl;
   cout << dpublic->getProtB() << endl;
   cout << dpublic->publicB << endl;
}
