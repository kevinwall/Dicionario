#include <iostream>
#include "DSAL.hpp"
#include <vector>
#include <algorithm>

using namespace std;

	template< typename Key, typename Data, typename KeyComparator> 
	bool DSAL<  Key,  Data,  KeyComparator> ::insert( const Key & _newKey , const Data & _newInfo){
		
			if(mi_Length < mi_Capacity){
			
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

			sort( mpt_Data.begin() ,mpt_Data.end());

			return true;
		}
		
		return false;
		}

	template < typename Key, typename Data, typename KeyComparator>
	Key DSAL<Key, Data, KeyComparator>::min( ) const {
		
		if( mi_Length.size() == 0){
			cout << " Empty Dictionary ";
		}

		return mpt_Data.front().id;
	}

	template < typename Key, typename Data, typename KeyComparator>
	Key DSAL<Key, Data, KeyComparator>::max( ) const {

		if( mi_Length.size() == 0){
			cout << " Empty Dictionary ";
		}

		return mpt_Data.back().id;
	}
	
	template < typename Key, typename Data, typename KeyComparator>
	bool DSAL<Key, Data, KeyComparator>:: sucessor( const Key & _x, const Key & _y ) const{
		
		if( mi_Length.size() == 0){
			return false
		}else if(mpt_Data[_x+1].id != NULL ){
			_y = mpt_Data[_x+1].id ;
			return true 
		}

		return false;
	}

	template < typename Key, typename Data, typename KeyComparator>
	bool DSAL<Key, Data, KeyComparator>:: predecessor( const Key & _x, const Key & _y ) const{
		
		if( mi_Length.size() == 0){
			return false
		}else if(mpt_Data[_x-1].id != NULL ){
			_y = mpt_Data[_x-1].id ;
			return true 
		}

		return false;
	}

	template < typename Key, typename Data, typename KeyComparator>
	int DSAL<Key, Data, KeyComparator>:: _search( const Key & _x ) const {
		
		auto begin = mpt_Data.begin();
		auto end = mpt_Data.end();	

		while( begin <= end ){
			auto mid = end + ( begin - end ) / 2;

			if( mpt_Data[mid] == _x ){
				return mid;
			
			}else if( mpt_Data[mid] < _x ){
				begin = mid +1 ;
			
			}else{
				end = mid - 1 ;
			}
		}

		return -1;
	
	}
