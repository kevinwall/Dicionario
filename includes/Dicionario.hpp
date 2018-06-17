#ifndef Dicionario_H
#define Dicionario_H

#include <iostream>

template < typename Key, typename Data, typename KeyComparator>
class DAL 
{
	protected:
		
		struct NodeAL 
		{ // Estrutura do n´o , representando o par chave - informa¸c~ao .
			Key id; // A chave ´e um inteiro simples .
			Data info ; // A informa¸c~ao ´e uma cadeia de caracteres .
		};

		static const size_t SIZE =50; // Tamanho default da lista .
		size_t mi_Length ; // Comprimento atual da lista .
		size_t mi_Capacity ; // Capacidade m´axima de armazenamento .
		NodeAL *mpt_Data ; // ´Area de armazenamento : vetor alocado dinamicamente .

		//Key _search ( const Key & _x ) const; // M´etodo de busca auxiliar .

	public:

		DAL ( size_t _MaxSz = SIZE ) : mi_Length(0), mi_Capacity(_MaxSz), mpt_Data(new NodeAL[_MaxSz])
		{
			//Empty
		}

		virtual ~DAL () 
		{ 
			delete [] mpt_Data ; 
		}
		
		bool insert ( const Key & _newKey , const Data & _newInfo ); // Insere na lista .

		bool remove ( const Key & _x , Data & _s ); // Remove da lista .
		
		bool search ( const Key & _x , Data & _s ) const; // Busca publica .

		Key min ( ) const; // Recupera a menor chave do dicion´ario .

		Key max ( ) const; // Recupera a maior chave do dicion´ario .

		// Recupera em _y a chave sucessora a _x , se existir ( true ).
		bool sucessor ( const Key & _x , Key & _y ) const;

		// Recupera em _y a chave antecessora a _x , se existir ( true ).
		bool predecessor ( const Key & _x , Key & _y ) const;

		//! Sends back to the output stream an ascii representation for the list .
		inline friend
		std::ostream & operator<<( std::ostream & _os , const DAL & _oList ) 
		{
			_os << "[ ";
			for ( size_t i = 0 ; i < _oList.mi_Length ; ++ i )
			{	
				_os << "{id: " << _oList . mpt_Data [i ]. id << ", info : "
				<< _oList . mpt_Data [i ]. info << "} ";
				_os << "]"<<std::endl;

			}
				
			return _os;
		}
};
#include "Dicionario.inl"

#endif