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
	
	DAL<int, std::string, Comparadora > teste;
	DSAL<int, std::string, Comparadora > teste_DSAL;

	std::string aux_2;

	int minimo;
	int maximo;

	{//Teste para ver se o metodo insert funciona corretamente.

		bool aux = teste.insert(3256757, "Olá");

		teste.insert(3257, "Dados 1");

		if(aux == true)
		{
			std::cout<<"Inserção realizada com sucesso"<<std::endl;
		}
		else
		{
			std::cout<<"Inserção falhou"<<std::endl;
		}

		std::cout<<teste;

		std::cout<<std::endl;
	
	}

	{//Teste para ver se o método remove funciona corretamente.

		teste.remove(3256757, aux_2);

		std::cout<<"A informação "<<aux_2<<" foi removida do Dicionario. "<<std::endl;

		std::cout<<teste;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método search funciona corretamante.

		teste.insert(3256757, "Informação buscada");

		teste.search(3256757, aux_2);

		std::cout<<"A informação buscada no Dicionario foi: "<<aux_2<<std::endl;

		std::cout<<teste;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método min funciona corretamente

		teste.insert(3, "Dado 2");

		teste.insert(0, "Menor chave");

		minimo = teste.min();

		std::cout<<"A menor chave do Dicionario é: "<<minimo<<std::endl;

		std::cout<<teste;

		std::cout<<std::endl;
	}
	
	{//Teste para ver se o método max funciona corretamente

		minimo = teste.max();

		std::cout<<"A maior chave do Dicionario é: "<<minimo<<std::endl;

		std::cout<<teste;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método sucessor funciona corretamente

		int chave = 0;

		int sucess;

		teste.sucessor(chave, sucess);

		//std::cout<<"O sucessor da chave : "<<chave<<" é: "<<sucess<<std::endl;

		std::cout<<teste;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método predecessor funciona corretamente

		int pred;

		int sucess = 0;

		teste.predecessor(sucess, pred);

		std::cout<<"O predecessor da chave : "<<sucess<<" é: "<<pred<<std::endl;

		std::cout<<teste;

		std::cout<<std::endl;
	}

	{//Teste para ver se o metodo insert funciona corretamente.

		bool aux = teste_DSAL.insert(3256757, "Dados aleatórios");

		teste_DSAL.insert(3257, "Dados 1");

		if(aux == true)
		{
			std::cout<<"Inserção realizada com sucesso"<<std::endl;
		}
		else
		{
			std::cout<<"Inserção falhou"<<std::endl;
		}

		std::cout<<teste_DSAL;

		std::cout<<std::endl;
	
	}



	{//Teste para ver se o método min funciona corretamente

		teste_DSAL.insert(3, "Dado 2");

		teste_DSAL.insert(0, "Menor chave");

		minimo = teste_DSAL.min();

		std::cout<<"A menor chave do Dicionario é: "<<minimo<<std::endl;

		std::cout<<teste_DSAL;

		std::cout<<std::endl;
	}
	
	{//Teste para ver se o método max funciona corretamente

		maximo = teste_DSAL.max();

		std::cout<<"A maior chave do Dicionario é: "<<maximo<<std::endl;

		std::cout<<teste_DSAL;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método sucessor funciona corretamente

		int chave = 0;

		int sucess;

		teste_DSAL.sucessor(chave, sucess);

		std::cout<<"O sucessor da chave : "<<chave<<" é: "<<sucess<<std::endl;

		std::cout<<teste_DSAL;

		std::cout<<std::endl;
	}

	{//Teste para ver se o método predecessor funciona corretamente

		int pred;

		int sucess = 3;

		teste_DSAL.predecessor(sucess, pred);

		std::cout<<"O predecessor da chave : "<<sucess<<" é: "<<pred<<std::endl;

		std::cout<<teste_DSAL;
	}


	return 0;
}