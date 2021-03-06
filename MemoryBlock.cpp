#ifndef MEMORYBLOCK_CPP
#define MEMORYBLOCK_CPP

class MemoryBlock {
protected:
	int total_block_size;           // tamanho total do bloco em bytes.
	int occupied_size;              // quantidade de bytes atualmente ocupada por um processo.
	int block_address;              // endereço do bloco dentro da estrutura de dados memory (ver kernel). vai ser == MemoryBlock*
	MemoryBlock* next_free_block;   // endere�o do pr�ximo bloco livre na lista de blocos livres (free_blocks_list). Se ocupado, valor NULL

public:
    
    MemoryBlock() {
        //TODO fazer um construtor não vazio
    }

	void set_next_free_block(MemoryBlock* block) {
		next_free_block = block;
    }

	MemoryBlock* get_next_free_block() const {
		return next_free_block;
    }
	
};

#endif