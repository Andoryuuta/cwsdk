#include "GameController.h"

namespace cube {
	void GameController::UpdateChunk(uint32_t x, uint32_t y) {
		// Go over all the loaded chunks
		int chunk_count = this->chunk_count_to_be_sqaured*this->chunk_count_to_be_sqaured;
		for (int i = 0; i < chunk_count; i++) {

			// Check if this is the chunk we want to update.
			cube::Chunk* chunk = &this->chunks[i];
			if (chunk->X == x && chunk->Y == y)
			{
				// If so, mark as needing update.
				chunk->needs_update = true;
			}
		}
	}
};

