/*
total_block_size: tamanho total do bloco em bytes.

occupied_size: quantidade de bytes atualmente ocupada por um processo.

block_address: endere�o do bloco dentro da estrutura de dados memory (ver
especifica��o do kernel).

next_free_block: endere�o do pr�ximo bloco livre na lista de blocos livres
(free_blocks_list). Se o bloco estiver ocupado, esta vari�vel deve ter o valor
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