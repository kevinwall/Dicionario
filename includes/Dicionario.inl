#include "Dicionario.hpp"

template < typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::insert ( const Key & _newKey , const Data & _newInfo )
{
	if(mi_Length < mi_Capacity)
	{
		mpt_Data[mi_Length].id = _newKey;
		mpt_Data[mi_Length].info = _newInfo;

		mi_Length++;

		return true;
	}
	
	return false;
}