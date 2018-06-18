#include "Dicionario.hpp"
#include <vector>
#include <algorithm>

template < typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::insert ( const Key & _newKey , const Data & _newInfo )
{
	if(mi_Length < mi_Capacity)
	{
		size_t i;

		for(i = 0; i < mi_Length; i++)
		{
			if(mpt_Data[i].id == _newKey)
			{
				return false;
			}
		}
		mpt_Data[mi_Length].id = _newKey;
		mpt_Data[mi_Length].info = _newInfo;

		mi_Length++;

		return true;
	}
	
	return false;
}

template < typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::remove ( const Key & _x , Data & _s )
{
	size_t i;

	for( i = 0; i < mi_Length; i++)
	{
		if(mpt_Data[i].id == _x)
		{
			_s = mpt_Data[i].info;

			NodeAL aux;

			for(auto j{i+1}; j < mi_Length; j++)
			{
				aux = mpt_Data[j-1];

				mpt_Data[j-1] = mpt_Data[j];

				mpt_Data[j] = aux;
			}

			mi_Length--;

			return true;
		}
	}

	return false;
}

template < typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::search ( const Key & _x , Data & _s ) const
{
	size_t i;

	for( i = 0; i < mi_Length; i++)
	{
		if(mpt_Data[i].id == _x)
		{
			_s = mpt_Data[i].info;

			return true;
		}
	}

	return false;
}

template < typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::min ( ) const
{
	size_t i;

	Key minimo = mpt_Data[0].id;

	KeyComparator comp;

	for( i = 1; i < mi_Length; i++)
	{
		if(comp(mpt_Data[i].id, minimo))
		{
			minimo = mpt_Data[i].id;
		}
	}

	return minimo;
}

template < typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::max ( ) const
{
	size_t i;

	Key maximo = mpt_Data[0].id;

	KeyComparator comp;

	for( i = 1; i < mi_Length; i++)
	{
		if(comp(maximo, mpt_Data[i].id))
		{
			maximo = mpt_Data[i].id;
		}
	}

	return maximo;
}

template < typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::sucessor ( const Key & _x , Key & _y ) const
{
	std::vector<Key> v;

	size_t i;

	KeyComparator comp;

	for(i = 0; i < mi_Length; i++)
	{
		if(comp(_x, mpt_Data[i].id))
		{
			v.push_back(mpt_Data[i].id);
		}
	}

	if(v.empty())
	{
		return false;
	}

	auto j = v.begin();

	Key suce = *j;

	j++;

	for(; j < v.end(); j++)
	{
		if(comp(*j, suce))
		{
			suce = *j;
		}
	}

	_y = suce;

	return true;
}

template < typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::predecessor ( const Key & _x , Key & _y ) const
{
	std::vector<Key> v;

	size_t i;

	KeyComparator comp;

	for(i = 0; i < mi_Length; i++)
	{
		if(comp(mpt_Data[i].id, _x))
		{
			v.push_back(mpt_Data[i].id);
		}
	}

	if(v.empty())
	{
		return false;
	}

	auto j = v.begin();

	Key suce = *j;

	j++;

	for(; j < v.end(); j++)
	{
		if(comp(suce, *j))
		{
			suce = *j;
		}
	}

	_y = suce;

	return true;
}

template< typename Key, typename Data, typename KeyComparator> 
	bool DSAL<  Key,  Data,  KeyComparator> ::insert( const Key & _newKey , const Data & _newInfo){
		
			if(this->mi_Length == this-> mi_Capacity || _search(_newKey) != -1){
				return false;
			}

			KeyComparator comp;
			Key aux;

			int pos = 0;
			int posicao = -1;

			while( pos < (int)this-> mi_Length){
				aux = this->mpt_Data[pos].id;
				if(comp(aux,_newKey)){
					posicao = pos;
				}
				++pos;
			}

			if( posicao == (int)this->mi_Length-1){
				this->mpt_Data[this->mi_Length].id = _newKey;
				this->mpt_Data[this->mi_Length].info = _newKey;
				++(this->mi_Length);
				return true;
			}else if( posicao == -1){
				for ( int i = (int)this->mi_Length; i > posicao+1; --i){
					this->mpt_Data[i].id = this->mpt_Data[i-1].id;
					this->mpt_Data[i].info = this->mpt_Data[i-1].info;
				}

				this->mpt_Data[posicao+1].id = _newKey;
				this->mpt_Data[posicao+1].info = _newInfo;
				++(this->mi_Length);
				return true;
			}

			return false;
		}

	template < typename Key, typename Data, typename KeyComparator>
	Key DSAL<Key, Data, KeyComparator>::min( ) const {
		
		if(this->mi_Length == 0){
			cout << " Empty Dictionary ";
		}

		return this->mpt_Data[0].id;
	}

	template < typename Key, typename Data, typename KeyComparator>
	Key DSAL<Key, Data, KeyComparator>::max( ) const {

		if(this->mi_Length == 0){
			cout << " Empty Dictionary ";
		}

		return this->mpt_Data[(this->mi_Length)-1].id;
	}
	
	template < typename Key, typename Data, typename KeyComparator>
	bool DSAL<Key, Data, KeyComparator>:: sucessor( const Key & _x, Key & _y ) const{
		
		int i = _search(_x);

		if ( i == (int)this->mi_Length-1 || i == -1 ||this->mi_Length == 0){
			return false;
		}

		_y = this -> mpt_Data[i+1].id;

		return true;
	}

	template < typename Key, typename Data, typename KeyComparator>
	bool DSAL<Key, Data, KeyComparator>:: predecessor( const Key & _x,  Key & _y ) const{
		
		int i = _search(_x);

		if ( i == 0 || i == -1 ||this->mi_Length == 0){
			return false;
		}

		_y = this -> mpt_Data[i-1].id;

		return true;
	}

	template < typename Key, typename Data, typename KeyComparator>
	int DSAL<Key, Data, KeyComparator>:: _search( const Key & _x ) const {
		
		auto begin = 0;
		auto end = this->mi_Length-1;	

		KeyComparator comp;

		while( begin <= (int)end ){
			auto mid = end + ( begin - end ) / 2;

			if( (not comp(_x, this->mpt_Data[mid].id)) and ( not comp(this->mpt_Data[mid].id, _x)) ){
				return mid;
			
			}else if( comp(_x, this->mpt_Data[mid].id) ){
				end = mid - 1 ;
			}else{
				begin = mid +1 ;
			}
		}

		return -1;
	
	}
