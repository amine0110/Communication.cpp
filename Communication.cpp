#include "stdafx.h"
#include "Communication.h"
#include "DialBoitier.h"


CCommunication::CCommunication()
{
}

CCommunication::~CCommunication()
{
}

CCommunication::CCommunication(CDialBoitier * ptra)
{
	ptrCDialBoitier = ptra;
}

void CCommunication::EcrireValeur(int valeur, int numAfficheur)
{
	
	int tab[10] = { 0x3F , 0x30, 0x6D, 0x79 ,0x72, 0x5B, 0x5F, 0x31, 0x7F, 0x7B };
	
	if(ptrCDialBoitier->actif)ptrCDialBoitier->outp(tab[valeur] + numAfficheur * (0x80), 0x278);
}

void CCommunication::EcrireMot(int valeurMot)
{
	int a, b;
	a = valeurMot % 10;
	b = valeurMot / 10;
	EcrireValeur(a, 1);
	EcrireValeur(b, 0);

}

void CCommunication::compteur()
{
	for (int i = 0; i < 100 && (ptrCDialBoitier->actif == true); i++)
	{
		EcrireMot(i);
		Sleep(100);
	}
}
