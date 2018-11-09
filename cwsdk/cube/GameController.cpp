#include "GameController.h"
#include <iostream>

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


	double degrees_to_radians(double degrees) {
		return (degrees * 3.1415926535) / 180.0;
	}
	double radians_to_degrees(double radians) {
		return (radians * 180.0) / 3.1415926535;
	}


	bool GameController::CameraVoxelRaycast(int64_t max_distance_in_blocks, Vector3<int64_t>* out_block, Vector3<int64_t>* out_face) {
		// Essentially Copy+Pasted from ChrisMiuchiz
		double yaw = degrees_to_radians(this->camera_current_rotation.Z + 90.0);
		double pitch = degrees_to_radians(this->camera_current_rotation.X);

		Vector3<double> direction;
		direction.X = cos(yaw) * sin(pitch);
		direction.Y = sin(yaw) * sin(pitch);
		direction.Z = -cos(pitch);

		std::cout << "Direction X:" << direction.X << std::endl;
		std::cout << "Direction Y:" << direction.Y << std::endl;
		std::cout << "Direction Z:" << direction.Z << std::endl;

		return this->world.VoxelRayCast(this->camera_position, direction, max_distance_in_blocks, out_block, out_face);

	}
};

