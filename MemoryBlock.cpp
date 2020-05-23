#ifndef MEMORYBLOCK_CPP
#define MEMORYBLOCK_CPP

class MemoryBlock {
protected:
	int total_block_size;           // tamanho total do bloco em bytes.
	int occupied_size;              // quantidade de bytes atualmente ocupada por um processo.
	int block_address;              // endereço do bloco dentro da estrutura de dados memory (ver kernel). vai ser == MemoryBlock*
	MemoryBlock* next_free_block;   // endere�o do pr�ximo bloco livre na lista de blocos livres (free_blocks_list). Se ocupado, valor NULL

public:
    
    MemoryBlock(int block_size) {
		total_block_size = block_size;
        //TODO fazer um construtor não vazio
    }

	void occupy(int size) {
		occupied_size = size;
	}

	void free() {
		occupied_size = 0;
	}

	void set_next_free_block(MemoryBlock* block) {
		next_free_block = block;
    }
	MemoryBlock* get_next_free_block() const {
		return next_free_block;
    }

	int get_total_block_size() const {
		return total_block_size;
	}
	
};

#endif