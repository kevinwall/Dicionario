#include "Dicionario.hpp"
#include <vector>

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