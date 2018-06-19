#include "../includes/Dicionario.hpp"

struct Comparadora
{
	bool operator()( const int &lhs, const int &rhs)
	{
		return lhs < rhs;
	}
};


int main()
{
	
	DSAL<int, std::string, Comparadora > teste_2;

	std::string aux_4;

	int minimo_2;

	{//Teste para ver se o metodo insert funciona corretamente.

		bool aux_3 = teste_2.insert(3256757, "Olá");

		teste_2.insert(3257, "Dados 1");

		if(aux_3 == true)
		{
			std::cout<<"Inserção realizada com sucesso"<<std::endl;
		}
		else
		{
			std::cout<<"Inserção falhou"<<std::endl;
		}

		std::cout<<teste_2;

		std::cout<<std::endl;
	
	}
	
	{//Teste para ver se o método search funciona corretamante.

		teste_2.insert(3256757, "Informação buscada");

		teste_2.search(3256757, aux_4);

		std::cout<<"A informação buscada no Dicionario foi: "<<aux_4<<std::endl;

		std::cout<<teste_2;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método min funciona corretamente

		teste_2.insert(3, "Dado 2");

		teste_2.insert(0, "Menor chave");

		minimo_2 = teste_2.min();

		std::cout<<"A menor chave do Dicionario é: "<<minimo_2<<std::endl;

		std::cout<<teste_2;

		std::cout<<std::endl;
	}
	
	{//Teste para ver se o método max funciona corretamente

		minimo_2 = teste_2.max();

		std::cout<<"A maior chave do Dicionario é: "<<minimo_2<<std::endl;

		std::cout<<teste_2;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método sucessor funciona corretamente

		int chave = 0;

		int sucess;

		teste_2.sucessor(chave, sucess);

		std::cout<<"O sucessor da chave : "<<chave<<" é: "<<sucess<<std::endl;

		std::cout<<teste_2;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método predecessor funciona corretamente

		int pred;

		int sucess = 3;

		teste_2.predecessor(sucess, pred);

		std::cout<<"O predecessor da chave : "<<sucess<<" é: "<<pred<<std::endl;

		std::cout<<teste_2;
	}

	return 0;
}