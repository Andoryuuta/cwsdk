#pragma once

namespace plasma {
	class Object {
	public:
		//void* vtable;
		void* plasma_d3d9engine;
		void* some_nodes_linked_list;


		virtual void vf_dtor(uint8_t x) {};
	};
};