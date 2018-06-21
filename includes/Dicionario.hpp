#ifndef Dicionario_H
#define Dicionario_H

#include <iostream>

using namespace std;

template < typename Key, typename Data, typename KeyComparator = std::less<Key>>
class DAL 
{
	protected:
		
		struct NodeAL 
		{
			Key id; 
			Data info ; 
		};

		static const size_t SIZE =50; // Tamanho default da lista.
		size_t mi_Length ; // Tamanho lógico da lista.
		size_t mi_Capacity ; // Tamanho maximo da lista.
		NodeAL *mpt_Data ; // Área de armazenamento : vetor alocado dinamicamente.

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
		
		bool insert ( const Key & _newKey , const Data & _newInfo ); // Insere na lista.

		bool remove ( const Key & _x , Data & _s ); // Remove da lista.
		
		bool search ( const Key & _x , Data & _s ) const; // Busca pública.

		Key min ( ) const; // Recupera a menor chave do dicionário.

		Key max ( ) const; // Recupera a maior chave do dicionário.

		// Recupera em _y a chave sucessora a _x , se existir ( true ).
		bool successor ( const Key & _x , Key & _y ) const;

		// Recupera em _y a chave antecessora a _x , se existir ( true ).
		bool predecessor ( const Key & _x , Key & _y ) const;

		// Verifica de o dicionário está vazio ou não.
		bool empty() const;

		// Retorna a capacidade maxima do dicionário.
		size_t capacity() const;

		// Retorna o tamanho lógico do dicionário.
		size_t size() const;

		// Operador << sobrecarregado para facilitar a impressão da lista.
		inline friend
		std::ostream & operator<<( std::ostream & _os , const DAL & _oList ) 
		{
			
			for ( size_t i = 0 ; i < _oList.mi_Length; ++ i )
			{	
				_os << "[ ";
				_os << "{id: " << _oList . mpt_Data [i ]. id << ", info : "
				<< _oList . mpt_Data [i ]. info << "} ";
				_os << "]"<<std::endl;

			}
				
			return _os;
		}
};

template < typename Key, typename Data, typename KeyComparator = std::less<Key>>
class DSAL : public DAL < Key, Data, KeyComparator>
{
	protected:		
		const static int SIZE = 50;
		int _search( const Key & _x ) const;
		
	public:	
		DSAL ( int _MaxSz = SIZE ) : DAL<Key, Data, KeyComparator>( _MaxSz ) {};
		virtual ~DSAL(){};

		bool insert ( const Key & _newKey , const Data & _newInfo ); // Insere na lista 
		Key min ( ) const; // Recupera a menor chave do dicion´ario .
		Key max ( ) const; // Recupera a maior chave do dicion´ario .
		
		bool search ( const Key & _x , Data & _s ) const; // Busca pública.

		// Recupera em _y a chave sucessora a _x , se existir ( true ).
		bool successor ( const Key & _x , Key & _y ) const;
		// Recupera em _y a chave antecessora a _x , se existir ( true ).
		bool predecessor ( const Key & _x , Key & _y ) const;
		
};
#include "Dicionario.inl"

#endif