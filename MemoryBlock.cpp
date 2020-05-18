/*
total_block_size: tamanho total do bloco em bytes.

occupied_size: quantidade de bytes atualmente ocupada por um processo.

block_address: endereço do bloco dentro da estrutura de dados memory (ver
especificação do kernel).

next_free_block: endereço do próximo bloco livre na lista de blocos livres
(free_blocks_list). Se o bloco estiver ocupado, esta variável deve ter o valor
NULL
*/


class MemoryBlock {
protected:
	int total_block_size;
	int occupied_size;
	int block_address;
	MemoryBlock* next_free_block;

public:
    
    MemoryBlock(){

    }

    MemoryBlock(){

    }

	void set_next_free_block(MemoryBlock* block)
    {
		next_free_block = block;
    }

	MemoryBlock* get_next_free_block() const
    {
		return next_free_block;
    }
	
};