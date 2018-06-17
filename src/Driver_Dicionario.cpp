#include "../includes/Dicionario.hpp"

struct Comparadora
{
	bool operator()( const int &rhs, const int &lhs)
	{
		return rhs < lhs;
	}
};


int main()
{
	
	DAL<int, std::string, Comparadora > teste;

	bool aux = teste.insert(3256757, "Olá");

	if(aux == true)
	{
		std::cout<<"Inserção realizada com sucesso"<<std::endl;
	}
	else
	{
		std::cout<<"Inserção falhou"<<std::endl;
	}

	std::cout<<teste;

	return 0;
}