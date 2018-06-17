#ifndef DSAL_H
#define DSAL_H

#include <iostream>
#include "Dicionario.h"


class DSAL : public DAL 
{
	static const int DEFAULT_SIZE = 50;
	
	DSAL( int _MaxSz = DEFAULT_SIZE ) : DAL<  Key,  Data,  KeyComparator> (_MaxSz ){} ;
	virtual ~DSAL(){};

	bool insert ( const Key & _newKey , const Data & _newInfo ); // Insere na lista 
	Key min ( ) const; // Recupera a menor chave do dicion´ario .
	Key max ( ) const; // Recupera a maior chave do dicion´ario .

	// Recupera em _y a chave sucessora a _x , se existir ( true ).
	bool sucessor ( const Key & _x , Key & _y ) const;
	// Recupera em _y a chave antecessora a _x , se existir ( true ).
	bool predecessor ( const Key & _x , Key & _y ) const;
	int _search( const Key & _x ) const;
};
